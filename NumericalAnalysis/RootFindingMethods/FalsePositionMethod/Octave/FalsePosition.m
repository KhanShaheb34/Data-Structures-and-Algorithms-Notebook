function [root, iter] = FalsePosition(y, a, b)
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

    c = (a+b)/2;

    for i = 1:100
        oldC = y(c);
        c = (a * y(b) - b * y(a)) / (y(b) - y(a));
        if y(a)*y(c) < 0
            b = c;
        else
            a = c;
        end
        if abs(y(c) - oldC) < 1e-6
            break
        end
    end
    root = c;
    iter = i;
endfunction