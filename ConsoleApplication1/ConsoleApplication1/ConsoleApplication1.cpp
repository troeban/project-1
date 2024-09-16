#include <iostream>
#include <limits>
using namespace std;

// Функція для введення числа з перевіркою на помилку
int inputNumber(const string& prompt) {
    int number;
    while (true) {
        cout << prompt;
        cin >> number;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Помилка, введіть дані повторно." << endl;
        }
        else {
            return number;
        }
    }
}

int main() {
    // Додавання укр. мови
    setlocale(LC_ALL, "ukr");

    // Змінні для початку і кінця діапазону, а також кількості тризначних чисел
    int st, count = 0, end;

    // Перевірка правильності введення даних
    do {
        st = inputNumber("Введіть початок діапазону: ");
        end = inputNumber("Введіть кінець діапазону: ");

        if (st > end) {
            cout << "Помилка: початок діапазону має бути менший або рівний кінцю діапазону. Повторіть спробу.\n";
        }
    } while (st > end);

    // Підрахунок кількості тризначних чисел у діапазоні
    for (int i = st; i <= end; i++) {
        // Перевірка, чи є число тризначним (включаючи від'ємні тризначні числа)
        if ((i >= 100 && i <= 999) || (i <= -100 && i >= -999)) {
            ++count;
        }
    }

    // Виведення кількості тризначних чисел
    if (count > 0) {
        cout << "Кількість тризначних чисел: " << count << endl;
    }
    else {
        cout << "У діапазоні немає тризначних чисел." << endl;
    }
    return 0;
}


