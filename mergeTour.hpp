//
// Created by caleb on 3/12/2019.
//

#ifndef ASSIGNMENT2_MERGETOUR_HPP
#define ASSIGNMENT2_MERGETOUR_HPP


#include "tourList.hpp"

class mergeTour {
private:
    static void sliceParent1(vector<city *> &cityList,  tour * randomParent);

    static void sliceParent2(vector<city *> &cityList,  tour * randomParent);

    static size_t selectRandomNumber(size_t start, size_t size);

public:

    static tour *  findCurrentElite( vector<tour *> temp);

    static vector <tour *> selectRandomArray(tourList const &tourList);

    static tourList crossOverTours(tourList &tourList);

    static bool isExist(city city1, vector<city *> cityList);


};


#endif //ASSIGNMENT2_MERGETOUR_HPP
