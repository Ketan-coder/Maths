#include <stdio.h>
#include <math.h>

double calculateEx(double x) {
    double result = 1.0;
    double term = 1.0;

    // Calculate e^x using the series expansion up to the first three terms
    for (int i = 1; i <= 3; i++) {
        term *= x / i;
        printf("Term at iteration %d: %.6f\n", i, term);
        result += term;
        printf("Result at iteration %d: %.6f\n", i, result);
    }
    printf("Final result: %.6f\n\n", result);
    return result;
}

int main() {
    double x = 2.0; // You can change the value of x as needed

    // Calculate e^x using the custom function
    double customResult = calculateEx(x);

    // Calculate e^x using the inbuilt exp() function
    double expResult = exp(x);

    // Print results
    printf("Custom e^%.2f = %.6f\n", x, customResult);
    printf("exp(%.2f) = %.6f\n", x, expResult);

    // Compare the results
    printf("Difference: %.6f\n", fabs(customResult - expResult));

    return 0;
}
