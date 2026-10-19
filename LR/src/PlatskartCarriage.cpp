#include "../headers/PlatskartCarriage.h"

using namespace std;

PlatskartCarriage::PlatskartCarriage()
    : PassengerCarriage("Плацкарт", 0, 18, 18), sideLowerSeats(9), sideUpperSeats(9) {
}

PlatskartCarriage::PlatskartCarriage(int carriageNumber, int lower, int upper, int sLower,
                                     int sUpper)
    : PassengerCarriage("Плацкарт", carriageNumber, lower, upper), sideLowerSeats(sLower),
      sideUpperSeats(sUpper) {
}

int PlatskartCarriage::getSideLowerSeats() const {
    return sideLowerSeats;
}
int PlatskartCarriage::getSideUpperSeats() const {
    return sideUpperSeats;
}

int PlatskartCarriage::getTotalSeats() const {
    return PassengerCarriage::getTotalSeats() + sideLowerSeats + sideUpperSeats;
}

void PlatskartCarriage::setSideLowerSeats(int sLower) {
    sideLowerSeats = sLower;
}
void PlatskartCarriage::setSideUpperSeats(int sUpper) {
    sideUpperSeats = sUpper;
}

bool PlatskartCarriage::isEqual(const Carriage &other) const {
    if (!PassengerCarriage::isEqual(other)) {
        return false;
    }
    const auto *p = dynamic_cast<const PlatskartCarriage *>(&other);
    return p != nullptr && this->sideLowerSeats == p->sideLowerSeats &&
           this->sideUpperSeats == p->sideUpperSeats;
}

void PlatskartCarriage::printVirtualInfo(ostream &os) const {
    os << "  Вагон Плацкарт №" << getNumber() << " | Нижних: " << getLowerSeats()
       << ", Верхних: " << getUpperSeats() << " | Боковых нижних: " << sideLowerSeats
       << ", Боковых верхних: " << sideUpperSeats;
}

void PlatskartCarriage::inputVirtualData(istream &is) {
    PassengerCarriage::inputVirtualData(is);
    cout << "Введите количество боковых нижних мест: ";
    while (!(is >> sideLowerSeats) || sideLowerSeats < 0) {
        cout << "Ошибка! Введите корректное число: ";
        is.clear();
        is.ignore(10000, '\n');
    }
    cout << "Введите количество боковых верхних мест: ";
    while (!(is >> sideUpperSeats) || sideUpperSeats < 0) {
        cout << "Ошибка! Введите корректное число: ";
        is.clear();
        is.ignore(10000, '\n');
    }
    is.ignore(10000, '\n');
}