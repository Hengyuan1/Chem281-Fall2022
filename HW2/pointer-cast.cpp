#include <iostream>

int main() {
	double num=1.5;
	unsigned long a = (unsigned long)num; 
	printf("num: %.5f, a: %ld\n", num, a);
	unsigned long b = *((unsigned long*)&num);
	printf("b: %ld\n", b);

	float num1=1.5;
	unsigned int a1 = (unsigned int)num1; 
	printf("num1: %.5f, a1: %d\n", num1, a1);
	unsigned int b1 = *((unsigned int*)&num1);
	printf("b1: %d\n", b1);

	return 0;
}
