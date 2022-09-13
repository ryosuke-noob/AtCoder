#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define max(p,q) ((p)>(q)?(p):(q))
#define min(p,q) ((p)<(q)?(p):(q))

void myswap(double *a, double *b)
{
	double tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(void)
{
	int n;
	int *a;
	double X, Y, odd, even;
	int head, tail, len, Max;

	scanf("%d",&n);
	a = (int *)malloc(sizeof(int) * (n+1));
	rep(i,1,n+1) scanf("%d",&a[i]);

	head = 1; tail = n; even = 0; odd = 0; X = 0; Y = 0;
	rep(i,1,n+1)
	{
		if (i % 2 == 0) even += a[i];
		else odd += a[i];
	}
	rep(i,1,n+1)
	{
		len = tail - head + 1;
		if (even > odd)
		{
			if (len%2==0)
			{
				if (i%2==1) X += a[tail];
				else Y += a[tail];
				even -= a[tail];
				tail--;
			}
			else
			{
				Max = max(a[head],a[tail]);
				if (i%2==1) X += Max;
				else Y += Max;
				odd -= Max;
				if (a[head]<=a[tail]) tail--;
				else {head++; myswap(&odd, &even);}
			}
		}
		else if (even < odd)
		{
			if (len%2==0)
			{
				if (i%2==1) X += a[head];
				else Y += a[head];
				odd -= a[head];
				head++;
				myswap(&odd, &even);
			}
			else
			{
				Max = max(a[head],a[tail]);
				if (i%2==1) X += Max;
				else Y += Max;
				odd -= Max;
				if (a[head]<=a[tail]) tail--;
				else {head++; myswap(&odd, &even);}
			}
		}
		else
		{
			Max = max(a[head],a[tail]);
			if (i%2==1) X += Max;
			else Y += Max;
			if (len%2==0 && a[head]<=a[tail]) even -= Max;
			else odd -= Max;
			if (a[head]<=a[tail]) tail--;
			else {head++; myswap(&odd, &even);}
		}
	}
	printf("%.0lf",X-Y);
	return (0);
}