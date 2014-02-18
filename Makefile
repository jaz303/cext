NAME = cext
BIN = build/$(NAME)
PREFIX = /usr/local

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

uninstall:
	rm $(PREFIX)/bin/$(NAME)