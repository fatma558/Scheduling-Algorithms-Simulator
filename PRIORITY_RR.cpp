#include <bits/stdc++.h>
#include "Sheduler.h"

void PRIORITY_RR(vector<Process>&arr)
{
    int n=arr.size(),timequantom=2,totalwaitingtime=0,cpuidletime=0,totalrunningtime=0;
    map<int,vector<Process>>mp;
    for(int i=0;i<n;i++){
        arr[i].remaintime=arr[i].brusttime;
        mp[arr[i].arrivaltime].push_back(arr[i]);
    }
    int completed=0,curtime=0,curindx=0;
    // sort Process according to arrival time
    sort(arr.begin(),arr.end(),compareArrThenId);
    for(int i=0;i<n;i++)arr[i].indx=i;
    priority_queue<Process,vector<Process>,compPriority>readyQueue;
    while(completed<n){
        // adding process with arrival time less than current time to ready queue
       while(curindx<n&&arr[curindx].arrivaltime<=curtime)readyQueue.push(arr[curindx++]);
       if(!readyQueue.empty()){
        // choose top of queue to take CPU
        Process running=readyQueue.top();
        readyQueue.pop();
        if(running.remaintime<=timequantom){
            running.completiontime=curtime+running.remaintime;
            running.turnaroundtime=running.completiontime-running.arrivaltime;
            running.waitingtime=running.turnaroundtime-running.brusttime;
            running.stamps.push_back({curtime,curtime+running.remaintime});
            running.remaintime=0;
            curtime=running.completiontime;
            arr[running.indx]=running;
            completed++;
        }
        else{
            running.stamps.push_back({curtime,curtime+timequantom});
            curtime+=timequantom;
            while(curindx<n&&arr[curindx].arrivaltime<=curtime)readyQueue.push(arr[curindx++]);
            running.remaintime-=timequantom;
            arr[running.indx]=running;
            readyQueue.push(running);
        }
       }
       else curtime++;
    }

    sort(arr.begin(),arr.end(),compareById);

    //updates every second with process running in this second
    vector<int>execution(curtime+1);
    for(int i=0;i<n;i++){
        for(auto&it:arr[i].stamps){
        execution[it.first]+=arr[i].id;
        execution[it.second]-=arr[i].id;
        }
        totalwaitingtime+=arr[i].waitingtime;
        totalrunningtime+=arr[i].brusttime;
    }
    for(int i=1;i<=curtime;i++)execution[i]+=execution[i-1];

    Results(arr, execution, curtime, n, totalwaitingtime, cpuidletime, totalrunningtime);
}
