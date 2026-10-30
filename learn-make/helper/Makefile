CXX = g++
TARGET = hello
SRC_DIR = src
INC_DIR = include
OBJ = main.o factorial.o printhello.o

CXXFLAGS = -Wall -I$(INC_DIR)

VPATH = $(SRC_DIR)

$(TARGET):$(OBJ)
	$(CXX) -o $@ $^
%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY:clean
clean:
	rm -f *.o $(TARGET)