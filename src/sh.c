#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<limits.h>
#include<dirent.h>
#include<unistd.h>
#include<ctype.h>
#include"stack.h"
#include"colors.c"
#include"ls.c"
#include"cd.c"
#include"pwd.c"
#include"push.c"
#include"pop.c"

static struct dirStack St;
static struct dirStack* mySt=(struct dirStack*)(&St);

int wordCountInASentence(char *str,char c)
{
	int count = 0, i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) == c || *(str + i + 1) == '\0')
			count++;
		i++;
	}
	return count;
}
int wordSize(char *str,char c)
{
	int i = 0;
	while (*(str + i) != c&& *(str + i) != '\0')
		i++;
	return i + 1;
}
char** StringTokens(char* str,char c)
{
	int size = wordCountInASentence(str,c), i, j, k = 0;
	char **tokens = (char**) malloc(sizeof(char*)*(size + 1));   //+1 for null character
	char **tokPtr = tokens;
	*(tokPtr + size) = 0;
	//allocation
	for (i = 0; *(str + i) != '\0'; i++)
	{
		if (*(str + i) == c || i == 0)
		{
			if (*(str + i) == c)
				i++;
			*tokPtr = (char*) malloc(sizeof(char)*wordSize(str + i,c));
			tokPtr++;
		}
	}
	//making tokens
	for (i = 0, tokPtr = tokens; i < size; i++, tokPtr++)
	{

		char *toksPtr = *tokPtr;
		for (j = 0; *(str + k) != c&& *(str + k) != '\0'; j++, k++) //original string reaches space or 
		{
			*(toksPtr + j) = *(str + k);
		}
		*(toksPtr + j) = '\0';
		k++;
	}
	return tokens;
}
static int i=0;
static int m=0;

void initialize(struct dirStack* mySt)
{
mySt->curr=-1;
mySt->no=0;
}
int main(int argc,char** argv)
{
if(!m++)
{
initialize(mySt);
}
if(!i++)
printf("\e[1;1H\e[2J");
if(argc==0)
exit(1);
char path[PATH_MAX];
getcwd(path,sizeof(path));
if(strlen(path)>=2)
{
if(path[0]=='/')
path[0]='-';
char** tok=StringTokens(path,'/');
int number=wordCountInASentence(path,'/');
strcpy(path,tok[number-1]);
}
else
 strcpy(path,"root");
int exit=0;
if(argc>1)
{
if(argv[1][0]=='l'&&argv[1][1]=='s')
{
ls(argc-1,argv+1);
}
else if(argv[1][0]=='c' && argv[1][1]=='d')
{
	cd(argv[2]);
}
else if(argv[1][0]=='c'&&argv[1][1]=='l'&&argv[1][2]=='e'&&argv[1][3]=='a'&&argv[1][4]=='r'&&argv[1][5]=='\0')
{

printf("\e[1;1H\e[2J");

}
else if(argv[1][0]=='p'&&argv[1][1]=='w'&&argv[1][2]=='d'&&argv[1][3]=='\0')
{
	pwd();
}
else if(argv[1][0]=='p'&&argv[1][1]=='u'&&argv[1][2]=='s'&&argv[1][3]=='h'&&argv[1][4]=='\0')
pushd(argc,argv,mySt);

else if(argv[1][0]=='p'&&argv[1][1]=='o'&&argv[1][2]=='p'&&argv[1][3]=='\0')
popd(argc,argv,mySt);
else if(argv[1][0]=='e'&&argv[1][1]=='x'&&argv[1][2]=='i'&&argv[1][3]=='t'&&argv[1][4]=='\0')
{exit=1;

}
else if(argv[1][0]!='\0')
{
boldCyan();
printf("Shell: ");
boldRed();
printf("command not found\n");
reset();
}
}
getcwd(path,sizeof(path));
if(strlen(path)>=2)
{
if(path[0]=='/')
path[0]='-';
char** tok=StringTokens(path,'/');
int number=wordCountInASentence(path,'/');
strcpy(path,tok[number-1]);
}
else
 strcpy(path,"root");
if(!exit)
{
boldGreen();
printf("17L-4308_");
boldBlue();
printf("%s",path);
boldGreen();
printf(">");
reset();
int i=0;
char* buffer;
buffer=(char*) malloc(sizeof(char)*100);
size_t size=100;
boldMagenta();
getline(&buffer,&size,stdin);
reset();
char* absPath=(char*)malloc(sizeof(char)*(strlen("./sh.o ")+strlen(buffer)));
strcpy(absPath,"./sh.o");
strcat(absPath," ");
strcat(absPath,buffer);

i=wordCountInASentence(absPath,' ');
char** tokens=StringTokens(absPath,' ');
tokens[i-1][strlen(tokens[i-1])-1]='\0';
main(i,tokens);
}
return 0;
}
