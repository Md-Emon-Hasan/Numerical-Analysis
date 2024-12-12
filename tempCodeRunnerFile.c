#include <stdio.h>
#include <math.h>

// Function g(x) derived from f(x) for fixed point iteration (example: g(x) = (x^3 - 9) / 4)
double g(double x) {
    return (pow(x, 3) - 9) / 4;  // Rearranged form of f(x) = x^3 - 4x - 9
}

// Fixed Point Iteration Method
void fixedPointIteration(double x0, double tol, int max_iter) {
    int iteration = 0;
    double x1 = g(x0);  // First approximation

    // Continue iterating until the tolerance is met or maximum iterations are reached
    while (fabs(x1 - x0) >= tol && iteration < max_iter) {
        printf("Iteration %d: x = %.6lf\n", iteration + 1, x1);
        x0 = x1;  // Update x0 to current approximation
        x1 = g(x0);  // Calculate next approximation
        iteration++;
    }

    // Check whether convergence was achieved
    if (fabs(x1 - x0) < tol) {
        printf("Convergence achieved. The root is: %.6lf\n", x1);
    } else {
        printf("Maximum iterations reached without convergence.\n");
    }
}

int main() {
    double x0 = 2;  // Initial guess
    double tol = 1e-6;  // Tolerance for convergence
    int max_iter = 100;  // Maximum number of iterations

    fixedPointIteration(x0, tol, max_iter);

    return 0;
}
