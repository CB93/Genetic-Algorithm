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


    /**
     * Generates a random name from the cityNames.hpp list of Strings
     * @param dev
     * @return Random String for City name
     */
    string getRandomName(mt19937 &dev);

    /**
     *  Generates a random number between 0 and 1000
     * @param dev
     * @return Random Float value
     */
    float getRandomX(mt19937 &dev);

    /**
     * Generates a random number between 0 and 1000
     * @param dev
     * @return Random Float Value
     */
    float getRandomY(mt19937 &dev);




public:

    /**
     * Constructor
     */
    city() {
        random_device dev;
        mt19937 gen(dev());

        name = getRandomName(gen);
        xCoordinate = getRandomX(gen);
        yCoordinate = getRandomY(gen);
    }

    /**
     * Overloaded assignment operator
     * @param city
     * @return
     */
    city &operator=(city city1);

    /**
     * Swaps cities instance value
     * @param first city
     * @param second city
     */
    friend void mySwap(city &first, city &second);
    /**
     * Prints a formatted city objects data
     * @param os
     * @param city1
     * @return string output
     */
    friend ostream &operator<<(ostream &os, const city &city1);
    /**
     * Overloaded equality operator for city object
     * @param rhs
     * @return bool
     */
    bool operator==(const city &rhs) const;
    /**
     * Overloaded inequality operator for city object
     * @param rhs
     * @return bool
     */
    bool operator!=(const city &rhs) const;

    /**
     * Copy Constructor
     * @param a
     */
    city(const city &a) { name = a.name, xCoordinate = a.xCoordinate, yCoordinate = a.yCoordinate; }

    /**
     * Destructor for city class
     */
    virtual ~city();

    /**
     * Getter for xCoordinate data member
     * @return float, cities xCoordinate value
     */
    float getXcoordinate() const;

    /**
     * Getter for yCoordinate data member
     * @return float, cities yCoordinate value
     */
    float getYcoordinate() const;


    /**
     * Getter for name data member
     * @return string, cities name value
     */
    const string &getName() const;

    /**
     * static createList called by city object
     * @return vector<city>
     */
    static vector<city> createList();
};


#endif //ASSIGNMENT2_CITY_HPP
