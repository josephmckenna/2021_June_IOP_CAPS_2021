package main

import (
	"fmt"
)
func IsPrime(n int) bool {
    for i:=2; i<=n/2; i++ {
        if (n % i == 0) {
           return false;
        }
    }
 return true;
}

func main() {
    for i:= 2; i<100; i++ {
        if (IsPrime(i)) {
           fmt.Println(i);
		}
    }
}