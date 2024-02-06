#include <stdio.h>
#include <math.h>

#define N 3 // Number of variables

// Function to print the matrix
void printMatrix(float mat[N][N + 1]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++)
            printf("%.2f\t", mat[i][j]);
        printf("\n");
    }
}

// Function to apply Gauss-Seidel method
void gaussSeidel(float mat[N][N + 1], int maxIterations, float tolerance) {
    float x[N] = {0}; // Initial guess for the variables

    for (int iter = 0; iter < maxIterations; iter++) {
        float maxDiff = 0;

        for (int i = 0; i < N; i++) {
            float sum = mat[i][N]; // Initialize sum with the RHS value

            for (int j = 0; j < N; j++) {
                if (i != j) {
                    sum -= mat[i][j] * x[j];
                }
            }

            float newX = sum / mat[i][i];

            maxDiff = fmax(maxDiff, fabs(newX - x[i]));

            x[i] = newX;
        }

        printf("Iteration %d: ", iter + 1);
        for (int i = 0; i < N; i++) {
            printf("x%d = %.6f\t", i + 1, x[i]);
        }
        printf("\n");

        if (maxDiff < tolerance) {
            printf("\nConverged to the specified tolerance.\n");
            return;
        }
    }

    printf("\nDid not converge within the maximum number of iterations.\n");
}

int main() {
    float mat[N][N + 1] = {
        {4, 1, 1, 4},
        {1, 4, -2, 4},
        {-1, 2, -4, 2}
    };

    int maxIterations = 50;
    float tolerance = 1e-6;

    printf("Original System of Equations:\n");
    printMatrix(mat);

    printf("\nGauss-Seidel Method:\n");
    gaussSeidel(mat, maxIterations, tolerance);

    return 0;
}
