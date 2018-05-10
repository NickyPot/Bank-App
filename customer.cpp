#include "customer.h"
#include"account.h"


customer::customer()
{
		
	numOfAccounts = 0;
	account acc[4];
	clientId = 0;
	clientName = "";
}

customer::customer(int id, string name)
{
	id = 0;
	name = "";
	clientId = id;
	clientName = name;
}

customer::~customer()
{
	
}

