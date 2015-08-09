#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;	     

const int N = 10000;

int mem [N + 1];
bool ami [N + 1];

int divsum (int n)
{
    int sum = 0, i = 1;
    for (; i * i <= n; i++)
	if (n % i == 0)
	    sum += i + n / i;
    if (i * i == n)
	sum -= i;

    return sum - n;
}

int main ()
{
    for (int i = 1; i <= N; i++)
	mem [i] = divsum (i);

    printf ("%d %d\n", mem [220], mem [284]);

    for (int i = 1; i <= N; i++)
	for (int j = i + 1; j <= N; j++)
	{
	    bool amic = (mem [i] == j && mem [j] == i); 
	    ami [j] |= amic;
	    ami [i] |= amic;
	}

    long long sum = 0;
    for (int i = 1; i <= N; i++)
	if (ami [i]) sum += (long long) i;
	
    printf ("%lld\n", sum);
}
