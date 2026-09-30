#pragma once

#include "Carriage.h"
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
    Train(std::string_view driver, int maxCarriages);

    [[nodiscard]] std::string getDriver() const;
    void setDriver(std::string_view driver);

    [[nodiscard]] int getMaxCarriages() const;
    void setMaxCarriages(int maxCarriages);

    [[nodiscard]] int getCurrentCarriageCount() const;
    std::vector<Carriage> &getCarriages();
    [[nodiscard]] const std::vector<Carriage> &getCarriages() const;

    void inputData();
    bool addCarriage(const Carriage &carriage);
    void printInfo() const;

    // Перегрузка операторов сравнения
    bool operator==(const Train &other) const;
    bool operator!=(const Train &other) const;
    bool operator<(const Train &other) const;
    bool operator>(const Train &other) const;

    // Перегрузка операторов += и -= для управления вагонами
    Train &operator+=(const Carriage &carriage);
    Train &operator-=(const Carriage &carriage);

    // Дружественные операторы ввода/вывода
    friend std::ostream &operator<<(std::ostream &os, const Train &train);
    friend std::istream &operator>>(std::istream &is, Train &train);

    // Дружественная функция с доступом к приватным данным
    friend bool compareTrainCapacity(const Train &t1, const Train &t2);
};