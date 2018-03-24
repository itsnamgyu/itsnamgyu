#include <stdio.h>

void print_byte(char *byte);

char f(char c);

void print_char_data(char c);

int main(void) {
	for (char c = 73; c ; putchar(c), c = f(c));

	/*
	char *string = "It's Namgyu!";
	char mapping[13][8];

	for (int i = 0; i < 13; ++i) {
		unsigned char msb = 128;
		char c = string[i];
		
		for (int j = 0; j < 8; ++j) {
			mapping[i][j] = !!(c & msb);
			c = c << 1;
		}

		printf("%c ", string[i]);
		print_byte(mapping[i]);
	}

	for (int i = 0; i < 8; ++i) {
		for (int k = 0; k < 2; ++k) {
			printf("\nByte #%d = %d\n", i, k);
			for (int j = 1; j < 13; ++j) {
				if (mapping[j][i] == k) {
					print_byte(mapping[j - 1]);
				}
			}
		}
	}

	char c = 73;
	for (int i = 0; i < 12; i ++) {
		printf("%c ", c);
		print_char_data(c);
		c = f(c);
	}

	*/
	return 0;
}

void print_byte(char *byte) {
	for (int i = 0; i < 8; ++i)
		printf("%d", byte[i]);
	printf("\n");
}

char f(char c) {
	char r = 0;
	char b1 = c & 64, b2 = c & 32, b3 = c & 16, b4 = c & 8,
		 b5 = c & 4, b6 = c & 2, b7 = c & 1;

	r = (r | (!b3 || b3 && b4)) << 1;
	r = (r | (b1 || !b2 || b5)) << 1;
	r = (r | (!!b4 == !b5 && !b5 == !b6)) << 1;
	r = (r | (!b1 == !b7 && b2 && !b3 && !b4)) << 1;
	r = (r | (!b6 && (!b2 || !b7 || b1 && b2 && b7 && (!b5 || b4)))) << 1;
	r = (r | (!b6 && !b7 || !b1 == !b4 && b2 && !b3 && b5)) << 1;
	r = (r | (b5 || b1 && b2 && !b6));
	
	return r;
	/*
	printf("%d", !!b1);
	printf("%d", !!b2);
	printf("%d", !!b3);
	printf("%d", !!b4);
	printf("%d", !!b5);
	printf("%d", !!b6);
	printf("%d", !!b7);
	printf("\n");

	printf("<%d>", r & 2);
	printf("<%d>", r & 2);
	printf("<%d>", r & 2);
	printf("<%d>", r & 2);
	printf("<%d>", r & 2);
	printf("<%d>", r & 2);
	printf("<%d>", r & 2);
	*/
}



void print_char_data(char c) {
	unsigned char b = 1 << 7;;
	for (; b; b /= 2)
		printf("%d", !!(c & b));
	printf("\n");
}
