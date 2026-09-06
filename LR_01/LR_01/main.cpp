#include "headers.h"

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    vector<Train> trains;
    int choice = 0;

    do {
        cout << "\n-------------- МЕНЮ --------------\n";
        cout << "1. Добавить новый поезд\n";
        cout << "2. Добавить вагон в поезд\n";
        cout << "3. Вывести информацию о всех поездах\n";
        cout << "4. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            Train newTrain;
            newTrain.inputData();
            trains.push_back(newTrain);
            cout << "Поезд добавлен! (Всего поездов: " << trains.size() << ")\n";
            break;
        }
        case 2: {
            if (trains.empty()) {
                cout << "\nВ системе нет ни одного поезда! Сначала создайте поезд.\n";
                break;
            }

            cout << "\nДоступные поезда (от 1 до " << trains.size() << "):\n";
            for (size_t i = 0; i < trains.size(); i++) {
                cout << i + 1 << ". Поезд машиниста " << trains[i].getDriver() << "\n";
            }

            int trainIndex;
            cout << "Выберите номер поезда для добавления вагона: ";
            cin >> trainIndex;

            if (trainIndex >= 1 && static_cast<size_t>(trainIndex) <= trains.size()) {
                Carriage newCarriage;
                newCarriage.inputData();
                trains[trainIndex - 1].addCarriage(newCarriage);
            } else {
                cout << "\nНеверный номер поезда!\n";
            }
            break;
        }
        case 3: {
            if (trains.empty()) {
                cout << "\nСписок поездов пуст.\n";
            } else {
                for (size_t i = 0; i < trains.size(); i++) {
                    cout << "\n--- Поезд №" << (i + 1) << " ---";
                    trains[i].printInfo();
                }
            }
            break;
        }
        case 4: {
            cout << "\nЗавершение работы программы\n";
            break;
        }
        default: {
            cout << "\nНеверный пункт меню, попробуйте снова!\n";
            break;
        }
        }
    } while (choice != 4);

    return 0;
}