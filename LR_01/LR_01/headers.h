#pragma once

#include <Windows.h>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

class Carriage {
  private:
    std::string type;
    int number;

  public:
    Carriage();
    Carriage(std::string_view t, int num);

    std::string getType() const;
    int getNumber() const;

    void setType(std::string_view t);
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
    Train(std::string_view d, int maxW);

    std::string getDriver() const;
    void setDriver(std::string_view d);

    int getMaxWagons() const;
    void setMaxWagons(int maxW);

    int getCurrentWagonCount() const;

    void inputData();
    bool addCarriage(const Carriage &carriage);
    void printInfo() const;
};