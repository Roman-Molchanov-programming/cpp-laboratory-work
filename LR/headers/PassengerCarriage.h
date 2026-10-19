#pragma once

#include "Carriage.h"

class PassengerCarriage : public Carriage {
  private:
    int lowerSeats;
    int upperSeats;

  public:
    PassengerCarriage();
    PassengerCarriage(std::string_view carriageType, int carriageNumber, int lower, int upper);

    int getLowerSeats() const;
    int getUpperSeats() const;
    int getTotalSeats() const override;

    void setLowerSeats(int lower);
    void setUpperSeats(int upper);

    void printVirtualInfo(std::ostream &os) const override;
    void inputVirtualData(std::istream &is) override;

  protected:
    bool isEqual(const Carriage &other) const override;
};