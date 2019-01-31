Srcfiles = $(wildcard *.c)
Target = $(patsubst %.c, %, $(Srcfiles))

$(Target):$(Srcfiles)
	gcc $< -o $@


