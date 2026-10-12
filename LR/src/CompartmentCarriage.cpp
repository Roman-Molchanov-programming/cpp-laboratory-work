#include "../headers/CompartmentCarriage.h"

using namespace std;

CompartmentCarriage::CompartmentCarriage() : Carriage("Купе", 0), compartmentsCount(9) {
}

CompartmentCarriage::CompartmentCarriage(int carriageNumber, int compartments)
    : Carriage("Купе", carriageNumber), compartmentsCount(compartments) {
}

int CompartmentCarriage::getCompartmentsCount() const {
    return compartmentsCount;
}
void CompartmentCarriage::setCompartmentsCount(int compartments) {
    compartmentsCount = compartments;
}

bool CompartmentCarriage::operator==(const Carriage &other) const {
    if (!Carriage::operator==(other))
        return false;
    const auto *c = dynamic_cast<const CompartmentCarriage *>(&other);
    return c != nullptr && this->compartmentsCount == c->compartmentsCount;
}

void CompartmentCarriage::printVirtualInfo(ostream &os) const {
    os << "  Вагон Купе №" << number << " | Купешек в вагоне: " << compartmentsCount;
}

void CompartmentCarriage::inputVirtualData(istream &is) {
    Carriage::inputVirtualData(is);
    cout << "Введите количество купе: ";
    while (!(is >> compartmentsCount) || compartmentsCount <= 0) {
        cout << "Ошибка! Введите положительное число купе: ";
        is.clear();
        is.ignore(10000, '\n');
    }
    is.ignore(10000, '\n');
}