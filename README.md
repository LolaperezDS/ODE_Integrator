# ODE Integrator
Runge Kutta solver for first-order homogeneous differential equations

##### Powered by the 4th order Runge Kutta function increment search algorithm
```C++
double RungeKutta45(double x, double y, double h, double(*func)(double, double)) {
    double k1 = h * func(x, y);
    double k2 = h * func(x + h / 2, y + k1 / 2);
    double k3 = h * func(x + h / 2, y + k2 / 2);
    double k4 = h * func(x + h, y + k3);
    double Dy = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
    return Dy;
}
```
