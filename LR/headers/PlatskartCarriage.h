#pragma once

#include "PassengerCarriage.h"

class PlatskartCarriage : public PassengerCarriage {
  private:
    int sideLowerSeats;
    int sideUpperSeats;

  public:
    PlatskartCarriage();
    PlatskartCarriage(int carriageNumber, int lower = 18, int upper = 18, int sLower = 9,
                      int sUpper = 9);

    int getSideLowerSeats() const;
    int getSideUpperSeats() const;
    int getTotalSeats() const override;

    void setSideLowerSeats(int sLower);
    void setSideUpperSeats(int sUpper);

    void printVirtualInfo(std::ostream &os) const override;
    void inputVirtualData(std::istream &is) override;

  protected:
    bool isEqual(const Carriage &other) const override;
};