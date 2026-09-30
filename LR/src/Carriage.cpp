#include "../headers/Carriage.h"

using namespace std;

Carriage::Carriage() : type("Неизвестно"), number(0) {
}

Carriage::Carriage(string_view type, int number) {
    this->type = type;
    this->number = number;
}

string Carriage::getType() const {
    return this->type;
}

int Carriage::getNumber() const {
    return this->number;
}

void Carriage::setType(string_view type) {
    this->type = type;
}

void Carriage::setNumber(int number) {
    this->number = number;
}

void Carriage::inputData() {
    cin >> *this;
}

void Carriage::printInfo() const {
    cout << *this;
}

bool Carriage::operator==(const Carriage &other) const {
    return this->number == other.number;
}

bool Carriage::operator!=(const Carriage &other) const {
    return !(*this == other);
}

bool Carriage::operator<(const Carriage &other) const {
    return this->number < other.number;
}

bool Carriage::operator>(const Carriage &other) const {
    return other < *this;
}

bool Carriage::operator<=(const Carriage &other) const {
    return !(*this > other);
}

bool Carriage::operator>=(const Carriage &other) const {
    return !(*this < other);
}

std::ostream &operator<<(std::ostream &os, const Carriage &carriage) {
    os << "  Вагон №" << carriage.number << " | Тип: " << carriage.type;
    return os;
}

std::istream &operator>>(std::istream &is, Carriage &carriage) {
    int inputNum = 0;
    std::string inputType;

    std::cout << "Введите номер вагона: ";
    while (!(is >> inputNum)) {
        std::cout << "Ошибка ввода! Введите числовой номер вагона: ";
        is.clear();
        is.ignore(10000, '\n');
    }
    carriage.setNumber(inputNum);

    is.ignore(10000, '\n');

    std::cout << "Введите тип вагона (Плацкарт, Купе, Сидячий): ";
    std::getline(is, inputType);
    carriage.setType(inputType);

    return is;
}