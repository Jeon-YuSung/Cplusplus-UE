#pragma once
#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <string> 
#include <cassert>
using namespace std;

//추상 클래스 Vehicle 정의

class Vehicle {

public:
    virtual Vehicle* clone() const = 0;
    virtual ~Vehicle() {}
};

//car 구체 클래스
class Car : public Vehicle {

private:
    string model;
    string color;
public:
    Car(string model, string color);
    Car(const Car& car);
    Car* clone() const;

};


//Truck 구체 클래스 
class Truck : public Vehicle
{
private:
    string size;
    string color;
public:
    Truck(string size, string color);
    Truck(const Truck& turck);
    Truck* clone() const;
};
#endif
