#include "headers.h"

// Методы Carriage

Carriage::Carriage() {
    type = "Неизвестно";
    number = 0;
}

Carriage::Carriage(string t, int num) {
    type = t;
    number = num;
}

string Carriage::getType() {
    return type;
}

int Carriage::getNumber() {
    return number;
}

void Carriage::setType(string t) {
    type = t;
}

void Carriage::setNumber(int num) {
    number = num;
}

void Carriage::inputData() {
    cout << "Введите номер вагона: ";
    cin >> number;
    cin >> ws;
    cout << "Введите тип вагона (Плацкарт, Купе, Сидячий): ";
    getline(cin, type);
}

void Carriage::printInfo() {
    cout << "  Вагон №" << number << " | Тип: " << type << "\n";
}

// Методы Train

Train::Train() {
    driver = "Не назначен";
    maxWagons = 0;
}

Train::Train(string d, int maxW) {
    driver = d;
    maxWagons = maxW;
}

string Train::getDriver() {
    return driver;
}

void Train::setDriver(string d) {
    driver = d;
}

int Train::getMaxWagons() {
    return maxWagons;
}

void Train::setMaxWagons(int maxW) {
    maxWagons = maxW;
}

int Train::getCurrentWagonCount() {
    return wagons.size();
}

void Train::inputData() {
    cout << "\n--- Настройка поезда ---\n";
    cout << "Введите ФИО машиниста: ";
    cin >> ws;
    getline(cin, driver);

    cout << "Введите максимальное количество вагонов: ";
    cin >> maxWagons;
}

bool Train::addCarriage(Carriage carriage) {
    if (wagons.size() >= static_cast<size_t>(maxWagons)) {
        cout << "\n[Ошибка] Нельзя добавить вагон №" << carriage.getNumber()
             << "! Достигнут лимит поезда (" << maxWagons << " ваг.).\n";
        return false;
    }
    wagons.push_back(carriage);
    cout << "\n[Успех] Вагон №" << carriage.getNumber() << " (" << carriage.getType()
         << ") добавлен в состав.\n";
    return true;
}

void Train::printInfo() {
    cout << "\n---------------------------------------\n";
    cout << "Информация о поезде:\n";
    cout << "Машинист: " << driver << "\n";
    cout << "Загрузка: " << wagons.size() << " из " << maxWagons << " вагонов\n";
    cout << "Состав поезда:\n";

    if (wagons.empty()) {
        cout << "  (Вагоны отсутствуют)\n";
    } else {
        for (size_t i = 0; i < wagons.size(); i++) {
            wagons[i].printInfo();
        }
    }
    cout << "---------------------------------------\n";
}