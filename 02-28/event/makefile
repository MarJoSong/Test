#General Generate Binary Makefile(aka'GGBM')

SRCFILES = $(wildcard *.c)
TAGFILES = $(patsubst %.c, %, $(SRCFILES))

all:$(TAGFILES)

%:%.c
	gcc -o $@ $< -levent

clean:
	-rm -f $(TAGFILES)

cc:
	-rm -f $(TAGFILES)
	-rm -f makefile
