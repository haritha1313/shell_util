#include <bits/stdc++.h>
using namespace std;
 
struct Process {
    int pid; // Process ID
    int bt; // Burst Time
    int art; // Arrival Time
};

void findWat(Process proc[], int n,
                                int wt[])
{
    int rt[n];
 
    for (int i = 0; i < n; i++)
        rt[i] = proc[i].bt;
 
    int complete = 0, t = 0, minm = INT_MAX;
    int small = 0, finish_time;
    bool check = false;
 
    while (complete != n) {
 
        for (int j = 0; j < n; j++) {
            if ((proc[j].art <= t) &&
            (rt[j] < minm) && rt[j] > 0) {
                minm = rt[j];
                small = j;
                check = true;
            }
        }
 
        if (check == false) {
            t++;
            continue;
        }
 
        rt[small]--;
 
        minm = rt[small];
        if (minm == 0)
            minm = INT_MAX;
 
        if (rt[small] == 0) {
 
            complete++;
 
            finish_time = t + 1;
 
            wt[small] = finish_time -proc[small].bt -proc[small].art;
 
            if (wt[small] < 0)
                wt[small] = 0;
        }
        t++;
    }
}
 
void findTat(Process proc[], int n,
                        int wt[], int tat[])
{
	for (int i = 0; i < n; i++)
        tat[i] = proc[i].bt + wt[i];
}
void findavgTime(Process proc[], int n)
{
    int wt[n], tat[n], total_wt = 0,
                    total_tat = 0;
 
    findWat(proc, n, wt);
 
    findTat(proc, n, wt, tat);
 
    cout << "Processes "
        << " Burst time "
        << " Waiting time "
        << " Turn around time\n";
 
    for (int i = 0; i < n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << proc[i].pid << "\t\t"
            << proc[i].bt << "\t\t " << wt[i]
            << "\t\t " << tat[i] << endl;
    }
 
    cout << "\nAverage waiting time = "
        << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
        << (float)total_tat / (float)n;
}
 
int main()
{
    Process proc[] = { { 1, 6, 1 }, { 2, 8, 1 },
                    { 3, 7, 2 }, { 4, 3, 3 } };
    int n =4; 
 
    findavgTime(proc, n);
    return 0;
}
