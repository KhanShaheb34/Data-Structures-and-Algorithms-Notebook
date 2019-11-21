f = @(x,y)x*y;
x = 0
y = 1
xn = 2
h = .001

for i = x : h : xn-h
    k1 = h * f(x, y);
    k2 = h * f(x+h, y+ k1);
    y = y + 0.5 * (k1+k2);
    x = x + h;

    x
    y
    k1
    k2
    disp("======")
end