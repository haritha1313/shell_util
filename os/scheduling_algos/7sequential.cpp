/* 
Sequential file allocation 
In this type of strategy, the files are allocated in a sequential manner such that there 
is a continuity among the various parts or fragments of the file.

Sample input:
4 10
0

*/

#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int f[50],i,st,j,len,c,k;
	for(i=0;i<50;i++)
		f[i]=0;
	X:
	cout<<"\n Enter the starting block & length of file";
	cin>>st>>len;
	for(j=st;j<(st+len);j++)
		if(f[j]==0)
		{
			f[j]=1;
			cout<<"\n"<<j<<"->"<<f[j]; 
		}
		else
		{
			cout<<"\nBlock already allocated";
			break;
		}
	if(j==(st+len))
	cout<<"\n the file is allocated to disk";
	cout<<"\n if u want to enter more files?(y-1/n-0)";
	cin>>c;
	if(c==1)
		goto X;
	else
		exit(0);
}
