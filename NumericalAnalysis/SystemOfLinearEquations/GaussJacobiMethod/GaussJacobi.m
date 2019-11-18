function retval =GaussJacobi(A, b)
  [r c] = size(A);
  b = b';
  n = length(b); 
  x = zeros(n, 1);
  xnew = zeros(n, 1);
  
  for iteration = 1:20
    for i = 1:n
        sum = 0;
        for j = 1:n
          if i ~= j
          sum = sum + A(i, j)*x(j);
          endif
        endfor
        xnew(i) = -1/A(i, i) * (sum - b(i));
      endfor
      x = xnew;
    endfor
retval = [x'];
endfunction
