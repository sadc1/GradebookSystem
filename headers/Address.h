#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>
#include <sstream>
using namespace std;

class Address {
    private:
        string str;
        string city;
        string state;
        int zip;
        string parsed;
    public:
        Address() {str = "default"; city = "default"; state = "default"; zip = 0;}
        Address(string parsed) : parsed(parsed) {
            istringstream iss(parsed);
            iss >> str >> city >> state >> zip;
        }
        Address(string street, string city, string state, int zip) : str(street), city(city), state(state), zip(zip) {}
        Address(string street, string city, int zip) : str(street), city(city), zip(zip) {}
        string getStreet() {return str;}
        string getCity() {return city;}
        string getState() {return state;}
        int getZipcode() {return zip;}
};

#endif