#include "pch.h"
#include "UntiEconomy.h"
#include <iostream>
#include <vector>

template <typename T>
void PrintVec(std::vector<T> vec)
{
	for (auto el : vec)
	{
		std::cout << el << std::endl;
	}
}

int main()
{
	UnitEconomy* ec = new UnitEconomy(15000, 0.0157, 2, 1400, 0, 900, 1.4, 13);
	Print(ec);
	return 0;
}

