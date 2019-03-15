//
// Created by caleb on 3/13/2019.
//

#ifndef ASSIGNMENT2_MUTATE_HPP
#define ASSIGNMENT2_MUTATE_HPP


#include "tourList.hpp"

class mutate {
private:

public:

    static void mutateList(vector<city *> &cityList);

    static tourList getMutableCities(tourList &tourList1);


    static float getChance();
};


#endif //ASSIGNMENT2_MUTATE_HPP
