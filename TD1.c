#include <stdio.h>
#include <time.h>

//Exercice 1:
//Question 1

long long fibonacci_naive(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

//Question 2

long long fibonacci_dp(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    
    long long prev2 = 0;
    long long prev1 = 1;
    long long current = 0;

    for (int i = 2; i <= n; ++i) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return current;
}

//Question 3 

int main() {
    int n = 40; // Valeur modérée car la version naïve devient très lente pour n > 40

    // Test Naïf
    clock_t start_naive = clock();
    long long res_naive = fibonacci_naive(n);
    clock_t end_naive = clock();
    double time_naive = (double)(end_naive - start_naive) / CLOCKS_PER_SEC;

    // Test DP
    clock_t start_dp = clock();
    long long res_dp = fibonacci_dp(n);
    clock_t end_dp = clock();
    double time_dp = (double)(end_dp - start_dp) / CLOCKS_PER_SEC;

    printf("n = %d\n", n);
    printf("Naif : %lld en %.6f s\n", res_naive, time_naive);
    printf("DP   : %lld en %.6f s\n", res_dp, time_dp);

    return 0;
}

