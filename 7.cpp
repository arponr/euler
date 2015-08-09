#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 1000000;
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
    int p = 0, i = 2;
    
    while (p < 10001)
    {
	while (!prime [i])
	    i++;
	p++;
	i++;
    }

    printf ("%d\n", i - 1);
}
