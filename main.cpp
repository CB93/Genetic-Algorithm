#include <iostream>
#include <list>
#include "city.hpp"
#include "tour.hpp"
#include "tourList.hpp"


int main() {
    // Create masterList of Cities
    vector<city> masterList = city::createList();

    // Creating tour from MasterList of Cities
    // tour tour(masterList);
    tourList tourList(masterList);


    cout << tourList;


            return 0;
         }




//    vector<city *> tourList = tour::generateTour(masterList, generator);


