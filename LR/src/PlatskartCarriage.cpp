#include "../headers/PlatskartCarriage.h"

using namespace std;

PlatskartCarriage::PlatskartCarriage() : Carriage("Плацкарт", 0), sideSeatsCount(18) {
}

PlatskartCarriage::PlatskartCarriage(int carriageNumber, int sideSeats)
    : Carriage("Плацкарт", carriageNumber), sideSeatsCount(sideSeats) {
}

int PlatskartCarriage::getSideSeatsCount() const {
    return sideSeatsCount;
}
void PlatskartCarriage::setSideSeatsCount(int sideSeats) {
    sideSeatsCount = sideSeats;
}

bool PlatskartCarriage::operator==(const Carriage &other) const {
    if (!Carriage::operator==(other))
        return false;
    const auto *p = dynamic_cast<const PlatskartCarriage *>(&other);
    return p != nullptr && this->sideSeatsCount == p->sideSeatsCount;
}

void PlatskartCarriage::printVirtualInfo(ostream &os) const {
    os << "  Вагон Плацкарт №" << number << " | Боковых мест: " << sideSeatsCount;
}

void PlatskartCarriage::inputVirtualData(istream &is) {
    Carriage::inputVirtualData(is);
    cout << "Введите количество боковых мест: ";
    while (!(is >> sideSeatsCount) || sideSeatsCount < 0) {
        cout << "Ошибка! Введите корректное число мест: ";
        is.clear();
        is.ignore(10000, '\n');
    }
    is.ignore(10000, '\n');
}