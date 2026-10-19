#pragma once

#include "PassengerCarriage.h"

class CompartmentCarriage : public PassengerCarriage {
  public:
    CompartmentCarriage();
    CompartmentCarriage(int carriageNumber, int lower = 18, int upper = 18);

    void printVirtualInfo(std::ostream &os) const override;
};