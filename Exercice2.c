#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define MAX_N 1000000
//Exercice 2 :
//Question 1

bool is_prime_naive(int k) {
    if (k < 2) return false;
    for (int i = 2; i * i <= k; ++i) {
        if (k % i == 0) return false;
    }
    return true;
}

int count_primes_naive(int n) {
    int count = 0;
    for (int i = 2; i < n; ++i) {
        if (is_prime_naive(i)) count++;
    }
    return count;
}

//Question 2 

int count_primes_sieve(int n) {
    if (n <= 2) return 0;
    if (n > MAX_N) {
        printf("Erreur : n dépasse la taille maximale fixe (%d).\n", MAX_N);
        return -1;
    }

    bool is_prime[MAX_N];

    for (int i = 0; i < n; ++i) {
        is_prime[i] = true;
    }
    is_prime[0] = is_prime[1] = false;

    for (int p = 2; p * p < n; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i < n; i += p) {
                is_prime[i] = false;
            }
        }
    }

    int count = 0;
    for (int i = 2; i < n; ++i) {
        if (is_prime[i]) {
            count++;
        }
    }

    return count;
}