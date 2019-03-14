//
// Created by caleb on 3/12/2019.
//

#include "mergeTour.hpp"
#include "constants.hpp"

vector<tour *> mergeTour::crossOverTours(tourList &tourList) {
    tour *eliteTour = tourList.getElite(); // Keep elite tour to the side
    vector<city *> cityList; // Creating a new cityList for a new tour


    // Slices first parent from the tourList and inserts it's portion into the cityList
    sliceParent1(cityList, tourList);

    // Slices second parent from the tourList and inserts it's portion into the cityList
    sliceParent2(cityList, tourList);

    cityList.push_back(cityList.at(0)); // Duplicating first city into last position to simulate a tour

    // Calling special tour constructor to create a tour from the merged cityList
    tour tour1(cityList);
    cout << "Final List" << endl;
    cout << tour1 << endl;
    cout << cityList.size() << endl;


}

int mergeTour::randomNumberGen() {
    random_device ranDevice;
    mt19937 gen(ranDevice());
    uniform_int_distribution<int> distribution(0, constants::POPULATION_SIZE - 2);

    int ran = distribution(gen);

    cout << "Random Number for 1st parent";
    cout << ran << endl;
    return ran;
}


bool mergeTour::isExist(city const city1, vector<city *> const cityList) {
    for (size_t i = 0; i < cityList.size(); i++) {
        if (city1 == *cityList.at(i)) {
            return true;
        }
    }
    return false;
}

void mergeTour::sliceParent2(vector<city *> &cityList, tourList &tourList) {
    size_t cityPosition = 0;
    while (cityList.size() != 31) {
        city *temp;
        temp = tourList.getList().at(1)->getTourOfCities().at(cityPosition);


        if (!mergeTour::isExist(*temp, cityList)) {
            cout << *temp << endl;

            cityList.push_back(temp);
        }

        cityPosition++;
    }

}

void mergeTour::sliceParent1(vector<city *> &cityList, tourList &tourList) {

    // Getting Random number for the amount of tours to take from the 1st parent
    int initialParent_size = mergeTour::randomNumberGen();

    // Looping the amount of tours that it will take from the 1st parent
    for (int j = 0; j < initialParent_size; j++) {
        city *temp;
        temp = (tourList.getList().at(0)->getTourOfCities().at(j));
        cityList.push_back(temp);
    }
}




