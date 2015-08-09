#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

const int primes [] = {2, 3, 5, 7, 11, 13, 17, 19};
const int P = 8;

int main ()
{
    int ppmax [P];
    memset (ppmax, 0, sizeof (ppmax));

    for (int i = 2; i <= 20; i++)
    {
	int n = i;
	for (int j = 0; j < P; j++)
	{
	    int pp = 0;
	    while (n % primes [j] == 0)
	    {
		pp++;
		n /= primes [j];
	    }
	    ppmax [j] = max (pp, ppmax [j]);
	}
    }

    int lcm = 1;
    for (int i = 0; i < P; i++)
	for (int j = 0; j < ppmax [i]; j++)
	    lcm *= primes [i];

    printf ("%d\n", lcm);
}
