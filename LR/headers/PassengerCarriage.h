#pragma once

#include "Carriage.h"

class PassengerCarriage : public Carriage {
  protected:
    int lowerSeats;
    int upperSeats;

  public:
    PassengerCarriage();
    PassengerCarriage(std::string_view carriageType, int carriageNumber, int lower, int upper);

    int getLowerSeats() const;
    int getUpperSeats() const;

    void setLowerSeats(int lower);
    void setUpperSeats(int upper);

    void inputVirtualData(std::istream &is) override;
};