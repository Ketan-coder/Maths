#include <stdio.h>
#include <math.h>

float func(float x) {
    return x * x * x - 5 * x + 1;
}

float bisection(float a, float b, float epsilon) {
    float c;
    while (fabs(b - a) >= epsilon) {
        c = (a + b) / 2;
        if (func(c) == 0) {
            return c; // Found the exact root
        } else if (func(a) * func(c) < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    return (a + b) / 2; // Approximate root
}

int main() {
    float a = 0.0; // Initial left endpoint
    float b = 1.0; // Initial right endpoint
    float epsilon = 0.0001; // Tolerance for convergence

    float root = bisection(a, b, epsilon);

    printf("Approximate root: %.4f\n", root);
    return 0;
}
