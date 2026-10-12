#include "../headers/SeatingCarriage.h"

using namespace std;

SeatingCarriage::SeatingCarriage() : Carriage("Сидячий", 0), rowsCount(20) {
}

SeatingCarriage::SeatingCarriage(int carriageNumber, int rows)
    : Carriage("Сидячий", carriageNumber), rowsCount(rows) {
}

int SeatingCarriage::getRowsCount() const {
    return rowsCount;
}
void SeatingCarriage::setRowsCount(int rows) {
    rowsCount = rows;
}

bool SeatingCarriage::operator==(const Carriage &other) const {
    if (!Carriage::operator==(other))
        return false;
    const auto *s = dynamic_cast<const SeatingCarriage *>(&other);
    return s != nullptr && this->rowsCount == s->rowsCount;
}

void SeatingCarriage::printVirtualInfo(ostream &os) const {
    os << "  Сидячий вагон №" << number << " | Рядов кресел: " << rowsCount;
}

void SeatingCarriage::inputVirtualData(istream &is) {
    Carriage::inputVirtualData(is);
    cout << "Введите количество рядов кресел: ";
    while (!(is >> rowsCount) || rowsCount <= 0) {
        cout << "Ошибка! Введите положительное число рядов: ";
        is.clear();
        is.ignore(10000, '\n');
    }
    is.ignore(10000, '\n');
}