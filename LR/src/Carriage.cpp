#include "../headers/Carriage.h"

using namespace std;

Carriage::Carriage() : type("Неизвестно"), number(0) {
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

ostream &operator<<(ostream &os, const Carriage &carriage) {
    os << "  Вагон №" << carriage.number << " | Тип: ";
    for (size_t i = 0; i < carriage.type.length(); ++i) {
        char c = carriage.type[i];
        if (c == '\n' || c == '\r') {
            os << '_';
        } else {
            os << c;
        }
    }
    return os;
}

istream &operator>>(istream &is, Carriage &carriage) {
    int inputNum = 0;
    string inputType;

    cout << "Введите номер вагона: ";
    while (!(is >> inputNum)) {
        cout << "Ошибка ввода! Введите числовой номер вагона: ";
        is.clear();
        is.ignore(10000, '\n');
    }
    carriage.setNumber(inputNum);

    is.ignore(10000, '\n');

    cout << "Введите тип вагона (Плацкарт, Купе, Сидячий): ";
    getline(is, inputType);
    carriage.setType(inputType);

    return is;
}