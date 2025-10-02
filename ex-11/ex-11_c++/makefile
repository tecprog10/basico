CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = relogio

all: $(TARGET)

$(TARGET): main.o Relogio.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.o Relogio.o

main.o: main.cpp Relogio.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Relogio.o: Relogio.cpp Relogio.h
	$(CXX) $(CXXFLAGS) -c Relogio.cpp

clean:
	del *.o $(TARGET).exe

.PHONY: all clean