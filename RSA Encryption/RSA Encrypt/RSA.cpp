#include "RSA.h"
#include "MathUtils.h"
#include <utility>
#include <cmath>
using namespace std;

// TODO: Delegating constructor
RSA::RSA() {
	std::pair<unsigned long long, unsigned long long> primes = MathUtils::uniquePrimePair();
	p = primes.first;
	q = primes.second;
	n = p * q;
	phi = (p - 1) * (q - 1);
	e = MathUtils::findCoprime(phi);
	d = MathUtils::calculatePrivateKey(phi, e);
}

unsigned long long RSA::getE() const {
	return e;
}

unsigned long long RSA::getN() const {
	return n;
}

unsigned long long RSA::getP() const {
	return p;
}

unsigned long long RSA::getQ() const {
	return q;
}

unsigned long long RSA::getPhi() const {
	return phi;
}

unsigned long long RSA::getD() const {
	return d;
}

string RSA::encryptMessage(string msg) const {
	return msg;
}

string RSA::decryptMessage(string ctxt) const {
	return ctxt;
}

unsigned long long RSA::encryptMessage(unsigned long long int msg) const {
	// Calculates msg ^ e (mod n)
	unsigned long long int num = MathUtils::modPow(msg, this->getE(), this->getN());
	return num;
}

unsigned long long RSA::decryptMessage(unsigned long long int ctxt) const {
	// Calculates ctxt ^ d (mod n)
	unsigned long long int num = MathUtils::modPow(ctxt, this->getD(), this->getN());
	return num;
}

ostream& operator<<(ostream& os, const RSA& rsa) {
	os << "Public key (e,n): " << "(" << rsa.getE() << ", " << rsa.getN() << ")" << endl;
	os << "Private key (d,n): " << "(" << rsa.getD() << ", " << rsa.getN() << ")" << endl;
	os << "p = " << rsa.getP() << ", q = " << rsa.getQ() << ", and phi(n) = " << rsa.getPhi() << endl;
	return os;
}
