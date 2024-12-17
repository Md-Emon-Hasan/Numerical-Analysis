% Define the coefficient matrix A and the right-hand side vector b
A = [10, 2, 3;
     3, 20, 1;
     2, 3, 15];
b = [27; 61; 33];

% Initial guess for the solution
x0 = [0; 0; 0]; % Initial guess for x1, x2, x3

% Set maximum number of iterations and tolerance for convergence
max_iter = 100; % Maximum iterations
tol = 1e-6; % Tolerance for convergence

% Initialize variables
x = x0; % Start with the initial guess
n = length(b); % Number of equations
iter = 0; % Iteration counter
error = inf; % Error (to control convergence)

% Initialize matrix to store solutions at each iteration
solutions = zeros(n, max_iter);

% Gauss-Jacobi Iteration
while iter < max_iter && error > tol
    x_new = zeros(n, 1); % Initialize a new vector for x values

    % Perform the iteration
    for i = 1:n
        sum = 0;
        for j = 1:n
            if i ~= j
                sum = sum + A(i, j) * x(j); % Sum over all terms except diagonal
            end
        end
        x_new(i) = (b(i) - sum) / A(i, i); % Update the value of x(i)
    end

    % Store the solution for this iteration
    solutions(:, iter + 1) = x_new;

    % Compute the error (difference between successive approximations)
    error = norm(x_new - x, inf);

    % Update x for the next iteration
    x = x_new;

    % Increment iteration counter
    iter = iter + 1;
end

% Display the result
fprintf('Solution after %d iterations:\n', iter);
disp(x);

% Plot the evolution of the solution
figure;
plot(1:iter, solutions(1, 1:iter), 'r-o', 'LineWidth', 2, 'DisplayName', 'x1');
hold on;
plot(1:iter, solutions(2, 1:iter), 'g-o', 'LineWidth', 2, 'DisplayName', 'x2');
plot(1:iter, solutions(3, 1:iter), 'b-o', 'LineWidth', 2, 'DisplayName', 'x3');
xlabel('Iteration');
ylabel('Solution Value');
title('Convergence of Gauss-Jacobi Method');
legend('show');
grid on;
hold off;
