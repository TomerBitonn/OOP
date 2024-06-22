#include "Phone.h"

void Phone::addToHistory(string callsHistory[], int& size,const string& phoneNumber)
{
	if (size < 10)
		callsHistory[size++] = phoneNumber;
	else
	{
		size = 0;
		callsHistory[size++] = phoneNumber;
	}
}

Phone::Phone()
{
	this->incoming_size = 0;
	this->outgoing_size = 0;
	setModel();
}

void Phone::acceptCall(const string& phoneNumber)
{
	cout << endl << "Recieving call from: " << phoneNumber << endl;
	addToHistory(IncomingCalls, incoming_size, phoneNumber);
}

void Phone::dialNumber(const string& phoneNumber)
{
	cout << endl << "Calling to: " << phoneNumber << endl;
	addToHistory(OutgoingCalls, outgoing_size, phoneNumber);
}

void Phone::showIncoming() const
{
	cout << endl << "Incoming calls list:" << endl;
	for (int i = 1; i <= incoming_size; i++)
		cout << "call " << i << ": " << IncomingCalls[i-1] << endl;
}

void Phone::showOutgoing() const
{
	cout << endl <<  "Outgoing calls list:" << endl;
	for (int i = 1; i <= outgoing_size; i++)
		cout << "call " << i << ": " << OutgoingCalls[i-1] << endl;
}

string Phone::getModel() const
{
	return Model;
}

void Phone::setModel() 
{
	string phone_model;
	cout << "Phone model: ";
	cin >> phone_model;
	this->Model = phone_model;
}