/*
 * BankAccount.cpp

 *
 *  Created on: Oct 21, 2015
 *      Author: Erika
 */
#include <string>
#include <math.h>
#include <cstdlib>
#include <iostream>
#include "BankAccount.h"

using namespace std;

//the constructor
BankAccount:: BankAccount() {

	 //initializes the account number and balance to 0
	 accountNumber = 0;
	 balance = 0.0;
	 //the account starts off inactive
	 activeStatus = false;


	cout << "An account cannot be opened without an initial deposit greater than 0"<< endl;

}

BankAccount:: BankAccount(string firstName, string lastName, int accountNumber, double balance) {

	//allows the user to create an account with a first name, last name, account number and a balance amount
	this->firstName = firstName;
	this->lastName = lastName;
	this->accountNumber = accountNumber;
	this->balance = balance;

	//once the user creates an account, it becomes active
	activeStatus = true;

}

//allows the user to put money into the account
void BankAccount:: deposit(double depositAmount){

	//if the user tries to deposit a negative amount or 0, an error will be printed out
	if (depositAmount < 0){
		cout << "Error: deposit amount cannot be negative"<< endl;
		return;
	}else if (depositAmount == 0){
		cout << "Error: no money"<< endl;
	}else {
		//otherwise, the deposit amount will be added to the current balance which will become the new balance
		balance = balance+ depositAmount;
	}

}

//allows the user to take money out of the account
double BankAccount:: withdraw(double withdrawAmount){

	//if the user tries to withdraw a negative amount or an amount greater than the current balance, an error will be printed out
	if (withdrawAmount < 0){
		cout << "Error: withdraw amount cannot be negative"<< endl;
		return 0.0;
	} else if (withdrawAmount > balance){
		cout << "Error: withdraw amount cannot be greater than the current balance"<< endl;
		return 0.0;
	}else {
		//otherwise the withdraw amount will be subtracted from the balance and the withdraw amount will be returned
		balance = balance - withdrawAmount;
		return withdrawAmount;
	}
}

//returns the current balance without changing anything
double BankAccount:: getBalance() const{
	return balance;
}

//closes the account and returns the balance at the time of closing
double BankAccount:: closeAccount(){

	//gets the balance and then sets it equal to 0
	double balanceAtClosing = getBalance();
	balance = 0.0;

	//once the account is closed, it is no longer active
	activeStatus = false;

	return balanceAtClosing;
}

//prints out all of the account information
void BankAccount:: printAccountInfo(){

	cout << "Account Number:" << accountNumber << endl;
	cout << "Name:" << lastName << ", " << firstName<< endl;
	cout << "Balance:" << balance  << endl;

	//lets the user know if the account is active or not
	if (activeStatus == true){
	cout << "Active: Yes"<< endl;
	}else {
		cout << "Active: No" << endl;
	}

}
