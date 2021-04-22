CC = g++
CFLAGS = -c -Wall

all:main

main:main.o
	$(CC) main.o -o main

complex.o:src/complex.cpp
	$(CC) src/complex.cpp

main.o:include/hash.h src/main.cpp
	$(CC) $(CFLAGS) src/main.cpp

cleanl:
	rm *.o main

cleanw:
	del *.o main.exe
