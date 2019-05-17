#pragma once
#include <iostream>
enum class PricingStrat;

struct UnitEconomy
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
	UnitEconomy(int ua, double conv, int prodcount, double prodav, int cogsp, double cogsfix, double apc, double cpa)
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

enum class PricingStrat
{

};



void Print(UnitEconomy* ec)
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
		<< ec->AC << std::endl
		<< "Revenue:"
		<< ec->REV << std::endl
		<< "...." << std::endl
		<< "...." << std::endl
		<< "...." << std::endl
		<< "Profit???:"
		<< (int)ec->CM << std::endl;
}
