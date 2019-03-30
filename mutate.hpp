//
// Created by caleb on 3/13/2019.
//

#ifndef ASSIGNMENT2_MUTATE_HPP
#define ASSIGNMENT2_MUTATE_HPP


#include "tourList.hpp"


class mutate {

private:
    // Keeps track of the number of mutations that occurred
    static int numberofMutations;

public:


    /**
     *  Holds the vector of cities that will be determined for mutation
     * @param cityList
     */
    static void mutateList(vector<city *> &cityList);

    /**
     *  Extracts the vector of cities from a tourList that will be determined for mutation
     * @param tourList1
     * @return tourList
     */
    static tourList getMutableCities(tourList &tourList1);

    /**
     *  Used to determine of 2 cities are going to be mutated. Random # between 0 - 100 is generated
     *  If number is below 16, cities are mutated
     * @return random Float value
     */
    static float getChance();

    /**
     * Getters for number of mutations instance data
     * @return int
     */
    static int getNumberofMutations();


};


#endif //ASSIGNMENT2_MUTATE_HPP
