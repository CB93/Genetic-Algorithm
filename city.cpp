//
// Created by caleb on 3/8/2019.
//
#include <random>
#include <iostream>
#include "city.hpp"
#include "citynames.hpp"
#include "constants.hpp"

using namespace std;

city &city::operator=(city city) {
    mySwap(*this, city);
    return *this;
}

void mySwap(city &first, city &second) {

    swap(first.xCoordinate, second.xCoordinate); // Using std::swap
    swap(first.yCoordinate, second.yCoordinate); // Using std::swap
    swap(first.name, second.name); // Using std::swap

}



string city::getRandomName(mt19937 &dev) {

    // Random number generator
    uniform_int_distribution<int> distribution(0, (int) cityNames.size() -
                                                  1); // distribution in range [0, size of vector -1]

    // random number
    int ran = distribution(dev);
    string randomName = cityNames.at(ran);
    cityNames.erase(cityNames.begin() + ran); // Deleting element with random number

    return randomName;
}


float city::getRandomX(mt19937 &dev) {

    uniform_real_distribution<float> distribution(numeric_limits<float>::min(), 999);
    return distribution(dev);
}

float city::getRandomY(mt19937 &dev) {

    uniform_real_distribution<float> distribution(numeric_limits<float>::min(), 999);
    return distribution(dev);
}


vector<city> city::createList() {
    vector<city> masterList;

    for (int i = 0; i < constants::CITIES_IN_TOUR; i++) {
        city temp;
        masterList.push_back(temp);
    }
    return masterList;
}

city::~city() = default;


/**
 * Getters and Setters
 */


float city::getXcoordinate() const {
    return xCoordinate;
}

void city::setXcoordinate(float xCoordinate) {
    city::xCoordinate = xCoordinate;
}

float city::getYcoordinate() const {
    return yCoordinate;
}

void city::setYcoordinate(float yCoordinate) {
    city::yCoordinate = yCoordinate;
}

const string &city::getName() const {
    return name;
}

void city::setName(const string &name) {
    city::name = name;
}

bool city::operator==(const city &rhs) const {
    return xCoordinate == rhs.xCoordinate &&
           yCoordinate == rhs.yCoordinate &&
           name == rhs.name;
}

bool city::operator!=(const city &rhs) const {
    return !(rhs == *this);
}

ostream &operator<<(ostream &os, const city &city1) {

    os << "name: " << city1.name << endl
    <<"xCoordinate: " << city1.xCoordinate << endl
    <<"yCoordinate: " << city1.yCoordinate;
    return os;
}











