#include <stdio.h>
void add(int, int, int *);
int main(void) {
    //! showMemory(start=65520)
	int a, b, sum;
	printf("Please enter two integers: ");
	scanf("%d%d", &a, &b);
	add(a, b, &sum);
	printf("%d + %d = %d\n", a, b, sum);
    return 0;
}

void add(int x, int y, int *resultptr) {
    int z;
    z = x+y;
    printf("Added numbers in the function!\n");
    *resultptr = z;
    printf("Updated variable with pointer in function.\n");
}
