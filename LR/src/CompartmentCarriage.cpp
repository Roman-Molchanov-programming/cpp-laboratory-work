#include "../headers/CompartmentCarriage.h"

using namespace std;

CompartmentCarriage::CompartmentCarriage() : PassengerCarriage("Купейный", 0, 18, 18) {
}

CompartmentCarriage::CompartmentCarriage(int carriageNumber, int lower, int upper)
    : PassengerCarriage("Купейный", carriageNumber, lower, upper) {
}

void CompartmentCarriage::printVirtualInfo(ostream &os) const {
    os << "  Вагон Купейный №" << getNumber() << " | Нижних: " << getLowerSeats()
       << ", Верхних: " << getUpperSeats();
}