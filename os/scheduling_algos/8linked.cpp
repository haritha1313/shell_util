/* 
Linked file allocation strategy
In this type of strategy, the files are allocated in a linked list 
format where each and every fragment is linked to the other file through 
either addresses or pointers. Thus, the starting location of the file serves 
for the purpose of extraction of the entire file because every fragment is linked to each other.

Sample input:
3
4 7 9
3
7
0

*/

#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int f[50],p,i,j,k,a,st,len,n,c;
	for(i=0;i<50;i++)
	f[i]=0;
	cout<<"Enter how many blocks that are already allocated";
	cin>>p;
	cout<<"\nEnter the blocks no.s that are already allocated";
	for(int i=0; i<p; i++){
		cin>>a;
		f[a]=1;
	}
	X:
	cout<<"\nEnter the starting index block & length";
	cin>>st>>len;
	k=len;
	for(j=st;j<(k+st);j++)
	{
		if(f[j]==0)
		{
			f[j]=1;
			cout<<"\n"<<j<<"->"<<f[j];
		}
		else
		{
			cout<<"\n"<<j<<"->file is already allocated";
			k++;
		}
	}
	cout<<"\n If u want to enter one more file? (yes-1/no-0)";
	cin>>c;
	if(c==1)
		goto X;
	else
		exit(0);
return 0;
}
