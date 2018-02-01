#include "stdio.h"
#include "one.h"
#include "tow.h"
#include "test.h"
#include "my.h"
#include "self.h"

int main(int argc,char **argv)
{
	test();
	one();
	tow();
	my();
	self();
	printf("this main\n");
	return 0;
}