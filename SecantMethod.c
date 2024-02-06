#include <stdio.h>
#include <math.h>

// Function to evaluate the equation: f(x) = x^2 - 4
double equation(double x) {
    return x * x - 4;
}

// Secant method for root approximation
double secantMethod(double x0, double x1, double tolerance, int maxIterations) {
    int iteration = 0;

    printf("Iteration\tRoot Approximation\n");
    printf("-------------------------------\n");

    while (iteration < maxIterations) {
        double f0 = equation(x0);
        double f1 = equation(x1);

        double x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0);

        printf("%d\t\t%.6lf\n", iteration, x2);

        if (fabs(x2 - x1) < tolerance) {
            printf("\nRoot Approximation Converged to %.6lf\n", x2);
            return x2; // Convergence achieved
        }

        x0 = x1;
        x1 = x2;

        iteration++;
    }

    printf("\nRoot Approximation did not converge within the maximum number of iterations.\n");
    return -1; // Convergence not achieved
}

int main() {
    double x0 = 1.0; // Initial guess 1
    double x1 = 3.0; // Initial guess 2
    double tolerance = 1e-6; // Tolerance for convergence
    int maxIterations = 50; // Maximum number of iterations

    double rootApproximation = secantMethod(x0, x1, tolerance, maxIterations);

    printf("\nFinal Approximation of the Root: %.6lf\n", rootApproximation);

    return 0;
}
