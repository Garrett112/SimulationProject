#include <iostream>
#include <string>
#include <random>
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
    cout << "-----------------------------------------------------" << endl;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, customerFrequency);
    CustomerQueue Queue;
    serverList List;
    Queue.setCustomerFrequency(customerFrequency);
    List.setWaitTime(waitTime);
    for (int i = 0; i < servers; ++i) {
        List.addServer();
    }
    int t = 0;
    while (t <= timeUnits-1) {
        Queue.checkCustomer(dis(gen), t);
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
    cout << "-----------------------------------------------------" << endl;
    cout << endl << "Number of customers left in queue: " << Queue.getLength() << endl;
    cout << endl << "Number of customers that arrived: " << Queue.getCustomerCount() << endl;
    cout << endl << "Number of customers who completed a transaction: " << Queue.getCustomerServed() << endl;
    if (Queue.getLength() != 0) {
        cout << endl << "Average wait time for customers in the queue: " << Queue.getWaitTimes();
    }
}

