#include <iostream>
#include <string>
#include "customerQueue.h"
#include "serverList.h"

using namespace std;

int main()
{
    int timeUnits;
    cout << "Enter the number of time units for the simulation: ";
    cin >> timeUnits;
    int servers;
    cout << endl << "Enter the number of servers: ";
    cin >> servers;
    int waitTime;
    cout << endl << "Enter the server transaction time units: ";
    cin >> waitTime;
    int customerFrequency;
    cout << endl << "Enter time units between customer arrivals: ";
    cin >> customerFrequency;
    cout << endl;

    CustomerQueue Queue;
    serverList List;
    Queue.setCustomerFrequency(customerFrequency);
    List.setWaitTime(waitTime);
    for (int i = 0; i < servers; ++i) {
        List.addServer();
    }
    int t = 0;
    while (t <= timeUnits-1) {
        Queue.checkCustomer(t);
        if (Queue.getLength() > 0) {
            int sID = List.findFree();
            if (sID != -1) {
                List.assignCustomer(Queue.removeCustomer(), sID);
            }
        }
        List.updateTime();
        Queue.updateTime();
        t++;
    }

    
}

