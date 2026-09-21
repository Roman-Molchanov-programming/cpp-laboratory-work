#include "../headers/Train.h"
#include <Windows.h>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

vector<shared_ptr<Train>> &operator-=(vector<shared_ptr<Train>> &trains, size_t index) {
    if (index < trains.size()) {
        cout << "Поезд успешно удален из системы!" << endl;
        trains.erase(trains.begin() + index);
    } else {
        cout << "Некорректный индекс поезда!" << endl;
    }
    return trains;
}

static void printMenu() {
    cout << endl << "========== МЕНЮ ==========" << endl;
    cout << "1. Показать информацию о поездах" << endl;
    cout << "2. Показать вагоны поезда" << endl;
    cout << "3. Изменить данные поезда" << endl;
    cout << "4. Изменить данные вагона" << endl;
    cout << "5. Добавить вагон в поезд" << endl;
    cout << "6. Добавить новый поезд" << endl;
    cout << "7. Удалить вагон из поезда" << endl;
    cout << "8. Удалить поезд из системы" << endl;
    cout << "0. Выход" << endl;
    cout << "===========================" << endl;
    cout << "Выберите пункт меню: ";
}

static void handlePrintAll(const vector<shared_ptr<Train>> &trains) {
    if (trains.empty()) {
        cout << endl << "Список поездов пуст." << endl;
        return;
    }
    for (size_t i = 0; i < trains.size(); ++i) {
        cout << endl << "--- Поезд №" << (i + 1) << " ---";
        trains[i]->printInfo();
    }
}

static void handlePrintCarriages(const vector<shared_ptr<Train>> &trains) {
    if (trains.empty()) {
        cout << endl << "Список поездов пуст." << endl;
        return;
    }
    cout << endl << "Выберите номер поезда (от 1 до " << trains.size() << "): ";
    size_t idx = 0;
    if (!(cin >> idx) || idx < 1 || idx > trains.size()) {
        cout << "Некорректный номер поезда!" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }
    const auto &carriages = trains[idx - 1]->getCarriages();
    cout << "Вагоны выбранного поезда:" << endl;
    if (carriages.empty()) {
        cout << "  (Вагоны отсутствуют)" << endl;
    } else {
        for (const auto &c : carriages) {
            c.printInfo();
        }
    }
}

static void handleEditTrain(vector<shared_ptr<Train>> &trains) {
    if (trains.empty()) {
        cout << endl << "Список поездов пуст." << endl;
        return;
    }
    cout << endl << "Выберите номер поезда для редактирования (от 1 до " << trains.size() << "): ";
    size_t idx = 0;
    if (!(cin >> idx) || idx < 1 || idx > trains.size()) {
        cout << "Некорректный номер поезда!" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }

    cin.ignore(10000, '\n');
    cout << "Введите новое ФИО машиниста: ";
    string newDriver;
    getline(cin, newDriver);
    trains[idx - 1]->setDriver(newDriver);

    int newMax = 0;
    cout << "Введите новый лимит вагонов: ";
    while (!(cin >> newMax) || newMax < trains[idx - 1]->getCurrentCarriageCount()) {
        cout << "Ошибка! Лимит не может быть меньше текущего числа вагонов ("
             << trains[idx - 1]->getCurrentCarriageCount() << "): ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    trains[idx - 1]->setMaxCarriages(newMax);
    cout << "Данные поезда успешно обновлены!" << endl;
}

static void handleEditCarriage(vector<shared_ptr<Train>> &trains) {
    if (trains.empty()) {
        cout << endl << "Список поездов пуст." << endl;
        return;
    }
    cout << endl << "Выберите номер поезда (от 1 до " << trains.size() << "): ";
    size_t tIdx = 0;
    if (!(cin >> tIdx) || tIdx < 1 || tIdx > trains.size()) {
        cout << "Некорректный номер поезда!" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }

    auto &carriages = trains[tIdx - 1]->getCarriages();
    if (carriages.empty()) {
        cout << "У выбранного поезда нет вагонов!" << endl;
        return;
    }

    cout << "Доступные вагоны:" << endl;
    for (size_t i = 0; i < carriages.size(); ++i) {
        cout << i + 1 << ". Вагон №" << carriages[i].getNumber() << " (" << carriages[i].getType()
             << ")" << endl;
    }
    cout << "Выберите номер вагона для изменения (от 1 до " << carriages.size() << "): ";
    size_t cIdx = 0;
    if (!(cin >> cIdx) || cIdx < 1 || cIdx > carriages.size()) {
        cout << "Некорректный номер вагона!" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }

    carriages[cIdx - 1].inputData();
    cout << "Данные вагона успешно обновлены!" << endl;
}

static void handleAddCarriage(vector<shared_ptr<Train>> &trains) {
    if (trains.empty()) {
        cout << endl << "В системе нет ни одного поезда! Сначала создайте поезд." << endl;
        return;
    }

    cout << endl << "Доступные поезда (от 1 до " << trains.size() << "):" << endl;
    for (size_t i = 0; i < trains.size(); ++i) {
        cout << i + 1 << ". Поезд машиниста " << trains[i]->getDriver() << endl;
    }

    size_t trainIndex = 0;
    cout << "Выберите номер поезда для добавления вагона: ";
    if (!(cin >> trainIndex) || trainIndex < 1 || trainIndex > trains.size()) {
        cout << endl << "Некорректный ввод!" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }

    Carriage newCarriage;
    newCarriage.inputData();
    trains[trainIndex - 1]->addCarriage(newCarriage);
}

static void handleAddTrain(vector<shared_ptr<Train>> &trains) {
    auto newTrain = make_shared<Train>();
    newTrain->inputData();
    trains.push_back(newTrain);
    cout << "Поезд добавлен! (Всего поездов: " << trains.size() << ")" << endl;
}

static void handleDeleteCarriage(vector<shared_ptr<Train>> &trains) {
    if (trains.empty()) {
        cout << endl << "Список поездов пуст." << endl;
        return;
    }

    cout << endl << "Выберите номер поезда (от 1 до " << trains.size() << "): ";
    size_t tIdx = 0;
    if (!(cin >> tIdx) || tIdx < 1 || tIdx > trains.size()) {
        cout << "Некорректный номер поезда!" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }

    const auto &train = trains[tIdx - 1];
    if (train->getCarriages().empty()) {
        cout << "В этом поезде нет вагонов для удаления!" << endl;
        return;
    }

    cout << "Введите номер вагона для удаления: ";
    int carNum = 0;
    if (!(cin >> carNum)) {
        cout << "Некорректный ввод!" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }

    *train -= carNum;
}

static void handleDeleteTrain(vector<shared_ptr<Train>> &trains) {
    if (trains.empty()) {
        cout << endl << "Список поездов пуст." << endl;
        return;
    }

    cout << endl << "Выберите номер поезда для удаления (от 1 до " << trains.size() << "): ";
    size_t idx = 0;
    if (!(cin >> idx) || idx < 1 || idx > trains.size()) {
        cout << "Некорректный номер поезда!" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }

    trains -= (idx - 1);
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    auto carriage1 = Carriage("Купе", 101);
    auto carriage2 = Carriage("Плацкарт", 102);
    auto carriage3 = Carriage("Плацкарт", 201);
    auto carriage4 = Carriage("Сидячий", 202);

    auto train1 = make_shared<Train>("Молчанов Р.А.", 3);
    auto train2 = make_shared<Train>("Скиба И.Г.", 2);

    train1->addCarriage(carriage1);
    train1->addCarriage(carriage2);

    train2->addCarriage(carriage3);
    train2->addCarriage(carriage4);

    vector<shared_ptr<Train>> trains = {train1, train2};

    int choice = -1;

    do {
        printMenu();
        if (!(cin >> choice)) {
            cout << endl << "Ошибка! Введите целое число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
        case 1:
            handlePrintAll(trains);
            break;
        case 2:
            handlePrintCarriages(trains);
            break;
        case 3:
            handleEditTrain(trains);
            break;
        case 4:
            handleEditCarriage(trains);
            break;
        case 5:
            handleAddCarriage(trains);
            break;
        case 6:
            handleAddTrain(trains);
            break;
        case 7:
            handleDeleteCarriage(trains);
            break;
        case 8:
            handleDeleteTrain(trains);
            break;
        case 0:
            cout << endl << "Завершение работы программы." << endl;
            break;
        default:
            cout << endl << "Неверный пункт меню, попробуйте снова!" << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}