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