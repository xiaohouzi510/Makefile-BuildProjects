#ifndef SELF_H
#define SELF_H

class self
{
public:
	void display();

	void display1()
	{
		printf("self11\n");
	}

	static self* ins()
	{
		static self s;
		return &s; 
	}
};

#endif