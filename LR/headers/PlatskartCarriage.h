#pragma once

#include "Carriage.h"
#include "SeatConfig.h"

class PlatskartCarriage : public Carriage {
  private:
    PlatskartSeatConfig platskartSeats;     // Конфигурация мест (нижние/верхние/нижние боковые/верхние боковые)

  public:
    PlatskartCarriage();
    PlatskartCarriage(int carriageNumber, int mLower = 18, int mUpper = 18, int sLower = 9,
                      int sUpper = 9);

    const PlatskartSeatConfig &getPlatskartSeats() const;
    void setPlatskartSeats(const PlatskartSeatConfig &seats);

    void printVirtualInfo(std::ostream &os) const override;
    void inputVirtualData(std::istream &is) override;

  protected:
    bool isEqual(const Carriage &other) const override;
};