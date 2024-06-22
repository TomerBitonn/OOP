#define _CRT_SECURE_NO_WARNINGS
#include "Account.h"

int Account::accountIdGenerator = 1; 

Account::Account(const char* name, double money)
{
	strncpy(this->name, name, sizeof(this->name) - 1); 
	this->name[sizeof(this->name) - 1] = '\0';
	this->money = money;
	accountId = accountIdGenerator;
	accountIdGenerator++;
	next = NULL; 
}

char *Account::GetName() const
{
	return (char*)name; 
}

void Account::SetName(const char* new_name)
{
	strncpy(this->name, new_name, sizeof(this->name) - 1);
	this->name[sizeof(this->name) - 1] = '\0';
}

void Account::SetNext(Account& next_account) 
{
	this->next = &next_account; 
}

Account* Account::GetNext() const
{
	return this->next;
}

void Account::print() const
{
	cout << "Name:" << name << endl << "Account Balance:" << money << endl 
		        << "Account ID:" << accountId << endl << endl;
}

ostream& operator<<(ostream& output, const Account& customer)
{
	output << "Name: " << customer.name <<" Amount of money: " << customer.money << " Account ID: "
		         << customer.accountId << endl;
	return output;
}
