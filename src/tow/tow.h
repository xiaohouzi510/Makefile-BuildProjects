#ifndef TOW_H
#define TOW_H

class tow 
{
public:
	void display();

	static tow* ins()
	{
		static tow s;
		return &s; 
	}
};

#endif