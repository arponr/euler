#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

const long long N = 100;

int main ()
{
    long long sumsq = N * (N + 1) * (2 * N + 1) / 6;
    long long sqsum = (N * (N + 1) / 2) * (N * (N + 1) / 2);
    printf ("%lld\n", sqsum - sumsq); 
}
