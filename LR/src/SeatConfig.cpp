#include "../headers/SeatConfig.h"

using namespace std;

SeatConfig::SeatConfig(int lower, int upper) : lowerSeats(lower), upperSeats(upper) {
}

int SeatConfig::getLowerSeats() const {
    return lowerSeats;
}
int SeatConfig::getUpperSeats() const {
    return upperSeats;
}
int SeatConfig::getTotalSeats() const {
    return lowerSeats + upperSeats;
}

void SeatConfig::setLowerSeats(int lower) {
    lowerSeats = lower;
}
void SeatConfig::setUpperSeats(int upper) {
    upperSeats = upper;
}

ostream &operator<<(ostream &os, const SeatConfig &config) {
    config.printInfo(os);
    return os;
}

istream &operator>>(istream &is, SeatConfig &config) {
    config.inputData(is);
    return is;
}

void SeatConfig::printInfo(ostream &os) const {
    os << "Нижних: " << lowerSeats << ", Верхних: " << upperSeats;
}

void SeatConfig::inputData(istream &is) {
    cout << "Введите кол-во нижних мест: ";
    while (!(is >> lowerSeats) || lowerSeats < 0) {
        cout << "Ошибка! Введите корректное число: ";
        is.clear();
        is.ignore(10000, '\n');
    }
    cout << "Введите кол-во верхних мест: ";
    while (!(is >> upperSeats) || upperSeats < 0) {
        cout << "Ошибка! Введите корректное число: ";
        is.clear();
        is.ignore(10000, '\n');
    }
    is.ignore(10000, '\n');
}

PlatskartSeatConfig::PlatskartSeatConfig(int mainLower, int mainUpper, int sideLower, int sideUpper)
    : SeatConfig(mainLower, mainUpper), sideLowerSeats(sideLower), sideUpperSeats(sideUpper) {
}

int PlatskartSeatConfig::getSideLowerSeats() const {
    return sideLowerSeats;
}
int PlatskartSeatConfig::getSideUpperSeats() const {
    return sideUpperSeats;
}

int PlatskartSeatConfig::getTotalSeats() const {
    return lowerSeats + upperSeats + sideLowerSeats + sideUpperSeats;
}

void PlatskartSeatConfig::setSideLowerSeats(int sideLower) {
    sideLowerSeats = sideLower;
}
void PlatskartSeatConfig::setSideUpperSeats(int sideUpper) {
    sideUpperSeats = sideUpper;
}

void PlatskartSeatConfig::printInfo(ostream &os) const {
    SeatConfig::printInfo(os);
    os << ", Боковых нижних: " << sideLowerSeats << ", Боковых верхних: " << sideUpperSeats;
}

void PlatskartSeatConfig::inputData(istream &is) {
    SeatConfig::inputData(is);
    cout << "Введите кол-во боковых нижних мест: ";
    while (!(is >> sideLowerSeats) || sideLowerSeats < 0) {
        cout << "Ошибка! Введите корректное число: ";
        is.clear();
        is.ignore(10000, '\n');
    }
    cout << "Введите кол-во боковых верхних мест: ";
    while (!(is >> sideUpperSeats) || sideUpperSeats < 0) {
        cout << "Ошибка! Введите корректное число: ";
        is.clear();
        is.ignore(10000, '\n');
    }
    is.ignore(10000, '\n');
}