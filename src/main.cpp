#include "stdio.h"
#include "one.h"
#include "tow.h"
#include "test.h"
#include "my.h"
#include "self.h"

void last();

int main(int argc,char **argv)
{
	test::ins()->display();
	one::ins()->display();
	tow::ins()->display();
	my::ins()->display();
	self::ins()->display();
	last();
	printf("this main\n");
	return 0;
}