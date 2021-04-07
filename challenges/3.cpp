/* 
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 - 600,851,475,143?
 */
#include <iostream>
#include <cstdio>
using namespace std;

const int PRIME_COUNT = 1000;

bool isPrime(int n) {
    return n % 2 != 0 && n % 3 != 0 && n % 5 != 0 && n % 7 != 0;
}

int * getPrimes() {
    static int primes [PRIME_COUNT] = { 2, 3, 5, 7 };
    int currentIndex = 4;
    int num = 8;
    while (currentIndex < PRIME_COUNT) {
        if (isPrime(num)) {
            primes[currentIndex] = num;
            currentIndex += 1;
        }
        num += 1;
    }
    return primes;
}

void log(int number) {
    cout << number << "\n";
}
void log(string message) {
    cout << message << "\n";
}
void log(long number) {
    cout << number << "\n";
}

int main() {
    // note 1
    int * primes = getPrimes();
    // note 2
    // for (int i = 0; i < PRIME_COUNT; i += 1) {
    //     cout << primes[i] << " ";
    // }
    long total = 600851475143;
    log(total);
    int primeIndex = 0;
    bool done = false;
    while (total / primes[primeIndex] != 1 && !done) {
        long currentPrime = primes[primeIndex];
        if (total % currentPrime > 0) {
            primeIndex += 1;
        }
        else {
            log("Total:");
            cout << total << " -> " << total / currentPrime << "\n";
            total /= currentPrime;
            log("CurrentPrime:");
            log(currentPrime);
            primeIndex += 1;
            // note 3
            if (total / primes[primeIndex] == 1) {
                log(total);
                done = true;
            }
        }
    }
    return 0;
}

/* NOTE 1
I'm not quite sure how to find prime factors, so that's something I'll be looking up.

A Prime:
"a whole number greater than 1 that can not be made by multiplying other whole numbers"

"'Factors' are the numbers you multiply together to get another number:"

"'Prime Factorization' is finding which prime numbers multiply together to make the original number."

My initial thinking for an approach: have a list of prime numbers. and slowly go up in that list. if it has remainders when divided, move onto next prime number, repeat until result is 1. The numbers used to divide are the prime factors. We then just need to see the largest one of those.
Something bruteforce could work? But also something recursive could be good.
 */

/* NOTE 2

Now I have a list of prime numbers, and I have easily change how many I want.
[ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71 ]
So the next thing is to test the divisions, and see how low I can get with just 20 primes.

One thing to update my thinking, is that I don't need to keep track of which primes I've used. Just the current index of prime, and the
current division "total". The final number where total / prime == 1 is where I stop and return that number.
 */

/* NOTE 3

So this part was more of a jump in logic that happened. Rather than getting the whole next thing of primes, and I suppose my
initial logic here was flawed - I needed to not do that, and rather instead remove one from the index?

But looking at the example, of 13195 - the highest factor is 29. But that's also the final number you'll get. If you divide by 
5, 7, and 13, you end up with 29 - and 29 / 29 is 1 and is a prime number.

So my initial output was giving my the next prime number in the sequence, when I really needed to be looking at the total I had,
before the while loop ended.

I also created 3 helper functions to log out new-lines, and maybe I should move those into a util header file?
 */