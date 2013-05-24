#include "fujin.h"
#include "utils.h"
#include "lib/chinookpack.h"
#include <stdio.h>
#include <string.h>

// Device Configurations registers
_FOSCSEL(FNOSC_FRCPLL); // select fast internal rc with pll
_FOSC(FCKSM_CSECMD & OSCIOFNC_OFF & POSCMD_XT);
_FWDT(FWDTEN_OFF); // Watchdog timer software enabled



void fujin_recv_can_msg(unsigned long ID,
                        T_TYPE_ID type_ID,
                        const void * data_rx,
                        char nbr_data);


uint8_t print=0;


T_CAN_Tx_MSG can_msg_clock;
T_CAN_Tx_MSG can_msg_current;
T_CAN_Tx_MSG can_msg_voltage;
T_CAN_Tx_MSG can_msg_pitch;
T_CAN_Tx_MSG can_msg_gear;

uint8_t can_msg_current_buf[3];
uint8_t can_msg_voltage_buf[3];

char can_buf[8];
chinookpack_fbuffer fbuf;
chinookpack_packer pk;

int main(void) {

    fujin_init_board();

    // CAN PREPARATION
    config_CAN_Tx_msg(&can_msg_current, CAN_MSG_VOLTAGE_MONITOR_SID , STANDARD_ID, 3);
    config_CAN_Tx_msg(&can_msg_voltage, CAN_MSG_CURRENT_MONITOR_SID , STANDARD_ID, 3);
    config_CAN_Tx_msg(&can_msg_clock,   CAN_MSG_TIME_SID , STANDARD_ID, 3);
    config_CAN_Tx_msg(&can_msg_pitch,   CAN_MSG_PITCH_AUTO_SID , STANDARD_ID, 3);
    config_CAN_Tx_msg(&can_msg_gear,    CAN_MSG_GEAR_FUJIN_SID , STANDARD_ID, 3);

    // Initialize everything
    clear_buf(can_buf,8);
    chinookpack_fbuffer_init(&fbuf,can_buf,8);
    chinookpack_packer_init(&pk,&fbuf,chinookpack_fbuffer_write);

    // Read Clock for timestamps
    #if ENABLE_RTC == TRUE
    // init the rtc
    #endif

    // TODO: Read Eeprom Parameters
    //       and and set settings

    int i=0;
    while(1){

        // 1. Read Current and SHUT DOWN RELAY if overloading
        #if ENABLE_VMON == TRUE && ENABLE_I2C == TRUE
        fujin.chinook.power.v = ltc4151_read_voltage(&(fujin.ltc4151_state));
        fujin.chinook.power.i = ltc4151_read_current(&(fujin.ltc4151_state));
        if(fujin.chinook.power.v > 13.5)
            SWITCH_RELAY = ON;

        // TODO : START A TIMER AND CHECK SAY 2 SEC LATER FOR VOLTAGE
        if(fujin.chinook.power.v < 13.5)
            SWITCH_RELAY = OFF;
        #endif

        
        // 2. Read Clock for timestamps
        #if ENABLE_RTC == TRUE
        // At some interval read rtc and send time on can
        #endif

        // 3. CAN Processing
        #if ENABLE_CAN == TRUE
        while(print==0);
        print=0;

        LATBbits.LATB14 ^=1;

        clear_buf(can_buf,8);
        chinookpack_pack_float(&pk,fujin.chinook.power.i);
        memcpy(can_msg_current_buf,can_buf,3);
        send_CAN_msg(&can_msg_current, can_msg_current_buf, 2);
        while(is_CAN_msg_send(&can_msg_current) != TRUE);      // test si le message est envoyé

        while(print==0);
        print=0;

        clear_buf(can_buf,8);
        chinookpack_pack_float(&pk,fujin.chinook.power.v);
        memcpy(can_msg_voltage_buf,can_buf,3);
        send_CAN_msg(&can_msg_voltage, can_msg_voltage_buf, 2);
        while(is_CAN_msg_send(&can_msg_voltage) != TRUE);      // test si le message est envoyé


        // 2. Read Clock for timestamps
        #if ENABLE_RTC == TRUE
        // At some interval read rtc and send time on can
        #endif

        #endif

        // 4. UART Processing
        #if ENABLE_UART == TRUE
        // 4.1 XBEE Processing
        #if ENABLE_XBEE == TRUE
        #endif
        // 4.2 USB-Serial Processing
        #if ENABLE_USBSERIAL == TRUE
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
void fujin_recv_can_msg(unsigned long ID,
                        T_TYPE_ID type_ID,
                        const void * data_rx,
                        char nbr_data){
  char* datReceive ;
  int old_ipl;
  // Block interruptions
  SET_AND_SAVE_CPU_IPL(old_ipl, 7);

  datReceive = (char *)data_rx;

  RESTORE_CPU_IPL(old_ipl);
}