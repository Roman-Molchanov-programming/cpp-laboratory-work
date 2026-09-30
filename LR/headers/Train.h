#pragma once

#include "Carriage.h"
#include <compare>
#include <iostream>
#include <memory>
#include <vector>

class Train {
  private:
    std::string driver;
    int maxCarriages;
    std::vector<Carriage> carriages;

  public:
    Train();
    Train(std::string_view driverName, int maxCapacity);

    std::string getDriver() const;
    void setDriver(std::string_view driver);

    int getMaxCarriages() const;
    void setMaxCarriages(int maxCarriages);

    int getCurrentCarriageCount() const;
    std::vector<Carriage> &getCarriages();
    const std::vector<Carriage> &getCarriages() const;

    void inputData();
    bool addCarriage(const Carriage &carriage);
    void printInfo() const;

    bool operator==(const Train &other) const;
    std::strong_ordering operator<=>(const Train &other) const;

    Train &operator+=(const Carriage &carriage);
    Train &operator-=(const Carriage &carriage);

    friend std::ostream &operator<<(std::ostream &os, const Train &train) {
        os << "\n---------------------------------------\n";
        os << "Информация о поезде:\n";
        os << "Машинист: " << train.driver << "\n";
        os << "Загрузка: " << train.carriages.size() << " из " << train.maxCarriages
           << " вагонов\n";
        os << "Состав поезда:\n";

        if (train.carriages.empty()) {
            os << "  (Вагоны отсутствуют)\n";
        } else {
            for (const auto &carriage : train.carriages) {
                os << carriage << "\n";
            }
        }
        os << "---------------------------------------\n";
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Train &train) {
        std::string inputDriver;
        int inputMaxC = 0;

        std::cout << "\n--- Настройка поезда ---\n";
        std::cout << "Введите ФИО машиниста: ";

        is >> std::ws;
        std::getline(is, inputDriver);
        train.setDriver(inputDriver);

        std::cout << "Введите максимальное количество вагонов: ";
        while (!(is >> inputMaxC) || inputMaxC <= 0) {
            std::cout << "Ошибка ввода! Введите число больше 0: ";
            is.clear();
            is.ignore(10000, '\n');
        }
        train.setMaxCarriages(inputMaxC);

        is.ignore(10000, '\n');
        return is;
    }

    friend bool compareTrainCapacity(const Train &t1, const Train &t2);
};