/*
Indexed file allocation strategy: In this type of strategy, 
the files are allocated based on the indexes that are created 
for each fragment of the file such that each and every similar 
indexed file is maintained by the primary index thereby providing 
flow to the file fragments.

Sample input:
9
3
1 2 3

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int f[50],i,k,j,inde[50],n,c,count=0,p;
	
	for(i=0;i<50;i++)
		f[i]=0;
	x:
	cout<<"\nenter index block\t";
	cin>>p;
	if(f[p]==0)
	{
		f[p]=1;
		cout<<"\nenter no of files on index\t";
		cin>>n;
	}
	else
	{
		cout<<"\nBlock already allocated\n";
		goto x;
	}
	for(i=0;i<n ;i++)
		cin>>inde[i];
	for(i=0;i<n; i++)
		if(f[inde[i]]==1)
		{
			cout<<"Block already allocated";
			goto x;
		}
	for(j=0;j<n; j++)
		f[inde[j]]=1;
	cout<<"\n allocated";
	cout<<"\n file indexed\n";
	for(k=0;k<n; k++)
		cout<<p<<"->"<<inde[k]<<" : "<<f[inde[k]]<<endl;
	printf("\n Enter 1 to enter more files and 0 to exit\t");
	cin>>c;
	if(c==1)
		goto x;
	else
		exit(0);
	
	return 0;
}
