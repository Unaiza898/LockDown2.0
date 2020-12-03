#pragma once
#ifndef LOCATION_H
#define LOCATION_H

#include "header.h"
enum Site { testing = 1, treatment, isolation };
class Location
{
private:
    string name = "";
    string address = "";
    string phoneNumber = "";
    string openingTime = "8:00 AM";
    string closingTime = "8:00 PM";
    Site SiteType = testing;
public:
    Location();
    Location(string name, string address, string phoneNumber, string openingTime, string closingTime, Site SiteType);

    void setName(string name);
    string getName()const;
    void setAddress(string address);
    string getAddress()const;
    void setPhoneNumber(string phoneNumber);
    string getPhoneNumber()const;
    void setOpeningTime(string openingTime);
    string getOpeningTime()const;
    void setClosingTime(string closingTime);
    string getClosingTime()const;
    void setSiteType(Site SiteType);
    Site getSiteType()const;

    //Need other functions
};
Location::Location() {}

Location::Location(string name, string address, string phoneNumber, string openingTime, string closingTime, Site SiteType) {


    this->name = name;
    this->address = address;
    this->phoneNumber = phoneNumber;
    this->openingTime = openingTime;
    this->closingTime = closingTime;
    this->SiteType = SiteType;

}

void Location::setName(string name)
{
    this->name = name;
}

string Location::getName()const
{
    return this->name;
}

void Location::setAddress(string address)
{
    this->address = address;
}

string Location::getAddress()const
{
    return this->address;
}

void Location::setPhoneNumber(string phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

string Location::getPhoneNumber()const
{
    return this->phoneNumber;
}

void Location::setOpeningTime(string openingTime)
{
    this->openingTime = openingTime;
}

string Location::getOpeningTime()const
{
    return this->openingTime;
}

void Location::setClosingTime(string closingTime)
{
    this->closingTime = closingTime;
}

string Location::getClosingTime()const
{
    return this->closingTime;
}

void Location::setSiteType(Site SiteType)
{
    this->SiteType = SiteType;
}

Site Location::getSiteType()const
{
    return this->SiteType;
}

#endif