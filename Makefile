SOURCES=main.c eulers.c
OBJECTS=main.o eulers.o
TARGET=eulers-method
TARGET_EXT=out
COMPILER=clang

${TARGET}.${TARGET_EXT}: ${OBJECTS}
	${COMPILER} -lm -Wall -O2 -o $@ $^

${OBJECTS}: ${SOURCES}
	${COMPILER} -c $^

clean:
	rm -f ${OBJECTS} ${TARGET}*