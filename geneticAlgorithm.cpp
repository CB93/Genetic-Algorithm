//
// Created by caleb on 3/14/2019.
//

#include <iomanip>
#include "geneticAlgorithm.hpp"
#include "constants.hpp"
#include "mergeTour.hpp"
#include "mutate.hpp"

void geneticAlgorithm::Algorithm(tour *const eliteTour, tourList tourList1) {
    bool factor = false;
    size_t iterations = 0;
    tourList *tempCompare = nullptr;
    tourList *temp = nullptr;


    double best = eliteTour->getFitness();


    while (iterations != constants::ITERATION_LIMIT) {

        temp = new tourList;
        *temp = mergeTour::crossOverTours(tourList1);
        *temp = mutate::getMutableCities(*temp);

        cout << "Iteration #: " << iterations + 1 << endl;

        if (iterations == 0) {
            cout << "No comparison" << endl;
        } else {
            cout << isImprovement(eliteTour, tempCompare->getElite()->getFitness());

        }

        cout << "Elite of this Iteration: " << temp->getElite()->getFitness() << endl;

        if (temp->getElite()->getFitness() < best) {
            best = temp->getElite()->getFitness();
        }
        tempCompare = temp;

        cout << "Best distance so far: " << best << endl;

        if (temp->getElite()->getFitness() < best) {

        }

        if ((temp->getElite()->getFitness()) < (eliteTour->getFitness() * .70)) {
            cout << "\n\nFound new elite after " << iterations + 1 << " iterations " << endl;
            break;
        }
        iterations++;
    }

    if (iterations < constants::ITERATION_LIMIT) {
        factor;
    }
    printFinalReport(eliteTour, temp, best, iterations, factor);
}

string geneticAlgorithm::isImprovement(tour *const eliteTour, int newElite) {

    if (eliteTour->getFitness() > newElite) {
        return "Improvement over base\n";
    }
    return "No improvement over base\n";

}

void geneticAlgorithm::printFinalReport(tour *const eliteTour, tourList *temp, double best, size_t iterations,
                                        bool improvementFactor) {
    cout << "\n\n ***STATUS REPORT***" << endl;
    cout << "\nNumber of iterations occurred:" << iterations << endl;
    (improvementFactor ? cout << "\nImprovement factor of 30% was achieved" << endl : cout
            << "\nImprovement factor of 30% was not achieved" << endl);
    cout << "\nNumber of mutations occurred: " << mutate::getNumberofMutations() << endl;
    cout << "\nFitness from Base: " << eliteTour->getFitness() << endl;
    cout << "\nFitness from Best: " << best << " with a difference of: " << setprecision(3)
         << getDifference(best, eliteTour) << " %" << endl;
    cout << "\n\n ***Best Route***" << endl;
    cout << *(temp)->getElite() << endl;
    cout << "\n\n ***Base Route***" << endl;
    cout << *eliteTour << endl;
}

double geneticAlgorithm::getDifference(double best, tour *eliteTour) {
    return abs(((eliteTour->getFitness() - best) / ((eliteTour->getFitness() + best) / 2)) * 100);


}
