CPP=g++
CPPFLAGS=-lpthread
CLEAN=-f
PROGRAM_NAME=No1
SOURCE_FILES=no1.cpp

$(PROGRAM_NAME): $(SOURCE_FILES) 
	$(CPP) $^ $(CPPFLAGS) -o $@ 
	./$(PROGRAM_NAME)

start:
	./$(PROGRAM_NAME) 
