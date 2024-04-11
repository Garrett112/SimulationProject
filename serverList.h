#pragma once
#include <iostream>
#include <string>
#include "LinkList.h"
#include "server.h"
#include "customer.h"

using namespace std;

struct office {
	Server s;
	Customer c;
};

class serverList : public LinkList <office> {
private:
	int customersServed;
	int totalWaitTime;
	int waitTime;
	int timeUnits;
	nodeType<office>* cursor;
	nodeType<office>* cursor2;
public:

	serverList() {
		customersServed = 0;
		totalWaitTime = 0;
		waitTime = 0;
		timeUnits = 0;
		cursor = nullptr;
	}

	void setWaitTime(int w) {
		waitTime = w;
	}

	void addServer() {
		increaseLength();
		nodeType<office>* newNode;
		newNode = new nodeType<office>;
		Server temp;
		newNode->info.s = temp;
		newNode->info.s.setServerID(getLength());
		newNode->link = nullptr;
		if (first == nullptr) {
			first = newNode;
			last = first;
		}
		else {
			last->link = newNode;
			last = last->link;
		}
	}

	int findFree() {
		cursor = first;
		while (cursor != nullptr) {
			if (cursor->info.s.getServerStatus() == 0) {
				return cursor->info.s.getServerID();
			}
			else {
				cursor = cursor->link;
			}
		}
		return -1;
	}

	void assignCustomer(Customer c, int sID) {
		cursor = first;
		for (int i = 1; i < sID; ++i) {
			cursor = cursor->link;
		}
		cursor->info.c = c;
		cursor->info.s.setServerStatus(1);
	}
	void completeCustomer(int sID) {
		customersServed++;
		cursor2 = first;
		for (int i = 0; i < sID; ++i) {
			cursor2 = cursor2->link;
		}
		totalWaitTime = totalWaitTime + cursor->info.c.getWaitTime();
		cursor->info.s.setServerStatus(0);
		cursor->info.s.setTransactionTime(0);
		cout << "From server: " << cursor->info.s.getServerID() << " customer " << cursor->info.c.getCustomerID() << " departed at time unit " << timeUnits << endl;
	}

	void updateTime() {
		timeUnits++;
		cursor = first;
		while (cursor != nullptr) {
			if (cursor->info.c.getCustomerID() != 0) {
				cursor->info.s.updateTransactionTime();
				if (cursor->info.s.getTransactionTime() == waitTime) {
					completeCustomer(cursor->info.s.getServerID());
				}
			}
			cursor = cursor->link;
		}
	}
	void checkServers(int) {

	}
};

