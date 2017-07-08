#
# Makefile for CSE 30 -- PA1
# You should not need to change anything in this file.
#

HEADERS		= pa1.h
C_SRCS		= main.c
ASM_SRCS	= isOdd.s printChar.s isInBounds.s numOfDigits.s drawZ.s
C_OBJS		= main.o
ASM_OBJS	= isOdd.o printChar.o isInBounds.o numOfDigits.o drawZ.o
OBJS		= ${C_OBJS} ${ASM_OBJS}
EXE	    	= pa1


#
# Relevant man pages:
#
# man gcc
# man as
# man lint
#

GCC		= gcc
ASM		= $(GCC)
LINT	= lint

GCC_FLAGS	= -c -g -Wall -D__EXTENSIONS__ -std=c99
LINT_FLAGS1	= -c -err=warn
LINT_FLAGS2	= -u -err=warn
ASM_FLAGS	= -c -g
LD_FLAGS	= -g -Wall

#
# Standard rules
#

.s.o:
	@echo "Assembling each assembly source file separately ..."
	$(ASM) $(ASM_FLAGS) $<
	@echo ""

.c.o:
	@echo "Linting each C source file separately ..."
	$(LINT) $(LINT_FLAGS1) $<
	@echo ""
	@echo "Compiling each C source file separately ..."
	$(GCC) $(GCC_FLAGS) $<
	@echo ""

#
# Simply have our project target be a single default $(EXE) executable.
#

$(EXE):	$(OBJS)
	@echo "2nd phase lint on all C source files ..."
	$(LINT) $(LINT_FLAGS2) *.ln
	@echo ""
	@echo "Linking all object modules ..."
	$(GCC) -o $(EXE) $(LD_FLAGS) $(OBJS)
	@echo ""
	@echo "Done."

${C_OBJS}:      ${HEADERS}


clean:
	@echo "Cleaning up project directory ..."
	/usr/bin/rm -f *.o $(EXE) *.ln core a.out \
    testisInBounds testisOdd testnumOfDigits testprintChar
	@echo ""
	@echo "Clean."

testisInBounds:	test.h pa1.h isInBounds.o testisInBounds.o
	@echo "Compiling testisInBounds.c"
	gcc -g -o testisInBounds testisInBounds.c isInBounds.s
	@echo "Done."

testisOdd: test.h pa1.h isOdd.o testisOdd.o
	@echo "Compiling testisOdd.c"
	gcc -g -o testisOdd testisOdd.c isOdd.s
	@echo "Done."

testnumOfDigits: test.h pa1.h numOfDigits.o testnumOfDigits.o isInBounds.o
	@echo "Compiling testnumOfDigits.c"
	gcc -g -o testnumOfDigits testnumOfDigits.c numOfDigits.s isInBounds.s
	@echo "Done."

testprintChar: test.h pa1.h printChar.o testprintChar.o
	@echo "Compiling testprintChar.c"
	gcc -g -o testprintChar testprintChar.c printChar.s
	@echo "Done."


new:
	make clean
	make

