#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;	     

int ndiv (int N)
{
    int div = 1;
    for (int i = 2; i * i <= N; i++)
	if (N % i == 0)
	    div++;
    return 2 * div - ((int) sqrt (N) == sqrt ((double) N));
}	

int main ()
{
    int i = (int) sqrt (1000);
    while (ndiv (i*(i+1)/2) <= 500)
	i++;
    printf ("%d\n", i*(i+1)/2);
}
