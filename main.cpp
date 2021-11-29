#include <iostream>
#include <locale>
#include <cmath>
//#include <cstdint>
#include <cassert>

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
	int m_array[10];
	int m_length;
public:
	void reset()
	{
		m_length = 0;
		for (int i = 0; i < 10; i++)
			m_array[i] = 0;
	}
	bool push(int cell)
	{
		if (m_length == 10)
			return false;

		else (m_array[m_length++] = cell);
			return true;
	}

	int pop()
	{
		assert (m_length > 0);

		return m_array[--m_length];
	}

	void print()
	{
		cout << "( ";
		for (int i = 0; i < m_length; i++)
			cout << m_array[i] << ' ';
		cout << ")" << endl;
	}
	
};




int main()
{	
	setlocale(0, "rus");

	//=================Task_1=====================
	cout << "===Task 1===" << endl;

	Power sum;
	sum.setPower();
	sum.Calculate();
	
	//=================Task_2=====================
	
	cout << endl << "===Task 2===" << endl;

	RGBA colors(3, 4, 5, 6);
	colors.print();
	
	//=================Task_3=====================
	cout << endl << "===Task 3===" << endl;

	Stack stack;
	stack.reset();
	stack.print();
	
	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();
	
	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();
	stack.print();

	return 0;
}

