//
// Created by caleb on 3/14/2019.
//

#include <iomanip>
#include "geneticAlgorithm.hpp"
#include "constants.hpp"
#include "mergeTour.hpp"
#include "mutate.hpp"

void geneticAlgorithm::Algorithm(tour *const eliteTour, tourList tourList1) {

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

        cout << "Elite of Iteration: " << temp->getElite()->getFitness() << endl;

        if (temp->getElite()->getFitness() < best) {
            best = temp->getElite()->getFitness();
        }
        tempCompare = temp;

        if (temp->getElite()->getFitness() < best) {

        }

        if ((temp->getElite()->getFitness()) < (eliteTour->getFitness() * .70)) {
            cout << "\n\nFound new elite after " << iterations + 1 << " iterations " << endl;
            break;
        }
        iterations++;
    }

    printFinalReport(eliteTour, temp, best);
}

string geneticAlgorithm::isImprovement(tour *const eliteTour, int newElite) {

    if (eliteTour->getFitness() > newElite) {
        return "Improvement over base\n";
    }
    return "No improvement over base\n";

}

void geneticAlgorithm::printFinalReport(tour *const eliteTour, tourList *temp, double best) {
    cout << "\n\n ***STATUS REPORT***" << endl;
    cout << "\nNumber of mutations that occured: " << mutate::getNumberofMutations() << endl;
    cout << "\nOld Elite Tour Fitness: " << eliteTour->getFitness() << endl;
    cout << "\nBest fitness from Base:" << best <<  " with a difference of:" << setprecision(3) << getDifference(best,eliteTour)<< "%" << endl;
    cout << "\n\n ***Best Route***" << endl;
    cout << *(temp->getElite()) << endl;
}

double geneticAlgorithm::getDifference(double best, tour * eliteTour) {
return abs(((eliteTour->getFitness()- best) / ((eliteTour->getFitness() + best) / 2)) * 100) ;


}
