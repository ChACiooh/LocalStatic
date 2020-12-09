#include <stdio.h>

#define	INITVAL	10

int * overflow;

void declare_define()
{
	static int dd = INITVAL;
	dd += 1;
	printf("adr dd: %p val:%d\n", &dd, dd);
}

void check();	// It doesn't have any difference with declare_define().

int main()
{
	int a = INITVAL;
	int i;
	overflow = &a;
	printf("adr ma: %p val:%d\n", &a, a);

	declare_define();
	declare_define();

	check();
	check();

	for(i = 0;  ; ++i) {
		if(i && i%100 == 0) {
			printf("%d times operated.\n", i);
		}
		overflow++;
		*overflow = INITVAL;	// terminate
	}
	return 0;
}

void check()
{
	static int ck = INITVAL;
	ck += 2;
	printf("adr ck: %p val:%d\n", &ck, ck);
}
