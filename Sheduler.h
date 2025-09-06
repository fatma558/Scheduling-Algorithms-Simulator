#ifndef Sheduler_H
#define Sheduler_H
#include <bits/stdc++.h>
using namespace std;
struct Process{
   int id,indx,arrivaltime,starttime,brusttime,completiontime,waitingtime,priority,turnaroundtime,remaintime;
   vector<pair<int,int>>stamps;
   Process(int a,int b,int c,int d){
       id=a;
       arrivaltime=b;
       brusttime=c;
       priority=d;
   }
};

struct compBrust {
    bool operator()(Process const &a, Process const &b) {
        if(a.brusttime != b.brusttime)
            return a.brusttime > b.brusttime; // Min-heap: smaller burst time has higher priority
        else if(a.arrivaltime!=b.arrivaltime)
            return a.arrivaltime > b.arrivaltime;
        else return a.id>b.id;
    }
};

struct compPriority {
    bool operator()(Process const &a, Process const &b) {
        if(a.priority != b.priority)
            return a.priority < b.priority; // max-heap: bigger priority higher priority
        else if(a.arrivaltime!=b.arrivaltime)
            return a.arrivaltime>b.arrivaltime;
        else return a.id>b.id;
    }
};
void FCFS( vector<Process>&P);
void SJF( vector<Process>&P);
void NPP( vector<Process>&P);
void RR( vector<Process>&P);
void PRIORITY_RR( vector<Process>&P);
void Results(vector<Process>&P,vector<int>&execution, int curtime, int n, int totalwaitingtime, int cpuidletime, int totalrunningtime);
bool compareById(const Process &a, const Process &b);
bool compareArrThenId(Process &a,Process &b);
bool compareArrThenPriority(Process &a,Process &b);

#endif
