#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;	     

FILE *in = fopen ("18.in", "r");

const int N [12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int sun = 0;

inline bool leap (int year)
{
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int main ()
{
    int day = 6, month = 0, year = 1901;

    while (year <= 2000)
    {
	sun += (day == 1);
	day += 7;
	if (day > (N [month] + (month == 1 && leap (year))))
	{
	    day %= (N [month] + (month == 1 && leap (year)));
	    if (++month == 12)
	    {
		month = 0;
		year++;
	    }
	}
    }

    printf ("%d\n", sun);
}
