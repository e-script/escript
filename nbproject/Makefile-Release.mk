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
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/escript/array.o \
	${OBJECTDIR}/src/escript/body.o \
	${OBJECTDIR}/src/escript/builder.o \
	${OBJECTDIR}/src/escript/character.o \
	${OBJECTDIR}/src/escript/expression.o \
	${OBJECTDIR}/src/escript/hash.o \
	${OBJECTDIR}/src/escript/invoke.o \
	${OBJECTDIR}/src/escript/number.o \
	${OBJECTDIR}/src/escript/number_value.o \
	${OBJECTDIR}/src/escript/oop.o \
	${OBJECTDIR}/src/escript/reference.o \
	${OBJECTDIR}/src/escript/set.o \
	${OBJECTDIR}/src/escript/set_value.o \
	${OBJECTDIR}/src/escript/source.o \
	${OBJECTDIR}/src/function.o \
	${OBJECTDIR}/src/main.o

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

${OBJECTDIR}/src/escript/array.o: src/escript/array.c 
	${MKDIR} -p ${OBJECTDIR}/src/escript
	${RM} "$@.d"
	$(COMPILE.c) -O2 -Iinclude -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/escript/array.o src/escript/array.c

${OBJECTDIR}/src/escript/body.o: src/escript/body.c 
	${MKDIR} -p ${OBJECTDIR}/src/escript
	${RM} "$@.d"
	$(COMPILE.c) -O2 -Iinclude -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/escript/body.o src/escript/body.c

${OBJECTDIR}/src/escript/builder.o: src/escript/builder.c 
	${MKDIR} -p ${OBJECTDIR}/src/escript
	${RM} "$@.d"
	$(COMPILE.c) -O2 -Iinclude -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/escript/builder.o src/escript/builder.c

${OBJECTDIR}/src/escript/character.o: src/escript/character.c 
	${MKDIR} -p ${OBJECTDIR}/src/escript
	${RM} "$@.d"
	$(COMPILE.c) -O2 -Iinclude -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/escript/character.o src/escript/character.c

${OBJECTDIR}/src/escript/expression.o: src/escript/expression.c 
	${MKDIR} -p ${OBJECTDIR}/src/escript
	${RM} "$@.d"
	$(COMPILE.c) -O2 -Iinclude -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/escript/expression.o src/escript/expression.c

${OBJECTDIR}/src/escript/hash.o: src/escript/hash.c 
	${MKDIR} -p ${OBJECTDIR}/src/escript
	${RM} "$@.d"
	$(COMPILE.c) -O2 -Iinclude -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/escript/hash.o src/escript/hash.c

${OBJECTDIR}/src/escript/invoke.o: src/escript/invoke.c 
	${MKDIR} -p ${OBJECTDIR}/src/escript
	${RM} "$@.d"
	$(COMPILE.c) -O2 -Iinclude -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/escript/invoke.o src/escript/invoke.c

${OBJECTDIR}/src/escript/number.o: src/escript/number.c 
	${MKDIR} -p ${OBJECTDIR}/src/escript
	${RM} "$@.d"
	$(COMPILE.c) -O2 -Iinclude -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/escript/number.o src/escript/number.c

${OBJECTDIR}/src/escript/number_value.o: src/escript/number_value.c 
	${MKDIR} -p ${OBJECTDIR}/src/escript
	${RM} "$@.d"
	$(COMPILE.c) -O2 -Iinclude -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/escript/number_value.o src/escript/number_value.c

${OBJECTDIR}/src/escript/oop.o: src/escript/oop.c 
	${MKDIR} -p ${OBJECTDIR}/src/escript
	${RM} "$@.d"
	$(COMPILE.c) -O2 -Iinclude -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/escript/oop.o src/escript/oop.c

${OBJECTDIR}/src/escript/reference.o: src/escript/reference.c 
	${MKDIR} -p ${OBJECTDIR}/src/escript
	${RM} "$@.d"
	$(COMPILE.c) -O2 -Iinclude -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/escript/reference.o src/escript/reference.c

${OBJECTDIR}/src/escript/set.o: src/escript/set.c 
	${MKDIR} -p ${OBJECTDIR}/src/escript
	${RM} "$@.d"
	$(COMPILE.c) -O2 -Iinclude -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/escript/set.o src/escript/set.c

${OBJECTDIR}/src/escript/set_value.o: src/escript/set_value.c 
	${MKDIR} -p ${OBJECTDIR}/src/escript
	${RM} "$@.d"
	$(COMPILE.c) -O2 -Iinclude -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/escript/set_value.o src/escript/set_value.c

${OBJECTDIR}/src/escript/source.o: src/escript/source.c 
	${MKDIR} -p ${OBJECTDIR}/src/escript
	${RM} "$@.d"
	$(COMPILE.c) -O2 -Iinclude -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/escript/source.o src/escript/source.c

${OBJECTDIR}/src/function.o: src/function.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -Iinclude -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/function.o src/function.c

${OBJECTDIR}/src/main.o: src/main.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -Iinclude -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main.o src/main.c

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
	$(COMPILE.c) -O2 -Iinclude -I. -std=c89 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/test_array.o tests/test_array.c


${OBJECTDIR}/src/escript/array_nomain.o: ${OBJECTDIR}/src/escript/array.o src/escript/array.c 
	${MKDIR} -p ${OBJECTDIR}/src/escript
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/escript/array.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Iinclude -std=c89 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/escript/array_nomain.o src/escript/array.c;\
	else  \
	    ${CP} ${OBJECTDIR}/src/escript/array.o ${OBJECTDIR}/src/escript/array_nomain.o;\
	fi

${OBJECTDIR}/src/escript/body_nomain.o: ${OBJECTDIR}/src/escript/body.o src/escript/body.c 
	${MKDIR} -p ${OBJECTDIR}/src/escript
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/escript/body.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Iinclude -std=c89 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/escript/body_nomain.o src/escript/body.c;\
	else  \
	    ${CP} ${OBJECTDIR}/src/escript/body.o ${OBJECTDIR}/src/escript/body_nomain.o;\
	fi

${OBJECTDIR}/src/escript/builder_nomain.o: ${OBJECTDIR}/src/escript/builder.o src/escript/builder.c 
	${MKDIR} -p ${OBJECTDIR}/src/escript
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/escript/builder.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Iinclude -std=c89 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/escript/builder_nomain.o src/escript/builder.c;\
	else  \
	    ${CP} ${OBJECTDIR}/src/escript/builder.o ${OBJECTDIR}/src/escript/builder_nomain.o;\
	fi

${OBJECTDIR}/src/escript/character_nomain.o: ${OBJECTDIR}/src/escript/character.o src/escript/character.c 
	${MKDIR} -p ${OBJECTDIR}/src/escript
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/escript/character.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Iinclude -std=c89 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/escript/character_nomain.o src/escript/character.c;\
	else  \
	    ${CP} ${OBJECTDIR}/src/escript/character.o ${OBJECTDIR}/src/escript/character_nomain.o;\
	fi

${OBJECTDIR}/src/escript/expression_nomain.o: ${OBJECTDIR}/src/escript/expression.o src/escript/expression.c 
	${MKDIR} -p ${OBJECTDIR}/src/escript
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/escript/expression.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Iinclude -std=c89 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/escript/expression_nomain.o src/escript/expression.c;\
	else  \
	    ${CP} ${OBJECTDIR}/src/escript/expression.o ${OBJECTDIR}/src/escript/expression_nomain.o;\
	fi

${OBJECTDIR}/src/escript/hash_nomain.o: ${OBJECTDIR}/src/escript/hash.o src/escript/hash.c 
	${MKDIR} -p ${OBJECTDIR}/src/escript
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/escript/hash.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Iinclude -std=c89 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/escript/hash_nomain.o src/escript/hash.c;\
	else  \
	    ${CP} ${OBJECTDIR}/src/escript/hash.o ${OBJECTDIR}/src/escript/hash_nomain.o;\
	fi

${OBJECTDIR}/src/escript/invoke_nomain.o: ${OBJECTDIR}/src/escript/invoke.o src/escript/invoke.c 
	${MKDIR} -p ${OBJECTDIR}/src/escript
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/escript/invoke.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Iinclude -std=c89 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/escript/invoke_nomain.o src/escript/invoke.c;\
	else  \
	    ${CP} ${OBJECTDIR}/src/escript/invoke.o ${OBJECTDIR}/src/escript/invoke_nomain.o;\
	fi

${OBJECTDIR}/src/escript/number_nomain.o: ${OBJECTDIR}/src/escript/number.o src/escript/number.c 
	${MKDIR} -p ${OBJECTDIR}/src/escript
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/escript/number.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Iinclude -std=c89 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/escript/number_nomain.o src/escript/number.c;\
	else  \
	    ${CP} ${OBJECTDIR}/src/escript/number.o ${OBJECTDIR}/src/escript/number_nomain.o;\
	fi

${OBJECTDIR}/src/escript/number_value_nomain.o: ${OBJECTDIR}/src/escript/number_value.o src/escript/number_value.c 
	${MKDIR} -p ${OBJECTDIR}/src/escript
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/escript/number_value.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Iinclude -std=c89 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/escript/number_value_nomain.o src/escript/number_value.c;\
	else  \
	    ${CP} ${OBJECTDIR}/src/escript/number_value.o ${OBJECTDIR}/src/escript/number_value_nomain.o;\
	fi

${OBJECTDIR}/src/escript/oop_nomain.o: ${OBJECTDIR}/src/escript/oop.o src/escript/oop.c 
	${MKDIR} -p ${OBJECTDIR}/src/escript
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/escript/oop.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Iinclude -std=c89 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/escript/oop_nomain.o src/escript/oop.c;\
	else  \
	    ${CP} ${OBJECTDIR}/src/escript/oop.o ${OBJECTDIR}/src/escript/oop_nomain.o;\
	fi

${OBJECTDIR}/src/escript/reference_nomain.o: ${OBJECTDIR}/src/escript/reference.o src/escript/reference.c 
	${MKDIR} -p ${OBJECTDIR}/src/escript
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/escript/reference.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Iinclude -std=c89 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/escript/reference_nomain.o src/escript/reference.c;\
	else  \
	    ${CP} ${OBJECTDIR}/src/escript/reference.o ${OBJECTDIR}/src/escript/reference_nomain.o;\
	fi

${OBJECTDIR}/src/escript/set_nomain.o: ${OBJECTDIR}/src/escript/set.o src/escript/set.c 
	${MKDIR} -p ${OBJECTDIR}/src/escript
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/escript/set.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Iinclude -std=c89 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/escript/set_nomain.o src/escript/set.c;\
	else  \
	    ${CP} ${OBJECTDIR}/src/escript/set.o ${OBJECTDIR}/src/escript/set_nomain.o;\
	fi

${OBJECTDIR}/src/escript/set_value_nomain.o: ${OBJECTDIR}/src/escript/set_value.o src/escript/set_value.c 
	${MKDIR} -p ${OBJECTDIR}/src/escript
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/escript/set_value.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Iinclude -std=c89 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/escript/set_value_nomain.o src/escript/set_value.c;\
	else  \
	    ${CP} ${OBJECTDIR}/src/escript/set_value.o ${OBJECTDIR}/src/escript/set_value_nomain.o;\
	fi

${OBJECTDIR}/src/escript/source_nomain.o: ${OBJECTDIR}/src/escript/source.o src/escript/source.c 
	${MKDIR} -p ${OBJECTDIR}/src/escript
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/escript/source.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Iinclude -std=c89 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/escript/source_nomain.o src/escript/source.c;\
	else  \
	    ${CP} ${OBJECTDIR}/src/escript/source.o ${OBJECTDIR}/src/escript/source_nomain.o;\
	fi

${OBJECTDIR}/src/function_nomain.o: ${OBJECTDIR}/src/function.o src/function.c 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/function.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Iinclude -std=c89 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/function_nomain.o src/function.c;\
	else  \
	    ${CP} ${OBJECTDIR}/src/function.o ${OBJECTDIR}/src/function_nomain.o;\
	fi

${OBJECTDIR}/src/main_nomain.o: ${OBJECTDIR}/src/main.o src/main.c 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Iinclude -std=c89 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main_nomain.o src/main.c;\
	else  \
	    ${CP} ${OBJECTDIR}/src/main.o ${OBJECTDIR}/src/main_nomain.o;\
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
