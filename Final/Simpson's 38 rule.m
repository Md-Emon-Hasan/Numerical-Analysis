% Define the function to integrate
f = @(x) x.^2 + 3 * x + 2; % Example function f(x) = x^2 + 3x + 2

% Define the integration interval
a = 0; % Lower bound
b = 5; % Upper bound

% Define the number of subintervals
n = 12; % Total number of subintervals (must be a multiple of 3 for Simpson's 3/8)

% Simpson's 3/8 Rule function
function result = simpson_38(f, a, b, n)
    if mod(n, 3) ~= 0
        error('n must be a multiple of 3 for Simpson''s 3/8 rule');
    end

    h = (b - a) / n; % Step size
    x = a:h:b; % x values
    y = f(x); % Function values
    % Simpson's 3/8 formula
    result = (3 * h / 8) * (y(1) + 3 * sum(y(2:3:end-1)) + 3 * sum(y(3:3:end-2)) + 2 * sum(y(4:3:end-3)) + y(end));
end

% Calculate integral using Simpson's 3/8 Rule
integral_38 = simpson_38(f, a, b, n);

% Display the result
fprintf('Integral using Simpson''s 3/8 rule: %.4f\n', integral_38);

% Plot the function and shaded areas for visualization
x_plot = linspace(a, b, 100); % x values for plotting
y_plot = f(x_plot); % f(x) values for plotting

figure;

% Plot for Simpson's 3/8 Rule
plot(x_plot, y_plot, 'r-', 'LineWidth', 1.5);
hold on;
fill([x_plot, fliplr(x_plot)], [y_plot, zeros(size(y_plot))], 'magenta', 'FaceAlpha', 0.3);
title(sprintf('Simpson''s 3/8 Rule (n = %d, Area = %.4f)', n, integral_38));
xlabel('x');
ylabel('f(x)');
grid on;
hold off;
