#include "stdio.h"
#include "one.h"
#include "tow.h"
#include "test.h"
#include "my.h"
#include "self.h"

void last();

int main(int argc,char **argv)
{
	test();
	one();
	tow();
	my();
	self();
	last();
	printf("this main\n");
	return 0;
}