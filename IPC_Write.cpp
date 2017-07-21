#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<iostream>
#include<stdio.h>
using namespace std;
int main(int argc,char *argv[])
{
	int fd,res;
	char Buffer[1024];
	if(argc!=2)
	{	
		cout<<"Usage "<<argv[0]<<"pipename\n";
		return -1;
	}
	
	mkfifo(argv[1],0777);
	
	cout<<"Process "<<getpid()<<" Opening file in write mode\n";
	fd=open(argv[1],O_WRONLY);
	if(fd!=-1)
	{	
		cout<<"Enter Data:\n";
		gets(Buffer);
		write(fd,Buffer,sizeof(Buffer));
		close(fd);
	}
	else
		cout<<"Opening file error\n";
	cout<<"Process "<<getpid()<<"Finished writing "<<endl;
	unlink(argv[1]);
	return 0;
}
