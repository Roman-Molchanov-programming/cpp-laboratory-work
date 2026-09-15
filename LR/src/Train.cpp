#include "../headers/Train.h"

using namespace std;

Train::Train() : driver("Не назначен"), maxWagons(0) {
}

Train::Train(string_view d, int maxW) : driver(d), maxWagons(maxW) {
}

string Train::getDriver() const {
    return driver;
}

void Train::setDriver(string_view d) {
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

std::vector<Carriage> &Train::getWagons() {
    return wagons;
}

const std::vector<Carriage> &Train::getWagons() const {
    return wagons;
}

void Train::inputData() {
    string inputDriver;
    int inputMaxW = 0;

    cout << endl << "--- Настройка поезда ---" << endl;
    cout << "Введите ФИО машиниста: ";

    cin >> ws;
    getline(cin, inputDriver);
    setDriver(inputDriver);

    cout << "Введите максимальное количество вагонов: ";
    while (!(cin >> inputMaxW) || inputMaxW <= 0) {
        cout << "Ошибка ввода! Введите число больше 0: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    setMaxWagons(inputMaxW);

    cin.ignore(10000, '\n');
}

bool Train::addCarriage(const Carriage &carriage) {
    if (wagons.size() >= static_cast<size_t>(maxWagons)) {
        cout << endl
             << "Не удалось добавить вагон №" << carriage.getNumber()
             << ": достигнут лимит поезда (" << maxWagons << " ваг.)" << endl;
        return false;
    }
    wagons.push_back(carriage);
    cout << endl
         << "Вагон №" << carriage.getNumber() << " (" << carriage.getType()
         << ") успешно добавлен в состав." << endl;
    return true;
}

void Train::printInfo() const {
    cout << endl << "---------------------------------------" << endl;
    cout << "Информация о поезде:" << endl;
    cout << "Машинист: " << driver << endl;
    cout << "Загрузка: " << wagons.size() << " из " << maxWagons << " вагонов" << endl;
    cout << "Состав поезда:" << endl;

    if (wagons.empty()) {
        cout << "  (Вагоны отсутствуют)" << endl;
    } else {
        for (const auto &carriage : wagons) {
            carriage.printInfo();
        }
    }
    cout << "---------------------------------------" << endl;
}