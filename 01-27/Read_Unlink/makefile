SrcFiles = $(wildcard *.c)
ObjFiles = $(patsubst %.c, %.o, $(SrcFiles))
Target = $(patsubst %.c, %, $(SrcFiles))

$(Target):$(ObjFiles)
	gcc $< -o $@  

%.o:%.c
	gcc -c $< -o $@

clean:
	rm -rf *.o

