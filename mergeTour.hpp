//
// Created by caleb on 3/12/2019.
//

#ifndef ASSIGNMENT2_MERGETOUR_HPP
#define ASSIGNMENT2_MERGETOUR_HPP


#include "tourList.hpp"

class mergeTour {
private:
    static void sliceParent1(vector<city *> &cityList, tourList &tourList);

    static void sliceParent2(vector<city *> &cityList, tourList &tourList);

public:

    // Constructor
    // Tour for merged tours

    static int randomNumberGen();

    static vector<tour *> crossOverTours(tourList &tourList);

    static bool isExist(city city1, vector<city *> cityList);


};


#endif //ASSIGNMENT2_MERGETOUR_HPP
