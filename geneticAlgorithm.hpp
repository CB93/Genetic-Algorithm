//
// Created by caleb on 3/14/2019.
//

#ifndef ASSIGNMENT2_GENETICALGORITHM_HPP
#define ASSIGNMENT2_GENETICALGORITHM_HPP


#include "tour.hpp"
#include "tourList.hpp"

class geneticAlgorithm {
private:
    static string isImprovement(tour * eliteTour, int newElite);

    static double getDifference(double best, tour * eliteTour);

    static void printFinalReport(tour* eliteTour, tourList* temptour, double best);


public:
    static void Algorithm(tour * eliteTour, tourList tourList1);

};


#endif //ASSIGNMENT2_GENETICALGORITHM_HPP
