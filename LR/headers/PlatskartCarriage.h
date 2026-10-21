#pragma once

#include "PassengerCarriage.h"

class PlatskartCarriage : public PassengerCarriage {
  private:
    int sideLowerSeats;
    int sideUpperSeats;

  public:
    PlatskartCarriage();
    PlatskartCarriage(int carriageNumber, int sideSeats);
    PlatskartCarriage(int carriageNumber, int lower, int upper, int sideLower, int sideUpper);

    int getSideLowerSeats() const;
    int getSideUpperSeats() const;

    void setSideLowerSeats(int sideLower);
    void setSideUpperSeats(int sideUpper);

    std::string getComfortCategory() const override;
    int calculateTotalSeats() const override;
    void printVirtualInfo(std::ostream &os) const override;
    void inputVirtualData(std::istream &is) override;
};