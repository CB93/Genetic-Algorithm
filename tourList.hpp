//
// Created by caleb on 3/9/2019.
//

#ifndef ASSIGNMENT2_TOURLIST_HPP
#define ASSIGNMENT2_TOURLIST_HPP


#include "tour.hpp"

class tourList {
private:
    // Represents list off all tours, these tours contain cities with randomly generated
    // data members
    vector<tour *> list;
    // Represents the tour within the list that has the best fitness
    tour *elite;
public:
    explicit tourList(vector<city> &cityList) {
        list = createTourList(cityList);
        elite = findElite();
    }

    // Creates a tourList. Takes in MasterList of cities and creates tours out of them
    // using the tours constructor. Pushes created tours into the tourList vector
    vector<tour *> createTourList(vector<city> cityList);

    // Finds the tour within the list that has the best fitness and insterts it into
    // the front of the list
    tour* findElite();

    // Overloaded insertion operator. TourList
    friend std::ostream &operator<<(std::ostream &out, const tourList &tourList);



    /*
     * Getters and Setters
     */

    // Getter for elite data member
    tour *getElite() const;

    // Setter for elite data member
    void setElite(tour *elite);

    // Getter for list data member
    const vector<tour *> &getList() const;

    // Setter for list data member
    void setList(const vector<tour *> &list);
};


#endif //ASSIGNMENT2_TOURLIST_HPP
