#	Standard Makefile Template
#	mpsk
#	2017/07/20

ifeq ($(OS),Windows_NT)
LDFLAGS=-lfreeglut -lopengl32 -lGLEW -Wl,--subsystem,windows
EXECUTABLE=GRiNa.exe
else
INCFLAGS=-I/usr/local/include/SDL2 -D_REENTRANT
LDFLAGS=-L/usr/local/lib -Wl,-rpath,/usr/local/lib -Wl,--enable-new-dtags -lSDL2
EXECUTABLE=GRiNA
endif

LDFLAGS_EXSDLIMG=-lSDL2_image

SRC_PATH = src/
BIN_PATH = bin/

CC = gcc
CXX = g++ -Wall
CXXFLAGS = -std=c++11

SRC = ${wildcard $(SRC_PATH)*.cpp}
OBJ = ${patsubst %.cpp, %.o, $(SRC)}

all:$(OBJ)
	$(CXX) $(CXXFLAGS) -o $(BIN_PATH)$(EXECUTABLE) $(OBJ) $(INCFLAGS) $(LDFLAGS) $(LDFLAGS_EXSDLIMG)

$(OBJ):%.o:%.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS_CV2) -o $@ -c $<

.PHONY : clean
clean:
	rm -rf $(SRC_PATH)*.o