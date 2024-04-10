#pragma once

class Server {
private:
    int serverID;
    bool status;
    int customerID;
    int transactionTime;
public:

    Server() {
        serverID = 0;
        status = 0;
        customerID = 0;
        transactionTime = 0;
    }

    void setServerID(int id) {
        serverID = id;
    }

    int getServerID() {
        return serverID;
    }

    void setServerStatus(bool s) {
        status = s;
    }

    bool getServerStatus() {
        return status;
    }

    void setTransactionTime(int t) {
        transactionTime = t;
    }

    int getTransactionTime() {
        return transactionTime;
    }

    void updateTransactionTime() {
        transactionTime++;
    }

    int getCustomerWaitTime() {
        return transactionTime;
    }

    int getCustomerID() {
        return customerID;
    }

    void addCustomer(int customer) {
        customerID = customer;
        setTransactionTime(0);
    }

};
