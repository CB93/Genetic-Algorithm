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

    // Constructor
    explicit tour(vector<city> &cityList) {
        tourOfCities = generateTour(cityList);
        fitness = calculateTourFitness();

    }


    // Copy Constructor
    tour(const tour &a) = default;

    // Destructor
    virtual ~tour();

    // Generates a tour based on random cities
    vector<city *> generateTour(vector<city> a);

    // Calculating the Distance between two X coordinates and two Y coordinates
    float distanceFormula(float xCoor1, float yCoor1, float xCoor2, float yCoor2);

    // Gets all of the cities in the entire tour and calculates the distance between
    int calculateTourFitness();

    // Overloaded insertion operator. tour
    friend std::ostream &operator<<(std::ostream &out, const tour &tour);











    /*
     * Getters and Setters
     */

    // Getter for TourOfCities data member
    const vector<city *> &getTourOfCities() const;

    // Getter for fitness data member
    int getFitness() const;

    // Setter for fitness data member
    void setFitness(int fitness);

    // Setter for TourOfCities data member
    void setTourOfCities(const vector<city *> &tourOfCities);


};


#endif //ASSIGNMENT2_TOUR_HPP
