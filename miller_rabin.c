#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <gmp.h>


// Miller Rabin Test
// n number to test for primality
// k number of test rounds
// random_state random number generator state
// algorithm:
// 1. write n - 1 as 2^r * d with d odd by factoring powers of 2 from n - 1
// 2. witness loop: repeat k times
//    a. pick a random integer a in the range [2, n - 2]
//    b. compute x = a^d mod n
//    c. if x == 1 or x == n - 1, continue to the next iteration
//    d. repeat r - 1 times
//       i. x = x^2 mod n
//       ii. if x == 1, return composite
//       iii. if x == n - 1, continue to the next iteration
//    e. return composite
// 3. return probably prime
int miller_rabin( mpz_t n, int k, gmp_randstate_t random_state) {

    // Sofortige Rückgabe für gewisse kleine Zahlen
    // Miller-Rabin benötigt n > 3
    if (mpz_cmp_ui(n, 2) < 0 || mpz_cmp_ui(n, 4) == 0)
        return 0;

    if (mpz_cmp_ui(n, 2) == 0 || mpz_cmp_ui(n, 3) == 0)
        return 1;

    // Sofortige Rückgabe, wenn die Zahl durch eine kleine Primzahl teilbar ist.
    if (mpz_divisible_ui_p(n, 2) != 0 
        || mpz_divisible_ui_p(n, 3) != 0
        || mpz_divisible_ui_p(n, 5) != 0 
        || mpz_divisible_ui_p(n, 7) != 0 
        || mpz_divisible_ui_p(n, 11) != 0
        || mpz_divisible_ui_p(n, 13) != 0
        || mpz_divisible_ui_p(n, 17) != 0
        || mpz_divisible_ui_p(n, 19) != 0
        || mpz_divisible_ui_p(n, 23) != 0
        || mpz_divisible_ui_p(n, 29) != 0
        || mpz_divisible_ui_p(n, 31) != 0
        || mpz_divisible_ui_p(n, 37) != 0
        || mpz_divisible_ui_p(n, 41) != 0
        || mpz_divisible_ui_p(n, 43) != 0
        || mpz_divisible_ui_p(n, 47) != 0
        || mpz_divisible_ui_p(n, 53) != 0
        || mpz_divisible_ui_p(n, 59) != 0
        || mpz_divisible_ui_p(n, 61) != 0
        || mpz_divisible_ui_p(n, 67) != 0
        || mpz_divisible_ui_p(n, 71) != 0
        || mpz_divisible_ui_p(n, 73) != 0
        || mpz_divisible_ui_p(n, 79) != 0
        || mpz_divisible_ui_p(n, 83) != 0
        || mpz_divisible_ui_p(n, 89) != 0
        || mpz_divisible_ui_p(n, 97) != 0
        )
        return 0;


    // n_minus_1 = n - 1
    // d größter ungerader Teiler n - 1
    // a Zufallszahl in [2, n - 2]
    // lh = a^d mod n or a^(2^r * d) mod n
    mpz_t n_minus_1, d, a, lh, gcd;
    mpz_inits(n_minus_1, d, a, lh, gcd, NULL);
    int is_prime = 1; // Annahme n ist eine Primzahl
                      // Schlägt einer der k Tests fehl, wird dies angepasst und n ist keine Primzahl

    mpz_sub_ui(n_minus_1, n, 1);
    mpz_set(d, n_minus_1);


    //
    //
    //
    // To Do - Implementieren Sie die fehlenden Schritte für den Miller-Rabin Test.
    //
    //
    //

    mpz_clears(n_minus_1, d, a, lh, gcd, NULL);
    return is_prime;
}
