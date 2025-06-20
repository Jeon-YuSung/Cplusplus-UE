#include<iostream>
using namespace std;

#ifndef 7-13_INTERFACE_H
#define 7-13_INTERFACE_H  

class Time{
  private:
    int hours;
    int minutes;
    int seconds;

    void normalize();

  public:
    Time(int hours, int minutes, int seconds);
    Time();
    ~Time();
    
    void print() const;
    void tick();

  };
  #endif
