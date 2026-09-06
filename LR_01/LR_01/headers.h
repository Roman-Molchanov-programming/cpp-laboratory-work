#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

class Carriage {
  private:
    string type;
    int number;

  public:
    Carriage();
    Carriage(string t, int num);

    string getType();
    int getNumber();

    void setType(string t);
    void setNumber(int num);

    void inputData();
    void printInfo();
};

class Train {
  private:
    string driver;
    int maxWagons;
    vector<Carriage> wagons;

  public:
    Train();
    Train(string d, int maxW);

    string getDriver();
    void setDriver(string d);

    int getMaxWagons();
    void setMaxWagons(int maxW);

    int getCurrentWagonCount();

    void inputData();
    bool addCarriage(Carriage carriage);
    void printInfo();
};