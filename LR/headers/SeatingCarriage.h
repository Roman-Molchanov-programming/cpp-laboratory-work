#pragma once

#include "Carriage.h"

class SeatingCarriage : public Carriage {
  private:
    int rowsCount;
    int seatsPerRow;

  public:
    SeatingCarriage();
    SeatingCarriage(int carriageNumber, int rows, int perRow = 3);

    int getRowsCount() const;
    int getSeatsPerRow() const;
    int getTotalSeats() const override;
    void setRowsCount(int rows);
    void setSeatsPerRow(int perRow);

    void printVirtualInfo(std::ostream &os) const override;
    void inputVirtualData(std::istream &is) override;

  protected:
    bool isEqual(const Carriage &other) const override;
};