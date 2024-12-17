% Define the function f(x, y) as an anonymous function
f = @(x, y) x + y; % Example: dy/dx = x + y

% Initial conditions
x0 = 0; % Initial x
y0 = 1; % Initial y
h = 0.1; % Step size
x_end = 1; % End point of x

% Create arrays to store results
x = x0:h:x_end; % Generate x values
y = zeros(size(x)); % Initialize y array

y(1) = y0; % Set initial y value

% Euler Method iteration
for n = 1:(length(x)-1)
y(n+1) = y(n) + h * f(x(n), y(n)); % Apply Euler formula
end

% Display results
disp('x values:');
disp(x);
disp('y values:');
disp(y);

% Plot the results
plot(x, y, 'b-o', 'LineWidth', 2, 'MarkerSize', 6);
title('Euler Method Solution');
xlabel('x');
ylabel('y');
grid on;
