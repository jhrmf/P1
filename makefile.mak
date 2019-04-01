CC = g++
CFLAGS = -std=c++0x
TARGET = P1
OBJS = main.o testScanner.o scanner.o
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp scanner.h
	$(CC) $(CFLAGS) -c main.cpp
testScanner.o: testScanner.cpp testScanner.h scanner.h token.h
	$(CC) $(CFLAGS) -c testScanner.cpp
scanner.o: scanner.cpp scanner.h testScanner.h token.h maps.h
	$(CC) $(CFLAGS) -c scanner.cpp

clean:
	/bin/rm -f *.o $(TARGET)
