CPP=g++
CPPFLAGS=-Wall
CLEAN=-f
PROGRAM_NAME=fixerProg
OBJECT_FILES=*.o
SOURCE_FILES=Main.cpp Fixer.cpp

$(PROGRAM_NAME): $(OBJECT_FILES) 
	$(CPP) $(CPPfLAGS) -o $@ $^

$(OBJECT_FILES): $(SOURCE_FILES)
	$(CPP) $(CPPFLAGS) -c $^

clean:
	$(CLEAN) *.o $(PROGRAM_NAME) 
#-Wall-warning all

#	$@-cur target		 $^-dependencies

#target: dependencies
#	instructions to reach the goal

#clean: (no dependencies)
#	.o files @ binary file to delete

#-c compile but don't link
#-o ___ place output file in ____
