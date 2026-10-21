#include "../headers/PlatskartCarriage.h"

using namespace std;

PlatskartCarriage::PlatskartCarriage()
    : PassengerCarriage("Плацкарт", 0, 18, 18), sideLowerSeats(9), sideUpperSeats(9) {
}

PlatskartCarriage::PlatskartCarriage(int carriageNumber, int sideSeats)
    : PassengerCarriage("Плацкарт", carriageNumber, 18, 18), sideLowerSeats(sideSeats / 2),
      sideUpperSeats(sideSeats - (sideSeats / 2)) {
}

PlatskartCarriage::PlatskartCarriage(int carriageNumber, int lower, int upper, int sideLower,
                                     int sideUpper)
    : PassengerCarriage("Плацкарт", carriageNumber, lower, upper), sideLowerSeats(sideLower),
      sideUpperSeats(sideUpper) {
}

int PlatskartCarriage::getSideLowerSeats() const {
    return sideLowerSeats;
}
int PlatskartCarriage::getSideUpperSeats() const {
    return sideUpperSeats;
}

void PlatskartCarriage::setSideLowerSeats(int sideLower) {
    sideLowerSeats = sideLower;
}
void PlatskartCarriage::setSideUpperSeats(int sideUpper) {
    sideUpperSeats = sideUpper;
}

string PlatskartCarriage::getComfortCategory() const {
    return "Стандарт (Плацкарт)";
}

int PlatskartCarriage::calculateTotalSeats() const {
    return lowerSeats + upperSeats + sideLowerSeats + sideUpperSeats;
}

void PlatskartCarriage::printVirtualInfo(ostream &os) const {
    os << "  Вагон Плацкарт №" << getNumber() << " | Категория: " << getComfortCategory()
       << " | Всего мест: " << calculateTotalSeats() << " (Основные: " << lowerSeats << "/"
       << upperSeats << ", Боковые: " << sideLowerSeats << "/" << sideUpperSeats << ")";
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