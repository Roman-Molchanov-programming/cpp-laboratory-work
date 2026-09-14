#pragma once

#include "Carriage.h"
#include <memory>
#include <vector>

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