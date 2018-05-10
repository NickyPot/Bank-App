#pragma once

class account
{
private:
	double balance;
	


public:
	account();
	~account();
	//getter for client balance 
	double getclientBal() {
		return balance;
	}

	//setter for client balance 
	void setclientBal(double bal) {
		balance = bal;
	}
	

};

