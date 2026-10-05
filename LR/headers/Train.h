#pragma once

#include "Carriage.h"
#include <compare>
#include <iostream>
#include <memory>
#include <vector>

class Train {
  private:
    std::string driver;
    int maxCarriages;
    std::vector<Carriage> carriages;

  public:
    Train();
    Train(std::string_view driverName, int maxCapacity);

    std::string getDriver() const;
    void setDriver(std::string_view newDriver);

    int getMaxCarriages() const;
    void setMaxCarriages(int newMaxCarriages);

    int getCurrentCarriageCount() const;
    std::vector<Carriage> &getCarriages();
    const std::vector<Carriage> &getCarriages() const;

    void inputData();
    bool addCarriage(const Carriage &carriage);
    void printInfo() const;

    bool operator==(const Train &other) const;
    std::strong_ordering operator<=>(const Train &other) const;

    Train &operator+=(const Carriage &carriage);
    Train &operator-=(const Carriage &carriage);

    friend std::ostream &operator<<(std::ostream &os, const Train &train);
    friend std::istream &operator>>(std::istream &is, Train &train);

    friend bool compareTrainCapacity(const Train &t1, const Train &t2);
};