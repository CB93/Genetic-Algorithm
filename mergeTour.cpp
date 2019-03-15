//
// Created by caleb on 3/12/2019.
//

#include "mergeTour.hpp"
#include "constants.hpp"

tourList mergeTour::crossOverTours(tourList &oldTourList) {
    vector<tour *> mergedTours;
    for (size_t i = 0; i < oldTourList.getList().size(); i++) {

        // Creating a new cityList for a new tour
        vector<city *> cityList;

        // Slices first parent from the tourList and inserts it's portion into the cityList
        size_t randomParent = selectRandomNumber(1, constants::POPULATION_SIZE - 1);
        sliceParent1(cityList, oldTourList, randomParent);

        // Slices second parent from the tourList and inserts it's portion into the cityList
        randomParent = selectRandomNumber(1, constants::POPULATION_SIZE - 1);
        sliceParent2(cityList, oldTourList, randomParent);

        // Duplicating first city into last position to simulate a tour
        cityList.push_back(cityList.at(0));

        // Calling special tour constructor to create a tour from the merged cityList
        auto *tempTour1 = new tour(cityList);
        mergedTours.push_back(tempTour1);
    }

    // Calling special tour constructor to create a tour from the merged cityList
    tourList tourNew(mergedTours);

    return tourNew;


}


bool mergeTour::isExist(city const city1, vector<city *> const cityList) {
    for (size_t i = 0; i < cityList.size(); i++) {
        if (city1 == *cityList.at(i)) {
            return true;
        }
    }
    return false;
}

void mergeTour::sliceParent2(vector<city *> &cityList, tourList const &tourList, size_t const position) {
    size_t cityPosition = 0;
    while (cityList.size() != 31) {
        city *temp;
        temp = tourList.getList().at(position)->getTourOfCities().at(cityPosition);


        if (!mergeTour::isExist(*temp, cityList)) {

            cityList.push_back(temp);
        }

        cityPosition++;
    }
}

void mergeTour::sliceParent1(vector<city *> &cityList, tourList const &tourList, size_t const position) {

    // Getting Random number for the amount of tours to take from the 1st parent
    size_t initialParent_size = mergeTour::selectRandomNumber(0, constants::POPULATION_SIZE - 1);


    // Looping the amount of tours that it will take from the 1st parent
    for (size_t j = 0; j < initialParent_size; j++) {
        city *temp;
        temp = (tourList.getList().at(position)->getTourOfCities().at(j));
        cityList.push_back(temp);
    }
}


size_t mergeTour::selectRandomNumber(size_t start, size_t size) {
    random_device ranDevice;
    mt19937 gen(ranDevice());

    uniform_int_distribution<size_t> distribution(start, size);
    size_t ran = distribution(gen);

    return ran;
}






