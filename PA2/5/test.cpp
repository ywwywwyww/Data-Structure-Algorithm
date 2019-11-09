#include <cstdio>
#include <cstring>
#include "algo.h"

int main()
{
	int a[] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	nth_element(a, a+4, a+9);
	return 0;
}
