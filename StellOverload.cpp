#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//ЗАДАНИЕ 1: Перегруженные функции
void processMatrix(int mat[][10], int n) {
    // Инициализация
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] = rand() % 100;

    // Вывод
    cout << "Матрица int:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << "\t";
        cout << endl;
    }

    // Min/max на диагонали
    int min = mat[0][0], max = mat[0][0];
    for (int i = 0; i < n; i++) {
        if (mat[i][i] < min) min = mat[i][i];
        if (mat[i][i] > max) max = mat[i][i];
    }
    cout << "Min: " << min << " Max: " << max << endl;

    // Сортировка строк
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1; j++)
            for (int k = j + 1; k < n; k++)
                if (mat[i][j] > mat[i][k])
                    swap(mat[i][j], mat[i][k]);

    cout << "После сортировки:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << "\t";
        cout << endl;
    }
}

void processMatrix(double mat[][10], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] = (rand() % 1000) / 10.0;

    cout << "Матрица double:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << "\t";
        cout << endl;
    }

    double min = mat[0][0], max = mat[0][0];
    for (int i = 0; i < n; i++) {
        if (mat[i][i] < min) min = mat[i][i];
        if (mat[i][i] > max) max = mat[i][i];
    }
    cout << "Min: " << min << " Max: " << max << endl;

    // Сортировка для double
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1; j++)
            for (int k = j + 1; k < n; k++)
                if (mat[i][j] > mat[i][k])
                    swap(mat[i][j], mat[i][k]);

    cout << "После сортировки:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << "\t";
        cout << endl;
    }
}

void processMatrix(char mat[][10], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] = 'A' + rand() % 26;

    cout << "Матрица char:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << "\t";
        cout << endl;
    }

    char min = mat[0][0], max = mat[0][0];
    for (int i = 0; i < n; i++) {
        if (mat[i][i] < min) min = mat[i][i];
        if (mat[i][i] > max) max = mat[i][i];
    }
    cout << "Min: " << min << " Max: " << max << endl;

    // Сортировка для char
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1; j++)
            for (int k = j + 1; k < n; k++)
                if (mat[i][j] > mat[i][k])
                    swap(mat[i][j], mat[i][k]);

    cout << "После сортировки:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << "\t";
        cout << endl;
    }
}

void task1() {
    cout << "=== ЗАДАНИЕ 1: Перегруженные функции для матриц ===\n";
    int n;
    cout << "Введите размер матрицы: ";
    cin >> n;

    int imat[10][10];
    double dmat[10][10];
    char cmat[10][10];

    processMatrix(imat, n);
    cout << "------------------------\n";
    processMatrix(dmat, n);
    cout << "------------------------\n";
    processMatrix(cmat, n);
}

//ЗАДАНИЕ 2:Рекурсивный НОД
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void task2() {
    cout << "ЗАДАНИЕ 2: Рекурсивный НОД\n";
    int a, b;
    cout << "Введите два числа: ";
    cin >> a >> b;

    // берем модули для отрицательных чисел
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    cout << "НОД(" << a << "," << b << ") = " << gcd(a, b) << endl;
}

//ЗАДАНИЕ 3: Быки и коровы 
bool hasUniqueDigits(int number) {
    bool digits[10] = { false };
    for (int i = 0; i < 4; i++) {
        int digit = number % 10;
        if (digits[digit]) return false;
        digits[digit] = true;
        number /= 10;
    }
    return true;
}

int generateSecret() {
    int number;
    do {
        number = 1000 + rand() % 9000;
    } while (!hasUniqueDigits(number));
    return number;
}

void play(int secret, int attempts = 1) {
    cout << "Попытка " << attempts << ": ";
    int guess;
    cin >> guess;

    if (guess < 1000 || guess > 9999) {
        cout << "Ошибка! Введите 4-значное число.\n";
        play(secret, attempts);
        return;
    }

    if (!hasUniqueDigits(guess)) {
        cout << "Ошибка! Все цифры должны быть разными.\n";
        play(secret, attempts);
        return;
    }

    int bulls = 0, cows = 0;
    int s = secret, g = guess;

    //проверяем быков
    for (int i = 0; i < 4; i++) {
        if (s % 10 == g % 10) bulls++;
        s /= 10;
        g /= 10;
    }

    //проверяем коров
    s = secret;
    for (int i = 0; i < 4; i++) {
        g = guess;
        for (int j = 0; j < 4; j++) {
            if (i != j && s % 10 == g % 10) {
                cows++;
                break;
            }
            g /= 10;
        }
        s /= 10;
    }

    cout << "Быки: " << bulls << " Коровы: " << cows << endl;

    if (bulls == 4) {
        cout << "ПОБЕДА! Вы угадали число за " << attempts << " попыток!\n";
        return;
    }

    play(secret, attempts + 1);
}

void task3() {
    cout << "ЗАДАНИЕ 3: Быки и коровы\n";
    cout << "Угадайте 4-значное число с разными цифрами\n";
    cout << "Быки - правильные цифры на своих местах\n";
    cout << "Коровы - правильные цифры не на своих местах\n";

    srand(time(NULL));
    int secret = generateSecret();
    play(secret);
}

//главное меню
int main() {
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    int choice;
    do {
        cout << "\n ГЛАВНОЕ МЕНЮ \n";
        cout << "1. Перегруженные функции для матриц\n";
        cout << "2. Рекурсивный НОД\n";
        cout << "3. Быки и коровы\n";
        cout << "0. Выход\n";
        cout << "Выберите задание: ";
        cin >> choice;

        switch (choice) {
        case 1: task1();
            break;
        case 2: task2();
            break;
        case 3: task3();
            break;
        case 0: cout << "Выход из программы\n";
            break;
        default:
            cout << "Неверный выбор!\n";
        }
    } while (choice != 0);

    return 0;
}
