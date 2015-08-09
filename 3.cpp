#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

const long long N = 600851475143;
long long big = 0;

void dfs (long long n)
{
    long long div = 1;

    for (long long i = 3; i * i <= n && div == 1; i += 2)
	if (n % i == 0)
	    div = i;
	    
    if (div > 1)
    {
	dfs (div);
	dfs (n / div);
    }
    else
	big = max (big, n);
}

int main ()
{
    dfs (N);
    printf ("%lld\n", big);
}
