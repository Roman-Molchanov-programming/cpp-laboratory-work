#include "../headers/SeatingCarriage.h"

using namespace std;

SeatingCarriage::SeatingCarriage() : Carriage("Сидячий", 0), rowsCount(20), seatsPerRow(3) {
}

SeatingCarriage::SeatingCarriage(int carriageNumber, int rows, int perRow)
    : Carriage("Сидячий", carriageNumber), rowsCount(rows), seatsPerRow(perRow) {
}

int SeatingCarriage::getRowsCount() const {
    return rowsCount;
}

int SeatingCarriage::getSeatsPerRow() const {
    return seatsPerRow;
}

int SeatingCarriage::getTotalSeats() const {
    return rowsCount * seatsPerRow;
}

void SeatingCarriage::setRowsCount(int rows) {
    rowsCount = rows;
}

void SeatingCarriage::setSeatsPerRow(int perRow) {
    seatsPerRow = perRow;
}

bool SeatingCarriage::isEqual(const Carriage &other) const {
    if (!Carriage::isEqual(other)) {
        return false;
    }
    const auto *s = dynamic_cast<const SeatingCarriage *>(&other);
    return s != nullptr && this->rowsCount == s->rowsCount && this->seatsPerRow == s->seatsPerRow;
}

void SeatingCarriage::printVirtualInfo(ostream &os) const {
    os << "  Сидячий вагон №" << getNumber() << " | Рядов: " << rowsCount
       << " | Мест в ряду: " << seatsPerRow << " | Всего мест: " << getTotalSeats();
}

void SeatingCarriage::inputVirtualData(istream &is) {
    Carriage::inputVirtualData(is);
    cout << "Введите количество рядов кресел: ";
    while (!(is >> rowsCount) || rowsCount <= 0) {
        cout << "Ошибка! Введите положительное число рядов: ";
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