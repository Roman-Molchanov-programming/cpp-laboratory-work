#include "../headers/Train.h"

using namespace std;

Train::Train() : driver("Не назначен"), maxCarriages(0) {
}

Train::Train(string_view driverName, int maxCapacity)
    : driver(driverName), maxCarriages(maxCapacity) {
}

string Train::getDriver() const {
    return this->driver;
}

void Train::setDriver(string_view newDriver) {
    this->driver = newDriver;
}

int Train::getMaxCarriages() const {
    return this->maxCarriages;
}

void Train::setMaxCarriages(int newMaxCarriages) {
    this->maxCarriages = newMaxCarriages;
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
        cout << "\nНе удалось добавить вагон: достигнут лимит поезда (" << this->maxCarriages
             << " ваг.)\n";
        return false;
    }
    this->carriages.push_back(carriage);
    cout << "\nВагон успешно добавлен в состав.\n";
    return true;
}

void Train::printInfo() const {
    cout << *this;
}

bool Train::operator==(const Train &other) const {
    return this->driver == other.driver && this->maxCarriages == other.maxCarriages &&
           this->carriages == other.carriages;
}

std::strong_ordering Train::operator<=>(const Train &other) const {
    return this->carriages.size() <=> other.carriages.size();
}

Train &Train::operator+=(const Carriage &carriage) {
    this->addCarriage(carriage);
    return *this;
}

Train &Train::operator-=(const Carriage &carriage) {
    for (auto it = this->carriages.begin(); it != this->carriages.end(); ++it) {
        if (*it == carriage) {
            this->carriages.erase(it);
            cout << "Вагон успешно удален из поезда!\n";
            return *this;
        }
    }
    cout << "Вагон не найден в составе поезда!\n";
    return *this;
}

bool compareTrainCapacity(const Train &t1, const Train &t2) {
    return t1.maxCarriages == t2.maxCarriages;
}