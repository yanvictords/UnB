# This makefile runs all necessary files to filter a package traffic in the local area
# To run, enter in a shell the follow commands::
# make
# ./OUTFILE_NAME_HERE

CC=gcc
CFLAGS=-pthread
OUTPUTFLAG=-o
OUTFILE=RDetector
EXE=${OUTPUTFLAG} ${OUTFILE}
MAIN_SERVER=src/main_server.o
DETECTOR_TOOL=src/analyzer.o src/identifier.o src/decoder.o src/record.o src/feedback.o

detector: ${MAIN_SERVER} ${DETECTOR_TOOL} 
	${CC} ${MAIN_SERVER} ${DETECTOR_TOOL} ${CFLAGS} ${EXE}

