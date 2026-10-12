#pragma once

#include "Carriage.h"

class SeatingCarriage : public Carriage {
  private:
    int rowsCount;

  public:
    SeatingCarriage();
    SeatingCarriage(int carriageNumber, int rows);

    int getRowsCount() const;
    void setRowsCount(int rows);

    bool operator==(const Carriage &other) const override;

    void printVirtualInfo(std::ostream &os) const override;
    void inputVirtualData(std::istream &is) override;
};