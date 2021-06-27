#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>
#include <thread>
#include <vector>
#include <random>

class looper
{
	private:
		const uint64_t num;
		const std::mt19937_64::result_type seed;
		const double two_pi = 2 * M_PI;
		const double one_over_max;
		std::mt19937_64 rnd;
		uint64_t count;
    public:
	looper(int _num, std::mt19937_64::result_type _seed) : num(_num), seed(_seed), one_over_max(1/(double)std::mt19937_64::max())
	{
		std::mt19937_64 rnd(seed);
		count = 0;
	}
	uint64_t GetCount() const
	{
		return count;
	}
	void run()
	{
		for (uint64_t i = 0; i < num; i++)
		{
			double rand_1 = (double)rnd() * one_over_max;
			double y_0 = (double)rnd() * one_over_max;
			double y_coordinate = fabs(sin(two_pi*rand_1));
			if (y_coordinate > y_0)
				count++;
		}
		return;
	}
};



int main()
{
	long long num;
	printf("What is N: ");
	scanf("%lld", &num);

	struct timeval stop, start;
	gettimeofday(&start, NULL);

	looper a(num, rand());
	a.run();
	uint64_t count = a.GetCount();
	printf("%f\n",(double)num/ count);
	double frac_error = 2 * (((((double)num) / count) / M_PI_2) - 1);

	gettimeofday(&stop, NULL);

	printf("Count = %lu \n Fractional Error = %lf \n", count, frac_error);
	double time_dif = (stop.tv_sec - start.tv_sec) * 1000000;
	printf("Time per = %f us/N \n", time_dif / num);
	return 0;
}
