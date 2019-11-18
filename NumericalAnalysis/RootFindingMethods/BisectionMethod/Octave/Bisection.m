function value=BisFunc(f,a,b);
f=inline(f);
d = 1e-10;
while b-a >= d
    m = (a + b)/2;
    printf("%d %d %d %d %d %d\n",a,b,f(a),f(b),m,f(m));
    %func(m)*func(a)
    if f(m)*f(a) < 0
        b = m;
    else
        a = m;
  endif
  
endwhile
value=m;
endfunction


