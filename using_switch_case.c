#include <stdio.h>
#include <math.h>

// Function to find the root of (example: f(x) = x^3 - 4x - 9)
double f(double x) {
    return x*x*x - 4*x - 9;
}

// Derivative of the function for Newton-Raphson
double df(double x) {
    return 3*x*x - 4;
}

// g(x) function for Fixed Point Iteration (example: g(x) = (x^3 - 9) / 4)
double g(double x) {
    return (pow(x, 3) - 9) / 4;
}

// Bisection Method
void bisection(double a, double b, double tol) {
    if (f(a) * f(b) >= 0) {
        printf("Bisection method fails. The function must have different signs at a and b.\n");
        return;
    }
    double c;
    int iteration = 0;
    while ((b - a) / 2.0 > tol) {
        c = (a + b) / 2.0;
        iteration++;
        printf("Bisection Iteration %d: c = %.6lf\n", iteration, c);
        if (f(c) == 0.0)
            break;
        else if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    }
    printf("Bisection root: %.6lf\n", c);
}

// False Position Method
void falsePosition(double a, double b, double tol) {
    if (f(a) * f(b) >= 0) {
        printf("False Position method fails. The function must have different signs at a and b.\n");
        return;
    }
    double c;
    int iteration = 0;
    while (fabs(f(c)) > tol) {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        iteration++;
        printf("False Position Iteration %d: c = %.6lf\n", iteration, c);
        if (f(c) == 0.0)
            break;
        else if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    }
    printf("False Position root: %.6lf\n", c);
}

// Newton-Raphson Method
void newtonRaphson(double x0, double tol, int max_iter) {
    double x1;
    int iteration = 0;
    do {
        x1 = x0 - f(x0) / df(x0);
        printf("Newton-Raphson Iteration %d: x = %.6lf\n", iteration + 1, x1);
        if (fabs(f(x1)) < tol)
            break;
        x0 = x1;
        iteration++;
        if (iteration >= max_iter) {
            printf("Maximum iterations reached.\n");
            break;
        }
    } while (fabs(f(x1)) > tol);
    printf("Newton-Raphson root: %.6lf\n", x1);
}

// Fixed Point Iteration Method
void fixedPointIteration(double x0, double tol, int max_iter) {
    double x1;
    int iteration = 0;
    do {
        x1 = g(x0);
        printf("Fixed Point Iteration %d: x = %.6lf\n", iteration + 1, x1);
        if (fabs(x1 - x0) < tol) {
            printf("Convergence achieved.\n");
            break;
        }
        x0 = x1;
        iteration++;
        if (iteration >= max_iter) {
            printf("Maximum iterations reached without convergence.\n");
            break;
        }
    } while (fabs(x1 - x0) > tol);
    printf("Fixed Point root: %.6lf\n", x1);
}

int main() {
    int choice;
    double a, b, x0, tol;
    int max_iter;

    // Ask the user to select the method
    printf("Select Root Finding Method:\n");
    printf("1. Bisection Method\n");
    printf("2. False Position Method\n");
    printf("3. Newton-Raphson Method\n");
    printf("4. Fixed Point Iteration\n");
    scanf("%d", &choice);

    // Common inputs for all methods
    tol = 1e-6;
    max_iter = 100;

    switch (choice) {
        case 1: // Bisection Method
            printf("Enter the interval [a, b]:\n");
            scanf("%lf %lf", &a, &b);
            bisection(a, b, tol);
            break;

        case 2: // False Position Method
            printf("Enter the interval [a, b]:\n");
            scanf("%lf %lf", &a, &b);
            falsePosition(a, b, tol);
            break;

        case 3: // Newton-Raphson Method
            printf("Enter initial guess x0:\n");
            scanf("%lf", &x0);
            newtonRaphson(x0, tol, max_iter);
            break;

        case 4: // Fixed Point Iteration
            printf("Enter initial guess x0:\n");
            scanf("%lf", &x0);
            fixedPointIteration(x0, tol, max_iter);
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
