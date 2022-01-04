#include <stdio.h>

int	main(void)
{
	int a;
	int *ptr1;
	int *ptr2;

	a = 15;
	ptr1 = &a;
	ptr2 = ptr1;
	printf("a = %d, &a = %p\n", a, &a);
	printf("*ptr1 = %d, ptr1 = %p\n", *ptr1, ptr1);
	printf("*ptr2 = %d, ptr2 = %p\n", *ptr2, ptr2);

	return (0);
}