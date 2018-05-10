#include <iostream>
#include "customer.h"
#include <string>
using namespace std;

//main function
customer client[4];   //class array for accounts
double custDep = 0;// custom deposit for accounts



//functions

//look for account and add deposit
int lookAccDep(int a,int accNum)
{
	switch (accNum) {

	case 0: client[a].accZero.setclientBal(client[a].accZero.getclientBal() + custDep); cout << " The new balance is " << client[a].accZero.getclientBal()<<endl; break;
	case 1: client[a].accOne.setclientBal(client[a].accOne.getclientBal() + custDep); cout << " The new balance is " << client[a].accOne.getclientBal() << endl; break;
	case 2: client[a].accTwo.setclientBal(client[a].accTwo.getclientBal() + custDep); cout << " The new balance is " << client[a].accTwo.getclientBal() << endl; break;
	case 3: client[a].accThree.setclientBal(client[a].accThree.getclientBal() + custDep); cout << " The new balance is " << client[a].accThree.getclientBal() << endl; break;
	case 4: client[a].accFour.setclientBal(client[a].accFour.getclientBal() + custDep); cout << " The new balance is " << client[a].accFour.getclientBal() << endl; break;
	default:cout << "ERROR"<<endl;
	}
	return 0;
}
//look for account and add deposit


//look for account and add ten deposit
int lookAccDepTen(int a, int accNum)
{
	switch (accNum) {

	case 0: client[a].accZero.setclientBal(client[a].accZero.getclientBal() + 10); cout << " The new balance is " << client[a].accZero.getclientBal() << endl; break;
	case 1: client[a].accOne.setclientBal(client[a].accOne.getclientBal() + 10); cout << " The new balance is " << client[a].accOne.getclientBal() << endl; break;
	case 2: client[a].accTwo.setclientBal(client[a].accTwo.getclientBal() + 10); cout << " The new balance is " << client[a].accTwo.getclientBal() << endl; break;
	case 3: client[a].accThree.setclientBal(client[a].accThree.getclientBal() + 10); cout << " The new balance is " << client[a].accThree.getclientBal() << endl; break;
	case 4: client[a].accFour.setclientBal(client[a].accFour.getclientBal() + 10); cout << " The new balance is " << client[a].accFour.getclientBal() << endl; break;
	default:cout << "ERROR" << endl;

	}
	return 0;
}
//look for account and add ten deposit

//look for account and add overdraft
int lookAccDepOv(int a, int accNum,int overdraft)
{
	switch (accNum) {

	case 0: client[a].accZero.setclientBal(client[a].accZero.getclientBal() + overdraft); cout << " The new available balance is " << client[a].accZero.getclientBal() << endl; break;
	case 1: client[a].accOne.setclientBal(client[a].accOne.getclientBal() + overdraft); cout << " The new available balance is " << client[a].accOne.getclientBal() << endl; break;
	case 2: client[a].accTwo.setclientBal(client[a].accTwo.getclientBal() + overdraft); cout << " The new available balance is " << client[a].accTwo.getclientBal() << endl; break;
	case 3: client[a].accThree.setclientBal(client[a].accThree.getclientBal() + overdraft); cout << " The available new balance is " << client[a].accThree.getclientBal() << endl; break;
	case 4: client[a].accFour.setclientBal(client[a].accFour.getclientBal() + overdraft); cout << " The new available balance is " << client[a].accFour.getclientBal() << endl; break;
	default:cout << "ERROR" << endl;

	}
	return 0;
}
//look for account and add overdraft

//functions



int main()
{	//Variables
	string nameOfClient;//takes in the name of the client when a new client is created
	int welcome;//takes in either the client id when the clerk is looking for an existing customer or takes 11 to create a new customer
	string pinNum;  //takes in the pin when it typed by either the customer or the clerk
	string decFornewClietnts; //takes in whether a deposit, withdraw, overdraft or loan is needed
	int overdraft;//takes in how much overdraft is needed
	double withdraw;// takes in how much is to be withdrawn
	double interestRate;// takes in the interest rate for loan
	int accNum;// takes in the account number 0,1,2,3,4
	int loan;// takes in the amount of money that is to borrowed
	string *pPin;

	pPin = &pinNum;

	//pre-existing accounts
	//Nick
	client[0].setclientName("Nick");
	client[0].setclientId(0);
	client[0].accZero.setclientBal(1000);
	client[0].setPin("1234");

	//john
	client[1].setclientName("john");
	client[1].setclientId(1);
	client[1].accZero.setclientBal(500);
	client[1].setPin("4567");

	//end of pre-existing accounts

	//set up an object at each index on the array
	for (int i = 0; i < 4; i++)
	{
		client[i].setclientId(i);
	}


	


	//Either create a new account or get info and manipulate an existing account
	for (;;) {

		cout << "----------Welcome to the Bank Of Abertay----------" << "\n" << "Input Client ID or input 11 to input a new client" << "\n"; //welcome message

		cin >> welcome;

		//creates new account	
		if (welcome == 11)
		{
			for (int a = 0; a < 4; a++)
			{
				//Looks for empty space for new account and can make a quick deposit
				if (client[a].getclientName() == "")
				{
					cout << "\n The account Id that has been selected and is " << a << ". " << "PLease input the full name of the client: \n";
					cin.ignore();
					getline(cin, nameOfClient);
					cout << "\n Please tell the customer to input his desired PIN\n ";
					getline(cin, *pPin);
					client[a].setPin(pinNum);
					pinNum = "0000";
					client[a].setclientId(a);
					client[a].setclientName(nameOfClient);
					cout << "What overdraft would they like? ";
					cin >> overdraft;
					cout << "For which account?";
					cin >> accNum;
					lookAccDepOv(a, accNum, overdraft);

					cout << "Would the customer like to make their first depost? Press y for a custom deposit, n for no deposit or type ten to make a quick 10 pound deposit.";
					cin >> decFornewClietnts;

					//depeding on the input of the user, the app decides if a quick or custom depositis to be made
					if (decFornewClietnts == "y")//custom deposit
					{
						cout << "How much do they want to deposit?";
						
						cin >> custDep;
						cout << "In which account? ";
						cin >> accNum;
						lookAccDep(a, accNum);
						

					}

					else if (decFornewClietnts == "ten")//quick 10 pound deposit
					{
						cout << "In which account? ";
						cin >> accNum;

						lookAccDepTen(a,accNum);

					}
					else
					{
						break;
					}
					break;
				}


			}
		}


		//looks up an existing account
		else
		{
			//cout << client[welcome].getclientBal() << "\n" << client[welcome].getclientId() << "\n" << client[welcome].getclientName()<<client[welcome].getclientBal();

			cout << "\n The account Id that has been selected is " << welcome << ". " << "Under the name " << client[welcome].getclientName();
			cin.ignore();

			cout << "\n Please tell the customer to input his  PIN\n ";
			getline(cin, *pPin);
			if (pinNum == client[welcome].getPin())//if the pin is correct
			{
				*pPin = "0000";//reset the pin to 0000
				for (;;)
				{
					cout << endl<<"Would the customer like to make a deposit, a withdrawal, apply for overdraft or get a loan? Press c for a custom deposit, type ten to make a quick 10 pound deposit,w for a withdrawal, o for overdraft or l for a loan check, or break to exit.";
					cin>>decFornewClietnts;


					if (decFornewClietnts == "c")//custom deposit
					{
						cout << "Which account do they want to make the deposit in?";
						cout << "Please input the custom deposit now:";
						cin >> custDep;
						cout << "In which account? ";
						cin >> accNum;

						lookAccDep(welcome, accNum);// custom deposit function



					}

					else if (decFornewClietnts == "ten")//quick 10 pound deposit
					{
						cout << "In which account? ";
						cin >> accNum;

						lookAccDepTen(welcome, accNum);

					}
					else if (decFornewClietnts == "w")//withdraw
					{
						cout << "Please input the account number from which they desire to withdraw: ";
						cin >> accNum;
						cout << "Please input the amount they desire to withdraw: ";
						cin >> withdraw;

						//looks for which account was selected and withdraws thew specified amount
						switch (accNum) {
						case 0:

							if (client[welcome].accZero.getclientBal() - withdraw >= 0)
							{
								client[welcome].accZero.setclientBal(client[welcome].accZero.getclientBal() - withdraw);
								cout << "The new balance is: " << client[welcome].accZero.getclientBal()<<endl;
							}
							else
							{
								cout << "Funds available not enough" << endl;
							}break;
						case 1: if (client[welcome].accOne.getclientBal() - withdraw >= 0)
						{
							client[welcome].accOne.setclientBal(client[welcome].accOne.getclientBal() - withdraw);
							cout << "The new balance is: " << client[welcome].accOne.getclientBal() << endl;
						}
								else
								{
									cout << "Funds available not enough" << endl;
								}break;
						case 2: if (client[welcome].accTwo.getclientBal() - withdraw >= 0)
						{
							client[welcome].accTwo.setclientBal(client[welcome].accTwo.getclientBal() - withdraw);
							cout << "The new balance is: " << client[welcome].accTwo.getclientBal() << endl;
						}
								else
								{
									cout << "Funds available not enough" << endl;
								}break;
						case 3:if (client[welcome].accThree.getclientBal() - withdraw >= 0)
						{
							client[welcome].accThree.setclientBal(client[welcome].accThree.getclientBal() - withdraw);
							cout << "The new balance is: " << client[welcome].accThree.getclientBal() << endl;
						}
							   else
							   {
								   cout << "Funds available not enough" << endl;
							   }break;
						case 4:if (client[welcome].accFour.getclientBal() - withdraw >= 0)
						{
							client[welcome].accFour.setclientBal(client[welcome].accFour.getclientBal() - withdraw);
							cout << "The new balance is: " << client[welcome].accFour.getclientBal() << endl;
						}
							   else
							   {
								   cout << "Funds available not enough" << endl;
							   }break;
						}

					}

					else if (decFornewClietnts == "o")
					{
						//Applies Overdraft
						cout << "What overdraft would they like? ";
						cin >> overdraft;
						cout << "For which account?";
						cin >> accNum;
						lookAccDepOv(welcome, accNum,overdraft);

					}
					else if (decFornewClietnts == "l")//if the client wants to take out a loan
					{
						cout << "What is the interest rate for the loan" << endl;
						cin >> interestRate;
						cout << "What is the amount that the customer wants to borrow?" << endl;
						cin >> loan;
						cout << "From which account?" << endl;
						cin >> accNum;
						switch (accNum) {
						case 0: if (loan < 2 * client[welcome].accZero.getclientBal())
						{
							cout << "The loan can be granted and the amount that will have to be paid back is " << loan*interestRate + loan << "pounds." << endl;
						}
								else
								{
									cout << "The loan can't be granted";
								}break;

						case 1: if (loan < 2 * client[welcome].accOne.getclientBal())
						{
							cout << "The loan can be granted and the amount that will have to be paid back is " << loan*interestRate + loan << "pounds." << endl;
						}
								else
								{
									cout << "The loan can't be granted";
								}break;

						case 2: if (loan < 2 * client[welcome].accTwo.getclientBal())
						{
							cout << "The loan can be granted and the amount that will have to be paid back is" << loan*interestRate + loan << "pounds." << endl;
						}
								else
								{
									cout << "The loan can't be granted";
								}break;

						case 3: if (loan < 2 * client[welcome].accThree.getclientBal())
						{
							cout << "The loan can be granted and the amount that will have to be paid back is" << loan*interestRate + loan << "pounds." << endl;
						}
								else
								{
									cout << "The loan can't be granted";
								}break;

						case 4: if (loan < 2 * client[welcome].accFour.getclientBal())
						{
							cout << "The loan can be granted and the amount that will have to be paid back is" << loan*interestRate + loan << "pounds." << endl;
						}
								else
								{
									cout << "The loan can't be granted";
								}break;
						}



					}





					else if (decFornewClietnts == "break")
					{
						break;
					}
				}





			}//for if pin  is correct
			else //if the ping is wrong
			{
				cout << "The PIN was wrong \n";

			}
		}//stop for big else cust

	}
}