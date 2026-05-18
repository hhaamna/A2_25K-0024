#ifndef ABSTRACTLISTING_H
#define ABSTRACTLISTING_H

#include <iostream>
#include <string>
using namespace std;

class AbstractListing {
public:
    virtual void displayListing() const = 0;

    virtual void approveListing() = 0;

    virtual void removeListing() = 0;

    virtual string getStatus() const = 0;

    virtual ~AbstractListing() {}
};

#endif
