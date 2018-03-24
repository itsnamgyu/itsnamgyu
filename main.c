#include <stdio.h>

char f(char c) {
	char r = 0;
	char b1 = c & 64, b2 = c & 32, b3 = c & 16, b4 = c & 8,
		 b5 = c & 4, b6 = c & 2, b7 = c & 1;

	r = (r | ((!b3 && (b1 || b6 || !b7)) || (b3 && b4))) << 1;
	r = (r | (b1 || !b2 || b5)) << 1;
	r = (r | (!!b4 == !b5 && !b5 == !b6)) << 1;
	r = (r | (!b1 == !b7 && b2 && !b3 && !b4)) << 1;
	r = (r | (!b6 && (!b2 || !b7 || (b1 && b2 && b7 && (!b5 || b4))))) << 1;
	r = (r | ((!b6 && !b7) || (!b1 == !b4 && b2 && !b3 && b5))) << 1;
	r = (r | (b5 || (b1 && b2 && !b6)));
	
	return r;
}

int main(void) {
	for (char c = 73; c ; putchar(c), c = f(c));

	return 0;
}
