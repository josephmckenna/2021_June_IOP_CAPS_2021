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
		std::thread* t;
		const uint64_t num;
		const std::mt19937_64::result_type seed;
		const double two_pi = 2 * M_PI;
		const double max;
		std::mt19937_64 rnd;
		uint64_t count;
    public:
	looper(int _num, std::mt19937_64::result_type _seed) : num(_num), seed(_seed), max((double)std::mt19937_64::max())
	{
		std::mt19937_64 rnd(seed);
		count = 0;
	}
	const uint64_t GetCount()
	{
		return count;
	}
	void StartThread()
	{
		t=new std::thread(&looper::run,this);
	}
	void JoinThread()
	{
		t->join();
	}
	void run()
	{
		for (uint64_t i = 0; i < num; i++)
		{
			double rand_1 = (double)rnd() / max;
			double y_0 = (double)rnd() / max;
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

	int threads;
	printf("# of threads: ");
	scanf("%d", &threads);

	struct timeval stop, start;
	gettimeofday(&start, NULL);

	std::vector<looper*> loopers;
	loopers.reserve(threads);
	for (int i = 0; i < threads; i++) {
		looper* a = new looper(num / threads, rand());
		a->StartThread();
		loopers.push_back(a);
		
	}

	uint64_t count = 0;
	for (int i = 0; i < threads; i++) {
		loopers[i]->JoinThread();
		count += loopers[i]->GetCount();
	}
	double frac_error = 2 * (((((double)num) / count) / M_PI_2) - 1);

	gettimeofday(&stop, NULL);

	printf("Count = %lu \n Fractional Error = %lf \n", count, frac_error);
	double time_dif = (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec;
	printf("Time per = %f us/N \n", time_dif / num);
	exit(0);

	return 0;
}
