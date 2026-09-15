#include "../headers/Carriage.h"

using namespace std;

// Методы Carriage

Carriage::Carriage() : type("Неизвестно"), number(0) {
}

Carriage::Carriage(string_view t, int num) : type(t), number(num) {
}

string Carriage::getType() const {
    return type;
}

int Carriage::getNumber() const {
    return number;
}

void Carriage::setType(string_view t) {
    type = t;
}

void Carriage::setNumber(int num) {
    number = num;
}

void Carriage::inputData() {
    int inputNum = 0;
    string inputType;

    cout << "Введите номер вагона: ";
    while (!(cin >> inputNum)) {
        cout << "Ошибка ввода! Введите числовой номер вагона: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    setNumber(inputNum);

    cin.ignore(10000, '\n');

    cout << "Введите тип вагона (Плацкарт, Купе, Сидячий): ";
    getline(cin, inputType);
    setType(inputType);
}

void Carriage::printInfo() const {
    cout << "  Вагон №" << number << " | Тип: " << type << endl;
}