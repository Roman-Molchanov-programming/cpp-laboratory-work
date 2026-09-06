#include "headers.h"

static void handleAddTrain(std::vector<Train> &trains) {
    Train newTrain;
    newTrain.inputData();
    trains.push_back(newTrain);
    std::cout << "Поезд добавлен! (Всего поездов: " << trains.size() << ")\n";
}

static void handleAddCarriage(std::vector<Train> &trains) {
    if (trains.empty()) {
        std::cout << "\nВ системе нет ни одного поезда! Сначала создайте поезд.\n";
        return;
    }

    std::cout << "\nДоступные поезда (от 1 до " << trains.size() << "):\n";
    for (size_t i = 0; i < trains.size(); ++i) {
        std::cout << i + 1 << ". Поезд машиниста " << trains[i].getDriver() << "\n";
    }

    int trainIndex = 0;
    std::cout << "Выберите номер поезда для добавления вагона: ";
    if (!(std::cin >> trainIndex)) {
        std::cout << "\nНекорректный ввод!\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return;
    }

    if (trainIndex >= 1 && static_cast<size_t>(trainIndex) <= trains.size()) {
        Carriage newCarriage;
        newCarriage.inputData();
        trains[static_cast<size_t>(trainIndex) - 1].addCarriage(newCarriage);
    } else {
        std::cout << "\nПоезд с таким номером не существует!\n";
        std::cin.ignore(10000, '\n');
    }
}

static void handlePrintAll(const std::vector<Train> &trains) {
    if (trains.empty()) {
        std::cout << "\nСписок поездов пуст.\n";
        return;
    }

    for (size_t i = 0; i < trains.size(); ++i) {
        std::cout << "\n--- Поезд №" << (i + 1) << " ---";
        trains[i].printInfo();
    }
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    std::vector<Train> trains;
    int choice = 0;

    do {
        std::cout << "\n-------------- МЕНЮ --------------\n";
        std::cout << "1. Добавить новый поезд\n";
        std::cout << "2. Добавить вагон в поезд\n";
        std::cout << "3. Вывести информацию о всех поездах\n";
        std::cout << "4. Выход\n";
        std::cout << "Выберите действие: ";

        if (!(std::cin >> choice)) {
            std::cout << "\nНеверный ввод! Введите число от 1 до 4.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
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
            std::cout << "\nЗавершение работы программы\n";
            break;
        default:
            std::cout << "\nНеверный пункт меню, попробуйте снова!\n";
            break;
        }
    } while (choice != 4);

    return 0;
}