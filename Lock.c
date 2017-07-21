#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
	int fd;
	char Buffer[255];
	struct flock fvar;
	if(argc!=2)
	{
		printf("Usage:%s filename\n",argv[0]);
		return -1;
	}
	fd=open(argv[1],O_RDWR);
	fvar.l_type=F_WRLCK;
	fvar.l_whence=SEEK_END;
	fvar.l_start=SEEK_END-100;
	fvar.l_len=100;
	
	printf("Press Enter to set the lock\n");
	getchar();
	printf("Trying to set the lock\n");
	if((fcntl(fd,F_SETLK,&fvar))==-1)
	{
		fcntl(fd,F_GETLK,&fvar);
		printf("The region is already LOCK\n");
		printf("Process id which locked the region is\t%d\n",fvar.l_pid);
		return -1;
	}
	printf("Region LOCKED\n");
	
	lseek(fd,SEEK_END-50,SEEK_END);
	read(fd,Buffer,sizeof(Buffer));
	printf("Data read:\t");
	puts(Buffer);
	printf("\nPress Enter to release the lock\n");
	getchar();
	fvar.l_type=F_UNLCK;
	fvar.l_whence=SEEK_SET;
	fvar.l_start=0;
	fvar.l_len=0;
	if(fcntl(fd,F_UNLCK,&fvar)==-1)
	{
		perror("fcntl");
		exit(0);
	}
	printf("UNLOCKED\n");
	close(fd);
	
	return 0;
}	
