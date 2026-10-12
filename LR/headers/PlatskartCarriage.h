#pragma once

#include "Carriage.h"

class PlatskartCarriage : public Carriage {
  private:
    int sideSeatsCount;

  public:
    PlatskartCarriage();
    PlatskartCarriage(int carriageNumber, int sideSeats);

    int getSideSeatsCount() const;
    void setSideSeatsCount(int sideSeats);

    void printVirtualInfo(std::ostream &os) const override;
    void inputVirtualData(std::istream &is) override;

  protected:
    bool isEqual(const Carriage &other) const override;
};