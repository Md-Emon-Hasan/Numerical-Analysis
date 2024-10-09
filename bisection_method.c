#include <stdio.h>
#include <math.h>

// Function to find the root of (example: f(x) = x^3 - 4x - 9)
double f(double x) {
    return x*x*x - 4*x - 9;
}

// Bisection Method function
void bisection(double a, double b, double tol) {
    if (f(a) * f(b) >= 0) {
        printf("Bisection method fails. The function must have different signs at a and b.\n");
        return;
    }

    double c;  // Midpoint of the interval
    int iteration = 0;

    // Perform iterations until the interval size is smaller than the tolerance
    while ((b - a) / 2.0 > tol) {
        c = (a + b) / 2.0;  // Midpoint
        iteration++;
        printf("Iteration %d: c = %.6lf\n", iteration, c);

        if (f(c) == 0.0) {  // If c is a root
            break;
        } else if (f(a) * f(c) < 0) {
            b = c;  // Root is in the left half
        } else {
            a = c;  // Root is in the right half
        }
    }

    printf("The root is: %.6lf\n", c);
}

int main() {
    double a = 2, b = 3, tol = 1e-6;  // Interval [2, 3] with tolerance 10^-6
    bisection(a, b, tol);
    return 0;
}
