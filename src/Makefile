MOTORCAR_DIR=../../motorcar
PREFIX=/opt
CC=g++

INCLUDES= -I${MOTORCAR_DIR}/src/compositor -I${MOTORCAR_DIR}/src/protocol -I${MOTORCAR_DIR}/src/device -I${PREFIX}/include
LIBS= -L${MOTORCAR_DIR}/lib -L${PREFIX}/lib -lmotorcar-compositor 
CFLAGS=-std=c++11
objects=

provr-compositor: main.cpp
	${CC}  main.cpp  ${CFLAGS} ${INCLUDES} ${LIBS} -o provr-compositor 

install:
	install provr-compositor ${PREFIX}/bin

clean:
	rm provr-compositor
