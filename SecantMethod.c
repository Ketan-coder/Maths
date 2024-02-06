#include <stdio.h>
#include <math.h>

// Function to evaluate the equation: x^2 - x - 2
double equation(double x) {
    return x * x - x - 2;
}

// Recursive function for root approximation
double bisectionRecursive(double a, double b, double tolerance, int maxIterations) {
    double c = (a + b) / 2;
    double fc = equation(c);

    printf("Root Approximation: %.6lf\n", c);

    if (fabs(fc) < tolerance || maxIterations == 0) {
        printf("\nRoot Approximation Converged to %.6lf\n", c);
        return c; // Convergence achieved
    }

    if (equation(a) * fc < 0) {
        return bisectionRecursive(a, c, tolerance, maxIterations - 1);
    } else {
        return bisectionRecursive(c, b, tolerance, maxIterations - 1);
    }
}

int main() {
    double a = 1.0; // Lower bound
    double b = 2.0; // Upper bound
    double tolerance = 0.000001; // Tolerance for convergence
    int maxIterations = 50; // Maximum number of iterations

    double rootApproximation = bisectionRecursive(a, b, tolerance, maxIterations);

    printf("\nFinal Approximation of the Root: %.6lf\n", rootApproximation);

    return 0;
}
