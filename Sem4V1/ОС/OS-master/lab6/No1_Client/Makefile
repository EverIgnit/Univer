CPP=g++
CPPFLAGS=-Wall
LIBS=-lpthread -lrt
PROGRAM_NAME=No1_Client
SOURCE_FILES=No1_Client.cpp

$(PROGRAM_NAME): $(SOURCE_FILES) 
	$(CPP) $^ -o $@ $(LIBS)
	./$(PROGRAM_NAME)
	
start:
	./$(PROGRAM_NAME) 
