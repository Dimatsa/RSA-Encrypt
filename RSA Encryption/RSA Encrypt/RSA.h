#pragma once
#include <string>
#include <iostream>
using namespace std;

class RSA
{
	unsigned long long int p;
	unsigned long long int q;
	unsigned long long int n;
	unsigned long long int e;
	unsigned long long int phi;
	unsigned long long int d;

public:
	RSA();
	string encryptMessage(string msg) const;
	string decryptMessage(string ctxt) const;
	unsigned long long int encryptMessage(unsigned long long int msg) const;
	unsigned long long int decryptMessage(unsigned long long int ctxt) const;
	
	unsigned long long int getP() const;
	unsigned long long int getQ() const;
	unsigned long long int getN() const;
	unsigned long long int getE() const;
	unsigned long long int getPhi() const;
	unsigned long long int getD() const;
};

ostream& operator<<(ostream& os, const RSA& rsa);

