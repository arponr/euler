#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;	     

const int N = 20;

long long dp [N + 1][N + 1];
       
int main ()
{
    dp [N][N] = 1;

    for (int i = N; i >= 0; i--)
	for (int j = N; j >= 0; j--)
	{
	    if (j < N)
		dp [i][j] += dp [i][j + 1];
	    if (i < N)
		dp [i][j] += dp [i + 1][j];
	}

    printf ("%lld\n", dp [0][0]);
}
		   
		   
