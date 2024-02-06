#include <stdio.h>
#include <math.h>

// Function to evaluate the equation: f(x) = x^3 - 6x^2 + 11x - 6
double equation(double x) {
    return x * x * x - 6 * x * x + 11 * x - 6;
}

// Recursive-like function for Regula-Falsi method
double regulaFalsiRecursive(double a, double b, double tolerance, int iteration, int maxIterations) {
    if (iteration >= maxIterations) {
        printf("\nRoot Approximation did not converge within the maximum number of iterations.\n");
        return -1; // Convergence not achieved
    }

    double fa = equation(a);
    double fb = equation(b);

    if (fa * fb > 0) {
        printf("Error: The chosen interval does not bracket the root.\n");
        return -1; // Method may not converge
    }

    double c = (a * fb - b * fa) / (fb - fa);
    double fc = equation(c);

    printf("%d\t\t%.6lf\n", iteration, c);

    if (fabs(fc) < tolerance) {
        printf("\nRoot Approximation Converged to %.6lf\n", c);
        return c; // Convergence achieved
    }

    if (fa * fc < 0) {
        return regulaFalsiRecursive(a, c, tolerance, iteration + 1, maxIterations);
    } else {
        return regulaFalsiRecursive(c, b, tolerance, iteration + 1, maxIterations);
    }
}

int main() {
    double a = 1.0; // Lower bound
    double b = 3.0; // Upper bound
    double tolerance = 0.000001; // Tolerance for convergence
    int maxIterations = 50; // Maximum number of iterations

    printf("Iteration\tRoot Approximation\n");
    printf("-------------------------------\n");

    double rootApproximation = regulaFalsiRecursive(a, b, tolerance, 0, maxIterations);

    printf("\nFinal Approximation of the Root: %.6lf\n", rootApproximation);

    return 0;
}
