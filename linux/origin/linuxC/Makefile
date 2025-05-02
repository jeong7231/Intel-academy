CC:=gcc
OBJECT=input.o output.o hi.o
TARGET=hi

$(TARGET): $(OBJECT)
#hi:input.o output.o hi.o
	$(CC) -o $@ $(OBJECT)
#       gcc -o hi input.o output.o hi.o

%.o: %.c
#input.o:input.c
	$(CC) -c -o $@ $<

#       gcc -c -o input.o input.c
clean:
	rm -f *.o $(TARGET)



