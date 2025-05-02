CC=gcc

OBJECT = input.o output.o hi.o
TARGET = hi
#hi:input.o output.o hi.o
$(TARGET): $(OBJECT)
	$(CC) -o $@ $(OBJECT)
#	gcc =-o hi input.o output.o hi.o
%.o: %.c
#input.o:input.c
	$(CC) -c -o $@ $<
#	gcc -c -o input.o input.c
clean:
	rm -f *.o $(TARGET)
