#include "../headers/Train.h"
#include <algorithm>

using namespace std;

Train::Train() : driver("Неизвестно"), maxCarriages(10) {
}

Train::Train(string_view driverName, int maxCapacity)
    : driver(driverName), maxCarriages(maxCapacity) {
}

string Train::getDriver() const {
    return driver;
}
void Train::setDriver(string_view newDriver) {
    driver = newDriver;
}

int Train::getMaxCarriages() const {
    return maxCarriages;
}
void Train::setMaxCarriages(int newMaxCarriages) {
    maxCarriages = newMaxCarriages;
}

int Train::getCurrentCarriageCount() const {
    return static_cast<int>(carriages.size());
}

Collection<shared_ptr<Carriage>> &Train::getCarriages() {
    return carriages;
}
const Collection<shared_ptr<Carriage>> &Train::getCarriages() const {
    return carriages;
}

void Train::inputData() {
    cin >> *this;
}

bool Train::addCarriage(const shared_ptr<Carriage> &carriage) {
    if (carriages.size() >= static_cast<size_t>(maxCarriages) || !carriage) {
        return false;
    }
    carriages.add(carriage);
    return true;
}

void Train::printInfo() const {
    cout << *this;
}

bool Train::operator==(const Train &other) const {
    if (driver != other.driver || carriages.size() != other.carriages.size()) {
        return false;
    }
    for (size_t i = 0; i < carriages.size(); ++i) {
        if (*carriages[i] != *other.carriages[i]) {
            return false;
        }
    }
    return true;
}

strong_ordering Train::operator<=>(const Train &other) const {
    return carriages.size() <=> other.carriages.size();
}

Train &Train::operator+=(const shared_ptr<Carriage> &carriage) {
    addCarriage(carriage);
    return *this;
}

int Train::operator-=(int carriageNumber) {
    return static_cast<int>(carriages.removeIf([carriageNumber](const shared_ptr<Carriage> &c) {
        return c && c->getNumber() == carriageNumber;
    }));
}

int Train::operator-=(const shared_ptr<Carriage> &carriage) {
    if (carriage) {
        return *this -= carriage->getNumber();
    }
    return 0;
}

int Train::operator-=(const Carriage &carriage) {
    return *this -= carriage.getNumber();
}

bool compareTrainCapacity(const Train &t1, const Train &t2) {
    return t1.carriages.size() < t2.carriages.size();
}