CC = gcc
CFLAGS = -std=c11
DEST_DIR = /usr/bin

reader: reader.o
	$(CC) $(CFLAGS) reader.o -o reader

reader.o: reader.c
	$(CC) $(CFLAGS) -c reader.c

.PHONY: clean
clean:
	rm -f reader reader.o

.PHONY: install
install: reader
	cp -p reader $(DEST_DIR)/

.PHONY: uninstall
uninstall:
	rm -rf $(DEST_DIR)/reader
