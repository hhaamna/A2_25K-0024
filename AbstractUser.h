#ifndef ABSTRACTUSER_H
#define ABSTRACTUSER_H

#include <iostream>
#include <string>
using namespace std;

class AbstractUser {
public:
    virtual void displayProfile() const = 0;

    virtual string getName() const = 0;

    virtual int getUserID() const = 0;

    virtual ~AbstractUser() {}
};

#endif
