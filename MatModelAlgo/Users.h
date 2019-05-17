#pragma once
#include <vector>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <numeric>
#include <random>

enum class Behavior;
enum class PayCategory;

struct Users
{
	std::vector<int>		 ages;
	std::vector<Behavior>	 behavior;
	std::vector<double>		 weights;
	std::vector<PayCategory> pays;
};

enum class Behavior
{
	STD,
	IO,
	ACT,
	PAS
};

enum class PayCategory
{
	HIGH,
	MED,
	LOW,
};

template <typename T>
T Give(int opt);

template<Behavior>
Behavior Give(int opt)
{
	Behavior res;
	switch (opt)
	{
	case 0:
		res = Behavior::STD;
		break;
	case 1:
		res = Behavior::IO;
		break;
	case 2:
		res = Behavior::ACT;
		break;
	case 3:
		res = Behavior::PAS;
		break;
	default:
		res = Behavior::STD;
	}
	return res;
}

template<PayCategory>
PayCategory Give(int opt)
{
	PayCategory res;
	switch (opt)
	{
	case 0:
		res = PayCategory::HIGH;
	case 1:
		res = PayCategory::MED;
	case 2:
		res = PayCategory::LOW;
	default:
		res = PayCategory::MED;
	}
	return res;
}

namespace dst {
	template <typename T>
	void initVectorWithNormalDistribution(std::vector<T>& vec, int num, double sigma, double dst)
	{
		std::default_random_engine eng;
		std::normal_distribution<double> distribution(sigma, dst);
		for (size_t i = 0; i < num; i++)
		{
			int el = (T)distribution(eng);
			if (el < 0)
				el = abs(el);
			vec.push_back(el);
		}
	}
	template<PayCategory>
	void initVectorWithNormalDistribution(std::vector<PayCategory>& vec, int num, double sigma, double dst)
	{
		std::default_random_engine eng;
		sigma = 3.0;
		dst = 1.0;
		std::normal_distribution<double> distribution(sigma, dst);
		for (size_t i = 0; i < num; i++)
		{
			int el = distribution(eng);
			if (el < 0)
				el = abs(el);
			vec.push_back(Give<PayCategory>(el));
		}
	}

	template<Behavior>
	void initVectorWithNormalDistribution(std::vector<PayCategory>& vec, int num, double sigma, double dst)
	{
		std::default_random_engine eng;
		sigma = 3.0;
		dst = 1.0;
		std::normal_distribution<double> distribution(sigma, dst);
		for (size_t i = 0; i < num; i++)
		{
			int el = distribution(eng);
			if (el < 0)
				el = abs(el);
			vec.push_back(Give<Behavior>(el));
		}
	}
}