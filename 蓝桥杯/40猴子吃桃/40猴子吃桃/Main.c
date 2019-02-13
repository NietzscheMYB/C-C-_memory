#include <stdio.h>
#pragma warning(disable :4996)
#include <stdio.h>

int main()
{
	int n, m, o, p, k, t, sum;

	scanf("%d%d", &n, &m);

	t = n + 1;
	p = 1;
	o = 1;
	k = 1;
	while (t-- > 0){
		p *= n;
		o *= (n - 1);
	}

	o /= (n - 1);
	while (o < m + 1){
		k++;
		p *= k;
		o *= k;
	}
	sum = p - ((n - 1) * m);

	printf("%d", sum);

	return 0;

}
