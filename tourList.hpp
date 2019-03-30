//
// Created by caleb on 3/9/2019.
//

#ifndef ASSIGNMENT2_TOURLIST_HPP
#define ASSIGNMENT2_TOURLIST_HPP


#include "tour.hpp"

class tourList {
private:
    // Represents list off all tours, these tours contain cities with randomly generated data members
    vector<tour *> list;
    // Represents the tour within the list that has the best fitness
    tour *elite;
public:
    /**
     * Constructor
     * @param cityList
     */
    explicit tourList(vector<city> &cityList) {
        list = createTourList(cityList);
        elite = findElite();
    }

    /**
     * Alternative constructor
     * @param tour
     */
    explicit tourList(vector<tour *> &tour) {
        list = tour;
        elite = findElite();
    }

    /**
     * Default constructor
     */
    tourList() = default;


    /**
     * Creates a tourList. Takes in MasterList of cities and creates tours out of them
     * using the tours constructor. Pushes created tours into the tourList vector
     * @param cityList
     * @return  vector<tour *>
     */
    vector<tour *> createTourList(vector<city> cityList);

    /**
     * Finds the tour within the list that has the best fitness and insterts it into
     * the front of the list
     * @return tour
     */
    tour *findElite();

    /**
     * Once elite is found using the findElite function. This function is called
     * to put the elite Tour to the front of the vector
     * @param elite_Position
     */
    void propagateElitetoTop(size_t elite_Position);

    /**
     * Overloaded insertion operator. TourList
     * @param out
     * @param tourList
     * @return os stream
     */
    friend std::ostream &operator<<(std::ostream &out, const tourList &tourList);



    /*
     * Getters and Setters
     */

    /**
     * Getter for elite data member
     * @return tour
     */
    tour *getElite() const;



    /**
     * Getter for list data member
     * @return vector<tour *>
     */
    const vector<tour *> &getList() const;


};


#endif //ASSIGNMENT2_TOURLIST_HPP
