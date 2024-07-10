#include <iostream>
#include <cmath>
#include <iomanip>

// Define the function g(x) derived from f(x)
double g(double x) {
    return 2 - 4 * exp(-x / 4);
}

// Define the function f(x) for checking the root
double f(double x) {
    return exp(-x / 4) * (2 - x) - 1;
}

int main() {
    double x0; // initial guess
    double x1; // next approximation
    double tol = 1e-6; // tolerance
    int max_iter = 1000; // maximum number of iterations
    int iter = 0;

    // Initial guess
    std::cout << "Enter initial guess: ";
    std::cin >> x0;

    std::cout << std::fixed << std::setprecision(6);

    while (iter < max_iter) {
        x1 = g(x0);
        std::cout << "Iteration " << iter + 1 << ": x = " << x1 << ", f(x) = " << f(x1) << std::endl;

        // Check for convergence
        if (std::abs(x1 - x0) < tol) {
            std::cout << "Converged to " << x1 << " after " << iter + 1 << " iterations." << std::endl;
            break;
        }

        // Update x0 for next iteration
        x0 = x1;
        iter++;
    }

    if (iter == max_iter) {
        std::cout << "Did not converge after " << max_iter << " iterations." << std::endl;
    }

    return 0;
}
