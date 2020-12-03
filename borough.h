#pragma once
#ifndef BOROUGH_H
#define BOROUGH_H
#include "header.h"

class Borough
{
private:
    string name = "";
    int peopleInfected = 0;
    int population = 0;
    double percentageInfected = 0;
    //Need a dynamic array of Locations
public:
    Borough();
    Borough(string name, int peopleInfected);
    void setName(string name);
    string getName()const;
    void setPopulation(int population);
    int getPopulation()const;
    void setPeopleInfected(int peopleInfected);
    int getPeopleInfected()const;
    void setPercentageInfected(int percentageInfected);
    int getPercentageInfected()const;

    //Need other member functions
};


Borough::Borough() {}//Default constructor

Borough::Borough(string name, int peopleInfected)
{
    this->name = name;
    this->peopleInfected = peopleInfected;
    //use peopleInfected and population to calculate percentageInfected
}

void Borough::setName(string name)
{
    this->name = name;
}
string Borough::getName()const
{
    return this->name;
}
void Borough::setPopulation(int population)
{
    this->population = population;
}
int Borough::getPopulation()const
{
    return this->population;
}
void Borough::setPeopleInfected(int peopleInfected)
{
    this->peopleInfected = peopleInfected;
}
int Borough::getPeopleInfected()const
{
    return this->peopleInfected;
}
void Borough::setPercentageInfected(int percentageInfected)
{
    this->percentageInfected = percentageInfected;
}
int Borough::getPercentageInfected()const
{
    return this->percentageInfected;
}
//Other member functions
#endif