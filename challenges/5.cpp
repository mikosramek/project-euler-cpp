/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/
#include <iostream>
#include <cstdio>
#include <math.h>
#include <cmath>
#include "utils/basic-functions.h"
using namespace std;

int divisors[18] = { 19, 17, 9, 7, 5, 18, 16, 14, 13, 12, 11, 20, 6, 8, 3, 4, 2, 10 };
//int divisors[9] = {  9, 7, 5, 6, 8, 3, 4, 2, 10 };


bool isEvenlyDivisible(long a, int b, bool debug) {
    double result = double(a) / b;
    long flooredResult = std::floor(result);
    bool answer = result == flooredResult;

//    x == std::floor(x)
    if (debug) {
        cout << "Result: " << result << " == " << flooredResult << " = " << (answer ? "true" : "false") << "\n\n";
    }
    return answer;
}

bool isTheTarget(long number, bool debug) {
    if(debug) {
        cout << "\n\n--------------\n";
    }
    for (int i = 0; i < 18; i += 1) {
        if (debug) {
            cout << "Number: " << number << "\n";
            cout << "Divisor: " << divisors[i] << "\n";
        }
        bool isEven = isEvenlyDivisible(number, divisors[i], debug);
        if (!isEven) {
            if (debug) {
                cout << "Number that isn't even :" << number << "\n";
            }
            return false;
        }
    }
    return true;
}

int main() {
    // Complete the code.
    long long start = 20;

    while (!isTheTarget(start, false)) {
        start += 1;
    }
//    int multipleCount = 100;
//    for (int i = 0; i < 19; i += 1) {
//        int count = 0;
//        int currentDivisor = divisors[i];
//        for(int x = 0; x < multipleCount; x += 1) {
//            if (isEvenlyDivisible(x, currentDivisor)) count += 1;
//        }
//        cout << "Count for " << currentDivisor << " between 0 and " << multipleCount << " is " << count << "\n";
//    }

//     isTheTarget(26142480, true);
//     isTheTarget(20, true);


    cout << start;
//    cout << isEvenlyDivisible(40, 20);

    return 0;
}


/*
    So my initial thought was completely wrong, as I thought 2520 could be divided by 10, then 9, then etc and still remain remainder-less. But it's that if
    you divide it by any of those numbers, it's all whole numbers.

    So how can I go about doing the reverse? I think going from 1-10 and getting 2520 is a good place to start with figuring out logic, as you have a smaller
    range, and the proper answer right here.

    I think going through all the numbers is a terrible idea, as you don't know the upward limit, and there isn't an easy cut-off point,
    -- sorry I misread it, and it's smallest number - so once we hit one that works, we can then keep that.
    We have what we can assume is a very low starting point of 2520.

    I suppose most brute force would be, start at 20, then loop through 2-20, and if any is not a whole number, add 1 and repeat


    Some rules that seem to make sense to me:
    can't be prime
    can't be odd - because of the 2 requirement
    the hardest numbers to be divisible by are: 19, 17, 9, 7, 5
    anything above 100 can be divided by 10 nicely

    so my initial thinking is just go up by 2, and divide in the order of:
    19, 17, 9, 7, 5, 18, 16, 14, 13, 12, 11, 20, 6, 8, 3, 4, 2, 10, (1)


    NOTE 2
    So currently my solution works for the example, but not for 1-20

    Count for 19 between 0 and 100 is 5
    Count for 17 between 0 and 100 is 5
    Count for 9 between 0 and 100 is 11
    Count for 7 between 0 and 100 is 14
    Count for 5 between 0 and 100 is 19
    Count for 18 between 0 and 100 is 5
    Count for 16 between 0 and 100 is 6
    Count for 14 between 0 and 100 is 7
    Count for 13 between 0 and 100 is 7
    Count for 12 between 0 and 100 is 8
    Count for 11 between 0 and 100 is 9
    Count for 20 between 0 and 100 is 4
    Count for 6 between 0 and 100 is 16
    Count for 8 between 0 and 100 is 12
    Count for 3 between 0 and 100 is 33
    Count for 4 between 0 and 100 is 24
    Count for 2 between 0 and 100 is 49
    Count for 10 between 0 and 100 is 9

    I wonder if it's safe to assume that it has to be a multiple of 20, and between 0 and 100, 20 has the least amount occurrences for being evenly divisible.

    So my issues were that: I was accidentally having an array-overflow resulting in diving by 0, and having NaN be the result for every number.
    The other issue was with how I was handling bigger numbers, and checking if they were even.
    I found std::floor to work a lot better, and made sure to use doubles instead of just floats - this allowed it to accurately calculate remainders.
*/
