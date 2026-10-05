#pragma once

#include <compare>
#include <iostream>
#include <string>
#include <string_view>

class Carriage {
  private:
    std::string type;
    int number;

  public:
    Carriage();
    Carriage(std::string_view carriageType, int carriageNumber);

    std::string getType() const;
    int getNumber() const;

    void setType(std::string_view newType);
    void setNumber(int newNumber);

    void inputData();
    void printInfo() const;

    auto operator<=>(const Carriage &other) const = default;

    friend std::ostream &operator<<(std::ostream &os, const Carriage &carriage);
    friend std::istream &operator>>(std::istream &is, Carriage &carriage);
};