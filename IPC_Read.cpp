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
	
	cout<<"Process "<<getpid()<<" Opening file in read mode\n";
	fd=open(argv[1],O_RDONLY);
	if(fd!=-1)
	{	
		read(fd,Buffer,sizeof(Buffer));
		cout<<"Data Read:\n";
		puts(Buffer);cout<<endl;
		close(fd);
	}
	else
		cout<<"Opening file error\n";
	cout<<"Process "<<getpid()<<"Finished reading "<<endl;
	return 0;
}
