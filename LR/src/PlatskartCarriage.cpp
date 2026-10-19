#include "../headers/PlatskartCarriage.h"

using namespace std;

PlatskartCarriage::PlatskartCarriage() : Carriage("Плацкарт", 0), platskartSeats(18, 18, 9, 9) {
}

PlatskartCarriage::PlatskartCarriage(int carriageNumber, int mLower, int mUpper, int sLower,
                                     int sUpper)
    : Carriage("Плацкарт", carriageNumber), platskartSeats(mLower, mUpper, sLower, sUpper) {
}

const PlatskartSeatConfig &PlatskartCarriage::getPlatskartSeats() const {
    return platskartSeats;
}

void PlatskartCarriage::setPlatskartSeats(const PlatskartSeatConfig &seats) {
    platskartSeats = seats;
}

bool PlatskartCarriage::isEqual(const Carriage &other) const {
    if (this->getType() != other.getType() || this->getNumber() != other.getNumber()) {
        return false;
    }
    const auto *p = dynamic_cast<const PlatskartCarriage *>(&other);
    return p != nullptr && this->platskartSeats == p->platskartSeats;
}

void PlatskartCarriage::printVirtualInfo(ostream &os) const {
    os << "  Вагон Плацкарт №" << getNumber() << " | Места: [" << platskartSeats << "]";
}

void PlatskartCarriage::inputVirtualData(istream &is) {
    Carriage::inputVirtualData(is);
    cout << "Настройка мест в плацкарте:\n";
    is >> platskartSeats;
}