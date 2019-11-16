function [root, iter] = NewtonRaphson(y, c)

    pkg load symbolic;
    syms x;
    ff = y(x);

    dif = diff(ff, x);
    y1 = function_handle(dif);

    for i = 1:100
        oldC = c;
        c = c - (y(c) / y1(c));
        if abs(c-oldC) < 1e-6
            break
        end
    end
    root = c; iter = i;
endfunction