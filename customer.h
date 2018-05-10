#pragma once
using namespace std;
#include <string>
#include "account.h"

class customer
{
	
private:
	string clientName;
	int clientId;
	int numOfAccounts;
	string pin;
	



public:
	customer();
	customer(int id, string name);
	~customer();

	account accZero;
	account accOne;
	account accTwo;
	account accThree;
	account accFour;

	//getter for client name
	string getclientName()
	{
		return clientName;
	}
	
	//setter for client name
	void setclientName(string name)
	{
		clientName = name;
	}

	//getter for client id
	int getclientId()
	{
		return clientId;
	}

	//setter for client id
	void setclientId(int id)
	{
		clientId = id;
	}

	

	//getter for client pin
	string getPin() {
		return pin;
	}

	//setter for client pin
	void setPin(string clientPin) {
		pin = clientPin;
	}

	
};

