#include <iostream>
#include <string>
using namespace std;

#pragma once
class Phone
{
private:
	string IncomingCalls[10];
	string OutgoingCalls[10];
	int incoming_size;
	int outgoing_size;
	string Model;
	void addToHistory(string callsHistory[], int& size, const string& phoneNumber);
public:
	Phone();
	virtual void acceptCall(const string& phoneNumber);
	virtual void dialNumber(const string& phoneNumber);
	virtual void showIncoming() const;
	virtual void showOutgoing() const;
	string getModel() const;
	void setModel();
};