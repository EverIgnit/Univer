CPP=g++
CPPFLAGS=-Wall
PROGRAM_NAME=No1
OBJECT_FILES=*.o
SOURCE_FILES=No1.cpp
CLEAN=rm -f

$(PROGRAM_NAME): $(OBJECT_FILES)
	$(CPP) $(CPPFLAGS) -o $@ $^
	./$(PROGRAM_NAME)

$(OBJECT_FILES): $(SOURCE_FILES)
	$(CPP) $(CPPFLAGS) -c $^

clean:
	$(CLEAN) $(OBJECT_FILES)
 
