#include <bits/stdc++.h>
#include "Sheduler.h"
using namespace std;
void printProcess(vector<Process>P){
    cout << "Process"
         << "  "
         << "ArvlTime"
         << "  "
         << "burstTime"
         << "  "
         << "Priority" << endl;

    for (auto p : P)
    {
        cout << left;
        cout << setw(9) << p.id;
        cout << setw(10) << p.arrivaltime;
        cout << setw(11) << p.brusttime;
        cout << setw(9) << p.priority << endl;
    }
}
int main()
{
    while(1){
    vector<Process>P;
    int processid,arrivalTime, burstTime, Priority;
	string line;

	// Open the file containing the processes data
	string fileName = "data.txt";
	fstream fileStream;
	fileStream.open(fileName, ios::in);

	if (!fileStream.is_open())
	{
		cerr << "Error opening the file " << fileName << endl;
		exit(1);
	}

	// Parse the file line by line, create each process
	while (getline(fileStream, line))
	{
		if(line.empty())
			break;
		stringstream lineStream(line);
		lineStream >> processid >> arrivalTime >> burstTime >> Priority;
        Process pr=Process(processid,arrivalTime,burstTime,Priority);
        P.push_back(pr);
	}
	cout << "\nChoose scheduling algorithm" << endl;
		cout << "[FCFS], [SJF],[NPP], [RR], [PRIORITY_RR], [EXIT]" << endl;

		string sLine;
		getline(cin, sLine);

        if(sLine=="FCFS"){
            printProcess(P);
            FCFS(P);
        }
		else if (sLine == "SJF"){
		    printProcess(P);
			SJF(P);
		}
		else if(sLine=="NPP"){
		    printProcess(P);
            NPP(P);
		}
		else if (sLine=="RR"){
		    printProcess(P);
            RR(P);
		}
		else if(sLine=="PRIORITY_RR"){
		    printProcess(P);
            PRIORITY_RR(P);
		}
		else if(sLine=="EXIT"){
            break;
		}
		else {
            cout<<"Invalid Input\n";
		}
    }
    return 0;
}
