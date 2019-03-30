//
// Created by caleb on 3/14/2019.
//

#ifndef ASSIGNMENT2_GENETICALGORITHM_HPP
#define ASSIGNMENT2_GENETICALGORITHM_HPP


#include "tour.hpp"
#include "tourList.hpp"

class geneticAlgorithm {
private:
    /**
     * Takes the elite base tour and compares it against the newly create tourLists elite
     * Checks if there is any improvement within the algorithm
     * @param eliteTour
     * @param newElite
     * @return string
     */
    static string isImprovement(tour *eliteTour, int newElite);

/**
 * Gets the difference of improvement between the best tour and the base tour
 * @param best
 * @param eliteTour
 * @return
 */
    static double getDifference(double best, tour *eliteTour);

/**
 * Prints a final report
 * @param eliteTour : base tour
 * @param bestTour : best tour from algorithm
 * @param best : Best distance generated from the algorithm
 * @param iterations : How many iterations occurred in the alogorithm
 * @param improvementFactor : What is the improvement factor from base to best
 */
    static void
    printFinalReport(tour *eliteTour, tourList *bestTour, double best, size_t iterations, bool improvementFactor);


public:
    /**
     *  The entrance to the algorithm, takes the base tour and the Tourlist to be mutated and merged
     * @param eliteTour tour
     * @param tourList1 tourList
     */
    static void Algorithm(tour *eliteTour, tourList tourList1);

};


#endif //ASSIGNMENT2_GENETICALGORITHM_HPP
