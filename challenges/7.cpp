/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?
*/
#include <iostream>
#include <cstdio>
#include "utils/basic-functions.h"

using namespace std;


// TODO: Remove all this manual checking
// instead https://primes.utm.edu/prove/merged.html
// to test for n, divide by all of the primes less than the square root of n
// For example, to show is 211 is prime, we just divide by 2, 3, 5, 7, 11, and 13
bool isPrime(int n) {
    return n % 2 != 0 &&
           n % 3 != 0 &&
           n % 5 != 0 &&
           n % 7 != 0 &&
           n % 11 != 0 &&
           n % 13 != 0 &&
           n % 17 != 0 &&
           n % 19 != 0 &&
           n % 23 != 0;
}

int primes[101] = {2, 3, 5, 7, 11, 13, 17, 19, 23};

long getNextPrime(long long currentNumber, int primeCount) {
    // if isn't prime, add one, go next,
    // if is prime, and primecount === 10,001 then return currentNumber
    // if is prime, add to primecount, add one, go next
    if (!isPrime(currentNumber)) {
        return getNextPrime(++currentNumber, primeCount);
    }
    else if (isPrime(currentNumber) && primeCount == 100) {
        cout << "Final? " << primeCount << "\n\n";
        primeCheck(primes);
        return currentNumber;
    }
    else if (isPrime(currentNumber)) {
//        cout << "Count: " << primeCount << " Numbah:" << currentNumber << "\n\n";
        primes[primeCount] = currentNumber;
        currentNumber += 1;
        primeCount += 1;
        return getNextPrime(currentNumber, primeCount);
    }
    else {
        cout << "Oops? " << primeCount << "\n\n";
        return currentNumber;
    }
}

int main() {
    // Complete the code.
    long long result = getNextPrime(14, 9);
    cout << result;

//    cout << (isPrime(121) ? "true" : "false");
//
//    cout << 121 % 7;

    return 0;
}
