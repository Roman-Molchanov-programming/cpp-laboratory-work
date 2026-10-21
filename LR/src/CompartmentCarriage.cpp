#include "../headers/CompartmentCarriage.h"

using namespace std;

CompartmentCarriage::CompartmentCarriage() : PassengerCarriage("Купе", 0, 18, 18) {
}

CompartmentCarriage::CompartmentCarriage(int carriageNumber)
    : PassengerCarriage("Купе", carriageNumber, 18, 18) {
}

CompartmentCarriage::CompartmentCarriage(int carriageNumber, int lower, int upper)
    : PassengerCarriage("Купе", carriageNumber, lower, upper) {
}

int CompartmentCarriage::getCompartmentsCount() const {
    return getLowerSeats() / 2;
}

string CompartmentCarriage::getComfortCategory() const {
    return "Комфорт (Купе)";
}

int CompartmentCarriage::calculateTotalSeats() const {
    return getLowerSeats() + getUpperSeats();
}

void CompartmentCarriage::printVirtualInfo(ostream &os) const {
    os << "  Вагон Купе №" << getNumber() << " | Категория: " << getComfortCategory()
       << " | Купе: " << getCompartmentsCount() << " | Всего мест: " << calculateTotalSeats()
       << " (Нижних: " << getLowerSeats() << ", Верхних: " << getUpperSeats() << ")";
}