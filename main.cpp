#include <iostream>
#include <list>
#include "city.hpp"
#include "tour.hpp"
#include "tourList.hpp"
#include "mergeTour.hpp"
#include "mutate.hpp"
#include "constants.hpp"
#include "geneticAlgorithm.hpp"
#include <vector>


int main() {
    // Create masterList of Cities
    vector<city> masterList = city::createList();

    // Creating tour list from MasterList of Cities
    tourList tourList1(masterList);

    tour *eliteTour = tourList1.getElite(); // Keep elite tour to the side

    geneticAlgorithm::Algorithm(eliteTour, tourList1);

    return 0;
}










