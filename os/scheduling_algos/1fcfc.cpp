#include<iostream>
using namespace std;

int main(){

	int n;
	cout<<"Enter number of processes\n";
	cin>>n;
	int processes[n], bt[n];
	cout<<"Enter process numbers\n";
	for(int i=0;i<n;i++)
		cin>>processes[i];
	cout<<"Enter burst times sequentially\n";
	for(int i=0;i<n;i++)
		cin>>bt[i];
	
	int wt[n], tat[n], tot_wt=0, tot_at=0;

	wt[0]=0;
	for(int i=1;i<n;i++)
	{
		wt[i]= bt[i-1]+wt[i-1];
	} 
	for(int i=0;i<n;i++)
	{
		tat[i]=bt[i]+wt[i];
	}
	for(int i=0;i<n;i++)
	{
		tot_wt = tot_wt + wt[i];
		tot_at = tot_at + tat[i];
		cout << "   " << i+1 << "\t" << bt[i] <<"\t"<< wt[i] <<"\t" << tat[i]<<"\n";
	}
	cout<<"Avg waiting time : "<<(float)tot_wt/(float)n;
	cout<<"\nAvg turnaround time : "<<(float)tot_at/(float)n;
	cout<<"\n";
	return 0;

}
