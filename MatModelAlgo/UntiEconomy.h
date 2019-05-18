#pragma once
#include <iostream>
enum class PricingStrat;

struct UnitEconomyForJohnSnow
{
	int UA;				//+
	double CONV;		//+
	double CL;				//
	int PRODCOUNT;		//+
	double PRODAV;		//+
	double PRICEAV;		//
	int COGSP;			//+
	double COGSFIX;		//+
	double COGS;			//
	double APC;			//+
	double ARPC;		//
	double ARPU;		//
	double CAC;			//
	double CPA;			//+
	double AC;			//
	double REV;			//
	double CM;			//
	UnitEconomyForJohnSnow() {}
	UnitEconomyForJohnSnow(int ua, double conv, int prodcount, double prodav, int cogsp, double cogsfix, double apc, double cpa)
	{
		UA = ua;
		CONV = conv;
		CL = UA * CONV;
		PRODCOUNT = prodcount;
		PRODAV = prodav;
		PRICEAV = PRODCOUNT*PRODAV;
		COGSP = cogsp;	
		COGSFIX = cogsfix;
		COGS = PRICEAV*COGSP + COGSFIX;	
		APC = apc;	
		ARPC = (PRICEAV - COGS) * APC;
		ARPU = ARPC * CONV;
		CPA = cpa;		
		AC = CPA * UA;
		CAC = AC / CL;
		REV = CONV * PRICEAV * APC;
		CM = ARPU * UA - AC;
	}
};

void Print(UnitEconomyForJohnSnow* ec)
{
	std::cout
		<< "Number of acquired users:"
		<< ec->UA << std::endl
		<< "Users conversion:"
		<< ec->CONV << std::endl
		<< "Clients per month:"
		<< ec->CL << std::endl
		<< "Number of products in stash:"
		<< ec->PRODCOUNT << std::endl
		<< "Average product price:"
		<< ec->PRODAV << std::endl
		<< "Average final summ:"
		<< ec->PRICEAV << std::endl
		<< "Variable costs:"
		<< ec->COGSP << std::endl
		<< "Constant costs:"
		<< ec->COGSFIX << std::endl
		<< "Overall costs:"
		<< ec->COGS << std::endl
		<< "Average num of deals per client:"
		<< ec->APC << std::endl
		<< "Average summ per client:"
		<< ec->ARPC << std::endl
		<< "Average summ per user:"
		<< ec->ARPU << std::endl
		<< "Cost of client acquisiton:"
		<< ec->CAC << std::endl
		<< "Cost of user acquisition:"
		<< ec->CPA << std::endl
		<< "Marketing budget:"
		<< (int)ec->AC << std::endl
		<< "Revenue:"
		<< ec->REV << std::endl
		<< "...." << std::endl
		<< "...." << std::endl
		<< "...." << std::endl
		<< "Profit???:"
		<< (int)ec->CM << std::endl;
	std::cout << std::endl;
}

struct UnitEconomyFull
{
	//Plan
	int U	 ;//Количество клиентов
	int FC	 ;//Постоянные затраты
	int ATV	 ;//Средняя стоимость покупки за период
	int AN	 ;//Среднее кол-во покупок за период
	int P	 ;//Рентабельность среднего чека
	int T	 ;//Средняя продолжительность жизни клиента(в периодах)
	int NC	 ;//Число новых клиентов
	int CAC	 ;//Стоимость привлечения клиентов
	//Facts	  //
	int R	 ;//Выручка (Валовый доход)
	int VC	 ;//Переменные затраты
	int FCd	 ;//Постоянные затраты
	int NP	 ;//Число покупок(чеков)
	int U	 ;//Число клиентов совершивших покупки
	int NC	 ;//Число новых клиентов
	int MCCnc;//Стоимость всех затрат на привлечение новых клиентов
	int T	 ;//Средняя продолжительность жизни клиента
};
