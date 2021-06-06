CPP=g++
CPPFLAGS=-lpthread
CLEAN=-f
PROGRAM_NAME=No3
SOURCE_FILES=No3_Semaphore.cpp

$(PROGRAM_NAME): $(SOURCE_FILES) 
	$(CPP) $^ $(CPPFLAGS) -o $@ 
	./$(PROGRAM_NAME)

start:
	./$(PROGRAM_NAME) 
