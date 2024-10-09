#include <stdio.h>
#include <math.h>

// Function to find the root of (example: f(x) = x^3 - 4x - 9)
double f(double x) {
    return x*x*x - 4*x - 9;
}

// False Position Method function
void falsePosition(double a, double b, double tol) {
    if (f(a) * f(b) >= 0) {
        printf("False position method fails. The function must have different signs at a and b.\n");
        return;
    }

    double c;  // Approximate root
    int iteration = 0;

    // Perform iterations until the root is found with desired tolerance
    while (fabs(f(c)) > tol) {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));  // Compute the false position

        iteration++;
        printf("Iteration %d: c = %.6lf\n", iteration, c);

        if (f(c) == 0.0) {  // If c is the exact root
            break;
        } else if (f(a) * f(c) < 0) {
            b = c;  // Root is between a and c
        } else {
            a = c;  // Root is between c and b
        }
    }

    printf("The root is: %.6lf\n", c);
}

int main() {
    double a = 2, b = 3, tol = 1e-6;  // Interval [2, 3] with tolerance 10^-6
    falsePosition(a, b, tol);
    return 0;
}
