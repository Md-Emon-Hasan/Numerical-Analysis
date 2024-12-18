#include <stdio.h>

// Function to calculate factorial
int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Newton Backward Interpolation
void newtonBackwardInterpolation(float x[], float y[][10], int n, float value) {
    // Calculate the backward difference table
    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
        }
    }

    // Display the backward difference table
    printf("\nBackward Difference Table:\n");
    for (int i = 0; i < n; i++) {
        printf("%6.2f", x[i]);
        for (int j = 0; j <= i; j++) {
            printf("%10.2f", y[i][j]);
        }
        printf("\n");
    }

    // Initialize variables for interpolation
    float u = (value - x[n - 1]) / (x[1] - x[0]);
    float result = y[n - 1][0];
    float u_term = 1;

    // Perform interpolation
    for (int i = 1; i < n; i++) {
        u_term *= (u + (i - 1));
        result += (u_term * y[n - 1][i]) / factorial(i);
    }

    // Print the interpolated result
    printf("\nValue at %.2f is %.6f\n", value, result);
}

int main() {
    int n;
    float value;

    // Input number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    // Input x and y values
    float x[n], y[n][10];
    printf("Enter the x values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }
    printf("Enter the y values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &y[i][0]);
    }

    // Input the value to interpolate
    printf("Enter the value of x to interpolate: ");
    scanf("%f", &value);

    // Perform interpolation
    newtonBackwardInterpolation(x, y, n, value);

    return 0;
}
