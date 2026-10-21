#pragma once

#include "Carriage.h"

class SeatingCarriage : public Carriage {
  private:
    int rowsCount = 15;
    int seatsPerRow = 4;

  public:
    SeatingCarriage();
    SeatingCarriage(int carriageNumber);
    SeatingCarriage(int carriageNumber, int rows);
    SeatingCarriage(int carriageNumber, int rows, int seatsInRow);

    int getRowsCount() const;
    int getSeatsPerRow() const;

    void setRowsCount(int rows);
    void setSeatsPerRow(int seatsInRow);

    std::string getComfortCategory() const override;
    int calculateTotalSeats() const override;
    void printVirtualInfo(std::ostream &os) const override;
    void inputVirtualData(std::istream &is) override;
};