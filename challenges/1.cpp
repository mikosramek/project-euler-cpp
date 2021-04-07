/* 
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
 */

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    // Complete the code.
    int total = 0;
    for (int index = 0; index < 1000; index += 1) {
        if (index % 3 == 0 || index % 5 == 0) {
            total += index;
        }
    }
    cout << total;
    return 0;
}
