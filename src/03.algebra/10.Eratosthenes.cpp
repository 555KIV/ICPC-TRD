#include <iostream>
#include <vector>

std::vector<int> sieve_of_eratosthenes(int n, int m) {
  std::vector<int> primes;
  std::vector<bool> is_prime(m + 1, true);

  is_prime[0] = is_prime[1] = false;

  for (int p = 2; p * p <= m; p++) {
    if (is_prime[p]) {
      for (int i = p * p; i <= m; i += p) {
        is_prime[i] = false;
      }
    }
  }

  for (int i = n; i <= m; i++) {
    if (is_prime[i]) {
      primes.emplace_back(i);
    }
  }

  return primes;
}
