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

    void printVirtualInfo(std::ostream &os) const override;
    void inputVirtualData(std::istream &is) override;

  protected:
    bool isEqual(const Carriage &other) const override;
};