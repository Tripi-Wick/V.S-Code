#include<iostream>
using namespace std;

void findWaitingTime(int processes[], int n, int bt[], int wt[])
{
	wt[0] = 0;

	for (int i = 1; i < n ; i++ )
		wt[i] = bt[i-1] + wt[i-1] ;
}

void findTurnAroundTime( int processes[], int n, int bt[], int wt[], int tat[])
{
	for (int i = 0; i < n ; i++)
		tat[i] = bt[i] + wt[i];
}

void findAvgTime( int processes[], int n, int bt[] )
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0;

	findWaitingTime(processes, n, bt, wt);

	findTurnAroundTime(processes, n, bt, wt, tat);

	cout << "Processes "<< " Burst time "<< " Waiting time " << " Turn around time \n";

	for (int i=0; i<n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		cout << " " << i+1 << "\t\t" << bt[i] <<"\t "<< wt[i] <<"\t\t " << tat[i] <<endl;
	}

	cout << "Average waiting time = "<< (float)total_wt / (float)n;
	cout << "\n Average turn around time = "<< (float)total_tat / (float)n;
}

int main()
{
    int a;
    cout<<"Enter the number of Process : ";
    cin>>a;

	int processes[a];

    for(int i = 1; i<=a; i++){
        processes[i]=i;
    }
    

	int burst_time[a];

    for(int i = 0; i<a; i++){
        cout<<"Enter the burst time of process no. "<<i+1<<" : ";
        cin>>burst_time[i];
    }

	findAvgTime(processes, a, burst_time);

	return 0;
}
