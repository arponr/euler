#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 2000000;
bool prime [N];

void sieve ()
{
    memset (prime, true, sizeof (prime));
    for (int i = 2; i * i <= N; i++)
	if (prime [i])
	    for (int j = i * i; j <= N; j += i)
		prime [j] = false;
}

int main ()
{
    sieve ();
    long long sum = 0;
    for (int i = 2; i < N; i++)
	sum += (long long) prime [i] * i;
    printf ("%lld\n", sum);
}
