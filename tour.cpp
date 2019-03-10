//
// Created by caleb on 3/9/2019.
//

#include "tour.hpp"
#include <cmath>
#include "constants.hpp"

using namespace std;


vector<city *> tour::generateTour(vector<city> cityList) {
    vector<city *> tour;
    random_device ranDevice;
    mt19937 gen(ranDevice());
    for (size_t i = 0; i < constants::CITIES_IN_TOUR - 1; i++) {

        uniform_int_distribution<int> distribution(0, (int) cityList.size() - 1);
        int ran = distribution(gen);
        city *randomCity = new city(cityList.at(ran));
        tour.push_back(randomCity);
        cityList.erase(cityList.begin() + ran);
    }

    // Inserts first City into position of last index of vector to simulate tour
    tour.push_back(tour.at(0));
    return tour;
}


int tour::calculateTourFitness() {
    float tourFitness = 0;
    for (size_t i = 0; i < constants::CITIES_IN_TOUR - 1; i++) {

        tourFitness += distanceFormula(tourOfCities.at(i)->getXcoordinate(), tourOfCities.at(i + 1)->getXcoordinate(),
                                       tourOfCities.at(i)->getYcoordinate(), tourOfCities.at(i + 1)->getYcoordinate());
    }
    return static_cast<int>(tourFitness);
}


float tour::distanceFormula(float xCoor1, float yCoor1, float xCoor2, float yCoor2) {
    return sqrtf(powf((xCoor2 - xCoor1), 2) + powf((yCoor2 - yCoor1), 2));
}

tour::~tour() = default;

std::ostream &operator<<(std::ostream &out, const tour &tour) {

    for (size_t i = 0; i < constants::CITIES_IN_TOUR; i++) {
        out << "Name: " << tour.getTourOfCities().at(i)->getName() << "\n"
            << "Xcoordinate: " << tour.getTourOfCities().at(i)->getXcoordinate() << "\n"
            << "Ycoordinate: " << tour.getTourOfCities().at(i)->getYcoordinate() << endl;

    }
    return out;
}










/**
 * Getters and Setters
 */

// Getter for tourOfCities data member
const vector<city *> &tour::getTourOfCities() const {
    return tourOfCities;
}

// Setter for tourOfCities data member
void tour::setTourOfCities(const vector<city *> &tourOfCities) {
    tour::tourOfCities = tourOfCities;
}

// Getter for fitness data member
int tour::getFitness() const {
    return fitness;
}

// Setter for fitness data member
void tour::setFitness(int fitness) {
    tour::fitness = fitness;
}



