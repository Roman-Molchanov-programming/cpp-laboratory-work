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

void PassengerCarriage::setLowerSeats(int lower) {
    lowerSeats = lower;
}
void PassengerCarriage::setUpperSeats(int upper) {
    upperSeats = upper;
}

void PassengerCarriage::inputVirtualData(istream &is) {
    cout << "Введите номер вагона: ";
    int inputNum = 0;
    while (!(is >> inputNum)) {
        cout << "Ошибка! Введите числовой номер: ";
        is.clear();
        is.ignore(10000, '\n');
    }
    setNumber(inputNum);

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