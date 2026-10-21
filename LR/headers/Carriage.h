#pragma once

#include <compare>
#include <iostream>
#include <string>
#include <string_view>

class Carriage {
  protected:
    std::string type;
    int number;

  public:
    Carriage();
    Carriage(std::string_view carriageType, int carriageNumber);
    virtual ~Carriage() = default;

    std::string getType() const;
    int getNumber() const;

    void setType(std::string_view newType);
    void setNumber(int newNumber);

    virtual std::string getComfortCategory() const = 0;
    virtual int calculateTotalSeats() const = 0;
    virtual void printVirtualInfo(std::ostream &os) const = 0;
    virtual void inputVirtualData(std::istream &is) = 0;

    auto operator<=>(const Carriage &other) const = default;

    friend std::ostream &operator<<(std::ostream &os, const Carriage &carriage) {
        carriage.printVirtualInfo(os);
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Carriage &carriage) {
        carriage.inputVirtualData(is);
        return is;
    }
};