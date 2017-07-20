#	Standard Makefile Template
#	mpsk
#	2017/07/04

ifeq ($(OS),Windows_NT)
LDFLAGS=-lfreeglut -lopengl32 -lGLEW -Wl,--subsystem,windows
EXECUTABLE=GRiNa.exe
else
LDFLAGS=-lGL -lglut -lGLEW
EXECUTABLE=GRiNA
endif

LDFLAGS_EXSDL=-lSDL2 -lSDL2_image

SRC_PATH = src/
BIN_PATH = bin/

CC = gcc
CXX = g++ -Wall
CXXFLAGS = -std=c++11

SRC = ${wildcard $(SRC_PATH)*.cpp}
OBJ = ${patsubst %.cpp, %.o, $(SRC)}

all:$(OBJ)
	$(CXX) $(CXXFLAGS) -o $(BIN_PATH)$(EXECUTABLE) $(OBJ) $(LDFLAGS) $(LDFLAGS_EXSDL)

$(OBJ):%.o:%.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS_CV2) -o $@ -c $<

.PHONY : clean
clean:
	rm -rf $(SRC_PATH)*.o