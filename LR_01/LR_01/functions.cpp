#include "headers.h"

// Методы Carriage

Carriage::Carriage() : type("Неизвестно"), number(0) {
}

Carriage::Carriage(std::string_view t, int num) : type(t), number(num) {
}

std::string Carriage::getType() const {
    return type;
}

int Carriage::getNumber() const {
    return number;
}

void Carriage::setType(std::string_view t) {
    type = t;
}

void Carriage::setNumber(int num) {
    number = num;
}

void Carriage::inputData() {
    int inputNum = 0;
    std::string inputType;

    std::cout << "Введите номер вагона: ";
    while (!(std::cin >> inputNum)) {
        std::cout << "Ошибка ввода! Введите числовой номер вагона: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    setNumber(inputNum);

    std::cin.ignore(10000, '\n');

    std::cout << "Введите тип вагона (Плацкарт, Купе, Сидячий): ";
    std::getline(std::cin, inputType);
    setType(inputType);
}

void Carriage::printInfo() const {
    std::cout << "  Вагон №" << number << " | Тип: " << type << "\n";
}

// Методы Train

Train::Train() : driver("Не назначен"), maxWagons(0) {
}

Train::Train(std::string_view d, int maxW) : driver(d), maxWagons(maxW) {
}

std::string Train::getDriver() const {
    return driver;
}

void Train::setDriver(std::string_view d) {
    driver = d;
}

int Train::getMaxWagons() const {
    return maxWagons;
}

void Train::setMaxWagons(int maxW) {
    maxWagons = maxW;
}

int Train::getCurrentWagonCount() const {
    return static_cast<int>(wagons.size());
}

void Train::inputData() {
    std::string inputDriver;
    int inputMaxW = 0;

    std::cout << "\n--- Настройка поезда ---\n";
    std::cout << "Введите ФИО машиниста: ";

    std::cin >> std::ws;
    std::getline(std::cin, inputDriver);
    setDriver(inputDriver);

    std::cout << "Введите максимальное количество вагонов: ";
    while (!(std::cin >> inputMaxW) || inputMaxW <= 0) {
        std::cout << "Ошибка ввода! Введите число больше 0: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    setMaxWagons(inputMaxW);

    std::cin.ignore(10000, '\n');
}

bool Train::addCarriage(const Carriage &carriage) {
    if (wagons.size() >= static_cast<size_t>(maxWagons)) {
        std::cout << "\n[Ошибка] Нельзя добавить вагон №" << carriage.getNumber()
                  << "! Достигнут лимит поезда (" << maxWagons << " ваг.).\n";
        return false;
    }
    wagons.push_back(carriage);
    std::cout << "\n[Успех] Вагон №" << carriage.getNumber() << " (" << carriage.getType()
              << ") добавлен в состав.\n";
    return true;
}

void Train::printInfo() const {
    std::cout << "\n---------------------------------------\n";
    std::cout << "Информация о поезде:\n";
    std::cout << "Машинист: " << driver << "\n";
    std::cout << "Загрузка: " << wagons.size() << " из " << maxWagons << " вагонов\n";
    std::cout << "Состав поезда:\n";

    if (wagons.empty()) {
        std::cout << "  (Вагоны отсутствуют)\n";
    } else {
        for (const auto &carriage : wagons) {
            carriage.printInfo();
        }
    }
    std::cout << "---------------------------------------\n";
}