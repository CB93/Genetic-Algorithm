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

/**
 * Genetic algorithm assignment,
 * @return int
 */
int main() {

    // Create masterList of Cities
    vector<city> masterList = city::createList();

    // Creating tour list from MasterList of Cities
    tourList tourList1(masterList);

    // Keep elite tour to the side
    tour *eliteTour = tourList1.getElite();

    // Running the genetic algorithm, using the eliteTour as comparison
    // and the tourList from mutation / merging to generate a better fitness
    geneticAlgorithm::Algorithm(eliteTour, tourList1);

    return 0;
}










