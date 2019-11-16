A = [4,1,2,-1; 3,6,-1,2; 2,-1,5,-3; 4,1,-3,-8];
B = [2; -1; 3; 2];
n = length(B);
x = zeros(n,1);
x(:) = 0;

for it = 1:100
    conv = true;
    for i = 1 : n
        sum = 0;
        for j = 1 : n
            if j ~= i
                sum += A(i, j)*x(j);
            end
        end
        temp = x(i);
        x(i) = -1 * (sum - B(i)) / A(i,i);
        if abs(temp - x(i)) > 1e-6
            conv = false;
        end
    end;
    if conv
        break
    end
end

disp("Solution: ")
x
disp("Iteration: ")
it
