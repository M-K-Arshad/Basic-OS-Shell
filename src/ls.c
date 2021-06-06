#include<dirent.h>
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

int ls(int argc,char* argv[])
{
	struct dirent** nameOfFiles;
	int countOfFiles;
	if(argc>1)
	{
		if(argc==2 && argv[1][0]!='-')
			{countOfFiles= scandir(argv[1],&nameOfFiles,NULL,alphasort);}
		else if(argc==2)
			countOfFiles= scandir(".",&nameOfFiles,NULL,alphasort);
		else if(argc==3)
			{
countOfFiles= scandir(argv[2],&nameOfFiles,NULL,alphasort);
}
	}
	else
	{
	
	countOfFiles= scandir(".",&nameOfFiles,NULL,alphasort);
	
	}

	if(countOfFiles<0)
		perror("scandir");
	else
	{
	
		int i=0;
		while(i<countOfFiles)
		{
			boldCyan();
			if(((argc>1)&&(argv[1][0]=='-'&&argv[1][1]=='a'))||i>1)
			{
			printf("%s	",nameOfFiles[i]->d_name);
			}
	reset();
			free(nameOfFiles[i++]);
		
}
		free(nameOfFiles);
		printf("\n");

	}
	return 0;
}
