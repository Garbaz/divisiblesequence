#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

/*
This program searches for the lowest number n, such that a_1 divides n, a_2 divides n+1, a_3 divides n+2, a_4 divides n+3, a_5 divides n+4, ...
In general terms: With {a_1, .. a_n} a list of n positive integers, find m such that a_1|m, a_2|(m+1), a_3|(m+2), ... , a_k|(m+N-1).

This is repeated for n from 1 to N with
list == {a_1, a_2, a_3, ..., a_N}

The search speed could probably be increased
*/

#define PRIME_NUMBERS {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743}

//const unsigned long numlist[] = {1,3,5,7,9,11,13,15,17,19,21,23,25,27,29};
const unsigned long numlist[] = PRIME_NUMBERS;
const unsigned long NUMLIST_SIZE = sizeof(numlist)/sizeof(numlist[0]);


bool isdivseq(unsigned long m, unsigned long k) {
    for(unsigned long i = 0; i <= k; i++) {
        if((m+i)%numlist[i] != 0) return false;
    }
    return true;
}

unsigned long m = 0;
unsigned long prod = 1;
int main() {
    for(unsigned long k = 0; k < NUMLIST_SIZE; k++) {
        m = 0;
        prod *= numlist[k];
        printf("%u - ",k);
        while(!isdivseq(m,k) && m < ULONG_MAX && m < prod) m+=numlist[0]; // Since numlist[0] has to divide m...
        if(m == ULONG_MAX) {
            printf("Reached %u bit limit!\n",sizeof(m)*8);
            return 1;
        }
        else if(m == prod) {
            printf("There aren't any solutions for {");
            for(unsigned long i = 0; i <= k; i++) {
                printf("%lu,",numlist[i]);
            }
            printf("}\n");
            return 2;
        }
        printf("%lu\n",m);
    }

    return 0;
}
