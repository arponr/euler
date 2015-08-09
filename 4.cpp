#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

const long long N = 600851475143;
long long big = 0;

bool pal (int n)
{
    int p = 0;
    int d = (int) log10 ((double) n);
    for (int i = d; i >= 0; i--)
	p += (int) pow (10.0, d - i) * ((int) (n / (int) pow (10.0, (double) i)) % 10);
    return n == p;
}

int main ()
{
    int big = 0;
    for (int i = 1000; i >= 100; i--)
	for (int j = 1000; j >= i; j--)
	    if (i * j > big && pal (i * j))
		big = i *j;
    printf ("%d\n", big);
}
