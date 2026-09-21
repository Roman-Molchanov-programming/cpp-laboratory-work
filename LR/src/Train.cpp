#include "../headers/Train.h"

using namespace std;

Train::Train() : driver("Не назначен"), maxCarriages(0) {
}

Train::Train(string_view d, int maxC) : driver(d), maxCarriages(maxC) {
}

string Train::getDriver() const {
    return driver;
}

void Train::setDriver(string_view d) {
    driver = d;
}

int Train::getMaxCarriages() const {
    return maxCarriages;
}

void Train::setMaxCarriages(int maxC) {
    maxCarriages = maxC;
}

int Train::getCurrentCarriageCount() const {
    return static_cast<int>(carriages.size());
}

std::vector<Carriage> &Train::getCarriages() {
    return carriages;
}

const std::vector<Carriage> &Train::getCarriages() const {
    return carriages;
}

void Train::inputData() {
    string inputDriver;
    int inputMaxC = 0;

    cout << endl << "--- Настройка поезда ---" << endl;
    cout << "Введите ФИО машиниста: ";

    cin >> ws;
    getline(cin, inputDriver);
    setDriver(inputDriver);

    cout << "Введите максимальное количество вагонов: ";
    while (!(cin >> inputMaxC) || inputMaxC <= 0) {
        cout << "Ошибка ввода! Введите число больше 0: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    setMaxCarriages(inputMaxC);

    cin.ignore(10000, '\n');
}

bool Train::addCarriage(const Carriage &carriage) {
    if (carriages.size() >= static_cast<size_t>(maxCarriages)) {
        cout << endl
             << "Не удалось добавить вагон: достигнут лимит поезда (" << maxCarriages << " ваг.)"
             << endl;
        return false;
    }
    carriages.push_back(carriage);
    cout << endl << "Вагон успешно добавлен в состав." << endl;
    return true;
}

void Train::printInfo() const {
    cout << endl << "---------------------------------------" << endl;
    cout << "Информация о поезде:" << endl;
    cout << "Машинист: " << driver << endl;
    cout << "Загрузка: " << carriages.size() << " из " << maxCarriages << " вагонов" << endl;
    cout << "Состав поезда:" << endl;

    if (carriages.empty()) {
        cout << "  (Вагоны отсутствуют)" << endl;
    } else {
        for (const auto &carriage : carriages) {
            carriage.printInfo();
        }
    }
    cout << "---------------------------------------" << endl;
}

Train &Train::operator-=(int carriageNumber) {
    for (auto it = carriages.begin(); it != carriages.end(); ++it) {
        if (it->getNumber() == carriageNumber) {
            carriages.erase(it);
            cout << "Вагон успешно удален из поезда!" << endl;
            return *this;
        }
    }

    cout << "Вагон с указанным номером не найден в составе поезда!" << endl;
    return *this;
}