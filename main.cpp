#include <iostream>
#include <list>
#include "city.hpp"
#include "tour.hpp"
#include "tourList.hpp"
#include "mergeTour.hpp"


int main() {
    // Create masterList of Cities
    vector<city> masterList = city::createList();

    // Creating tour from MasterList of Cities
    tourList OldtourList(masterList);

    tour *eliteTour = OldtourList.getElite(); // Keep elite tour to the side

    tourList temp;
    size_t iterations = 0;
    while (iterations != 1000) {
        temp = mergeTour::crossOverTours(OldtourList);

        if (temp.getElite()->getFitness() < eliteTour->getFitness()) {
            cout << "Found new elite after " << iterations << " iterations " << endl;
            break;
        }
        iterations++;
    }

    cout << "Old Elite Tour Fitness: " << eliteTour->getFitness() << endl;
    cout << "New Elite Tour Fitness: " << temp.getElite()->getFitness() << endl;


    return 0;
}






