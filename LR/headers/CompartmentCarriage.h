#pragma once

#include "Carriage.h"

class CompartmentCarriage : public Carriage {
  private:
    int compartmentsCount;

  public:
    CompartmentCarriage();
    CompartmentCarriage(int carriageNumber, int compartments);

    int getCompartmentsCount() const;
    void setCompartmentsCount(int compartments);

    bool operator==(const Carriage &other) const override;

    void printVirtualInfo(std::ostream &os) const override;
    void inputVirtualData(std::istream &is) override;
};