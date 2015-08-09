#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;	     

FILE *in = fopen ("18.in", "r");

const int N = 15;

int tri [N][N];

int main ()
{
    for (int i = 0; i < N; i++)
	for (int j = 0; j <= i; j++)
	    fscanf (in, "%d", &tri [i][j]);

    for (int i = N - 2; i >= 0; i--)
	for (int j = 0; j <= i; j++)
	    tri [i][j] += max (tri [i + 1][j], tri [i + 1][j + 1]);

    printf ("%d\n", tri [0][0]);
}
