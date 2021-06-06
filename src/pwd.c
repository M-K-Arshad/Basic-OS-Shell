#include<dirent.h>
#include<sys/types.h>
#include<stdio.h>


int pwd()
{


char path[PATH_MAX];
getcwd(path,sizeof(path));
reset();
printf("%s\n",path);
return 0;
}
