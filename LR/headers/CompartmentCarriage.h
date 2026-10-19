#pragma once

#include "Carriage.h"
#include "SeatConfig.h"

class CompartmentCarriage : public Carriage {
  private:
    SeatConfig seats; // Конфигурация мест (нижние/верхние)

  public:
    CompartmentCarriage();
    CompartmentCarriage(int carriageNumber, int lower = 18, int upper = 18);

    const SeatConfig &getSeats() const;
    void setSeats(const SeatConfig &newSeats);

    void printVirtualInfo(std::ostream &os) const override;
    void inputVirtualData(std::istream &is) override;

  protected:
    bool isEqual(const Carriage &other) const override;
};