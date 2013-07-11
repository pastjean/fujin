#include "fujin.h"
#include "utils.h"
#include "lib/chinookpack.h"
#include <stdio.h>
#include <string.h>

// Device Configurations registers
_FOSCSEL(FNOSC_FRCPLL); // select fast internal rc with pll
_FOSC(FCKSM_CSECMD & OSCIOFNC_OFF & POSCMD_XT);
_FWDT(FWDTEN_OFF); // Watchdog timer software enabled

uint8_t print=0;
unsigned char CanTimeout = 0;

int datReceive_can_cmd;
char datReceive_can_shift;
char datReceive_can_EEPROM_CONFIG_ANSWER;
float datReceive_can_pitch_orientation = 0.0f;
float datReceive_can_wind_speed = 0.0f;
float datReceive_can_wind_direction = 0.0f;
float datReceive_can_turbine_rpm_motor = 0.0f;
float datReceive_can_wheel_rpm = 0.0f;
float datReceive_can_turbine_direction = 0.0f;
unsigned char datReceive_can_gear = 0;
float datReceive_can_voltage_monitor = 0.0f;

void setup_can_rx(void);
void fct_can_cmd(unsigned long ID, T_TYPE_ID type_ID, T_CAN_DATA* recopie, char nbr_data);
void fct_can_shift(unsigned long ID, T_TYPE_ID type_ID, T_CAN_DATA* recopie, char nbr_data);
void fct_can_EEPROM_CONFIG_ANSWER(unsigned long ID, T_TYPE_ID type_ID, T_CAN_DATA* recopie, char nbr_data);
void fct_can_pitch_orientation(unsigned long ID, T_TYPE_ID type_ID, T_CAN_DATA* recopie, char nbr_data);
void fct_can_wind_speed(unsigned long ID, T_TYPE_ID type_ID, T_CAN_DATA* recopie, char nbr_data);
void fct_can_wind_direction(unsigned long ID, T_TYPE_ID type_ID, T_CAN_DATA* recopie, int nbr_data);
void fct_can_turbine_rpm_motor(unsigned long ID, T_TYPE_ID type_ID, T_CAN_DATA* recopie, char nbr_data);
void fct_can_wheel_rpm(unsigned long ID, T_TYPE_ID type_ID, T_CAN_DATA* recopie, char nbr_data);
void fct_can_turbine_direction(unsigned long ID, T_TYPE_ID type_ID, T_CAN_DATA* recopie, char nbr_data);
void fct_can_gear(unsigned long ID, T_TYPE_ID type_ID, T_CAN_DATA* recopie, char nbr_data);

T_CAN_Tx_MSG can_msg_clock;
T_CAN_Tx_MSG can_msg_current;
T_CAN_Tx_MSG can_msg_voltage;
T_CAN_Tx_MSG can_msg_pitch;
T_CAN_Tx_MSG can_msg_gear;

char bTxCanBuffer[8];
chinookpack_fbuffer buf;
chinookpack_packer pk;
chinookpack_unpacked unpacker; //Will contain the unpacked data
unsigned int off = 0; //offset to read more than 1 msg in 1 packet

uint8_t can_msg_current_buf[5];
uint8_t can_msg_voltage_buf[5];

char can_buf[8];
chinookpack_fbuffer fbuf;
chinookpack_packer pk;

void tst(Skadi* skadi, SkadiArgs args){LATBbits.LATB13 ^=1;}

SkadiCommand skadiCommandTable[] = {
  {"test", tst, 0, "test test test test test"}
};

uint8_t uartline_rcv_new;
char uartline_rcv[256];

void uartReceiveLineEvt(const char* line,size_t s){
    uartline_rcv_new=1;
    memcpy(uartline_rcv,line,s-1);
    uartline_rcv[s-1]= '\0';
}

int main(void) {

    fujin_init_board();

    // CAN PREPARATION
    #if ENABLE_CAN == TRUE
    config_CAN_Tx_msg(&can_msg_current, CAN_MSG_CURRENT_MONITOR_SID , STANDARD_ID, 3);
    config_CAN_Tx_msg(&can_msg_voltage, CAN_MSG_VOLTAGE_MONITOR_SID , STANDARD_ID, 3);
    config_CAN_Tx_msg(&can_msg_clock,   CAN_MSG_TIME_SID , STANDARD_ID, 3);
    //config_CAN_Tx_msg(&can_msg_pitch,   CAN_MSG_PITCH_AUTO_SID , STANDARD_ID, 3);
    config_CAN_Tx_msg(&can_msg_gear,    CAN_MSG_GEAR_FUJIN_SID , STANDARD_ID, 3);
    #endif
    
    // Read Clock for timestamps
    #if ENABLE_RTC == TRUE
    // init the rtc
    #endif

    // TODO: Read Eeprom Parameters
    //       and and set settings
    UartSetRXLineEvt(UART_1,uartReceiveLineEvt);
    UartSetRXLineEvt(UART_2,uartReceiveLineEvt);
    skadi_init(&fujin.skadi, skadiCommandTable,sizeof(skadiCommandTable)/sizeof(SkadiCommand));

    skadi_process_command(&fujin.skadi,"test");
    while(1){
        // 1. Read Current and SHUT DOWN RELAY if overloading
        #if ENABLE_VMON == TRUE && ENABLE_I2C == TRUE
        fujin.chinook.power.v = ltc4151_read_voltage(&(fujin.ltc4151_state));
        fujin.chinook.power.i = ltc4151_read_current(&(fujin.ltc4151_state));
        #endif

        
        // 2. Read Clock for timestamps
        #if ENABLE_RTC == TRUE
        // At some interval read rtc and send time on can
        #endif
        if(print)
        {
            // 3. CAN Processing
            #if ENABLE_CAN == TRUE
            chinookpack_pack_float(&pk,fujin.chinook.power.i);
            Set_Timeout();
            send_CAN_msg(&can_msg_current, can_buf, 5);
            while(is_CAN_msg_send(&can_msg_current) != TRUE && !CanTimeout);      // test si le message est envoyÃ©
            Reset_Timeout();
            chinookpack_fbuffer_clear(&fbuf);

            chinookpack_pack_float(&pk,fujin.chinook.power.v);
            Set_Timeout();
            send_CAN_msg(&can_msg_voltage, can_buf, 5);
            while(is_CAN_msg_send(&can_msg_voltage) != TRUE && !CanTimeout);      // test si le message est envoyÃ©
            Reset_Timeout();
            chinookpack_fbuffer_clear(&fbuf);

            print = 0;
        }
        // 2. Read Clock for timestamps
        #if ENABLE_RTC == TRUE
        // At some interval read rtc and send time on can
        #endif

        #endif


        // skadi_process_command(&fujin.skadi, "cmdline :)");
        // 4. UART Processing
        #if ENABLE_UART == TRUE
        // 4.1 XBEE Processing
        #if ENABLE_XBEE == TRUE
// TODO: Si en listen mode send DATA

        #endif
        // 4.2 USB-Serial Processing
        #if ENABLE_USBSERIAL == TRUE
        if(uartline_rcv_new){
            skadi_process_command(&fujin.skadi,uartline_rcv);
            uartline_rcv_new=0;
        }
        #endif
        #endif

    }

    // Should never go there
    return 0;
}

void __attribute__((interrupt, auto_psv)) _T5Interrupt(void)
{
    /*Timer used for display at 10 Hz*/
    if(print==0) print = 1;

    _T5IF=0;
}
void __attribute__((interrupt, auto_psv)) _T3Interrupt(void)
{
    CanTimeout = 1;
    _T3IF=0;
}

void setup_can_rx(void)
{

	/*configuration du message pour le boutton */
	config_CAN_filter(0, CAN_MSG_BUTTON_CMD_SID , STANDARD_ID);
	receive_CAN_msg(0, 3, fct_can_cmd);
	//config_CAN_mask(0, 2.0f, STANDARD_ID);

	/*configuration du message pour le shift */
	config_CAN_filter(1, CAN_MSG_SHIFT_SID , STANDARD_ID);
	receive_CAN_msg(1, 3, fct_can_shift);
	//config_CAN_mask(0, 2.0f, STANDARD_ID);

        /*configuration du message de la requête des dernières valeurs d'automatisation */
	config_CAN_filter(2, CAN_MSG_EEPROM_CONFIG_ANSWER_SID, STANDARD_ID);
	receive_CAN_msg(2, 3, fct_can_EEPROM_CONFIG_ANSWER);
	//config_CAN_mask(0, 2.0f, STANDARD_ID);

        	/*configuration du message pour les commandes */
	config_CAN_filter(3, CAN_MSG_BUTTON_CMD_SID , STANDARD_ID);
	receive_CAN_msg(3, 3, fct_can_cmd);
	//config_CAN_mask(0, 2.0f, STANDARD_ID);

	/*configuration du message pour l'orientation du pitch */
	config_CAN_filter(4, CAN_MSG_MANUAL_PITCH_SID , STANDARD_ID);
	receive_CAN_msg(4, 3, fct_can_pitch_orientation);
	//config_CAN_mask(1, 2.0f, STANDARD_ID);

	/*configuration du message pour la vitesse du vent */
	config_CAN_filter(5, CAN_MSG_WIND_SPEED_SID , STANDARD_ID);
	receive_CAN_msg(5, 3, fct_can_wind_speed);
	//config_CAN_mask(2, 2.0f, STANDARD_ID);

	/*configuration du message pour la direction du vent */
	config_CAN_filter(6, CAN_MSG_WIND_DIRECTION_SID , STANDARD_ID);
	receive_CAN_msg(6, 3, fct_can_wind_direction);
	//config_CAN_mask(3, 2.0f, STANDARD_ID);

	/*configuration du message pour le RPM Moteur */
	config_CAN_filter(7, CAN_MSG_TURBINE_RPM_MOTOR_SID , STANDARD_ID);
	receive_CAN_msg(7, 3, fct_can_turbine_rpm_motor);
	//config_CAN_mask(5, 2.0f, STANDARD_ID);

	/*configuration du message pour le RPM Roues */
	config_CAN_filter(8, CAN_MSG_WHEEL_RPM_SID , STANDARD_ID);
	receive_CAN_msg(8, 3, fct_can_wheel_rpm);
	//config_CAN_mask(6, 2.0f, STANDARD_ID);

	/*configuration du message pour la direction de l'eolienne */
	config_CAN_filter(9, CAN_MSG_TURBINE_DIRECTION_SID , STANDARD_ID);
	receive_CAN_msg(9, 3, fct_can_turbine_direction);
	//config_CAN_mask(7, 2.0f, STANDARD_ID);

	/*configuration du message pour le gear */
	config_CAN_filter(10, CAN_MSG_GEAR_SID , STANDARD_ID);
	receive_CAN_msg(10, 3, fct_can_gear);
	//config_CAN_mask(8, 2.0f, STANDARD_ID);

}
void fct_can_cmd(unsigned long ID, T_TYPE_ID type_ID, T_CAN_DATA* recopie, char nbr_data)
{
        const char ubReceiveData[5] = {(recopie->data3 & 0x00FF),(recopie->data3 & 0xFF00)>>8,(recopie->data4 & 0x00FF),(recopie->data4 & 0xFF00)>>8,(recopie->data5 & 0x00FF)};
	int old_ipl;

	// Block interruptions
	SET_AND_SAVE_CPU_IPL(old_ipl, 7);

	off = 0;
	chinookpack_unpack_next(&unpacker,ubReceiveData,5,&off);
	off = 0;

	RESTORE_CPU_IPL(old_ipl);

        datReceive_can_cmd = (int)unpacker.data.via.i64;
}
void fct_can_shift(unsigned long ID, T_TYPE_ID type_ID, T_CAN_DATA* recopie, char nbr_data)
{
        const char ubReceiveData[5] = {(recopie->data3 & 0x00FF),(recopie->data3 & 0xFF00)>>8,(recopie->data4 & 0x00FF),(recopie->data4 & 0xFF00)>>8,(recopie->data5 & 0x00FF)};
	int old_ipl;

	// Block interruptions
	SET_AND_SAVE_CPU_IPL(old_ipl, 7);

	off = 0;
	chinookpack_unpack_next(&unpacker,ubReceiveData,5,&off);
	off = 0;

	RESTORE_CPU_IPL(old_ipl);

        datReceive_can_shift = (char)unpacker.data.via.u64;
}
void fct_can_EEPROM_CONFIG_ANSWER(unsigned long ID, T_TYPE_ID type_ID, T_CAN_DATA* recopie, char nbr_data)
{
        const char ubReceiveData[5] = {(recopie->data3 & 0x00FF),(recopie->data3 & 0xFF00)>>8,(recopie->data4 & 0x00FF),(recopie->data4 & 0xFF00)>>8,(recopie->data5 & 0x00FF)};
	int old_ipl;

	// Block interruptions
	SET_AND_SAVE_CPU_IPL(old_ipl, 7);

	off = 0;
	chinookpack_unpack_next(&unpacker,ubReceiveData,5,&off);
	off = 0;

	RESTORE_CPU_IPL(old_ipl);

        datReceive_can_EEPROM_CONFIG_ANSWER = (char)unpacker.data.via.u64;
}
void fct_can_pitch_orientation(unsigned long ID, T_TYPE_ID type_ID, T_CAN_DATA* recopie, char nbr_data)
{
        const char ubReceiveData[5] = {(recopie->data3 & 0x00FF),(recopie->data3 & 0xFF00)>>8,(recopie->data4 & 0x00FF),(recopie->data4 & 0xFF00)>>8,(recopie->data5 & 0x00FF)};
	int old_ipl;

	// Block interruptions
	SET_AND_SAVE_CPU_IPL(old_ipl, 7);
	off = 0;
	chinookpack_unpack_next(&unpacker,ubReceiveData,5,&off);
	off = 0;
	RESTORE_CPU_IPL(old_ipl);
        datReceive_can_pitch_orientation = unpacker.data.via.dec;
}
void fct_can_wind_speed(unsigned long ID, T_TYPE_ID type_ID, T_CAN_DATA* recopie, char nbr_data)
{
        const char ubReceiveData[5] = {(recopie->data3 & 0x00FF),(recopie->data3 & 0xFF00)>>8,(recopie->data4 & 0x00FF),(recopie->data4 & 0xFF00)>>8,(recopie->data5 & 0x00FF)};
	int old_ipl;

	// Block interruptions
	SET_AND_SAVE_CPU_IPL(old_ipl, 7);
	off = 0;
	chinookpack_unpack_next(&unpacker,ubReceiveData,5,&off);
	off = 0;
	RESTORE_CPU_IPL(old_ipl);
        datReceive_can_wind_speed = unpacker.data.via.dec;
}
//volatile void fct_can_wind_direction(unsigned long ID, T_TYPE_ID type_ID,T_CAN_DATA recopie, int nbr_data)
void fct_can_wind_direction(unsigned long ID, T_TYPE_ID type_ID, T_CAN_DATA* recopie, int nbr_data)
{
        const char ubReceiveData[5] = {(recopie->data3 & 0x00FF),(recopie->data3 & 0xFF00)>>8,(recopie->data4 & 0x00FF),(recopie->data4 & 0xFF00)>>8,(recopie->data5 & 0x00FF)};
	int old_ipl;

	// Block interruptions
	SET_AND_SAVE_CPU_IPL(old_ipl, 7);
	off = 0;
	chinookpack_unpack_next(&unpacker,ubReceiveData,5,&off);
	off = 0;
	RESTORE_CPU_IPL(old_ipl);
        datReceive_can_wind_direction = unpacker.data.via.dec;

}
void fct_can_turbine_rpm_motor(unsigned long ID, T_TYPE_ID type_ID, T_CAN_DATA* recopie, char nbr_data)
{
        const char ubReceiveData[5] = {(recopie->data3 & 0x00FF),(recopie->data3 & 0xFF00)>>8,(recopie->data4 & 0x00FF),(recopie->data4 & 0xFF00)>>8,(recopie->data5 & 0x00FF)};
	int old_ipl;

	// Block interruptions
	SET_AND_SAVE_CPU_IPL(old_ipl, 7);
	off = 0;
	chinookpack_unpack_next(&unpacker,ubReceiveData,5,&off);
	off = 0;
	RESTORE_CPU_IPL(old_ipl);
        datReceive_can_turbine_rpm_motor = unpacker.data.via.dec;
}
void fct_can_wheel_rpm(unsigned long ID, T_TYPE_ID type_ID, T_CAN_DATA* recopie, char nbr_data)
{
        const char ubReceiveData[5] = {(recopie->data3 & 0x00FF),(recopie->data3 & 0xFF00)>>8,(recopie->data4 & 0x00FF),(recopie->data4 & 0xFF00)>>8,(recopie->data5 & 0x00FF)};
	int old_ipl;

	// Block interruptions
	SET_AND_SAVE_CPU_IPL(old_ipl, 7);
	off = 0;
	chinookpack_unpack_next(&unpacker,ubReceiveData,5,&off);
	off = 0;
	RESTORE_CPU_IPL(old_ipl);
        datReceive_can_wheel_rpm = unpacker.data.via.dec;
}
void fct_can_turbine_direction(unsigned long ID, T_TYPE_ID type_ID, T_CAN_DATA* recopie, char nbr_data)
{
        const char ubReceiveData[5] = {(recopie->data3 & 0x00FF),(recopie->data3 & 0xFF00)>>8,(recopie->data4 & 0x00FF),(recopie->data4 & 0xFF00)>>8,(recopie->data5 & 0x00FF)};
	int old_ipl;

	// Block interruptions
	SET_AND_SAVE_CPU_IPL(old_ipl, 7);
	off = 0;
	chinookpack_unpack_next(&unpacker,ubReceiveData,5,&off);
	off = 0;
	RESTORE_CPU_IPL(old_ipl);
        datReceive_can_turbine_direction = unpacker.data.via.dec;
}
void fct_can_gear(unsigned long ID, T_TYPE_ID type_ID, T_CAN_DATA* recopie, char nbr_data)
{
        const char ubReceiveData[2] = {(recopie->data3 & 0x00FF),(recopie->data3 & 0xFF00)>>8};
	int old_ipl;

	// Block interruptions
	SET_AND_SAVE_CPU_IPL(old_ipl, 7);
	off = 0;
	chinookpack_unpack_next(&unpacker,ubReceiveData,5,&off);
	off = 0;
	RESTORE_CPU_IPL(old_ipl);
        datReceive_can_gear = (unsigned char)unpacker.data.via.u64;
}

/************************************************************/