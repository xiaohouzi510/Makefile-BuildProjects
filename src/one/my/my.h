#ifndef MY_H
#define MY_H

class my 
{
public:
	void display();

	static my* ins()
	{
		static my s;
		return &s; 
	}
};

#endif