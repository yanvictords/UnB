# This makefile runs all necessary files to filter a package traffic in the local area
# To run, enter in a shell the follow commands::
# make
# ./OUTFILE_NAME_HERE

CC=gcc
CFLAGS=-pthread
OUTPUTFLAG=-o
OUTFILE=api
EXE=${OUTPUTFLAG} ${OUTFILE}
API=src/Api/api_server.o src/Api/socket.o src/Api/utils.o
DETECTOR_TOOL=src/DetectorTool/detector.o src/DetectorTool/identifier.o src/DetectorTool/decoder.o src/DetectorTool/record.o src/DetectorTool/ui.o

detector: ${API} ${DETECTOR_TOOL} 
	${CC} ${API} ${DETECTOR_TOOL} ${CFLAGS} ${EXE}

