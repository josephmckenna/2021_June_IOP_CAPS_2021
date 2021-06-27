#include <iostream>
#include <cmath>
#include <random>
int main()
{
    // Set up function for random distributions
    std::uniform_real_distribution<double> 
       RandomAngle(0, 2*M_PI);
    std::uniform_real_distribution<double>
       RandomHeight(0,1);
    // Setup random engine
    std::default_random_engine re;
    
    uint64_t N = 100000;
    uint64_t C = 0;
    for (uint64_t i = 0; i < N; i++)
    {
        double theta = RandomAngle(re);
        double height = fabs(sin(theta));
        if (height > RandomHeight(re))
             C++;
    }
    std::cout<<"Pi:"<< 2*(double)N / (double)C <<std::endl;
    return 0;
}
