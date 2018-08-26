# This makefile runs all necessary files to filter a package traffic in the local area
# To run, just shell the follow commands:
# make
# ./OUTFILE_NAME_HERE

CC=gcc
CFLAGS=-pthread
OUTPUTFLAG=-o
OUTFILE=RDetector
EXE=${OUTPUTFLAG} ${OUTFILE}
FILTER_SERVER=filter_server.o
DETECTOR_TOOL=DetectorTool/analyzer.o DetectorTool/identifier.o DetectorTool/decoder.o DetectorTool/record.o DetectorTool/feedback.o

detector: ${FILTER_SERVER} ${DETECTOR_TOOL} 
	${CC} ${FILTER_SERVER} ${DETECTOR_TOOL} ${EXE} ${CFLAGS}

