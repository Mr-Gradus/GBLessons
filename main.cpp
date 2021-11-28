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

	void print() // Переделать в отдельную функцию??
	{
		cout << "Red." << m_red << endl << "Green." << m_green << endl << "Blue." << m_blue << endl << "Alpha." << m_alpha << endl;
	}
};

//=================Task_3=====================

class Stack
{
private:
	int Array[10];
	int stackLength;
public:
	void reset();
	
	void push();

	void pop();

	void print();


};

Stack::Stack()
{
}

Stack::~Stack()
{
}




int main()
{	
	setlocale(0, "rus");

	//=================Task_1=====================
	cout << "===Task 1===" << endl;

	Power sum;
	sum.setPower();
	sum.Calculate();
	
	//=================Task_2=====================
	cout << "===Task 2===" << endl;

	RGBA colors(3, 4, 5, 6);
	colors.print();
	
	return 0;
}

