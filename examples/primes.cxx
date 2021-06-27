
#include <iostream>

bool IsPrime(int n)
{
    for ( int i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
           return false;
        }
    }
 return true;
}

int main()
{
    for (int i = 2; i< 100000; i++)
    {
        if (IsPrime(i))
           std::cout <<i<<"\n";
    }
}