#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/dspic.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/dspic.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/main.o ${OBJECTDIR}/fujin.o ${OBJECTDIR}/i2c.o ${OBJECTDIR}/uart.o ${OBJECTDIR}/cat24c256w.o ${OBJECTDIR}/ds1338.o ${OBJECTDIR}/ltc4151.o ${OBJECTDIR}/M_TMR.o ${OBJECTDIR}/chinookpack_unpack.o
POSSIBLE_DEPFILES=${OBJECTDIR}/main.o.d ${OBJECTDIR}/fujin.o.d ${OBJECTDIR}/i2c.o.d ${OBJECTDIR}/uart.o.d ${OBJECTDIR}/cat24c256w.o.d ${OBJECTDIR}/ds1338.o.d ${OBJECTDIR}/ltc4151.o.d ${OBJECTDIR}/M_TMR.o.d ${OBJECTDIR}/chinookpack_unpack.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/main.o ${OBJECTDIR}/fujin.o ${OBJECTDIR}/i2c.o ${OBJECTDIR}/uart.o ${OBJECTDIR}/cat24c256w.o ${OBJECTDIR}/ds1338.o ${OBJECTDIR}/ltc4151.o ${OBJECTDIR}/M_TMR.o ${OBJECTDIR}/chinookpack_unpack.o


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/dspic.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33EP512MC806
MP_LINKER_FILE_OPTION=,--script=p33EP512MC806.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/main.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d"        -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -omf=elf -O0 -I"/Users/pastjean/Documents/projets/fujin/firmware/dspic" -msmart-io=1 -Wall -msfr-warn=off --std=c99
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/fujin.o: fujin.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/fujin.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  fujin.c  -o ${OBJECTDIR}/fujin.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/fujin.o.d"        -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -omf=elf -O0 -I"/Users/pastjean/Documents/projets/fujin/firmware/dspic" -msmart-io=1 -Wall -msfr-warn=off --std=c99
	@${FIXDEPS} "${OBJECTDIR}/fujin.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/i2c.o: i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/i2c.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  i2c.c  -o ${OBJECTDIR}/i2c.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/i2c.o.d"        -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -omf=elf -O0 -I"/Users/pastjean/Documents/projets/fujin/firmware/dspic" -msmart-io=1 -Wall -msfr-warn=off --std=c99
	@${FIXDEPS} "${OBJECTDIR}/i2c.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/uart.o: uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/uart.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  uart.c  -o ${OBJECTDIR}/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/uart.o.d"        -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -omf=elf -O0 -I"/Users/pastjean/Documents/projets/fujin/firmware/dspic" -msmart-io=1 -Wall -msfr-warn=off --std=c99
	@${FIXDEPS} "${OBJECTDIR}/uart.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/cat24c256w.o: cat24c256w.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/cat24c256w.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  cat24c256w.c  -o ${OBJECTDIR}/cat24c256w.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/cat24c256w.o.d"        -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -omf=elf -O0 -I"/Users/pastjean/Documents/projets/fujin/firmware/dspic" -msmart-io=1 -Wall -msfr-warn=off --std=c99
	@${FIXDEPS} "${OBJECTDIR}/cat24c256w.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ds1338.o: ds1338.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ds1338.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ds1338.c  -o ${OBJECTDIR}/ds1338.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ds1338.o.d"        -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -omf=elf -O0 -I"/Users/pastjean/Documents/projets/fujin/firmware/dspic" -msmart-io=1 -Wall -msfr-warn=off --std=c99
	@${FIXDEPS} "${OBJECTDIR}/ds1338.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ltc4151.o: ltc4151.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ltc4151.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ltc4151.c  -o ${OBJECTDIR}/ltc4151.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ltc4151.o.d"        -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -omf=elf -O0 -I"/Users/pastjean/Documents/projets/fujin/firmware/dspic" -msmart-io=1 -Wall -msfr-warn=off --std=c99
	@${FIXDEPS} "${OBJECTDIR}/ltc4151.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/M_TMR.o: M_TMR.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/M_TMR.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  M_TMR.c  -o ${OBJECTDIR}/M_TMR.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/M_TMR.o.d"        -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -omf=elf -O0 -I"/Users/pastjean/Documents/projets/fujin/firmware/dspic" -msmart-io=1 -Wall -msfr-warn=off --std=c99
	@${FIXDEPS} "${OBJECTDIR}/M_TMR.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/chinookpack_unpack.o: chinookpack_unpack.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/chinookpack_unpack.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  chinookpack_unpack.c  -o ${OBJECTDIR}/chinookpack_unpack.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/chinookpack_unpack.o.d"        -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -omf=elf -O0 -I"/Users/pastjean/Documents/projets/fujin/firmware/dspic" -msmart-io=1 -Wall -msfr-warn=off --std=c99
	@${FIXDEPS} "${OBJECTDIR}/chinookpack_unpack.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/main.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d"        -g -omf=elf -O0 -I"/Users/pastjean/Documents/projets/fujin/firmware/dspic" -msmart-io=1 -Wall -msfr-warn=off --std=c99
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/fujin.o: fujin.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/fujin.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  fujin.c  -o ${OBJECTDIR}/fujin.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/fujin.o.d"        -g -omf=elf -O0 -I"/Users/pastjean/Documents/projets/fujin/firmware/dspic" -msmart-io=1 -Wall -msfr-warn=off --std=c99
	@${FIXDEPS} "${OBJECTDIR}/fujin.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/i2c.o: i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/i2c.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  i2c.c  -o ${OBJECTDIR}/i2c.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/i2c.o.d"        -g -omf=elf -O0 -I"/Users/pastjean/Documents/projets/fujin/firmware/dspic" -msmart-io=1 -Wall -msfr-warn=off --std=c99
	@${FIXDEPS} "${OBJECTDIR}/i2c.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/uart.o: uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/uart.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  uart.c  -o ${OBJECTDIR}/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/uart.o.d"        -g -omf=elf -O0 -I"/Users/pastjean/Documents/projets/fujin/firmware/dspic" -msmart-io=1 -Wall -msfr-warn=off --std=c99
	@${FIXDEPS} "${OBJECTDIR}/uart.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/cat24c256w.o: cat24c256w.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/cat24c256w.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  cat24c256w.c  -o ${OBJECTDIR}/cat24c256w.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/cat24c256w.o.d"        -g -omf=elf -O0 -I"/Users/pastjean/Documents/projets/fujin/firmware/dspic" -msmart-io=1 -Wall -msfr-warn=off --std=c99
	@${FIXDEPS} "${OBJECTDIR}/cat24c256w.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ds1338.o: ds1338.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ds1338.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ds1338.c  -o ${OBJECTDIR}/ds1338.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ds1338.o.d"        -g -omf=elf -O0 -I"/Users/pastjean/Documents/projets/fujin/firmware/dspic" -msmart-io=1 -Wall -msfr-warn=off --std=c99
	@${FIXDEPS} "${OBJECTDIR}/ds1338.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ltc4151.o: ltc4151.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ltc4151.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ltc4151.c  -o ${OBJECTDIR}/ltc4151.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ltc4151.o.d"        -g -omf=elf -O0 -I"/Users/pastjean/Documents/projets/fujin/firmware/dspic" -msmart-io=1 -Wall -msfr-warn=off --std=c99
	@${FIXDEPS} "${OBJECTDIR}/ltc4151.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/M_TMR.o: M_TMR.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/M_TMR.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  M_TMR.c  -o ${OBJECTDIR}/M_TMR.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/M_TMR.o.d"        -g -omf=elf -O0 -I"/Users/pastjean/Documents/projets/fujin/firmware/dspic" -msmart-io=1 -Wall -msfr-warn=off --std=c99
	@${FIXDEPS} "${OBJECTDIR}/M_TMR.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/chinookpack_unpack.o: chinookpack_unpack.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/chinookpack_unpack.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  chinookpack_unpack.c  -o ${OBJECTDIR}/chinookpack_unpack.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/chinookpack_unpack.o.d"        -g -omf=elf -O0 -I"/Users/pastjean/Documents/projets/fujin/firmware/dspic" -msmart-io=1 -Wall -msfr-warn=off --std=c99
	@${FIXDEPS} "${OBJECTDIR}/chinookpack_unpack.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/dspic.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/dspic.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -omf=elf -Wl,--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_ICD3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,--report-mem$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/dspic.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/dspic.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -Wl,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,--report-mem$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}/xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/dspic.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
