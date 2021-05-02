/*
The sum of the squares of the first ten natural numbers is:

1^2 + 2^2 ... + 10^2 = 385

The square of the sum of the first ten natural numbers is:

( 1 + 2 ... + 10 )^2 = 55^2 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers
and the square of the sum is:

3025 - 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

1^2 + 2^2 ... + 100^2 = a
( 1 + 2 ... + 100 )^2 = b

b - a = ?

*/

#include <iostream>
#include <cstdio>
#include <math.h>

#include "utils/basic-functions.h"

using namespace std;

int main() {
    // Complete the code.
    long int base = 0;
    long int sum = 0;
    for (int i = 1; i <= 100; i += 1) {
        long int power = pow(i, 2);
        base += power;
        sum += i;
    }

    long int result = pow(sum, 2) - base;

    cout << result << "\n";


    return 0;
}

/*

    So I guess this is just a nice loop? I assume the issue comes from having large numbers again...

    Yeah this felt like a simple problem, and didn't really have to do with math. But it was nice to see how to use pow(?)

*/
