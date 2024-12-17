% Define the function to integrate
f = @(x) x.^2 + 3 * x + 2; % Example function f(x) = x^2 + 3x + 2

% Define the integration interval
a = 0; % Lower bound
b = 5; % Upper bound

% Define the number of subintervals
n = 12; % Total number of subintervals (must be even for Simpson's 1/3)

% Simpson's 1/3 Rule function
function result = simpson_13(f, a, b, n)
    if mod(n, 2) ~= 0
        error('n must be even for Simpson''s 1/3 rule');
    end
    h = (b - a) / n; % Step size
    x = a:h:b; % x values
    y = f(x); % Function values
    % Simpson's 1/3 formula
    result = (h / 3) * (y(1) + 4 * sum(y(2:2:end-1)) + 2 * sum(y(3:2:end-2)) + y(end));
end

% Calculate integral using Simpson's 1/3 Rule
integral_13 = simpson_13(f, a, b, n);

% Display the result
fprintf('Integral using Simpson''s 1/3 rule: %.4f\n', integral_13);

% Plot the function and shaded areas for visualization
x_plot = linspace(a, b, 100); % x values for plotting
y_plot = f(x_plot); % f(x) values for plotting

figure;
plot(x_plot, y_plot, 'b-', 'LineWidth', 1.5);
hold on;
fill([x_plot, fliplr(x_plot)], [y_plot, zeros(size(y_plot))], 'cyan', 'FaceAlpha', 0.3);
title(sprintf('Simpson''s 1/3 Rule (n = %d, Area = %.4f)', n, integral_13));
xlabel('x');
ylabel('f(x)');
grid on;
hold off;
