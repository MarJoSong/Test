#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>

typedef struct _Student{
	int sid;
	char sname[20];
}Student;

int main(int argc, char* argv[])
{
	if(argc!=2)
	{
		printf("Usage: cmd filename\n");
		return -1;
	}
	int fd = open(argv[1], O_RDWR);
	if(fd<0)
	{
		printf("open err");
		return -1;
	}
	int length = sizeof(Student);

	ftruncate(fd, length);

	Student* stu = mmap(NULL, length, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	if(stu == MAP_FAILED)
	{
		perror("map err");
		return -1;
	}

	int num = 1;
	while(1)
	{
		printf("Stu->ID = %d, Stu->Name = %s\n", stu->sid, stu->sname);
		sleep(1);
	}
	munmap(stu, length);
	close(fd);

	return 0;
}
