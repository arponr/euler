#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
	
int main ()
{
    for (int a = 1; a < 500; a++)
	for (int b = a; b < 500; b++)
	{
	    int c = (int) sqrt (a * a + b * b);
	    if (c == sqrt ((double) a * (double) a + (double) b * (double) b) && a + b + c == 1000)
		printf ("%d\n", a*b*c);
	}
}
