#include "../headers/SeatingCarriage.h"

using namespace std;

SeatingCarriage::SeatingCarriage() : Carriage("Сидячий", 0) {
}

SeatingCarriage::SeatingCarriage(int carriageNumber) : Carriage("Сидячий", carriageNumber) {
}

SeatingCarriage::SeatingCarriage(int carriageNumber, int rows)
    : Carriage("Сидячий", carriageNumber), rowsCount(rows) {
}

SeatingCarriage::SeatingCarriage(int carriageNumber, int rows, int seatsInRow)
    : Carriage("Сидячий", carriageNumber), rowsCount(rows), seatsPerRow(seatsInRow) {
}

int SeatingCarriage::getRowsCount() const {
    return rowsCount;
}
int SeatingCarriage::getSeatsPerRow() const {
    return seatsPerRow;
}

void SeatingCarriage::setRowsCount(int rows) {
    rowsCount = rows;
}
void SeatingCarriage::setSeatsPerRow(int seatsInRow) {
    seatsPerRow = seatsInRow;
}

string SeatingCarriage::getComfortCategory() const {
    return "Эконом (Сидячий)";
}

int SeatingCarriage::calculateTotalSeats() const {
    return rowsCount * seatsPerRow;
}

void SeatingCarriage::printVirtualInfo(ostream &os) const {
    os << "  Вагон Сидячий №" << getNumber() << " | Категория: " << getComfortCategory()
       << " | Всего мест: " << calculateTotalSeats() << " (Рядов: " << rowsCount
       << ", Мест в ряду: " << seatsPerRow << ")";
}

void SeatingCarriage::inputVirtualData(istream &is) {
    cout << "Введите номер вагона: ";
    int inputNum = 0;
    while (!(is >> inputNum)) {
        cout << "Ошибка! Введите числовой номер: ";
        is.clear();
        is.ignore(10000, '\n');
    }
    setNumber(inputNum);

    cout << "Введите количество рядов кресел: ";
    while (!(is >> rowsCount) || rowsCount <= 0) {
        cout << "Ошибка! Введите положительное число: ";
        is.clear();
        is.ignore(10000, '\n');
    }
    cout << "Введите количество мест в ряду: ";
    while (!(is >> seatsPerRow) || seatsPerRow <= 0) {
        cout << "Ошибка! Введите положительное число: ";
        is.clear();
        is.ignore(10000, '\n');
    }
    is.ignore(10000, '\n');
}