#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>

int count = 0;

int DirCount(char* dirname)
{
	printf("%s\n", dirname);
	//打开目录
	DIR* dirp = opendir(dirname);
	if(dirp==NULL)
	{
		perror("opendir err");
		return -1;
	}

	struct dirent* dentp = NULL;
	while((dentp=readdir(dirp))!=NULL)
	{
		if(dentp->d_type==DT_DIR)
		{
			if(strcmp(".", dentp->d_name)==0 || strcmp("..", dentp->d_name)==0)
			{
				continue;
			}
			char newdirname[256]={0};
			sprintf(newdirname, "%s/%s", dirname, dentp->d_name);
			DirCount(newdirname);
		}
		if(dentp->d_type==DT_REG)
		{
			count++;
			printf("dname:%s\n", dentp->d_name);
		}
	}
	closedir(dirp);
	return 0;
}

int main(int argc, char* argv[])
{
	if(argc!=2)
	{
		printf("./filesCount dirname\n");
		return -1;
	}
	DirCount(argv[1]);
	printf("Total %d", count);
	return 0;
}
