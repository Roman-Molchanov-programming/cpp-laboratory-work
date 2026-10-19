#include "../headers/CompartmentCarriage.h"

using namespace std;

CompartmentCarriage::CompartmentCarriage() : Carriage("Купе", 0), seats(18, 18) {
}

CompartmentCarriage::CompartmentCarriage(int carriageNumber, int lower, int upper)
    : Carriage("Купе", carriageNumber), seats(lower, upper) {
}

const SeatConfig &CompartmentCarriage::getSeats() const {
    return seats;
}

void CompartmentCarriage::setSeats(const SeatConfig &newSeats) {
    seats = newSeats;
}

bool CompartmentCarriage::isEqual(const Carriage &other) const {
    if (this->getType() != other.getType() || this->getNumber() != other.getNumber()) {
        return false;
    }
    const auto *c = dynamic_cast<const CompartmentCarriage *>(&other);
    return c != nullptr && this->seats == c->seats;
}

void CompartmentCarriage::printVirtualInfo(ostream &os) const {
    os << "  Вагон Купе №" << getNumber() << " | Места: [" << seats << "]";
}

void CompartmentCarriage::inputVirtualData(istream &is) {
    Carriage::inputVirtualData(is);
    cout << "Настройка мест в купе:\n";
    is >> seats;
}