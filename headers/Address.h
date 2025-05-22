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
        Address(string parsed) : parsed(parsed) { //One entire string read from the rest of the line after the first and last name, has spaces
            istringstream iss(parsed);
            iss >> str >> city >> state >> zip;
        }
        Address(string street, string city, string state, int zip) : str(street), city(city), state(state), zip(zip) {}
        Address(string street, string city, int zip) : str(street), city(city), zip(zip) {}
        string getStreet() {return str;}
        string getCity() {return city;}
        string getState() {return state;}
        string formattedAddress() {return str + " " + city + " " + state + " " + to_string(zip);}
        int getZipcode() {return zip;}
};

#endif