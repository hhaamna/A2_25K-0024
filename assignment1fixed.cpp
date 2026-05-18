#include<iostream>
#include<string>
using namespace std;

// i edited my previous assignment since there were some errors in it, and this is the edited version. 
// ill be using this version for completing assigment 2 so i dont repeat the previous errors :)

class Listing;
class Vehicle;

class User {
protected:
    const int userID;
    string name;
    string email;
    string phone;
    string city;
    static int totalUsers;

public:
    User() : userID(++totalUsers) {
        name = "Unknown";
        email = "Unknown";
        phone = "Unknown";
        city = "Unknown";
    }

    User(int id, string n, string e, string ph, string c)
        : userID(id), name(n), email(e), phone(ph), city(c) {
        totalUsers++;
    }

    // copy const when copyinguser obj 
    User(const User& u)
        : userID(u.userID), name(u.name), email(u.email), phone(u.phone), city(u.city) {}

    int getUserID() const { return userID; }
    string getName() const { return name; }
    string getEmail() const { return email; }
    string getPhone() const { return phone; }
    string getCity() const { return city; }

    void setName(string n) { name = n; }
    void setEmail(string e) { email = e; }
    void setPhone(string ph) { phone = ph; }
    void setCity(string c) { city = c; }

    static int getTotalUsers() { return totalUsers; }

    void displayProfile() const {
        cout << "  User ID : " << userID << endl;
        cout << "  Name    : " << name << endl;
        cout << "  Email   : " << email << endl;
        cout << "  Phone   : " << phone << endl;
        cout << "  City    : " << city << endl;
    }

    void updateContactInfo(string newPhone, string newCity) {
        phone = newPhone;
        city = newCity;
        cout << "  Contact info updated for " << name << "." << endl;
    }

    bool isFromCity(string c) const {
        return city == c;
    }
};
int User::totalUsers = 0;


class CarDetail {
private:
    string fuelType;
    string transmission;
    string color;
    int doors;
    float fuelAvg;
    bool hasAC;

public:
    CarDetail() {
        fuelType = "Unknown";
        transmission = "Unknown";
        color = "Unknonw";
        doors = 4;
        fuelAvg = 15.0;
        hasAC = true;
    }

    CarDetail(string ft, string tr, string cl, int d, float avg, bool ac)
        : fuelType(ft), transmission(tr), color(cl), doors(d), fuelAvg(avg), hasAC(ac) {}

    string getFuelType() const { return fuelType; }
    string getTransmission() const { return transmission; }
    string getColor() const { return color; }
    int getDoors() const { return doors; }
    float getFuelAvg() const { return fuelAvg; }
    bool getHasAC() const { return hasAC; }

    void setFuelType(string ft) { fuelType = ft; }
    void setTransmission(string tr) { transmission = tr; }
    void setColor(string cl) { color = cl; }
    void setFuelAvg(float avg) { fuelAvg = avg; }

    void displayCarDetail() const {
        cout << "  Fuel      : " << fuelType << "  |  Transmission : " << transmission << endl;
        cout << "  Color     : " << color << "     |  Doors        : " << doors << endl;
        cout << "  Fuel Avg  : " << fuelAvg << " km/l" << "  |  AC           : " << (hasAC ? "Yes" : "No") << endl;
    }

    void checkFuelEfficiency() const {
        if (fuelAvg >= 12.0)
            cout << "  Fuel efficiency is good: " << fuelAvg << " km/l" << endl;
        else
            cout << "  Fuel efficiency is bad: " << fuelAvg << " km/l" << endl;
    }
};


class Vehicle {
private:
    const int vehicleID;
    string company;
    string model;
    int year;
    double price;
    int mileage;
    CarDetail carDetail; // using composition 
    static int totalVehicles;

public:
    Vehicle(int id, string comp, string mdl, int y, double p, int mi, CarDetail cd = CarDetail())
        : vehicleID(id), company(comp), model(mdl), year(y), price(p), mileage(mi), carDetail(cd) {
        totalVehicles++;
    }

    int getVehicleID() const { return vehicleID; }
    string getCompany() const { return company; }
    string getModel() const { return model; }
    int getYear() const { return year; }
    double getPrice() const { return price; }
    int getMileage() const { return mileage; }

    void setPrice(double p) { price = p; }
    void setMileage(int m) { mileage = m; }

    static int getTotalVehicles() { return totalVehicles; }

    void displayInfo() const {
        cout << "  Vehicle ID : " << vehicleID << endl;
        cout << "  " << company << " " << model << "  |  Year: " << year << "  |  Price: Rs." << price << "  |  Mileage: " << mileage << " km" << endl;
        carDetail.displayCarDetail();
    }

    void checkCondition() const {
        cout << "  Condition check for " << company << " " << model << ": ";
        if (mileage < 50000)
            cout << "Good condition." << endl;
        else if (mileage < 100000)
            cout << "Fair condition." << endl;
        else
            cout << "Heavily used. Vehicle is in poor condition!" << endl;
    }

    void showFuelInfo() const {
        carDetail.checkFuelEfficiency();
    }

    bool isLuxury() const {
        return price > 5000000;
    }

    double calculateTax() const {
        if (price < 2000000) return price * 0.02;
        else if (price < 4000000) return price * 0.05;
        else return price * 0.08;
    }
};
int Vehicle::totalVehicles = 0;

class Car : public Vehicle {
private:
    int engineCC;
    string bodyType;
    int numSeats;

public:
    Car(int id, string comp, string mdl, int y, double p, int mi,
        int cc, string body, int seats, CarDetail cd = CarDetail())
        : Vehicle(id, comp, mdl, y, p, mi, cd),
          engineCC(cc), bodyType(body), numSeats(seats) {}

    int getEngineCC() const { return engineCC; }
    string getBodyType() const { return bodyType; }
    int getNumSeats() const { return numSeats; }

    void displayCarInfo() const {
        displayInfo();
        cout << "  Engine    : " << engineCC << "cc" << "  |  Body: " << bodyType << "  |  Seats: " << numSeats << endl;
    }

    double calculateRegistrationFee() const {
        if (engineCC < 1000) return getPrice() * 0.01;
        else if (engineCC < 1500) return getPrice() * 0.02;
        else return getPrice() * 0.03;
    }

    bool isSmallCar() const {
        return engineCC <= 1000;
    }
};

class Bike : public Vehicle {
private:
    int engineCC;
    string bikeType;
    string ignition;
    int gears;

public:
    Bike(int id, string comp, string mdl, int y, double p, int mi,
         int cc, string type, string ign, int g)
        : Vehicle(id, comp, mdl, y, p, mi),
          engineCC(cc), bikeType(type), ignition(ign), gears(g) {}

    int getEngineCC() const { return engineCC; }
    string getBikeType() const { return bikeType; }

    void displayBikeInfo() const {
        displayInfo();
        cout << "  Engine    : " << engineCC << "cc" << "  |  Type: " << bikeType << "  |  Ignition: " << ignition << "  |  Gears: " << gears << endl;
    }

    bool requiresLicense() const {
        return engineCC > 100;
    }

    double estimateFuelEfficiency() const {
        if (engineCC <= 70) return 50.0;
        else if (engineCC <= 100) return 45.0;
        else if (engineCC <= 125) return 40.0;
        else return 30.0;
    }
};

class Listing {
private:
    const int listingID;
    Vehicle* vehicle; // aggregating 
    string city;
    string postDate;
    string status;
    int views;
    static int totalListings;

public:
    Listing(int id, Vehicle* v, string c, string d)
        : listingID(id), vehicle(v), city(c), postDate(d), status("Pending"), views(0) {
        totalListings++;
    }

    int getListingID() const { return listingID; }
    string getCity() const { return city; }
    string getStatus() const { return status; }
    string getPostDate() const { return postDate; }
    Vehicle* getVehicle() const { return vehicle; }
    int getViews() const { return views; }

    void setStatus(string s) { status = s; }
    void setCity(string c) { city = c; }
    void incrementViews() { views++; }

    static int getTotalListings() { return totalListings; }

    void approveListing() {
        status = "Approved";
        cout << "  Listing " << listingID << " has been approved." << endl;
    }

    void removeListing() {
        status = "Removed";
        cout << "  Listing " << listingID << " has been removed from the marketplace." << endl;
    }

    void updatePrice(double newPrice) {
        vehicle->setPrice(newPrice);
        cout << "  Listing " << listingID << " price updated to Rs." << newPrice << endl;
    }

    bool isPending() const {
        return status == "Pending";
    }

    void displayListing() const {
        cout << "  Listing #" << listingID << endl;
        if (vehicle != nullptr) vehicle->displayInfo();
        cout << "  City: " << city << "  |  Status: " << status << "  |  Posted: " << postDate << "  |  Views: " << views << endl;
    }
};
int Listing::totalListings = 0;

class Seller : public User {
private:
    Listing* myListings[5]; //pointer array
    int listingCount;
    double rating;
    bool verified;
    const string role;

public:
    Seller() : User(), listingCount(0), rating(5.0), verified(false), role("Seller") {}

    Seller(int id, string n, string e, string ph, string c, double r)
        : User(id, n, e, ph, c), listingCount(0), rating(r), verified(true), role("Seller") {}

    double getRating() const { return rating; }
    bool isVerified() const { return verified; }
    void setRating(double r) { rating = r; }

    void addListing(Listing* l) {
        if (listingCount < 5) {
            myListings[listingCount++] = l;
            cout << " Listing " << l->getListingID() << " added by " << getName() << "." << endl;
        } else {
            cout << " Listing limit has beenn reached for " << getName() << "." << endl;
        }
    }

    void viewMyListings() const {
        cout << " Listings posted by " << getName() << ":" << endl;
        for (int i = 0; i < listingCount; i++)
            myListings[i]->displayListing();
    }

    void updateListingPrice(int idx, double newPrice) {
        if (idx >= 0 && idx < listingCount)
            myListings[idx]->updatePrice(newPrice);
    }

    void deleteListing(int idx) {
        if (idx >= 0 && idx < listingCount) {
            myListings[idx]->removeListing();
            for (int i = idx; i < listingCount - 1; i++)
                myListings[i] = myListings[i + 1];
            listingCount--;
        }
    }

    void displaySellerInfo() const {
        displayProfile();
        cout << "  Rating    : " << rating << "  |  Verified: " << (verified ? "Yes" : "No") << "  |  Listings: " << listingCount << endl;
    }
};

class Message {
private:
    const int messageID;
    User* sender; // aggregating
    User* receiver; // aggregating 
    string content;
    bool seen;
    static int totalMessages;

public:
    Message(int id, User* s, User* r, string c)
        : messageID(id), sender(s), receiver(r), content(c), seen(false) {
        totalMessages++;
    }

    int getMessageID() const { return messageID; }
    string getContent() const { return content; }
    bool getSeen() const { return seen; }
    void setSeen(bool s) { seen = s; }

    static int getTotalMessages() { return totalMessages; }

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

    void deleteMessage() {
        cout << "  Message #" << messageID << " has been deleted." << endl;
    }
};
int Message::totalMessages = 0;

class Favourite {
private:
    const int favouriteID;
    Vehicle* vehicle; // aggregating again 
    string dateAdded;
    bool priceAlert;
    string notes;
    static int totalFavourites;

public:
    Favourite(int id, Vehicle* v, string date, bool alert, string n)
        : favouriteID(id), vehicle(v), dateAdded(date), priceAlert(alert), notes(n) {
        totalFavourites++;
    }

    Vehicle* getVehicle() const { return vehicle; }
    string getDateAdded() const { return dateAdded; }
    bool getPriceAlert() const { return priceAlert; }
    void setPriceAlert(bool a) { priceAlert = a; }
    void setNotes(string n) { notes = n; }

    void toggleAlert() {
        priceAlert = !priceAlert;
        cout << " Price alert " << (priceAlert ? "enabled" : "disabled") << " for this vehicle." << endl;
    }

    void displayFavourite() const {
        cout << "  Fav #" << favouriteID << "  |  ";
        if (vehicle != nullptr)
            cout << vehicle->getCompany() << " " << vehicle->getModel() << "  |  Rs." << vehicle->getPrice();
        cout << "  |  Added: " << dateAdded << "  |  Alert: " << (priceAlert ? "On" : "Off")<< "  |  Notes: " << notes << endl;
    }

    static int getTotalFavourites() { return totalFavourites; }
};
int Favourite::totalFavourites = 0;

class Buyer : public User {
private:
    double budget;
    Favourite* savedVehicles[5]; //ptr array 
    int savedCount;
    const int maxSaved; 
    bool notificationsOn;

public:
    Buyer() : User(), budget(0), savedCount(0), maxSaved(5), notificationsOn(false) {}

    Buyer(int id, string n, string e, string ph, string c, double b)
        : User(id, n, e, ph, c), budget(b), savedCount(0), maxSaved(5), notificationsOn(true) {}

    double getBudget() const { return budget; }
    bool getNotificationsOn() const { return notificationsOn; }
    void setBudget(double b) { budget = b; }
    void setNotificationsOn(bool n) { notificationsOn = n; }

    void addToFavourites(Favourite* f) {
        if (savedCount < maxSaved) {
            savedVehicles[savedCount++] = f;
            cout << " Vehicle is saved to favourites." << endl;
        } else {
            cout << "Oops!!! Favourites list is full." << endl;
        }
    }

    void removeFromFavourites(int idx) {
        if (idx < 0 || idx >= savedCount) {
            cout << "Invalid index!!" << endl;
            return;
        }
        for (int i = idx; i < savedCount - 1; i++)
            savedVehicles[i] = savedVehicles[i + 1];
        savedCount--;
        cout << " Vehicle is removed from favourites." << endl;
    }

    void displayFavourites() const {
        if (savedCount == 0) {
            cout << "Favourites list is empty !!" << endl;
            return;
        }
        cout << "  Favourites for " << getName() << " (" << savedCount << "):" << endl;
        for (int i = 0; i < savedCount; i++)
            savedVehicles[i]->displayFavourite();
    }

    void sendMessage(Seller* s, string content) {
        static int msgCounter = 0;
        Message m(++msgCounter, this, s, content);
        m.sendMessage();
    }

    void searchByBudget(Vehicle* vehicles[], int total) const {
        cout << "  Vehicles within " << getName() << "'s budget (Rs." << budget << "):" << endl;
        bool found = false;
        for (int i = 0; i < total; i++) {
            if (vehicles[i]->getPrice() <= budget) {
                vehicles[i]->displayInfo();
                found = true;
            }
        }
        if (!found) cout << "  No vehicles found within budget." << endl;
    }
};

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

    int getAccessLevel() const { return accessLevel; }
    int getListingsApproved() const { return listingsApproved; }

    static int getTotalAdmins() { return totalAdmins; }
    static void showAdminCount() {
        cout << "  Total Admins registered: " << totalAdmins << endl;
    }

    void approveListing(Listing* l) {
        if (l != nullptr) {
            l->approveListing();
            listingsApproved++;
        }
    }

    void removeListing(Listing* l) {
        if (l != nullptr)
            l->removeListing();
    }

    void banUser(User* u) {
        cout << "  " << u->getName() << " has been banned by Admin." << endl;
    }

    bool hasPermission(int code) const {
        for (int i = 0; i < 5; i++)
            if (permissions[i] == code) return true;
        return false;
    }

    void generateReport() const {
        cout << "Admin      : " << getName() << endl;
        cout << "Level      : " << accessLevel << endl;
        cout << "Approved   : " << listingsApproved << " listings" << endl;
        cout << "Admin Code : " << adminCode << endl;
    }
};
int Admin::totalAdmins = 0;

class Inspection {
private:
    const int inspectionID;
    Vehicle* vehicle; // again aggregation 
    string inspectorName;
    float engineScore;
    float bodyScore;
    float interiorScore;
    bool certified;
    string remarks;
    static int totalInspections;

public:
    Inspection(int id, Vehicle* v, string inspector, float es, float bs, float is_, bool cert, string rem)
        : inspectionID(id), vehicle(v), inspectorName(inspector),
          engineScore(es), bodyScore(bs), interiorScore(is_),
          certified(cert), remarks(rem) {
        totalInspections++;
    }

    float getEngineScore() const { return engineScore; }
    float getBodyScore() const { return bodyScore; }
    bool isCertified() const { return certified; }
    void setRemarks(string r) { remarks = r; }

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
            cout << "Vehicle ispected. Not Certified based on the inspectipn." << endl;
        }
    }

    void displayReport() const {
        cout << "Inspection #" << inspectionID << endl;
        if (vehicle != nullptr)
            cout << "  Vehicle   : " << vehicle->getCompany() << " " << vehicle->getModel() << endl;
        cout << "  Inspector : " << inspectorName << endl;
        cout << "  Engine    : " << engineScore << "/10" << "  |  Body: " << bodyScore << "/10" << "  |  Interior: " << interiorScore << "/10" << endl;
        cout << "  Overall   : " << calculateOverallScore() << "/10"<< "  |  Certified: " << (certified ? "Yes" : "No") << endl;
        cout << "  Remarks   : " << remarks << endl;
    }

    static int getTotalInspections() { return totalInspections; }
};
int Inspection::totalInspections = 0;

class Marketplace {
private:
    const string platformName;
    Listing* listings[20];
    User* users[20];
    int listingCount;
    int userCount;
    string location;
    static int totalMarketplaces;

public:
    Marketplace(string name, string loc)
        : platformName(name), location(loc), listingCount(0), userCount(0) {
        totalMarketplaces++;
    }

    string getPlatformName() const { return platformName; }
    int getListingCount() const { return listingCount; }
    string getLocation() const { return location; }

    static int getTotalMarketplaces() { return totalMarketplaces; }
    static void showMarketplaceCount() {
        cout << "Total Marketplace instances: " << totalMarketplaces << endl;
    }

    void addListing(Listing* l) {
        if (listingCount < 20) {
            listings[listingCount++] = l;
            cout << "  Listing " << l->getListingID() << " added to marketplace." << endl;
        } else {
            cout <<"  Marketplace is full!!" << endl;
        }
    }

    void addUser(User* u) {
        if (userCount < 20)
            users[userCount++] = u;
    }

    void displayAllListings() const {
        cout << " Total listings: " << listingCount << endl;
        cout << endl;
        for (int i = 0; i < listingCount; i++) {
            listings[i]->displayListing();
            cout << endl;
        }
    }

    void searchByPrice(double maxPrice) const {
        cout << " Vehicles under Rs." << maxPrice << ":" << endl;
        bool found = false;
        for (int i = 0; i < listingCount; i++) {
            if (listings[i]->getVehicle()->getPrice() <= maxPrice) {
                listings[i]->displayListing();
                found = true;
            }
        }
        if (!found) cout << " No vehicles are available from this price range." << endl;
    }

    void searchByCity(string cityName) const {
        cout << "  Listings in " << cityName << ":" << endl;
        bool found = false;
        for (int i = 0; i < listingCount; i++) {
            if (listings[i]->getCity() == cityName) {
                listings[i]->displayListing();
                found = true;
            }
        }
        if (!found) cout << "No listings found in " << cityName << "." << endl;
    }

    void searchByCompany(string comp) const {
        cout << "  Listings for " << comp << ":" << endl;
        bool found = false;
        for (int i = 0; i < listingCount; i++) {
            if (listings[i]->getVehicle()->getCompany() == comp) {
                listings[i]->displayListing();
                found = true;
            }
        }
        if (!found) cout << "No listings found for " << comp << "." << endl;
    }

    void searchByYear(int yr) const {
        cout << "  Listings from year " << yr << ":" << endl;
        bool found = false;
        for (int i = 0; i < listingCount; i++) {
            if (listings[i]->getVehicle()->getYear() == yr) {
                listings[i]->displayListing();
                found = true;
            }
        }
        if (!found) cout << " No listings found for year " << yr << "." << endl;
    }

    void searchByMileage(int maxMileage) const {
        cout << " Vehicles with mileage under " << maxMileage << " km:" << endl;
        bool found = false;
        for (int i = 0; i < listingCount; i++) {
            if (listings[i]->getVehicle()->getMileage() <= maxMileage) {
                listings[i]->displayListing();
                found = true;
            }
        }
        if (!found) cout << " No vehicles found under this mileage." << endl;
    }

    void approveAllPending() {
        cout << "  Approving all pending listings..." << endl;
        for (int i = 0; i < listingCount; i++) {
            if (listings[i]->isPending())
                listings[i]->approveListing();
        }
    }
};
int Marketplace::totalMarketplaces = 0;

int main() {

    cout << "============================================" << endl;
    cout << "        PAKWHEELS - VEHICLE MARKETPLACE         " << endl;
    cout << "============================================" << endl;

    Marketplace market("PakWheels.pk", "Pakistan");
    cout << endl;
    cout << "  Platform : " << market.getPlatformName() << endl;
    cout << "  Location : " << market.getLocation() << endl;

    cout << endl;
    cout << "--------------------------------------------" << endl;
    cout << "  BUYER REGISTRATION                        " << endl;
    cout << "--------------------------------------------" << endl;

    Buyer b1(001, "Hamna Azhar", "Hamna@gmail.com", "03112958300", "Hyderabad", 4000000);
    Buyer b2(002, "Palwasha Azhar", "pallo@gmail.com", "03009867673", "Karachi", 2000000);
    b1.displayProfile();
    cout << endl;
    b2.displayProfile();

    market.addUser(&b1);
    market.addUser(&b2);

    cout << endl;
    cout << "--------------------------------------------" << endl;
    cout << "  SELLER REGISTRATION                       " << endl;
    cout << "--------------------------------------------" << endl;

    Seller s1(2001, "Hassan Raheem", "hassan@gmail.com", "03001112342", "Lahore", 4.8);
    Seller s2(2002, "Bilal Abbas", "bilal@gmail.com", "030099956568", "Karachi", 4.2);
    s1.displaySellerInfo();
    cout << endl;
    s2.displaySellerInfo();

    market.addUser(&s1);
    market.addUser(&s2);

    cout << endl;
    cout << "--------------------------------------------" << endl;
    cout << "  VEHICLE LISTINGS                          " << endl;
    cout << "--------------------------------------------" << endl;

    CarDetail cd1("Petrol", "Manual", "White", 4, 14.0, true);
    CarDetail cd2("Diesel", "Automatic", "Black", 4, 11.0, true);
    CarDetail cd3("Petrol", "Manual", "Red", 4, 13.5, false);

    Car car1(3001, "Toyota", "Corolla", 2020, 3200000, 45000, 1800, "Sedan", 5, cd1);
    Car car2(3002, "Honda", "Civic", 2019, 4500000, 60000, 1500, "Sedan", 5, cd2);
    Car car3(3003, "Suzuki", "Alto", 2021, 1850000, 30000, 660, "Hatchback", 4, cd3);
    Bike bike1(3004, "Yamaha", "YBR125", 2022, 280000, 15000, 125, "Sports", "Self Start", 5);

    cout << endl;
    car1.displayCarInfo();
    cout << endl;
    car2.displayCarInfo();
    cout << endl;
    car3.displayCarInfo();
    cout << endl;
    bike1.displayBikeInfo();

    cout << endl;
    cout << "--------------------------------------------" << endl;
    cout << "  VEHICLE CONDITION AND FUEL CHECK          " << endl;
    cout << "--------------------------------------------" << endl;

    car1.checkCondition();
    car2.checkCondition();
    car3.checkCondition();
    bike1.checkCondition();
    cout << endl;
    car1.showFuelInfo();
    car2.showFuelInfo();
    cout << endl;
    cout << "  Toyota Corolla tax estimate  : Rs." << car1.calculateTax() << endl;
    cout << "  Honda Civic tax estimate     : Rs." << car2.calculateTax() << endl;
    cout << "  Suzuki Alto reg fee          : Rs." << car3.calculateRegistrationFee() << endl;
    cout << "  Yamaha license required      : " << (bike1.requiresLicense() ? "Yes" : "No") << endl;
    cout << "  Yamaha fuel efficiency est.  : " << bike1.estimateFuelEfficiency() << " km/l" << endl;

    cout << endl;
    cout << "--------------------------------------------" << endl;
    cout << "  CREATING LISTINGS                         " << endl;
    cout << "--------------------------------------------" << endl;

    Listing l1(4001, &car1, "Lahore", "2026-05-10");
    Listing l2(4002, &car2, "Karachi", "2026-05-12");
    Listing l3(4003, &car3, "Lahore", "2026-05-14");
    Listing l4(4004, &bike1, "Islamabad", "2025-03-16");

    cout << endl;
    s1.addListing(&l1);
    s1.addListing(&l3);
    s2.addListing(&l2);
    s2.addListing(&l4);

    cout << endl;
    cout << "--------------------------------------------" << endl;
    cout << "  ADMIN PANEL                               " << endl;
    cout << "--------------------------------------------" << endl;

    Admin admin1(1001, "Usman Khan", "usman@pakwheels.pk", "0333567676677", "Karachi", 3, "adminhehe");
    cout << endl;
    admin1.displayProfile();
    cout << endl;
    admin1.approveListing(&l1);
    admin1.approveListing(&l2);
    admin1.approveListing(&l3);
    admin1.removeListing(&l4);
    cout << endl;
    cout << "  --- Admin Report ---" << endl;
    admin1.generateReport();
    Admin::showAdminCount();

    cout << endl;
    cout << "--------------------------------------------" << endl;
    cout << "  MARKETPLACE - ALL LISTINGS                " << endl;
    cout << "--------------------------------------------" << endl;

    market.addListing(&l1);
    market.addListing(&l2);
    market.addListing(&l3);
    cout << endl;
    market.displayAllListings();

    cout << "--------------------------------------------" << endl;
    cout << "  SEARCH - By Price (under Rs.3500000)      " << endl;
    cout << "--------------------------------------------" << endl;
    market.searchByPrice(3500000);

    cout << endl;
    cout << "--------------------------------------------" << endl;
    cout << "  SEARCH - By City (Lahore)                 " << endl;
    cout << "--------------------------------------------" << endl;
    market.searchByCity("Lahore");

    cout << endl;
    cout << "--------------------------------------------" << endl;
    cout << "  SEARCH - By Company (Honda)               " << endl;
    cout << "--------------------------------------------" << endl;
    market.searchByCompany("Honda");

    cout << endl;
    cout << "--------------------------------------------" << endl;
    cout << "  SEARCH - By Year (2020)                   " << endl;
    cout << "--------------------------------------------" << endl;
    market.searchByYear(2020);

    cout << endl;
    cout << "--------------------------------------------" << endl;
    cout << "  SEARCH - By Mileage (under 50000 km)      " << endl;
    cout << "--------------------------------------------" << endl;
    market.searchByMileage(50000);

    cout << endl;
    cout << "--------------------------------------------" << endl;
    cout << "  BUYER FAVOURITES                          " << endl;
    cout << "--------------------------------------------" << endl;

    Favourite fav1(6001, &car1, "2026-05-01", true, "Top choice");
    Favourite fav2(6002, &car2, "2026-05-03", false, "Backup option");

    b1.addToFavourites(&fav1);
    b1.addToFavourites(&fav2);
    cout << endl;
    b1.displayFavourites();
    cout << endl;
    fav1.toggleAlert();
    b1.removeFromFavourites(1);
    cout << endl;
    b1.displayFavourites();

    cout << endl;
    cout << "--------------------------------------------" << endl;
    cout << "  BUDGET SEARCH                             " << endl;
    cout << "--------------------------------------------" << endl;

    Vehicle* allVehicles[4] = { &car1, &car2, &car3, &bike1 };
    cout << endl;
    b1.searchByBudget(allVehicles, 4);
    cout << endl;
    b2.searchByBudget(allVehicles, 4);

    cout << endl;
    cout << "--------------------------------------------" << endl;
    cout << "  MESSAGING AREA      " << endl;
    cout << "--------------------------------------------" << endl;

    cout << endl;
    b1.sendMessage(&s1, "Corolla avaiable hai ?");
    b2.sendMessage(&s2, "Can you lower the price of the Civic pls?");

    Message msg1(7001, &b1, &s1, "I want a test drive arranged please .");
    cout << endl;
    msg1.sendMessage();
    msg1.markSeen();
    msg1.displayMessage();
    msg1.deleteMessage();

    cout << endl;
    cout << "--------------------------------------------" << endl;
    cout << "  SELLER UPDATES                            " << endl;
    cout << "--------------------------------------------" << endl;

    cout << endl;
    s1.updateListingPrice(0, 3100000);
    s1.viewMyListings();

    cout << endl;
    cout << "--------------------------------------------" << endl;
    cout << "  VEHICLE INSPECTIONS                       " << endl;
    cout << "--------------------------------------------" << endl;

    Inspection insp1(8001, &car1, "Tariq Sahabb", 8.5, 9.0, 7.5, false, "Engine tou theek hai, minor interior wear.");
    Inspection insp2(8002, &car2, "Kamran Sheikh", 7.0, 6.5, 8.0, false, "Slight rust on body panels.");

    cout << endl;
    insp1.displayReport();
    cout << endl;
    insp2.displayReport();
    cout << endl;
    insp1.certifyVehicle();
    insp2.certifyVehicle();
    cout << endl;
    cout << "  Corolla overall score : " << insp1.calculateOverallScore() << "/10" << endl;
    cout << "  Civic overall score   : " << insp2.calculateOverallScore() << "/10" << endl;
    cout << "  Corolla passing       : " << (insp1.isPassing() ? "Yes" : "No") << endl;

    cout << endl;
    cout << "============================================" << endl;
    cout << "  SYSTEM STATISTICS                         " << endl;
    cout << "============================================" << endl;
    cout << "  Total Vehicles    : " << Vehicle::getTotalVehicles() << endl;
    cout << "  Total Listings    : " << Listing::getTotalListings() << endl;
    cout << "  Total Users       : " << User::getTotalUsers() << endl;
    cout << "  Total Messages    : " << Message::getTotalMessages() << endl;
    cout << "  Total Favourites  : " << Favourite::getTotalFavourites() << endl;
    cout << "  Total Inspections : " << Inspection::getTotalInspections() << endl;
    Marketplace::showMarketplaceCount();

    cout << endl;
    cout << "============================================" << endl;
    cout << "     Thank you for using PakWheels.pk! :)     " << endl;
    cout << "============================================" << endl;

    return 0;
}