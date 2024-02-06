#include <stdio.h>
#include <math.h>

// Function to evaluate the integrand: f(x) = 1/(1+x^2)
double f(double x) {
    return 1.0 / (1.0 + x * x);
}

// Simpson's 1/3 rule for definite integral
double simpsonsOneThird(double a, double b, int n) {
    double h = (b - a) / n;
    double result = f(a) + f(b);

    // 1,3,5,7....
    for (int i = 1; i < n; i += 2) {
        result += 4 * f(a + i * h);
    }

    // 2,4,6,8....
    for (int i = 2; i < n - 1; i += 2) {
        result += 2 * f(a + i * h);
    }

    return h * result / 3.0;
}

int main() {
    double lowerLimit = 0.0;  // LL
    double upperLimit = 2.0;  // HL
    int numPoints = 3;

    double integralValue = simpsonsOneThird(lowerLimit, upperLimit, numPoints);

    printf("Approximate value of the integral: %.6lf\n", integralValue);

    return 0;
}
