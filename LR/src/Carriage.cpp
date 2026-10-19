#include "../headers/Carriage.h"

using namespace std;

Carriage::Carriage() : type("Базовый вагон"), number(0) {
}

Carriage::Carriage(string_view carriageType, int carriageNumber)
    : type(carriageType), number(carriageNumber) {
}

string Carriage::getType() const {
    return this->type;
}
int Carriage::getNumber() const {
    return this->number;
}
void Carriage::setType(string_view newType) {
    this->type = newType;
}
void Carriage::setNumber(int newNumber) {
    this->number = newNumber;
}

void Carriage::inputData() {
    cin >> *this;
}
void Carriage::printInfo() const {
    cout << *this;
}

void Carriage::printVirtualInfo(std::ostream &os) const {
    os << "  Вагон №" << number << " | Тип: " << type;
}

void Carriage::inputVirtualData(std::istream &is) {
    int inputNum = 0;
    cout << "Введите номер вагона: ";
    while (!(is >> inputNum) || inputNum < 0) {
        cout << "Ошибка! Введите числовой номер вагона: ";
        is.clear();
        is.ignore(10000, '\n');
    }
    setNumber(inputNum);
    is.ignore(10000, '\n');
}