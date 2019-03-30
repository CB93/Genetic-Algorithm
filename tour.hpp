//
// Created by caleb on 3/9/2019.
//

#ifndef ASSIGNMENT2_TOUR_HPP
#define ASSIGNMENT2_TOUR_HPP

#include "city.hpp"

using namespace std;

class tour {
private:
    // Represents the total distance of the tour
    int fitness;
    // Represents the entire tour and the cities within the tour
    vector<city *> tourOfCities;

public:

    /**
     * Tour Constructor
     * @param cityList
     */
    explicit tour(vector<city> &cityList) {
        tourOfCities = generateTour(cityList);
        fitness = calculateTourFitness();

    }

    /**
     * Special constructor for Merged tours
     * @param cityList vector<city *>
     */
    explicit tour(vector<city *> &cityList) {
        tourOfCities = cityList;
        fitness = calculateTourFitness();

    }

    /**
     * Copy Constructor for tour class
     * @param a tour object
     */
    tour(const tour &a) = default;

    /**
     * Destructor
     */
    virtual ~tour();

    /**
     * // Generates a tour based on random cities
     * @param a vector<city>
     * @return vector<city *>
     */
    vector<city *> generateTour(vector<city> a);

    /**
     * Calculating the Distance between two X coordinates and two Y coordinates
     * @param xCoor1 float
     * @param yCoor1 float
     * @param xCoor2 float
     * @param yCoor2 float
     * @return float (Represented as tour fitness)
     */
    float distanceFormula(float xCoor1, float yCoor1, float xCoor2, float yCoor2);

    /**
     * Gets all of the cities in the entire tour and calculates the distance between
     * @return int
     */
    int calculateTourFitness();

    /**
     * Overloaded output operator for tour class
     * @param out
     * @param tour
     * @return os stream
     */
    friend std::ostream &operator<<(std::ostream &out, const tour &tour);



    /*
     * Getters and Setters
     */

    /**
     * Getter for TourOfCities data member
     * @return vector<city *>
     */
    const vector<city *> &getTourOfCities() const;

    /**
     * Getter for fitness data member
     * @return int
     */
    int getFitness() const;


};


#endif //ASSIGNMENT2_TOUR_HPP
