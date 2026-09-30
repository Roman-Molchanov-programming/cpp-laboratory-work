#include "../headers/Train.h"

using namespace std;

Train::Train() : driver("Не назначен"), maxCarriages(0) {
}

Train::Train(string_view driver, int maxCarriages) {
    this->driver = driver;
    this->maxCarriages = maxCarriages;
}

string Train::getDriver() const {
    return this->driver;
}

void Train::setDriver(string_view driver) {
    this->driver = driver;
}

int Train::getMaxCarriages() const {
    return this->maxCarriages;
}

void Train::setMaxCarriages(int maxCarriages) {
    this->maxCarriages = maxCarriages;
}

int Train::getCurrentCarriageCount() const {
    return static_cast<int>(this->carriages.size());
}

std::vector<Carriage> &Train::getCarriages() {
    return this->carriages;
}

const std::vector<Carriage> &Train::getCarriages() const {
    return this->carriages;
}

void Train::inputData() {
    cin >> *this;
}

bool Train::addCarriage(const Carriage &carriage) {
    if (this->carriages.size() >= static_cast<size_t>(this->maxCarriages)) {
        cout << "\nНе удалось добавить вагон №" << carriage.getNumber()
             << ": достигнут лимит поезда (" << this->maxCarriages << " ваг.)\n";
        return false;
    }
    this->carriages.push_back(carriage);
    cout << "\nВагон №" << carriage.getNumber() << " успешно добавлен в состав.\n";
    return true;
}

void Train::printInfo() const {
    cout << *this;
}

bool Train::operator==(const Train &other) const {
    return this->driver == other.driver;
}

bool Train::operator!=(const Train &other) const {
    return !(*this == other);
}

bool Train::operator<(const Train &other) const {
    return this->carriages.size() < other.carriages.size();
}

bool Train::operator>(const Train &other) const {
    return other < *this;
}

Train &Train::operator+=(const Carriage &carriage) {
    this->addCarriage(carriage);
    return *this;
}

Train &Train::operator-=(const Carriage &carriage) {
    for (auto it = this->carriages.begin(); it != this->carriages.end(); ++it) {
        if (*it == carriage) {
            this->carriages.erase(it);
            cout << "Вагон №" << carriage.getNumber() << " успешно удален из поезда!\n";
            return *this;
        }
    }
    cout << "Вагон №" << carriage.getNumber() << " не найден в составе поезда!\n";
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Train &train) {
    os << "\n---------------------------------------\n";
    os << "Информация о поезде:\n";
    os << "Машинист: " << train.driver << "\n";
    os << "Загрузка: " << train.carriages.size() << " из " << train.maxCarriages << " вагонов\n";
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

std::istream &operator>>(std::istream &is, Train &train) {
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

bool compareTrainCapacity(const Train &t1, const Train &t2) {
    return t1.maxCarriages == t2.maxCarriages;
}