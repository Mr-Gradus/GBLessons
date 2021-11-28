#include <iostream>
#include <locale>
#include <cmath>
#include <cstdint>

using namespace std;
//=================Task_1=====================

class Power 
{
private:
	double num1;
	double num2;

public:
	void setPower()
	{
		num1 = 4.13;
		num2 = 2.00;
	}
	void Calculate()
	{
		cout << pow(num1,num2) << endl;
	}
	
};

//=================Task_2=====================

class RGBA
{
private:
	uint8_t m_red = 0;
	uint8_t m_green = 0;
	uint8_t m_blue = 0;
	uint8_t m_alpha = 255;
public:
	RGBA(int r, int g, int b, int a)
	{
		m_red = r;
		m_green = g;
		m_blue = b;
		m_alpha = a;
	}

	~RGBA()
	{

	}

	void print()
	{
		cout << "Red." << m_red << endl << "Green." << m_green << endl << "Blue." << m_blue << endl << "Alpha." << m_alpha << endl;
	}
};


int main()
{	
	//=================Task_1=====================
	cout << "===Task 1===" << endl;

	Power sum;
	sum.setPower();
	sum.Calculate();
	
	//=================Task_2=====================
	cout << "===Task 2===" << endl;

	RGBA colors(1, 2, 3, 111);
	colors.print();
	
	return 0;
}

