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
    virtual ~Carriage() = default;

    std::string getType() const;
    int getNumber() const;

    void setType(std::string_view newType);
    void setNumber(int newNumber);

    virtual void inputData();
    virtual void printInfo() const;

    bool operator==(const Carriage &other) const {
        return this->isEqual(other);
    }

    auto operator<=>(const Carriage &other) const = default;

    friend std::ostream &operator<<(std::ostream &os, const Carriage &carriage) {
        carriage.printVirtualInfo(os);
        return os;
    }

    virtual void printVirtualInfo(std::ostream &os) const;

    friend std::istream &operator>>(std::istream &is, Carriage &carriage) {
        carriage.inputVirtualData(is);
        return is;
    }

    virtual void inputVirtualData(std::istream &is);

  protected:
    virtual bool isEqual(const Carriage &other) const {
        return this->type == other.type && this->number == other.number;
    }
};