//
// Created by caleb on 3/9/2019.
//

#include "tourList.hpp"
#include "constants.hpp"

// Creates a tourList. Takes in MasterList of cities and creates tours out of them
// using the tours constructor. Pushes created tours into the tourList vector
vector<tour *> tourList::createTourList(vector<city> cityList) {

    vector<tour *> tourList;

    for (int i = 0; i < constants::CITIES_IN_TOUR; i++) {
        tour *randomTour = new tour(cityList);
        tourList.push_back(randomTour);

    }


    return tourList;
}


std::ostream &operator<<(std::ostream &out, const tourList &tourList) {
    for (size_t i = 0; i < 32; i++) {
        out << "-------- TOUR #: " << (i + 1) << "  -------- " << endl;

        for (size_t j = 0; j < 32; j++) {

            out << "Name: " << tourList.getList().at(i)->getTourOfCities().at(j)->getName() << endl
                << "Xcoordinate: " << tourList.getList().at(i)->getTourOfCities().at(j)->getXcoordinate() << endl
                << "Ycoordinate: " << tourList.getList().at(i)->getTourOfCities().at(j)->getYcoordinate() << endl;

        }
        out << "Total Fitness :" << tourList.getList().at(i)->getFitness() << endl;
        out << "-------- END OF TOUR --------" << endl;
    }
    return out;
}

tour *tourList::findElite() {
    return nullptr;
}

/**
 * Getters and Setters
 */

// Setter for list data member
void tourList::setList(const vector<tour *> &list) {

    tourList::list = list;

}

// Getter for list data member
const vector<tour *> &tourList::getList() const {
    return list;
}

tour *tourList::getElite() const {
    return elite;
}

void tourList::setElite(tour *elite) {
    tourList::elite = elite;
}


