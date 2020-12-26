// RSA Encrypt
#include <iostream>
#include <fstream>
#include "RSA.h"
#include "MathUtils.h"
#include <utility>
#include <numeric>

using namespace std;

int main() {
	RSA rsa;
	cout << rsa;

	string cmd = "";
	unsigned long long int val = 0;

	do {
		cin >> cmd;
		if (cmd == "encrypt") {
			cout << "Enter a message M, 0 <= M < " << rsa.getN() << ": " << endl;
			cin >> val;
			unsigned long long int ctext = rsa.encryptMessage(val);
			cout << "Cyphertext is: " << ctext << endl;
		}
		else if (cmd == "decrypt") {
			cout << "Enter cyphertext C, 0 <= C < " << rsa.getN() << ": " << endl;
			cin >> val;
			unsigned long long int msg = rsa.decryptMessage(val);
			cout << "Message is: " << msg << endl;
		}
	} while (cmd != "quit");
}

