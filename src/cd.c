#include<unistd.h>
#include<stdio.h>

void cd(char* path)
{

if(path!=0)
{
if(chdir(path)<0)
{

perror("chdir");

}

}
else
{

red();
printf("cd:path not given\n");
reset();
}


}



