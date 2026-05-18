# PakWheels Vehicle Marketplace — OOP Assignment 2

**Name:** [Hamna Azhar Khan]
**Roll Number:** [25K - 0024]
**Class:** [BAI - 2C]

---

## Table of Contents

1. Buyer Registration
2. Seller Registration
3. Vehicle Listings (Cars & Bike)
4. Vehicle Condition and Fuel Check
5. Operator Overloading
6. Creating Listings
7. Admin Panel
8. Friend Functions
9. Marketplace — All Listings
10. Search Features
11. Buyer Favourites
12. Messaging Area
13. Seller Updates
14. Vehicle Inspections

---

## Buyer Registration

<img width="419" height="465" alt="image" src="https://github.com/user-attachments/assets/f1432e5f-5bab-4881-b520-73ebf59cfc35" />

Buyer class is a derived class. It inherits from the User class, and the User class inherits from the AbstractUser class. Buyer class is reusing all the profile data and the display function made in the User class through inheritance, and new fields like budget and notification are being added. The function to displayProfile is being ovverridden through polymorphism.

**OOP Concepts: Inheritance, Polymorphism**

```cpp
class Buyer : public User {
protected:
    double budget;
    Favourite* savedVehicles[5];
    int savedCount;
    const int maxSaved;
    bool notificationsOn;

public:
    Buyer(int id, string n, string e, string ph, string c, double b)
        : User(id, n, e, ph, c), budget(b), savedCount(0), maxSaved(5), notificationsOn(true) {}

    void displayProfile() const override {
        User::displayProfile();
        cout << "  Budget    : Rs." << budget << "  |  Notifications: " << (notificationsOn ? "On" : "Off") << endl;
    }
};
```

---

## Seller Registration

<img width="438" height="448" alt="image" src="https://github.com/user-attachments/assets/0d53862d-8ea4-42de-af4f-5fb04bd89351" />

The Seller class is also inheriting from the User class. Again, both inheritance and polymorphism is being used; for inheriting featues from User class, and for ovverridding the display function, respectively. 

**OOP Concepts: Inheritance, Polymorphism**

```cpp
class Seller : public User {
protected:
    Listing* myListings[5];
    int listingCount;
    double rating;
    bool verified;
    const string role;

public:
    Seller(int id, string n, string e, string ph, string c, double r)
        : User(id, n, e, ph, c), listingCount(0), rating(r), verified(true), role("Seller") {}

    void displayProfile() const override {
        User::displayProfile();
        cout << "  Rating    : " << rating << "  |  Verified: " << (verified ? "Yes" : "No") << "  |  Listings: " << listingCount << endl;
    }
};
```

---

## Vehicle Listings (Cars and Bike)

<img width="940" height="453" alt="image" src="https://github.com/user-attachments/assets/e79aabc0-0151-476b-839f-de756e61a5ba" />
<img width="940" height="466" alt="image" src="https://github.com/user-attachments/assets/b6ca295e-ef0d-4b9d-ad28-7f0945849d62" />


The Car class, and the Bike class are both inhertiting from the Vehicle class, which inherits from the AbstractVehicle class. A multilevel inheritance chain is created. Car and Ride are also using polymorphism to override the display function from Vehicle, which also overrides the pure virtual function from its Abstract class.
The Vehicle class also shows composition by using the CarDetail object in it. 

**OOP Concepts: Inheritance, Polymorphism, Abstraction**

```cpp
class Car : public Vehicle {
protected:
    int engineCC;
    string bodyType;
    int numSeats;

public:
    Car(int id, string comp, string mdl, int y, double p, int mi,
        int cc, string body, int seats, CarDetail cd = CarDetail())
        : Vehicle(id, comp, mdl, y, p, mi, cd),
          engineCC(cc), bodyType(body), numSeats(seats) {}

    void displayDetails() const override {
        Vehicle::displayDetails();
        cout << "  Engine    : " << engineCC << "cc" << "  |  Body: " << bodyType << "  |  Seats: " << numSeats << endl;
    }
};

class Bike : public Vehicle {
protected:
    int engineCC;
    string bikeType;
    string ignition;
    int gears;

public:
    Bike(int id, string comp, string mdl, int y, double p, int mi,
         int cc, string type, string ign, int g)
        : Vehicle(id, comp, mdl, y, p, mi),
          engineCC(cc), bikeType(type), ignition(ign), gears(g) {}

    void displayDetails() const override {
        Vehicle::displayDetails();
        cout << "  Engine    : " << engineCC << "cc" << "  |  Type: " << bikeType << "  |  Ignition: " << ignition << "  |  Gears: " << gears << endl;
    }
};
```

---

## Vehicle Condition and Fuel Check

<img width="638" height="340" alt="image" src="https://github.com/user-attachments/assets/78297778-e876-428f-ac3f-86c910eb3607" />


The checkCondition function is a pure virtual function in the AbstractVehicle class, which detemines the condition of the vehicle as good, fair, or poor; based on the mileage. It is implemented in the Vehicle class, and is used by both Car and Bike classes. 
Similar functions that i made: checkConditionm, CalculateTax, calculateRegistrationFee

**OOP Concepts: Polymorphism, Inheritance**

```cpp
void checkCondition() const override {
    cout << "  Condition check for " << company << " " << model << ": ";
    if (mileage < 50000)
        cout << "Good condition." << endl;
    else if (mileage < 100000)
        cout << "Fair condition." << endl;
    else
        cout << "Heavily used. Vehicle is in poor condition!" << endl;
}

double calculateTax() const {
    if (price < 2000000) return price * 0.02;
    else if (price < 4000000) return price * 0.05;
    else return price * 0.08;
}
```

---

## Operator Overloading

<img width="1031" height="799" alt="image" src="https://github.com/user-attachments/assets/4df604a0-297d-4c20-a912-0e83ab2a6c05" />


Operator overloading is used to compare the vehicles. It is important to make it easier for the user to compare the car features before buying it.
It is also used to check if two users have the same IDs, to find and remove this error easily. 
'+' is used to add the mileages of the car to see the total easily.
 then == is used to compare prices of the car to find and compare cars of the same price.

**OOP Concept: Operator Overloading**

```cpp
int operator+(const Vehicle& other) const {
    return mileage + other.mileage;
}

bool operator==(const Vehicle& other) const {
    return (int)(price / 500000) == (int)(other.price / 500000);
}

bool operator==(const User& other) const {
    return userID == other.userID;
}

int operator+(const Marketplace& other) const {
    return listingCount + other.listingCount;
}

bool operator==(const Listing& other) const {
    return city == other.city;
}
```

---

## Creating Listings
<img width="234" height="217" alt="image" src="https://github.com/user-attachments/assets/bda217cb-0cf1-4867-b020-8a6d013540aa" />
<img width="1045" height="270" alt="image" src="https://github.com/user-attachments/assets/b99a9b23-c98f-48c6-b726-48d08a736599" />

Listing class inherits from the AbstractListing class and implements all its pure virtual functions. 

we are also using the == operator to compare two listings by their cities.


**OOP Concepts: Abstraction , Operator Overloading**

```cpp
class Listing : public AbstractListing {
protected:
    const int listingID;
    Vehicle* vehicle;
    string city;
    string postDate;
    string status;
    int views;

public:
    Listing(int id, Vehicle* v, string c, string d)
        : listingID(id), vehicle(v), city(c), postDate(d), status("Pending"), views(0) {
        totalListings++;
    }

    void approveListing() override {
        status = "Approved";
        cout << "  Listing " << listingID << " has been approved." << endl;
    }

    void removeListing() override {
        status = "Removed";
        cout << "  Listing " << listingID << " has been removed from the marketplace." << endl;
    }

    void displayListing() const override {
        cout << "  Listing #" << listingID << endl;
        if (vehicle != nullptr) vehicle->displayInfo();
        cout << "  City: " << city << "  |  Status: " << status << "  |  Posted: " << postDate << "  |  Views: " << views << endl;
    }

    string getStatus() const override { return status; }

    bool operator==(const Listing& other) const {
        return city == other.city;
    }
};
```

---

## Admin Panel

<img width="599" height="526" alt="image" src="https://github.com/user-attachments/assets/c84298d9-7aaa-4695-bbad-0b3cc149c7ef" />

Admin is also inheriting fromm the User class. It is working in the same way as the Buyer and Seller classes, with its own additional features, aswell as overriding like before. The new features include accessLevel, and some approval functions.

**OOP Concepts: Inheritance, Polymorphism**

```cpp
class Admin : public User {
private:
    int accessLevel;
    int permissions[5];
    int listingsApproved;
    const string role;
    const char* adminCode;
    static int totalAdmins;

public:
    Admin(int id, string n, string e, string ph, string c, int lvl, const char* code)
        : User(id, n, e, ph, c), accessLevel(lvl), listingsApproved(0),
          role("Admin"), adminCode(code) {
        totalAdmins++;
        for (int i = 0; i < 5; i++) permissions[i] = i + 1;
    }

    void approveListing(Listing* l) {
        if (l != nullptr) {
            l->approveListing();
            listingsApproved++;
        }
    }

    void displayProfile() const override {
        User::displayProfile();
        cout << "  Access Level  : " << accessLevel << "  |  Listings Approved: " << listingsApproved << endl;
    }

    void generateReport() const {
        cout << "Admin      : " << getName() << endl;
        cout << "Level      : " << accessLevel << endl;
        cout << "Approved   : " << listingsApproved << " listings" << endl;
        cout << "Admin Code : " << adminCode << endl;
    }

    friend void verifyAdminCode(const Admin& a);
};
```

---

## Friend Functions
> This is an implementation of the admin, so there is no specific screenshot of this, since it is an extension of the Admin role. It is working for different functionalities in the code.

Friend functions are used to accesss private data from classes. It is a non member function. 
Usage in my code:
1. verifyAdminCode function: declared as a friend fucntion so it can read the adminCode private member from the Admin class.
2. showBuyerBudget function: accesses private attributes such as 'name' and 'budget' from the Buyer class.
3. InspectMessage function: uses the private members of the Message class to see the messages for the inspection by the admin. 

**OOP Concept: Friend Functions**

```cpp
friend void verifyAdminCode(const Admin& a);

void verifyAdminCode(const Admin& a) {
    cout << "  [VERIFY] Admin \"" << a.name << "\" code is: " << a.adminCode << endl;
}

friend void showBuyerBudget(const Buyer& b);

void showBuyerBudget(const Buyer& b) {
    cout << "  [BUDGET CHECK] " << b.name << " has a budget of Rs." << b.budget << endl;
}

friend void inspectMessage(const Message& m);

void inspectMessage(const Message& m) {
    cout << "  [ADMIN INSPECT] Message #" << m.messageID
         << " | Content: \"" << m.content << "\""
         << " | Seen: " << (m.seen ? "Yes" : "No") << endl;
}
```

---

## Marketplace -> Shows all our Listings

<img width="998" height="904" alt="image" src="https://github.com/user-attachments/assets/98656675-ff81-450c-a657-31abacfd36c9" />

The Marketplace class is used to display this entire market, acting like the homepage for the website. This class is using the displatListing function on each of the Listing object, through the AbstractListing class's interface pointer. 
Listing class overrides the pure virtual function, and the correct verysion is called at the runtime. This is though runtime polymorphism.

**OOP Concepts: Abstraction, Polymorphism**

```cpp
void displayAllListings() const {
    cout << " Total listings: " << listingCount << endl;
    cout << endl;
    for (int i = 0; i < listingCount; i++) {
        listings[i]->displayListing();
        cout << endl;
    }
}
```

---

## Search Features
<img width="308" height="357" alt="image" src="https://github.com/user-attachments/assets/d53980cd-1b63-4604-9041-c437a5f9da4b" />
<img width="230" height="218" alt="image" src="https://github.com/user-attachments/assets/a2557eef-7506-4630-bfe9-1420024f655b" />
<img width="230" height="174" alt="image" src="https://github.com/user-attachments/assets/c6635e69-449b-40bb-bf1b-945911bafaf8" />

The search functions loop through all the listings in the Marketplace and calls getVehicle function for each listing, to get their data. This is done though the use of base class pointer, which is Vehicle*, and the function displays the information for each object.
Feature made for easily searching for a vehicle through desired filter
**OOP Concepts: Polymorphism, Abstraction**

```cpp
void searchByPrice(double maxPrice) const {
    cout << " Vehicles under Rs." << maxPrice << ":" << endl;
    for (int i = 0; i < listingCount; i++) {
        if (listings[i]->getVehicle()->getPrice() <= maxPrice)
            listings[i]->displayListing();
    }
}

void searchByCity(string cityName) const {
    cout << "  Listings in " << cityName << ":" << endl;
    for (int i = 0; i < listingCount; i++) {
        if (listings[i]->getCity() == cityName)
            listings[i]->displayListing();
    }
}

void searchByCompany(string comp) const {
    cout << "  Listings for " << comp << ":" << endl;
    for (int i = 0; i < listingCount; i++) {
        if (listings[i]->getVehicle()->getCompany() == comp)
            listings[i]->displayListing();
    }
}

void searchByYear(int yr) const {
    for (int i = 0; i < listingCount; i++) {
        if (listings[i]->getVehicle()->getYear() == yr)
            listings[i]->displayListing();
    }
}

void searchByMileage(int maxMileage) const {
    for (int i = 0; i < listingCount; i++) {
        if (listings[i]->getVehicle()->getMileage() <= maxMileage)
            listings[i]->displayListing();
    }
}
```

---

## Buyer Favourites
<img width="1040" height="507" alt="image" src="https://github.com/user-attachments/assets/85f71ef6-e237-4f4f-98a8-b078aa11882f" />

For the favourites, the buyer class creates a list of Favourite objetcs. Favourite stores a pointer of the Vehicle which is used to access different functions for all the favourited items, all defined in the AbstractVehicle class. No matter whichever vehicle is used, whether Car, or Bike, the same interface is used each time!
This function is used so that the users can bookmark their items to avoid losing them.

**OOP Concepts: Polymorphism, Inheritance**

```cpp
void addToFavourites(Favourite* f) {
    if (savedCount < maxSaved) {
        savedVehicles[savedCount++] = f;
        cout << " Vehicle is saved to favourites." << endl;
    } else {
        cout << "Oops!!! Favourites list is full." << endl;
    }
}

void displayFavourites() const {
    cout << "  Favourites for " << getName() << " (" << savedCount << "):" << endl;
    for (int i = 0; i < savedCount; i++)
        savedVehicles[i]->displayFavourite();
}

void toggleAlert() {
    priceAlert = !priceAlert;
    cout << " Price alert " << (priceAlert ? "enabled" : "disabled") << " for this vehicle." << endl;
}
```
---

## Messaging Area
<img width="426" height="407" alt="image" src="https://github.com/user-attachments/assets/8e4cae35-928e-4570-998e-66c5a80357d9" />

The Message class uses the User pointers for the senders and receivers of messages. Both the Buyer and Seller are inheriting from the same User class, so they can be accessed using the getName function.
The previously introduced friend function is used over here with the function inspectMessage, that can access the private memberes such as messageID.
This function allows the communication between the buyer and seller.
**OOP Concepts: Inheritance, Polymorphism, Friend Functions**

```cpp
class Message {
private:
    const int messageID;
    User* sender;
    User* receiver;
    string content;
    bool seen;

    friend void inspectMessage(const Message& m);

public:
    void sendMessage() const {
        cout << "  [MSG] " << sender->getName() << " -> " << receiver->getName() << " : \"" << content << "\"" << endl;
    }

    void markSeen() {
        seen = true;
        cout << "  Message #" << messageID << " marked as seen." << endl;
    }

    void displayMessage() const {
        cout << "  Message #" << messageID << "  |  From: " << sender->getName() << "  |  To: " << receiver->getName() << "  |  Seen: " << (seen ? "Yes" : "No") << endl;
        cout << "  Content: \"" << content << "\"" << endl;
    }
};

void inspectMessage(const Message& m) {
    cout << "  [ADMIN INSPECT] Message #" << m.messageID
         << " | Content: \"" << m.content << "\""
         << " | Seen: " << (m.seen ? "Yes" : "No") << endl;
}
```

---

## Seller Updates
<img width="380" height="160" alt="image" src="https://github.com/user-attachments/assets/598fa81a-589d-4deb-8772-c01fc4f8e2d4" />

Again using Listing pointers, we call the updatePrice function and display function. This way, the sellar can see all the updates to their listings made.
**OOP Concepts: Abstraction, Inheritance**

```cpp
void addListing(Listing* l) {
    if (listingCount < 5) {
        myListings[listingCount++] = l;
        cout << " Listing " << l->getListingID() << " added by " << getName() << "." << endl;
    }
}

void updateListingPrice(int idx, double newPrice) {
    if (idx >= 0 && idx < listingCount)
        myListings[idx]->updatePrice(newPrice);
}

void viewMyListings() const {
    cout << " Listings posted by " << getName() << ":" << endl;
    for (int i = 0; i < listingCount; i++)
        myListings[i]->displayListing();
}
```

---

## Vehicle Inspections

<img width="940" height="523" alt="image" src="https://github.com/user-attachments/assets/128ca8fe-7d52-4bd7-8a9b-2c163a1d6bde" />

Inspection class uses the Vehicle* pointer aswell. This function is implemented so the users can get a detailed inspection for their car so they can list it, or get a listed car inspected before buying, to confirm its condition.

**OOP Concept: Polymorphism, Encapsulation**

```cpp
class Inspection {
private:
    const int inspectionID;
    Vehicle* vehicle;
    string inspectorName;
    float engineScore;
    float bodyScore;
    float interiorScore;
    bool certified;
    string remarks;

public:
    float calculateOverallScore() const {
        return (engineScore + bodyScore + interiorScore) / 3.0;
    }

    bool isPassing() const {
        return calculateOverallScore() >= 7.0;
    }

    void certifyVehicle() {
        if (calculateOverallScore() >= 8.0) {
            certified = true;
            cout << "Vehicle inspected. Certified based on the inspection." << endl;
        } else {
            cout << "Vehicle inspected. Not Certified based on the inspection." << endl;
        }
    }

    void displayReport() const {
        cout << "Inspection #" << inspectionID << endl;
        if (vehicle != nullptr)
            cout << "  Vehicle   : " << vehicle->getCompany() << " " << vehicle->getModel() << endl;
        cout << "  Inspector : " << inspectorName << endl;
        cout << "  Engine    : " << engineScore << "/10  |  Body: " << bodyScore << "/10  |  Interior: " << interiorScore << "/10" << endl;
        cout << "  Overall   : " << calculateOverallScore() << "/10  |  Certified: " << (certified ? "Yes" : "No") << endl;
        cout << "  Remarks   : " << remarks << endl;
    }
};
```
---
