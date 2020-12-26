#include "MathUtils.h"
#include <numeric>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

/**
*  Returns two unique random primes read from the file
*/
std::pair<unsigned long long int, unsigned long long int> MathUtils::uniquePrimePair()
{
	do {
		srand((unsigned int)time(NULL));
		// Index to find the prime numbers in the file
		int primeIndex1 = rand() % NUM_PRIMES_TO_CHECK;
		int primeIndex2 = rand() % NUM_PRIMES_TO_CHECK;

		unsigned long long int prime1 = getPrimeFromFile(primeIndex1);
		unsigned long long int prime2 = getPrimeFromFile(primeIndex2);

		if (primeIndex1 == primeIndex2 || prime1 == prime2) {
			cout << "Primes are equal. Selecting new random primes in file" << endl;
		} 
		else if (!isPrime(prime1)) {
			cout << prime1 << " is not a prime" << endl;
		} 
		else if (!isPrime(prime2)) {
			cout << prime2 << " is not a prime" << endl;
		}
		else if (prime1 >= PRIME_MAX) {
			cout << prime1 << " is too big!" << endl;
		} 
		else if (prime2 >= PRIME_MAX) {
			cout << prime2 << " is too big!" << endl;
		}
		else {
			return std::pair<unsigned long long int, unsigned long long int>(prime1, prime2);
		}
	} while (true);
}

unsigned long long int MathUtils::findCoprime(unsigned long long int num) {
	for (int i = 0; i < NUM_PRIMES_TO_CHECK; ++i) {
		unsigned long long int numToTest = getPrimeFromFile(i);
		if (gcd(num, numToTest) == 1) {
			return numToTest;
		}
	}
	return 0;
}

unsigned long long MathUtils::getPrimeFromFile(int primeIndex) {
	ifstream file;
	// Retrieves the file for the primes
	ifstream primes("primes.txt");
	primes.exceptions(ios::eofbit | ios::failbit);

	unsigned long long int prime = 0;
	for (int i = 0; i < primeIndex; ++i) {
		try {
			primes >> prime;
		}
		catch (ios::failure&) {
			if (primes.eof()) break;
			primes.clear();
			primes.ignore();
		}
	}

	return prime;
}

bool MathUtils::isPrime(unsigned long long int num) {
	if (num <= 1) {
		return false;
	}

	for (unsigned long long int i = 2; i <= num / 2; ++i) {
		if (num % i == 0) {
			return false;
		}
	}

	return true;
}

unsigned long long int MathUtils::calculatePrivateKey(unsigned long long int phi, unsigned long long int e) {
	long long int val = MathUtils::eea(phi, e);
	if (val >= 0) {
		return val;
	}
	else {
		return val + phi;
	}
}

long long int MathUtils::eea(long long int a, long long int b) {
	struct row {
		long long int a;
		long long int b;
		long long int r;
		long long int q;
	};

	vector<row> rows;

	rows.push_back(row{ 1 , 0 , a, 0 });
	rows.push_back(row{ 0, 1, b, 0 });

	while (true) {
		// Calculating values for new row
		long long int newQ = rows[0].r / rows[1].r;
		long long int newA = rows[0].a - newQ * rows[1].a;
		long long int newB = rows[0].b - newQ * rows[1].b;
		long long int newR = rows[0].r - newQ * rows[1].r;

		// New row to be placed at index 2
		rows.push_back(row{ newA, newB, newR, newQ });

		// Returns the value of b in the second-to-last row
		if (rows[2].r == 0) {
			return rows[1].b;
		}

		// Remove first row
		rows.erase(rows.begin());
	}
}

long long int MathUtils::modPow(unsigned long long int b, unsigned long long int e, unsigned long long int m)
{
	if (m == 1) {
		return 0;
	}

	unsigned long long int r = 1;
	b = b % m;

	while (e > 0) {
		if (e % 2 == 1) {
			r = MathUtils::modMult(r, b, m);
		}

		e = floor(e / 2);
		b = MathUtils::modMult(b, b, m);
	}
	return r;
}

long long int MathUtils::modMult(unsigned long long int a, unsigned long long int b, unsigned long long int m)
{
	unsigned long long int result = 0;
	a %= m;
	
	while (b > 0) {
		if (b % 2 == 1) {
			result = (result + a) % m;
		}

		a = (a * 2) % m;
		b /= 2;
	}
	
	result %= m;

	return result;
}


