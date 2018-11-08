#ifndef MRPriime
#define MRPriime

#include <gmpxx.h>
#include <vector>
#include <string>

using namespace std;

extern vector<mpz_class> BaseNumber;

void initBaseNumber(vector<string>);
bool isPrime(mpz_class goal);

#endif