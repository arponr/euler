#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 4000000;
int fib [50], F;

void init ()
{
    fib [0] = 1;
    fib [1] = 2;

    int i = 1;
    while (fib [i] <= N)
	fib [++i] = fib [i - 1] + fib [i - 2];
    F = i;
}

int main ()
{
    init ();
    
    int sum = 0;
    for (int i = 1; i < F; i += 3)
	sum += fib [i];
    printf ("%d\n", sum);
}
