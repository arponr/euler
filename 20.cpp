#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;	     

const int MAXN = 5000, b = 8, B = 100000000;

struct bigint 
{
    int N, D [MAXN];

    bigint (string data)
    {
	memset (D, 0, sizeof (D));
	
	N = (int) ceil ((double) data.size () / (double) b);
	int n = data.size () % b;

	for (int i = 0, p = data.size () - b; i < N - (n != 0); i++, p -= b)
	    for (int j = 0; j < b; j++)
		D [i] += (data [p + j] - '0') * (int) pow (10.0, (double) b - 1 - j);

	if (n != 0)
	    for (int j = 0; j < n; j++)
		D [N - 1] += (data [j] - '0') * (int) pow (10.0, (double) n - 1 - j);   
    }
	

    inline bigint operator + (const bigint &o) const
    {
	bigint sum ("0");
	sum.N = max (N, o.N);
       
	int carry = 0;
	for (int i = 0; i < sum.N; i++)
	{
	    sum.D [i] = D [i] + o.D [i] + carry;
	    carry = sum.D [i] / B;
	    sum.D [i] %= B;
	}
	
	if (carry > 0)
	    sum.D [++sum.N - 1] = carry;

	return sum;
    }	
};

int main ()
{
    bigint power ("100");
    for (int i = 99; i >= 2; i--)
    {
	bigint temp = power;
	for (int j = 1; j < i; j++)
	    power = power + temp;
    }

    long long sum = 0;
    for (int i = 0; i < power.N; i++)
	for (int j = 1; j <= B; j *= 10)
	    sum += (long long) ((power.D [i] / j) % 10);

    printf ("%lld\n", sum);
}
