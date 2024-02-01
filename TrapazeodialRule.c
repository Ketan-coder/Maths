#include <stdio.h>
#include <math.h>

// Function to evaluate the integrand: f(x) = 1/x
double f(double x) {
    return 1.0 / x;
}

// Trapezoidal rule for definite integral
double trapezoidal(double a, double b, int n) {
    double h = (b - a) / n;
    double result = 0.5 * (f(a) + f(b)); // First and last terms

    printf("Initial result: %.6lf\n", result);

    for (int i = 1; i < n; i++) {
        double xi = a + i * h;
        double fi = f(xi);
        result += fi;
        printf("xi at iteration %d: %.6lf, f(xi): %.6lf\n", i, xi, fi);
    }

    return h * result;
}

int main() {
    double a = 0.2; // Lower limit
    double b = 1.0; // Upper limit
    int n = (int)((b - a) / 0.2); // Calculate the number of subintervals

    double integral = trapezoidal(a, b, n);

    printf("Approximate value of the integral: %.6lf\n", integral);

    return 0;
}
