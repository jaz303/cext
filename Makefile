NAME = cext
BIN = build/$(NAME)
PREFIX = /usr/local

MAN_FILE = cext.1
MAN_DIR  = $(PREFIX)/share/man/man1
MAN_PATH = $(MAN_DIR)/$(MAN_FILE)

.PHONY: clean install

$(BIN): build main.c
	$(CC) -o $@ main.c

build:
	mkdir -p build

clean:
	rm -rf build

install: $(BIN)
	install -v -d $(PREFIX)/bin
	install -v $(BIN) $(PREFIX)/bin
	mkdir -p $(MAN_DIR)
	cp $(MAN_FILE) $(MAN_PATH)

uninstall:
	rm -f $(PREFIX)/bin/$(NAME)
	rm -f $(MAN_PATH)