/************************************************************************
    > Author: syh
    > File type: C Source code
    > Mail: 769200142@qq.com 
    > Environment: Linux && Ubuntu 18.04
    > Tool: Vim && Gcc 
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <grp.h>
#include <pwd.h>	
#include <time.h>

int main(int argc, char* argv[])
{
	if(argc!=2)
	{
		printf("Usage: ./ls_l filename\n");
		return -1;
	}

	struct stat sb;
	stat(argv[1], &sb);
	//解析属性信息
	//解析文件类型
	char stmode[11] = {0};
	memset(stmode, '-', 10);
	if(S_ISREG(sb.st_mode));
	if(S_ISDIR(sb.st_mode)) stmode[0] = 'd';
	if(S_ISCHR(sb.st_mode)) stmode[0] = 'c';
	if(S_ISBLK(sb.st_mode)) stmode[0] = 'b';
	if(S_ISFIFO(sb.st_mode)) stmode[0] = 'p';
	if(S_ISLNK(sb.st_mode)) stmode[0] = 'l';
	if(S_ISSOCK(sb.st_mode)) stmode[0] = 's';

	//解析权限
	if(sb.st_mode & S_IRUSR) stmode[1] = 'r';
	if(sb.st_mode & S_IWUSR) stmode[2] = 'w';
	if(sb.st_mode & S_IXUSR) stmode[3] = 'x';
	if(sb.st_mode & S_IRGRP) stmode[4] = 'r';
	if(sb.st_mode & S_IWGRP) stmode[5] = 'w';
	if(sb.st_mode & S_IRGRP) stmode[6] = 'x';
	if(sb.st_mode & S_IROTH) stmode[7] = 'r';
	if(sb.st_mode & S_IWOTH) stmode[8] = 'w';
	if(sb.st_mode & S_IXOTH) stmode[9] = 'x';
	
	//struct tm* modtime = localtime(&)
	printf("%s %ld %s %s %ld %d月  %d %02d:%02d %s\n",stmode, sb.st_nlink, getpwuid(sb.st_uid)->pw_name, getgrgid(sb.st_gid)->gr_name, sb.st_size, localtime(&sb.st_mtim.tv_sec)->tm_mon+1, localtime(&sb.st_mtim.tv_sec)->tm_mday, localtime(&sb.st_mtim.tv_sec)->tm_hour, localtime(&sb.st_mtim.tv_sec)->tm_min, argv[1]);
	
	//-rwxrwxr-x 1 ms ms 8456 1月  26 16:00 ls_l*

	return 0;
}

