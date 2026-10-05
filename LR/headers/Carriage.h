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

    friend std::ostream &operator<<(std::ostream &os, const Carriage &carriage) {
        os << "  Вагон №" << carriage.number << " | Тип: " << carriage.type;
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Carriage &carriage) {
        int inputNum = 0;
        std::string inputType;

        std::cout << "Введите номер вагона: ";
        while (!(is >> inputNum)) {
            std::cout << "Ошибка ввода! Введите числовой номер вагона: ";
            is.clear();
            is.ignore(10000, '\n');
        }
        carriage.setNumber(inputNum);

        is.ignore(10000, '\n');

        std::cout << "Введите тип вагона (Плацкарт, Купе, Сидячий): ";
        std::getline(is, inputType);
        carriage.setType(inputType);

        return is;
    }
};