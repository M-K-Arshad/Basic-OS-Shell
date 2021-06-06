void pop(char* path,struct dirStack* mySt)
{
if(path!=0)
strcpy(path,mySt->dirs[mySt->curr]);
mySt->no--;
mySt->curr--;

}


void push(struct dirStack * mySt,char* path)
{
mySt->curr=mySt->no;
strcpy(mySt->dirs[mySt->no++],path);

}

int pushd(int argc,char* argv[],struct dirStack * mySt)
{

if(argc==3)
{


char path[PATH_MAX];
getcwd(path,sizeof(path));

if(chdir(argv[2])<0)
{

perror("chdir");

}
else
{
push(mySt,path);

}

}
else
{

printf("pushd:command failed\n");

}



return 0;
}

