#ifndef ABSTRACTVEHICLE_H
#define ABSTRACTVEHICLE_H

#include <iostream>
#include <string>
using namespace std;

class AbstractVehicle {
public:
    virtual void displayDetails() const = 0;

    virtual void checkCondition() const = 0;

    virtual double getPrice() const = 0;

    virtual string getCompany() const = 0;

    virtual string getModel() const = 0;

    virtual ~AbstractVehicle() {}
};

#endif
