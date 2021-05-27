INCLUDE_DIRS := Includes
CC 			 := g++
CFLAGS 		 := -I$(INCLUDE_DIRS)

OBJS 		 := customErrorClass.o class_template.o
DEPS 		 := ${INCLUDE_DIRS}/customErrorClass.h

.PHONY: clean all

all: sortAlgorithm customErrorClass.o class_template.o

clean:
	rm $(OBJS) sortAlgorithm

customErrorClass.o: customErrorClass.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

class_template.o: class_template.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

sortAlgorithm: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)