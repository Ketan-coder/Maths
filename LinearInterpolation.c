#include <stdio.h>

int main() {
    float x0, y0, x1, y1, xp, yp;

    printf("Enter the first point (x0, y0):\n");
    scanf("%f %f", &x0, &y0);

    printf("Enter the second point (x1, y1):\n");
    scanf("%f %f", &x1, &y1);

    printf("Enter the interpolation point:\n");
    scanf("%f", &xp);

    // Calculate the interpolated value using the linear interpolation formula
    yp = y0 + ((y1 - y0) / (x1 - x0)) * (xp - x0);

    printf("Interpolated value at %.3f is %.3f\n", xp, yp);

    return 0;
}
