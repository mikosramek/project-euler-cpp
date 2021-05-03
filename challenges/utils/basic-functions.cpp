#ifndef BASIC_FUNCTIONS
#define BASIC_FUNCTIONS

#include <iostream>

void log(int integerNumber) {
    std::cout << integerNumber << "\n";
}
void logF(float floatNumber) {
    std::cout << floatNumber << "\n";
}
void log(std::string message) {
    std::cout << message << "\n";
}
void log(long longNumber) {
    std::cout << longNumber << "\n";
}

int primeList[100] = {
2,
3,
5,
7,
11,
13,
17,
19,
23,
29,
31,
37,
41,
43,
47,
53,
59,
61,
67,
71,
73,
79,
83,
89,
97,
101,
103,
107,
109,
113,
127,
131,
137,
139,
149,
151,
157,
163,
167,
173,
179,
181,
191,
193,
197,
199,
211,
223,
227,
229,
233,
239,
241,
251,
257,
263,
269,
271,
277,
281,
283,
293,
307,
311,
313,
317,
331,
337,
347,
349,
353,
359,
367,
373,
379,
383,
389,
397,
401,
409,
419,
421,
431,
433,
439,
443,
449,
457,
461,
463,
467,
479,
487,
491,
499,
503,
509,
521,
523,
541
};

const std::string red("\033[0;31m");
const std::string green("\033[0;32m");
const std::string reset("\033[0m");

void primeCheck (int *toCheck) {
    for (int i = 0; i < 100; i+= 1) {
        bool doesMatch = toCheck[i] == primeList[i];
        std::cout << "Index: " << i <<
        " Check: " << primeList[i] <<
        " Input: " << toCheck[i] <<
        " Result: " << (doesMatch ? "\033[0;32m pass" : "\033[0;31m fail") << "\033[0m\n";
    }
}


#endif
