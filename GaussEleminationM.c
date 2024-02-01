#include <stdio.h>

int main() {
    float a[3][4] = {
        {4, 1, 1, 4},
        {1, 4, -2, 4},
        {-1, 2, -4, 2}
    };

    int n = 3; // Number of equations

    // Forward elimination
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            float factor = a[j][i] / a[i][i];
            for (int k = i; k <= n; k++) {
                a[j][k] -= factor * a[i][k];
            }
        }
    }

    // Back-substitution
    float x[n];
    for (int i = n - 1; i >= 0; i--) {
        x[i] = a[i][n];
        for (int j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }

    // Print the solution
    printf("Solution:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %.2f\n", i + 1, x[i]);
    }

    return 0;
}
