#ifndef ONE_H
#define ONE_H

class one 
{
public:
	void display();

	static one* ins()
	{
		static one s;
		return &s; 
	}
};

#endif