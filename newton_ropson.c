#include <stdio.h>
#include <math.h>

// Function to find the root of (example: f(x) = x^3 - 4x - 9)
double f(double x) {
    return x*x*x - 4*x - 9;
}

// Derivative of the function (example: f'(x) = 3x^2 - 4)
double df(double x) {
    return 3*x*x - 4;
}

// Newton-Raphson Method function
void newtonRaphson(double x0, double tol, int max_iter) {
    double x1 = x0;  // Initialize x1 with the initial guess
    int iteration = 0;

    // Loop until tolerance is met or maximum iterations are reached
    while (fabs(f(x1)) > tol && iteration < max_iter) {
        x1 = x0 - f(x0) / df(x0);  // Newton-Raphson formula
        printf("Iteration %d: x = %.6lf\n", iteration + 1, x1);
        
        x0 = x1;  // Update for the next iteration
        iteration++;
    }

    if (fabs(f(x1)) <= tol) {
        printf("The root is: %.6lf\n", x1);
    } else {
        printf("Maximum iterations reached without finding a root within the tolerance.\n");
    }
}

int main() {
    double x0 = 3;  // Initial guess
    double tol = 1e-6;  // Tolerance for convergence
    int max_iter = 100;  // Maximum number of iterations

    newtonRaphson(x0, tol, max_iter);

    return 0;
}
