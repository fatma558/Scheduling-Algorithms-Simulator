#include <bits/stdc++.h>
#include "Sheduler.h"

bool compareById(const Process &a, const Process &b) {
    return a.id < b.id;   // ascending order by PID
}

bool compareArrThenId(Process &a,Process &b){
  if(a.arrivaltime!=b.arrivaltime)return a.arrivaltime<b.arrivaltime;
  else return a.id<b.id;
}

bool compareArrThenPriority(Process &a,Process &b){
   if(a.arrivaltime!=b.arrivaltime)return a.arrivaltime<b.arrivaltime;
   else return a.priority>b.priority;
}

void Results(vector<Process>&arr,vector<int>&execution, int curtime, int n, int totalwaitingtime, int cpuidletime, int totalrunningtime){

    cout<<"The excution order\nFrom  To  PID\n";
    int lstsecond=0,curid=execution[0];
    for(int i=1;i<=curtime;i++){
        if(execution[i]==curid)continue;
        else{
             cout << setw(6) << lstsecond;
             cout << setw(5) << i;
             cout << setw(5);
             if(curid!=0)cout<<curid<<'\n';
             else
             {
                 cout<<"Idle\n";
                 cpuidletime+=(i-lstsecond);
             }
            lstsecond=i;
            curid=execution[i];
        }
    }

    cout<<"\nAverage WaitingTime = "<<totalwaitingtime*1.0/n<<"\n";
    cout<<"Utilization = "<<(totalrunningtime*100.0)/(totalrunningtime+cpuidletime)<<"%\n\n";

   cout<<"PID  ArivTime  EndTime  TrnArndTime   WaitingTime\n";
   for(auto&p:arr){
        cout << left;
        cout << setw(9) << p.id;
        cout << setw(10) << p.arrivaltime;
        cout << setw(11) << p.completiontime;
        cout << setw(9) << p.turnaroundtime ;
        cout << setw(9) << p.waitingtime << endl;
   }
}
