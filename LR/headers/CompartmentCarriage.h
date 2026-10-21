#pragma once

#include "PassengerCarriage.h"

class CompartmentCarriage : public PassengerCarriage {
  public:
    CompartmentCarriage();
    CompartmentCarriage(int carriageNumber, int lower = 18, int upper = 18);

    int getCompartmentsCount() const;

    std::string getComfortCategory() const override;
    int calculateTotalSeats() const override;
    void printVirtualInfo(std::ostream &os) const override;
};