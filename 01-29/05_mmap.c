#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/mman.h>

int main(int argc, char* argv[])
{
	//打开文件
	int fd = open("memTestFile.txt", O_RDWR);

	//建立映射区
	char* mem = mmap(NULL, 8, PROT_READ|PROT_WRITE, MAP_PRIVATE, fd, 0);
	//char* mem = mmap(NULL, 8, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);

	//写入内存
	strcpy(mem, "helloworld");

	//关闭映射区和文件描述符
	munmap(mem, 8);
	close(fd);

	return 0;
}

