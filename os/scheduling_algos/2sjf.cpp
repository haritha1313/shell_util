#include<bits/stdc++.h>
using namespace std;

struct process
{
	int pid;
	int bt;
};

bool comparison(process a, process b)
{
	return (a.bt<b.bt);
}


int main()
{

	process proc[]={{1,30}, {2,14}, {3,20}};
	int n=3;
	sort(proc,proc+n,comparison);
	for(int i=0;i<n;i++)
	{
		cout<<proc[i].pid<<" ";
	}
	cout<<"\n";

	int wt[n], tat[n], tot_wt=0, tot_at=0;

	wt[0]=0;
	for(int i=1;i<n;i++)
	{
		wt[i]= proc[i-1].bt+wt[i-1];
	} 
	for(int i=0;i<n;i++)
	{
		tat[i]=proc[i].bt+wt[i];
	}
	for(int i=0;i<n;i++)
	{
		tot_wt = tot_wt + wt[i];
		tot_at = tot_at + tat[i];
		cout << "   " << proc[i].pid << "\t" << proc[i].bt <<"\t"<< wt[i] <<"\t" << tat[i]<<"\n";
	}
	cout<<"Avg waiting time : "<<(float)tot_wt/(float)n;
	cout<<"\nAvg turnaround time : "<<(float)tot_at/(float)n;

	return 0;
}