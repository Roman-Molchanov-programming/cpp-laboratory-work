#pragma once

#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>

class Carriage {
  private:
    std::string type;
    int number;

  public:
    Carriage();
    Carriage(const std::string &t, int num);

    std::string getType() const;
    int getNumber() const;

    void setType(const std::string &t);
    void setNumber(int num);

    void inputData();
    void printInfo() const;
};

class Train {
  private:
    std::string driver;
    int maxWagons;
    std::vector<Carriage> wagons;

  public:
    Train();
    Train(const std::string &d, int maxW);

    std::string getDriver() const;
    void setDriver(const std::string &d);

    int getMaxWagons() const;
    void setMaxWagons(int maxW);

    int getCurrentWagonCount() const;

    void inputData();
    bool addCarriage(const Carriage &carriage);
    void printInfo() const;
};