#pragma once
#include "LinkList.h"
#include "customer.h"
#include "iostream"
#include "string"

using namespace std;

class CustomerQueue : public LinkList<Customer> {
private:
    int customerCount;
    int customerFrequency;
    int customerServed;
    nodeType<Customer>* cursor;
public:

    CustomerQueue() {
        customerCount = 0;
        customerFrequency = 0;
    }

    void setCustomerFrequency(int f) {
        customerFrequency = f;
    }

    void addCustomer(int t) {
        customerCount++;
        increaseLength();
        nodeType<Customer>* newNode;
        newNode = new nodeType<Customer>;
        newNode->info.setCustomerID(customerCount);
        newNode->link = nullptr;
        if (first == nullptr) {
            first = newNode;
            last = first;
        }
        else {
            last->link = newNode;
            last = last->link;
        }
        cout << "Customer number: " << customerCount << " arrived at time unit: " << t << endl;
    }

    Customer removeCustomer() {
        cursor = first;
        first = first->link;
        reduceLength();
        customerServed++;
        return cursor->info;
    }

    void checkCustomer(int r, int t) {
        if (r == 1) {
            addCustomer(t);
        }
    }

    void updateTime() {
        cursor = first;
        while (cursor != nullptr) {
            cursor->info.updateWaitTime();
            cursor = cursor->link;
        }
    }

    int getQueueLength() {
        return getLength();
    }

    float getWaitTimes() {
        float total = 0;
        nodeType<Customer>* cursor = first;
        while (cursor != nullptr) {
            total = total + cursor->info.getWaitTime();
            cursor = cursor->link;
        }
        return total / getLength();
    }

    int getCustomerCount() {
        return customerCount;
    }
    
    int getCustomerServed() {
        return customerServed;
    }
};
