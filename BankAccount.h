/*
 * BankAccount.h
 *
 *  Created on: Oct 21, 2015
 *      Author: Erika
 */

#ifndef BANKACCOUNT_H_
#define BANKACCOUNT_H_

#include <string>
using namespace std;

class BankAccount {

//all the information held in an account
private:
	string firstName;
	string lastName;
	int accountNumber;
	double balance;
	bool activeStatus;

//all of the functions the user can use to create and change bank accounts
public:
	BankAccount();
	BankAccount(string firstName, string lastName, int accountNumber, double balance);
	void deposit(double depositAmount);
	double withdraw(double withdrawAmount);
	double getBalance() const;
	double closeAccount();
	void printAccountInfo();

};

#endif /* BANKACCOUNT_H_ */
