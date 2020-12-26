#pragma once
#include <utility>
#include <fstream>
#include <iostream>

// smallest valid prime
const unsigned long long int PRIME_MIN = 15;
// 2^32, if number is bigger, then it will overflow unsigned long long
const unsigned long long int PRIME_MAX = 4294967296;
// How many primes to check for in file
const int NUM_PRIMES_TO_CHECK = 10000;

class MathUtils
{
public:
	/**
	 * Returns a pair of unique primes
	 */
	static std::pair<unsigned long long int, unsigned long long int> uniquePrimePair();

	/**
	 * Returns whether num is a prime
	 */
	static bool isPrime(unsigned long long int num);

	/**
	 * finds a co-prime for num
	 */
	static unsigned long long int findCoprime(unsigned long long int num);

	/**
	 * Calculates the value of d in (d,n) the private key from phi(n) and the public key (e,n)
	 */
	static unsigned long long calculatePrivateKey(unsigned long long int phi, unsigned long long int e);

	static long long int eea(long long int a, long long int b);

	/**
	 * Calculates the value of b^e (mod m)
	 */
	static long long int modPow(unsigned long long int b, unsigned long long int e, unsigned long long int m);

	/**
	 * Calculates the value of a * b (mod m)
	 */
	static long long int modMult(unsigned long long int a, unsigned long long int b, unsigned long long int m);

private:
	/**
	 * Returns the prime at index primeIndex in the file
	 */
	static unsigned long long getPrimeFromFile(int primeIndex);
};

