/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <iostream>
#include <cstdio>
#include <math.h>

#include "utils/basic-functions.h"

using namespace std;


// https://randerson112358.medium.com/palindrome-program-explained-510fd952baa has some great logic, and I'd suggest not
// even looking at the code portion, but only the first few paragraphs

bool isPalindrome(string number) {
    int length = number.length();
    if (length == 0 || length == 1) {
        return true;
    }
    // outer letters match
    if (number[0] == number[length - 1]) {
        // Shave off outer two matching digits
        string newNumber = number.substr(1, length - 2);
        // check if it's a length of 1 or 0, then it's a palindrome
        if (newNumber.length() == 1 || newNumber.length() == 0) return true;
        // otherwise convert and pass this new number for another round of checking
        else return isPalindrome(newNumber);
    }
    return false;
}

// using recursion to find the next palindrome
// here I subtract by 1, because I assume that by doing so, I won't get the same number back
int findNextPalindrome(int n) {
    if (!isPalindrome(to_string(n))) {
        return findNextPalindrome(n - 1);
    }
    return n;
}

int getLargestPalindrome(int palindrome, float divider) {
    float result = palindrome / divider;

    // doesn't count
    // if it's above 999, go to next palindrome, reset divider
    if (result > 999) {
        int nextPalindrome = findNextPalindrome(palindrome - 1);
        log(nextPalindrome);
        return getLargestPalindrome(nextPalindrome, 999);
    }
    // if it's just not a whole number, go to next divider
    else if (fmod(result, int(result)) > 0) {
        return getLargestPalindrome(palindrome, divider - 1);
    }
    else {
        return palindrome;
    }
}

int main() {
    // Complete the code.

    // I want to start at 999 * 999, because that's the largest option
    int top = 999 * 999;

    // here I can brute force it a bit, and for this palindrome to be the highest, it needs to satisfy 2 conditions when divided by a number lower than 999
    // 1. that it results in a number below 1000 and 2. that it's an even number
    //    cout << (fmod(5.3,int(5.3))); - I can fmod a value with a casted version, to see if there's a remainder

    // Ran into an issue around string -> integer conversion, where "09" would become 9, and because that has a length of 1, it would pass the palindrome check
    // so I had to make sure I was only using a number to iterate through, but not check
    //      cout << (isPalindrome(to_string(990999)));

    int firstPalindrome = findNextPalindrome(top);
    int finalPalindrome = getLargestPalindrome(firstPalindrome, 999);
    log(finalPalindrome);

    return 0;
}


/* NOTE 1
    Initial thoughts are to write a function to check if a number is a palindrome. Then how can I go through numbers, and recognize a pattern that shows which will be palindromes. For example, is there an obvious reason that 91 * 99 results in a palindrome but 92 * 99 doesn't?
    Can that then be extrapolated to three-digit numbers.
*/
