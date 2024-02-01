#include <stdio.h>
#include <math.h>

float func(float x) {
    return x * x + x + 7;
}

float forwardDifference(float x, float h) {
    return (func(x + h) - func(x)) / h;
}

float centralDifference(float x, float h) {
    return (func(x + h) - func(x - h)) / (2 * h);
}

int main() {
    float x; 
    float h = 1.0;
    printf("Enter the value of x: ");
    scanf("%f", &x);

    float forwardDerivative = forwardDifference(x, h);
    float centralDerivative = centralDifference(x, h);

    printf("Forward Difference Derivative: %.4f\n", forwardDerivative);
    printf("Central Difference Derivative: %.4f\n", centralDerivative);

    return 0;
}
