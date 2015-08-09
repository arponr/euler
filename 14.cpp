#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;	     

const int MAX = 1000000;

long long mem [3 * MAX + 2], big = 0;

long long collatz (long long n)
{
    if (n < MAX)
    {
	if (mem [n] == -1)
	    mem [n] = (n % 2 == 0) ? collatz (n / 2) + 1 : collatz (3 * n + 1) + 1;
	
	return mem [n];
    }
    else
	return (n % 2 == 0) ? collatz (n / 2) + 1 : collatz (3 * n + 1) + 1;
}
       
int main ()
{
    memset (mem, -1, sizeof (mem));
    mem [1] = 0;

    int ans = 0;
    for (long long i = 2; i < MAX; i++)
    {
	int cur = collatz (i);
	if (cur > big)
	{
	    big = cur;
	    ans = i;
	}
    }

    printf ("%d\n", ans);
}
		   
		   
