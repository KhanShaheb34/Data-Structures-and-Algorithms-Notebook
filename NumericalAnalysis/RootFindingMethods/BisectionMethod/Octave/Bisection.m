function [root, iter] = Bisection(y, a, b)
    if y(a) * y(b) > 0
        root = 0; iter = 0;
        fprintf("No root in range!\n")
        return
    end

    if y(a) == 0
        root = a; iter = 0;
        return
    end

    if y(b) == 0
        root = b; iter = 0;
        return
    end

    c = a;

    for i = 1:100
        oldC = c;
        c = (a+b)/2;
        if y(a)*y(c) < 0
            b = c;
        else
            a = c;
        end
        if abs(c - oldC) < 1e-6
            break
        end
    end
    root = c;
    iter = i;
endfunction
