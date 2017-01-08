#ifndef RANDOM_H
#define RANDOM_H

class Random
{
protected:
	virtual size_t GetRandom(size_t _firstElement, size_t _lastElement)const;
	virtual ~Random() = default;
};

#endif RANDOM_H