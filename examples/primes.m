%% In Octave a script cannot start with the keyword 'function'
disp("Running")

function retval = primes(n)
    retval = true;
    for i = 2:round(n/2)
        if ( mod (n , i) == 0)
            retval = false;
            return
        endif
    endfor
endfunction

for i = [2:100]
    if primes(i)
        disp(i)
    endif
endfor
        
