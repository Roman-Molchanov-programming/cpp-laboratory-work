#pragma once

#include "Carriage.h"
#include <memory>
#include <vector>

class Train {
  private:
    std::string driver;
    int maxCarriages;
    std::vector<Carriage> carriages;

  public:
    Train();
    Train(std::string_view d, int maxC);

    std::string getDriver() const;
    void setDriver(std::string_view d);

    int getMaxCarriages() const;
    void setMaxCarriages(int maxC);

    int getCurrentCarriageCount() const;
    std::vector<Carriage> &getCarriages();
    const std::vector<Carriage> &getCarriages() const;

    void inputData();
    bool addCarriage(const Carriage &carriage);
    void printInfo() const;

    Train &operator-=(int carriageNumber);
};