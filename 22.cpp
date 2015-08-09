#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

FILE *in = fopen ("names", "r");

char name [10000][100];
int N = 0;

int comp (const void *s, const void *t)
{
    return strcmp ((char *) s, (char *) t);
}

int main ()
{
    fscanf (in, "\"%[^\",]\"", name [N++]);
    while (fscanf (in, ",\"%[^\",]\"", name [N++]));
    N--;
    qsort (name, N, sizeof (name [0]), comp);

    int total = 0;
    for (int i = 0; i < N; i++)
    {
	char *p = name [i];
	int alpha = 0;
	while (*p) 
	    alpha += (*p++) - 'A' + 1;
	total += alpha * (i + 1);
    }
    printf ("%d\n", total);
    
}
