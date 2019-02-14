#General Generate Binary Makefile(aka'GGBM')

SRCFILES = $(wildcard *.c)
TAGFILES = $(patsubst %.c, %, $(SRCFILES))

all:$(TAGFILES)

%:%.c
	gcc -o $@ $< -lpthread

clean:
	-rm -f $(TAGFILES)
