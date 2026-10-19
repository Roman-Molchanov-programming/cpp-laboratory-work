#include "../headers/PassengerCarriage.h"

using namespace std;

PassengerCarriage::PassengerCarriage() : Carriage("Пассажирский", 0), lowerSeats(0), upperSeats(0) {
}

PassengerCarriage::PassengerCarriage(string_view carriageType, int carriageNumber, int lower,
                                     int upper)
    : Carriage(carriageType, carriageNumber), lowerSeats(lower), upperSeats(upper) {
}

int PassengerCarriage::getLowerSeats() const {
    return lowerSeats;
}
int PassengerCarriage::getUpperSeats() const {
    return upperSeats;
}
int PassengerCarriage::getTotalSeats() const {
    return lowerSeats + upperSeats;
}

void PassengerCarriage::setLowerSeats(int lower) {
    lowerSeats = lower;
}
void PassengerCarriage::setUpperSeats(int upper) {
    upperSeats = upper;
}

bool PassengerCarriage::isEqual(const Carriage &other) const {
    if (!Carriage::isEqual(other)) {
        return false;
    }
    const auto *p = dynamic_cast<const PassengerCarriage *>(&other);
    return p != nullptr && this->lowerSeats == p->lowerSeats && this->upperSeats == p->upperSeats;
}

void PassengerCarriage::printVirtualInfo(ostream &os) const {
    os << "  Вагон №" << getNumber() << " | Тип: " << getType() << " | Нижних: " << lowerSeats
       << ", Верхних: " << upperSeats;
}

void PassengerCarriage::inputVirtualData(istream &is) {
    Carriage::inputVirtualData(is);
    cout << "Введите количество нижних мест: ";
    while (!(is >> lowerSeats) || lowerSeats < 0) {
        cout << "Ошибка! Введите корректное число: ";
        is.clear();
        is.ignore(10000, '\n');
    }
    cout << "Введите количество верхних мест: ";
    while (!(is >> upperSeats) || upperSeats < 0) {
        cout << "Ошибка! Введите корректное число: ";
        is.clear();
        is.ignore(10000, '\n');
    }
    is.ignore(10000, '\n');
}