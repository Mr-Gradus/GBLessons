#include <iostream>
#include <locale>
#include <string>

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
		num2 = 2.22;
	}
	void Calculate()
	{
		cout << num1 << " в степени " << num2 << " = " << pow(num1, num2) << endl;
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

};

//=================Task_3=====================




int main()
{	
	setlocale(0, "rus");

	//=================Task_1=====================
	cout << "===Task 1===" << endl;

	
	//=================Task_2=====================
	
	cout << endl << "===Task 2===" << endl;

	
	//=================Task_3=====================
	cout << endl << "===Task 3===" << endl;


	return 0;
}

