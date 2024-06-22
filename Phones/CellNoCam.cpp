#include "CellNoCam.h"

void CellNoCam::saveContact(const string& name, const string& number)
{
	if (contactsCount < 50)
	{
		Names[contactsCount] = name;
		PhoneNumbers[contactsCount++] = number;
		cout << endl << "New contact: " << name << " " << number << endl;
	}
	else
		cout << endl << "Contacts list is full" << endl;
}

void CellNoCam::deleteContact(const string& name)
{
	int flag = contactsCount;
	for (int i = 0; i < contactsCount; i++)
	{
		if (Names[i] == name)
		{
			Names[i] = Names[contactsCount - 1];
			PhoneNumbers[i] = PhoneNumbers[contactsCount - 1];
			contactsCount--;
			cout << "Contact deleted: '" << name << "'" << endl;
		}
	}
	if (contactsCount == flag)
		cout << "Contact '" << name <<"' not found" << endl;
}

void CellNoCam::GetTime() const
{
	cout << "The time is: " << Watch << endl;
}

void CellNoCam::SetTime()
{
	cout << "Enter time in format (HH:MM): ";
	cin >> Watch;
}

void CellNoCam::showContacts() const
{
	cout << endl << "Contacts list: " << endl;
	for (int i = 1; i <= contactsCount; i++)
	{
		cout << "Contact " << i << ": " << Names[i - 1] << " " << PhoneNumbers[i - 1] << endl;
	}
	cout << "End of contacts list." << endl;
}

int CellNoCam::getContactsCount() const
{
	return contactsCount;
}