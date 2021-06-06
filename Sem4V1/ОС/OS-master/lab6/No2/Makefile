CPP=g++
CPPFLAGS=-Wall
LIBS=-lpthread -lrt
PROGRAM_NAME=No2
SOURCE_FILES=No2.cpp

$(PROGRAM_NAME): $(SOURCE_FILES) 
	$(CPP) $^ -o $@ 
	./$(PROGRAM_NAME)
	
start:
	./$(PROGRAM_NAME) 
