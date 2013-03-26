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
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/peripherals/i2c.o ${OBJECTDIR}/main.o ${OBJECTDIR}/fujin.o ${OBJECTDIR}/devices/cat24c256w.o ${OBJECTDIR}/devices/ds1338.o ${OBJECTDIR}/devices/ltc4151.o
POSSIBLE_DEPFILES=${OBJECTDIR}/peripherals/i2c.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/fujin.o.d ${OBJECTDIR}/devices/cat24c256w.o.d ${OBJECTDIR}/devices/ds1338.o.d ${OBJECTDIR}/devices/ltc4151.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/peripherals/i2c.o ${OBJECTDIR}/main.o ${OBJECTDIR}/fujin.o ${OBJECTDIR}/devices/cat24c256w.o ${OBJECTDIR}/devices/ds1338.o ${OBJECTDIR}/devices/ltc4151.o


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
${OBJECTDIR}/peripherals/i2c.o: peripherals/i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/peripherals 
	@${RM} ${OBJECTDIR}/peripherals/i2c.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  peripherals/i2c.c  -o ${OBJECTDIR}/peripherals/i2c.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/peripherals/i2c.o.d"        -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off --std=c99
	@${FIXDEPS} "${OBJECTDIR}/peripherals/i2c.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/main.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d"        -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off --std=c99
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/fujin.o: fujin.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/fujin.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  fujin.c  -o ${OBJECTDIR}/fujin.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/fujin.o.d"        -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off --std=c99
	@${FIXDEPS} "${OBJECTDIR}/fujin.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/devices/cat24c256w.o: devices/cat24c256w.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/devices 
	@${RM} ${OBJECTDIR}/devices/cat24c256w.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  devices/cat24c256w.c  -o ${OBJECTDIR}/devices/cat24c256w.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/devices/cat24c256w.o.d"        -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off --std=c99
	@${FIXDEPS} "${OBJECTDIR}/devices/cat24c256w.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/devices/ds1338.o: devices/ds1338.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/devices 
	@${RM} ${OBJECTDIR}/devices/ds1338.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  devices/ds1338.c  -o ${OBJECTDIR}/devices/ds1338.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/devices/ds1338.o.d"        -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off --std=c99
	@${FIXDEPS} "${OBJECTDIR}/devices/ds1338.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/devices/ltc4151.o: devices/ltc4151.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/devices 
	@${RM} ${OBJECTDIR}/devices/ltc4151.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  devices/ltc4151.c  -o ${OBJECTDIR}/devices/ltc4151.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/devices/ltc4151.o.d"        -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off --std=c99
	@${FIXDEPS} "${OBJECTDIR}/devices/ltc4151.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/peripherals/i2c.o: peripherals/i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/peripherals 
	@${RM} ${OBJECTDIR}/peripherals/i2c.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  peripherals/i2c.c  -o ${OBJECTDIR}/peripherals/i2c.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/peripherals/i2c.o.d"        -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off --std=c99
	@${FIXDEPS} "${OBJECTDIR}/peripherals/i2c.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/main.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d"        -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off --std=c99
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/fujin.o: fujin.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/fujin.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  fujin.c  -o ${OBJECTDIR}/fujin.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/fujin.o.d"        -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off --std=c99
	@${FIXDEPS} "${OBJECTDIR}/fujin.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/devices/cat24c256w.o: devices/cat24c256w.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/devices 
	@${RM} ${OBJECTDIR}/devices/cat24c256w.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  devices/cat24c256w.c  -o ${OBJECTDIR}/devices/cat24c256w.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/devices/cat24c256w.o.d"        -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off --std=c99
	@${FIXDEPS} "${OBJECTDIR}/devices/cat24c256w.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/devices/ds1338.o: devices/ds1338.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/devices 
	@${RM} ${OBJECTDIR}/devices/ds1338.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  devices/ds1338.c  -o ${OBJECTDIR}/devices/ds1338.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/devices/ds1338.o.d"        -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off --std=c99
	@${FIXDEPS} "${OBJECTDIR}/devices/ds1338.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/devices/ltc4151.o: devices/ltc4151.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/devices 
	@${RM} ${OBJECTDIR}/devices/ltc4151.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  devices/ltc4151.c  -o ${OBJECTDIR}/devices/ltc4151.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/devices/ltc4151.o.d"        -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off --std=c99
	@${FIXDEPS} "${OBJECTDIR}/devices/ltc4151.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
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
