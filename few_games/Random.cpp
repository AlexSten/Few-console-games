#include "Random.h"
#include <random>
#include <time.h>



size_t Random::GetRandom(size_t _firstElement, size_t _lastElement)const
{
	static std::mt19937 gen((unsigned int)time(0));
	std::uniform_int_distribution<> uid(_firstElement, _lastElement);
	int temp = uid(gen);
	return temp;
}