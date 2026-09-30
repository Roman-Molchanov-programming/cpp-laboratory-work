#pragma once

#include <iostream>
#include <string>
#include <string_view>

class Carriage {
  private:
    std::string type;
    int number;

  public:
    Carriage();
    Carriage(std::string_view type, int number);

    [[nodiscard]] std::string getType() const;
    [[nodiscard]] int getNumber() const;

    void setType(std::string_view type);
    void setNumber(int number);

    void inputData();
    void printInfo() const;

    // Перегрузка операторов сравнения
    bool operator==(const Carriage &other) const;
    bool operator!=(const Carriage &other) const;
    bool operator<(const Carriage &other) const;
    bool operator>(const Carriage &other) const;
    bool operator<=(const Carriage &other) const;
    bool operator>=(const Carriage &other) const;

    // Дружественные операторы ввода/вывода
    friend std::ostream &operator<<(std::ostream &os, const Carriage &carriage);
    friend std::istream &operator>>(std::istream &is, Carriage &carriage);
};