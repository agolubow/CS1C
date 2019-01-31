# Compiler Specific:
COMP=g++
CFLAG=-c
WFLAG=-Wall
OFLAG=-o

# Program Specific:
SOURCES=hw01.cpp

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=hw01


# Start of Make:
hw01: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(COMP) $(OBJECTS) $(OFLAG) $@ $(WFLAG)

.cpp.o:
	$(COMP) $(CFLAG) $< $(OFLAG) $@ $(WFLAG)

# Cleanup Routines:
clean:
	rm $(OBJECTS) $(EXECUTABLE)

clean-o:
	rm $(OBJECTS)

clean-b:
	rm $(EXECUTABLE)