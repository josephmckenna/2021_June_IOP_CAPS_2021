IsPrime <- function(n) {
    for (i in 2:(n/2)) {
        if ( n %% i == 0) {
            return(FALSE)
        }
    }
    return(TRUE)
}

for (i in 2:100)
    if (IsPrime(i))
        print(i)
