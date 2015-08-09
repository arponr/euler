#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

const int up = 28123;

bool sum [up + 5];
int N = 0, abun [up + 5];

int divsum (int n)
{
    int d = 1;
    for (int i = 2; i * i <= n; i++)
	if (n % i == 0)
	    d += i + (i != n / i) * n / i;
    return d;
}

int main ()
{
    for (int i = 1; i < up; i++)
	if (divsum (i) > i)
	    abun [N++] = i;

    for (int i = 0; i < N; i++)
	for (int j = i; j < N && abun [i] + abun [j] < up; j++)
	    sum [abun [i] + abun [j]] = true;

    int S = 0;
    for (int i = 1; i < up; i++)
	if (!sum [i]) S += i;
    printf ("%d\n", S);
}
