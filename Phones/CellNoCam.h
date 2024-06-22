#include "Phone.h"

#pragma once
class CellNoCam : public Phone 
{
private:
	string Names[50];
	string PhoneNumbers[50];
	string Watch;
	int contactsCount;
public:
	CellNoCam() { contactsCount = 0, Watch = "00:00"; }
	virtual void saveContact(const string& name, const string& number);
	virtual void deleteContact(const string& name);
	virtual void GetTime() const;
	virtual void SetTime();
	virtual void showContacts() const;
	int getContactsCount() const;
};