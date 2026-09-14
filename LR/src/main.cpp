#include <Windows.h>
#include "../headers/Train.h"
using namespace std;

static void handleAddTrain(vector<shared_ptr<Train>> &trains) {
    auto newTrain = make_shared<Train>();
    newTrain->inputData();
    trains.push_back(newTrain);
    cout << "Поезд добавлен! (Всего поездов: " << trains.size() << ")\n";
}

static void handleAddCarriage(vector<shared_ptr<Train>> &trains) {
    if (trains.empty()) {
        cout << "\nВ системе нет ни одного поезда! Сначала создайте поезд.\n";
        return;
    }

    cout << "\nДоступные поезда (от 1 до " << trains.size() << "):\n";
    for (size_t i = 0; i < trains.size(); ++i) {
        cout << i + 1 << ". Поезд машиниста " << trains[i]->getDriver() << "\n";
    }

    int trainIndex = 0;
    cout << "Выберите номер поезда для добавления вагона: ";
    if (!(cin >> trainIndex)) {
        cout << "\nНекорректный ввод!\n";
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }

    if (trainIndex >= 1 && static_cast<size_t>(trainIndex) <= trains.size()) {
        Carriage newCarriage;
        newCarriage.inputData();
        trains[static_cast<size_t>(trainIndex) - 1]->addCarriage(newCarriage);
    } else {
        cout << "\nПоезд с таким номером не существует!\n";
        cin.ignore(10000, '\n');
    }
}

static void handlePrintAll(const vector<shared_ptr<Train>> &trains) {
    if (trains.empty()) {
        cout << "\nСписок поездов пуст.\n";
        return;
    }

    for (size_t i = 0; i < trains.size(); ++i) {
        cout << "\n--- Поезд №" << (i + 1) << " ---";
        trains[i]->printInfo();
    }
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // Начальные данные с помощью auto и make_shared
    auto carriage1 = Carriage("Купе", 101);
    auto carriage2 = Carriage("Плацкарт", 102);
    auto carriage3 = Carriage("СВ", 201);
    auto carriage4 = Carriage("Сидячий", 202);

    auto train1 = make_shared<Train>("Молчанров Р.А.", 3);
    auto train2 = make_shared<Train>("Скиба И.Г.", 2);

    train1->addCarriage(carriage1);
    train1->addCarriage(carriage2);

    train2->addCarriage(carriage3);
    train2->addCarriage(carriage4);

    vector<shared_ptr<Train>> trains = {train1, train2};

    int choice = 0;

    do {
        cout << "\n-------------- МЕНЮ --------------\n";
        cout << "1. Добавить новый поезд\n";
        cout << "2. Добавить вагон в поезд\n";
        cout << "3. Вывести информацию о всех поездах\n";
        cout << "4. Выход\n";
        cout << "Выберите действие: ";

        if (!(cin >> choice)) {
            cout << "\nНеверный ввод! Введите число от 1 до 4.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
        case 1:
            handleAddTrain(trains);
            break;
        case 2:
            handleAddCarriage(trains);
            break;
        case 3:
            handlePrintAll(trains);
            break;
        case 4:
            cout << "\nЗавершение работы программы\n";
            break;
        default:
            cout << "\nНеверный пункт меню, попробуйте снова!\n";
            break;
        }
    } while (choice != 4);

    return 0;
}