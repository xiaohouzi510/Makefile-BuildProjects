#ifndef TEST_H
#define TEST_H

class test 
{
public:
	void display();

	static test* ins()
	{
		static test s;
		return &s; 
	}
};

#endif