//
// Created by caleb on 3/8/2019.
//

#ifndef ASSIGNMENT2_CITY_HPP
#define ASSIGNMENT2_CITY_HPP

#include <string>
#include <random>
#include <iostream>

using namespace std;

class city {
private:
    // Represents the X coordinate of the city
    float xCoordinate;
    // Represents the Y coordinate of the city
    float yCoordinate;
    // Represents the cities name
    string name;

    // Generates a random name from the cityNames.hpp list of Strings
    string getRandomName(mt19937 &dev);

    // Generates a random number between 0 and 1000
    float getRandomX(mt19937 &dev);

    // Generates a random number between 0 and 1000
    float getRandomY(mt19937 &dev);




public:

    // Constructor
    city() {
        random_device dev;
        mt19937 gen(dev());

        name = getRandomName(gen);
        xCoordinate = getRandomX(gen);
        yCoordinate = getRandomY(gen);
    }

    city &operator=(city city1);

    friend void mySwap(city &first, city &second);

    friend ostream &operator<<(ostream &os, const city &city1);

    bool operator==(const city &rhs) const;

    bool operator!=(const city &rhs) const;

    // Copy constructor
    city(const city &a) { name = a.name, xCoordinate = a.xCoordinate, yCoordinate = a.yCoordinate; }

    // Desctructor for city class
    virtual ~city();

    // Getter for xCoordinate data member
    float getXcoordinate() const;

    // Setter for xCoordinate data member
    void setXcoordinate(float xCoordinate);

    // Getter for yCoordinate data member
    float getYcoordinate() const;

    // Setter for yCoordinate data member
    void setYcoordinate(float yCoordinate);

    // Getter for name data member
    const string &getName() const;

    // Setter for name data member
    void setName(const string &name);

    static vector<city> createList();
};


#endif //ASSIGNMENT2_CITY_HPP
