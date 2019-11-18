dy = @(x,y)x*y;
x = 0
y = 1
xn = 2
h = .001

for i = x : h : xn-h
    x = x + h;
    y = y + dy(x,y) * h;

    x
    y
    disp("======")
end