#include <bits/stdc++.h>
#include "Sheduler.h"
void FCFS(vector<Process>&arr) {

  map<int,vector<Process>>mp;
  int n=arr.size();
  for(int i=0;i<n;i++){
        mp[arr[i].arrivaltime].push_back(arr[i]);
    }
    int completed=0,curtime=0,curindx=0,endtime=0,totalwaitingtime=0,cpuidletime=0,totalrunningtime=0;
    // sort Process according to arrival time
    sort(arr.begin(),arr.end(),compareArrThenId);
    for(int i=0;i<n;i++)arr[i].indx=i;
    // ready queue which sorts Processes according to arrival time
    deque<Process>q;
    while(completed<n){
        // adding process with arrival time less than current time to ready queue
       while(curindx<n&&arr[curindx].arrivaltime<=curtime)q.push_back(arr[curindx++]);
       if(!q.empty()){
        // choose top of queue to take CPU
        Process running=q.front();
        q.pop_front();
        arr[running.indx].completiontime=curtime+running.brusttime;
        arr[running.indx].starttime=curtime;
        arr[running.indx].turnaroundtime=arr[running.indx].completiontime-arr[running.indx].arrivaltime;
        arr[running.indx].waitingtime=arr[running.indx].turnaroundtime-running.brusttime;
        curtime+=running.brusttime;
        completed++;
       }
       else curtime++;
    }
    sort(arr.begin(),arr.end(),compareById);

    //updates every second with process running in this second
    vector<int>execution(curtime+1);
    for(int i=0;i<n;i++){
        execution[arr[i].completiontime]-=arr[i].id;
        execution[arr[i].starttime]+=arr[i].id;
        totalwaitingtime+=arr[i].waitingtime;
        totalrunningtime+=arr[i].brusttime;
    }
    for(int i=1;i<=curtime;i++)execution[i]+=execution[i-1];

    Results(arr, execution, curtime, n, totalwaitingtime, cpuidletime, totalrunningtime);

}
