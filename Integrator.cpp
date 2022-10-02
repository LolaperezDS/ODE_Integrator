// Integrator.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
using namespace std;

double func1(double x, double y);
double RungeKutta45(double x, double y, double h, double(*func)(double, double));

double testfunc(double x, double y);



struct VariablesForOde {
    double y0, y, dy;
    double (*func) (double x, double y);
};


int main()
{
    setlocale(LC_ALL, "Russian");

    // x0, xend - начальная и конечная абсцисса интегрирования
    // y0 - начальная ордината интегрирования
    // h - шаг (dx)
    // x, y - темп переменные для хранения промежуточных значений
    // dy - differencial "y" (f'(x)*dx)
    double h, x0, xend, x;
    VariablesForOde diffur1;

    diffur1.func = testfunc;

    // Ввод данных от пользователя
    cout << "Введите начальное условие y0 для 1 и второго уравнения:\n";
    cin >> diffur1.y0;

    diffur1.y = diffur1.y0;
    cout << "Введите начальное условие х0:\n";
    cin >> x0;
    cout << "Введите конец интегрирования:\n";
    cin >> xend;
    cout << "Введите шаг интегрирования:\n";
    cin >> h;


    for (double x = x0; x < xend; x = x + h) {
        cout << " X: " << x << "\ty1: " << diffur1.y << endl;

        diffur1.dy = RungeKutta45(x, diffur1.y, h, diffur1.func);
        diffur1.y = diffur1.y + diffur1.dy;
    }


    system("pause");
    return 0;
}

// правая часть диффура вида y' = f(x, y)
double func1(double x, double y) {
    double answer;
    answer = pow((pow(y, 2) - 1), 0.25);
    return answer;
}

// поиск приращения функции методом Рунгк-Кутта 4-5 порядка
double RungeKutta45(double x, double y, double h, double(*func)(double, double)) {
    double k1 = h * func(x, y);
    double k2 = h * func(x + h / 2, y + k1 / 2);
    double k3 = h * func(x + h / 2, y + k2 / 2);
    double k4 = h * func(x + h, y + k3);
    double Dy = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
    return Dy;
}


// функция для проверки работоспособности тела
double testfunc(double x, double y) {
    return -y * tan(x);
}