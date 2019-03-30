//
// Created by caleb on 3/12/2019.
//

#ifndef ASSIGNMENT2_MERGETOUR_HPP
#define ASSIGNMENT2_MERGETOUR_HPP


#include "tourList.hpp"

class mergeTour {
private:

    /**
     *
     * @param tourList
     * @return
     */
    static vector<tour *> selectRandomArray(tourList const &tourList);

    /**
   * Selects a random number between 0 - 31 that will be used to extract
   * the initial amount of cities from the 1st chosen parent
   * @param start
   * @param size
   * @return size_t
   */
    static size_t selectRandomNumber(size_t start, size_t size);

    /**
     * Gets the 5 random potential parents, chooses 1 and takes a random amount
     * of cities from the chosen parent. Puts the extracted cities into a new tour
     * @param cityList
     * @param randomParent
     */
    static void sliceParent1(vector<city *> &cityList, tour *randomParent);

    /**
    * Gets the 5 random potential parents, chooses 1 and takes a random amount
    * of cities from the chosen parent. Puts the extracted cities into a new tour
    * @param cityList
    * @param randomParent
    */
    static void sliceParent2(vector<city *> &cityList, tour *randomParent);


public:
    /**
     * Finds the current elite from the newly created tour
     * @param temp
     * @return tour
     */
    static tour *findCurrentElite(vector<tour *> temp);


    /**
     * A loop composed of the functions within the mutate class
     * to properly cross the tour parents over. For ever iteration that occurs
     * a complete new tourList occurs
     * @param tourList
     * @return tourList
     */
    static tourList crossOverTours(tourList &tourList);

    /**
     * Used make sure there are no duplicate cities when extracting the 2nd parents
     * cities into the new tour.
     * @param city1
     * @param cityList
     * @return bool
     */
    static bool isExist(city city1, vector<city *> cityList);


};


#endif //ASSIGNMENT2_MERGETOUR_HPP
