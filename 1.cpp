#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 1000;

int main ()
{
    int A = (int) (N - 1) / 3, B = (int) (N - 1) / 5, C = (int) (N - 1) / 15;
    printf ("%d %d %d\n", A, B, C);
    int sum =  3 * A * (A + 1) / 2 
	    +  5 * B * (B + 1) / 2
            - 15 * C * (C + 1) / 2;
    printf ("%d\n", sum);
}
