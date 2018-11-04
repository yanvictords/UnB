# This makefile runs all necessary files to filter a package traffic in the local area
# To run, enter in a shell the follow commands::
# make
# ./OUTFILE_NAME_HERE

CC=gcc
CFLAGS=-pthread
OUTPUTFLAG=-o
OUTFILE=api
EXE=${OUTPUTFLAG} ${OUTFILE}
MAIN_SERVER=src/Api/api_server.o
DETECTOR_TOOL=src/DetectorTool/analyzer.o src/DetectorTool/identifier.o src/DetectorTool/decoder.o src/DetectorTool/record.o src/DetectorTool/ui.o

detector: ${MAIN_SERVER} ${DETECTOR_TOOL} 
	${CC} ${MAIN_SERVER} ${DETECTOR_TOOL} ${CFLAGS} ${EXE}

