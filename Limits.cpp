#define _POSIX_C_SOURCE 199309L
#include<iostream>
#include<unistd.h>
using namespace std;
int main()
{
	int res;
	
	//No. of Clk tics
	if((res=sysconf(_SC_CLK_TCK))==-1)
		cout<<"System does not support Clock tics\n";
	else
		cout<<"No. of Clock ticks:\t"<<res<<endl;

	//Max. no of child process
	if((res=sysconf(_SC_CHILD_MAX))==-1)
		cout<<"System does not support child max option\n";
	else
		cout<<"Max. no of child process:\t"<<res<<endl;
	
	//Max. path length
	if((res=pathconf("/",_PC_PATH_MAX))==-1)
		cout<<"System does not support Path max option\n";
	else
		cout<<"Max. path length:\t"<<res<<endl;

	//Max. no. of characters in a file name
	if((res=pathconf("/",_PC_NAME_MAX))==-1)
		cout<<"System does not support name max option\n";
	else
		cout<<"Max. no. of characters in a file name:\t"<<res<<endl;

	//Max. no. of open files/ process
	if((res=sysconf(_SC_OPEN_MAX))==-1)
		cout<<"System does not support open max option\n";
	else
		cout<<"Max no. of open files/ process:\t"<<res<<endl;
	return 0;
}

