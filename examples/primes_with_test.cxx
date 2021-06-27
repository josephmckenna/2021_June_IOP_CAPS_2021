#include <iostream>
//This requires C++17
constexpr bool IsPrime(int n)
{
    for ( int i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
           return false;
        }
    }
 return true;
}
static_assert(IsPrime(3)==true,"3 should be prime!");

int main()
{
    for (int i = 2; i< 100; i++)
    {
        if (IsPrime(i))
           std::cout <<i<<"\n";
    }
}