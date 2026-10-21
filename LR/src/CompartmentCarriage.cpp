#include "../headers/CompartmentCarriage.h"

using namespace std;

CompartmentCarriage::CompartmentCarriage() : PassengerCarriage("Купе", 0, 18, 18) {
}

CompartmentCarriage::CompartmentCarriage(int carriageNumber, int lower, int upper)
    : PassengerCarriage("Купе", carriageNumber, lower, upper) {
}

int CompartmentCarriage::getCompartmentsCount() const {
    return lowerSeats / 2;
}

string CompartmentCarriage::getComfortCategory() const {
    return "Комфорт (Купе)";
}

int CompartmentCarriage::calculateTotalSeats() const {
    return lowerSeats + upperSeats;
}

void CompartmentCarriage::printVirtualInfo(ostream &os) const {
    os << "  Вагон Купе №" << getNumber() << " | Категория: " << getComfortCategory()
       << " | Купе: " << getCompartmentsCount() << " | Всего мест: " << calculateTotalSeats()
       << " (Нижних: " << lowerSeats << ", Верхних: " << upperSeats << ")";
}