int popd(int argc,char* argv[],struct dirStack* mySt)
{


if(argc==3)
{

if(argv[2][0]=='-'&&argv[2][1]=='s'&&argv[2][2]=='h'&&argv[2][3]=='o'&&argv[2][4]=='w'&&argv[2][5]=='t'&&argv[2][6]=='o'&&argv[2][7]=='p'&&argv[2][8]=='\0')
{

if(mySt->curr>=0)
printf("%s\n",mySt->dirs[mySt->curr]);
else
	printf("pop: stack is empty\n");

}
else
	printf("pop: wrong flag\n");


}
else if(argc==2)
{

if(mySt->curr>=0)
{
if(chdir(mySt->dirs[mySt->curr])<0)
{

perror("chdir");

}
else
{

pop(0,mySt);

}
}
else
	printf("pop: stack is empty\n");
}
else
printf("pop: invalid arguments\n");
return 0;
}
