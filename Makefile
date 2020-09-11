CC = gcc
CFLAGS = -std=c11 -Wall 
DEST_DIR = /usr/bin
LIBS = -l m
all = reader
reader: reader.o
	$(CC) $(CFLAGS)   reader.o -o reader $(LIBS)
reader.o: reader.c
	$(CC) $(CFLAGS)  -c reader.c 


.PHONY: clean
clean:
	rm -f reader reader.o

.PHONY: install
install: reader
	cp -p reader $(DEST_DIR)/

.PHONY: uninstall
uninstall:
	rm -rf $(DEST_DIR)/reader
