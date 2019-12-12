#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/array.o \
	${OBJECTDIR}/body.o \
	${OBJECTDIR}/character.o \
	${OBJECTDIR}/expression.o \
	${OBJECTDIR}/invoke.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/number.o \
	${OBJECTDIR}/oop.o \
	${OBJECTDIR}/operand.o \
	${OBJECTDIR}/reference.o \
	${OBJECTDIR}/source.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/tests/test_array.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/escript

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/escript: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/escript ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/array.o: array.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/array.o array.c

${OBJECTDIR}/body.o: body.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/body.o body.c

${OBJECTDIR}/character.o: character.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/character.o character.c

${OBJECTDIR}/expression.o: expression.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/expression.o expression.c

${OBJECTDIR}/invoke.o: invoke.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/invoke.o invoke.c

${OBJECTDIR}/main.o: main.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.c

${OBJECTDIR}/number.o: number.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/number.o number.c

${OBJECTDIR}/oop.o: oop.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/oop.o oop.c

${OBJECTDIR}/operand.o: operand.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/operand.o operand.c

${OBJECTDIR}/reference.o: reference.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/reference.o reference.c

${OBJECTDIR}/source.o: source.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source.o source.c

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/test_array.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} 


${TESTDIR}/tests/test_array.o: tests/test_array.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -std=c89 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/test_array.o tests/test_array.c


${OBJECTDIR}/array_nomain.o: ${OBJECTDIR}/array.o array.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/array.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -std=c89 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/array_nomain.o array.c;\
	else  \
	    ${CP} ${OBJECTDIR}/array.o ${OBJECTDIR}/array_nomain.o;\
	fi

${OBJECTDIR}/body_nomain.o: ${OBJECTDIR}/body.o body.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/body.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -std=c89 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/body_nomain.o body.c;\
	else  \
	    ${CP} ${OBJECTDIR}/body.o ${OBJECTDIR}/body_nomain.o;\
	fi

${OBJECTDIR}/character_nomain.o: ${OBJECTDIR}/character.o character.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/character.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -std=c89 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/character_nomain.o character.c;\
	else  \
	    ${CP} ${OBJECTDIR}/character.o ${OBJECTDIR}/character_nomain.o;\
	fi

${OBJECTDIR}/expression_nomain.o: ${OBJECTDIR}/expression.o expression.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/expression.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -std=c89 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/expression_nomain.o expression.c;\
	else  \
	    ${CP} ${OBJECTDIR}/expression.o ${OBJECTDIR}/expression_nomain.o;\
	fi

${OBJECTDIR}/invoke_nomain.o: ${OBJECTDIR}/invoke.o invoke.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/invoke.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -std=c89 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/invoke_nomain.o invoke.c;\
	else  \
	    ${CP} ${OBJECTDIR}/invoke.o ${OBJECTDIR}/invoke_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -std=c89 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_nomain.o main.c;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

${OBJECTDIR}/number_nomain.o: ${OBJECTDIR}/number.o number.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/number.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -std=c89 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/number_nomain.o number.c;\
	else  \
	    ${CP} ${OBJECTDIR}/number.o ${OBJECTDIR}/number_nomain.o;\
	fi

${OBJECTDIR}/oop_nomain.o: ${OBJECTDIR}/oop.o oop.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/oop.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -std=c89 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/oop_nomain.o oop.c;\
	else  \
	    ${CP} ${OBJECTDIR}/oop.o ${OBJECTDIR}/oop_nomain.o;\
	fi

${OBJECTDIR}/operand_nomain.o: ${OBJECTDIR}/operand.o operand.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/operand.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -std=c89 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/operand_nomain.o operand.c;\
	else  \
	    ${CP} ${OBJECTDIR}/operand.o ${OBJECTDIR}/operand_nomain.o;\
	fi

${OBJECTDIR}/reference_nomain.o: ${OBJECTDIR}/reference.o reference.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/reference.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -std=c89 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/reference_nomain.o reference.c;\
	else  \
	    ${CP} ${OBJECTDIR}/reference.o ${OBJECTDIR}/reference_nomain.o;\
	fi

${OBJECTDIR}/source_nomain.o: ${OBJECTDIR}/source.o source.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -std=c89 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source_nomain.o source.c;\
	else  \
	    ${CP} ${OBJECTDIR}/source.o ${OBJECTDIR}/source_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/escript

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
