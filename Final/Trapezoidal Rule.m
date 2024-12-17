% Define the function to integrate
f = @(x) x.^2 + 3 * x + 2; % Example function f(x) = x^2 + 3x + 2

% Define the integration interval
a = 0; % Lower bound
b = 5; % Upper bound

% Define the number of subintervals
n = 12; % Total number of subintervals

% Trapezoidal Rule function
function result = trapezoidal(f, a, b, n)
    h = (b - a) / n; % Step size
    x = a:h:b; % x values
    y = f(x); % Function values
    % Trapezoidal formula
    result = (h / 2) * (y(1) + 2 * sum(y(2:end-1)) + y(end));
end

% Calculate integral using Trapezoidal Rule
integral_trapezoidal = trapezoidal(f, a, b, n);

% Display the result
fprintf('Integral using Trapezoidal rule: %.4f\n', integral_trapezoidal);

% Plot the function and shaded areas for visualization
x_plot = linspace(a, b, 100); % x values for plotting
y_plot = f(x_plot); % f(x) values for plotting

figure;
plot(x_plot, y_plot, 'g-', 'LineWidth', 1.5);
hold on;
fill([x_plot, fliplr(x_plot)], [y_plot, zeros(size(y_plot))], 'yellow', 'FaceAlpha', 0.3);
title(sprintf('Trapezoidal Rule (n = %d, Area = %.4f)', n, integral_trapezoidal));
xlabel('x');
ylabel('f(x)');
grid on;
hold off;