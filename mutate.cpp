//
// Created by caleb on 3/13/2019.
//

#include "mutate.hpp"
#include "constants.hpp"
#include "city.hpp"

using namespace std;

tourList mutate::getMutableCities(tourList &tourList1) {
    vector<tour *> mutatedTours;

    for (size_t i = 0; i < constants::POPULATION_SIZE; i++) {
        vector<city *> cityList;


        cityList = tourList1.getList().at(i)->getTourOfCities();

        mutateList(cityList);

        auto *tempTour1 = new tour(cityList);
        mutatedTours.push_back(tempTour1);

    }
    tourList mutatedTourList(mutatedTours);

    return mutatedTourList;

}

void mutate::mutateList(vector<city *> &cityList) {

    for (size_t i = 0; i < constants::POPULATION_SIZE - 1; i++) {

        if (i == 31) {
            break;
        }
        if (getChance() < constants::MUTATION_CHANCE) {
            cout << "MUTATION OCCURED" << endl;
            iter_swap(cityList.begin() + i, cityList.begin() + (i + 1));

        }


    }


}


float mutate::getChance() {
    random_device ranDevice;
    mt19937 gen(ranDevice());
    uniform_real_distribution<float> distribution(numeric_limits<float>::min(), 100);


    return distribution(gen);

}

