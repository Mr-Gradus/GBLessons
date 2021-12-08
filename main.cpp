#include <iostream>
#include <locale>
#include <string>

using namespace std;

//=================Task_1=====================

	class Figure 	{
	public:
	Figure () {}
	virtual ~Figure() {};
	virtual void area() const = 0;

	};

	class Parallelogram : public Figure {
	//protected:

	public:
		Parallelogram () {}
		void area() const override {
			cout << "Параллелограм S = a * h" << endl;
		}
	};

	class Circle : public Figure {
	//private:

	public:
		Circle () {}
		void area() const override {
			cout << "Круг S = piR^" << endl;
		}
	};

	class Rectangle : private Parallelogram {
	//private:

	public:
		Rectangle () {}
		void area() const override {
			cout << "Прямоугольник S = a * b" << endl;
		}
	};

	class Square : private Parallelogram {
	//private:

	public:
		Square () {}
		void area() const override {
			cout << "Квадрат S = a^" << endl;
		}
	};

	class Rhombus : private Parallelogram {
	//private:

	public:
		Rhombus () {}
		void area() const override {
			cout << "Ромб S = a^ * sin A" << endl;
		}
	};

//=================Task_2=====================

	class Car {
	protected:
		string company;
		string model;
	public:
		Car() {}
		
		/*Car(string company, string model) {
			cout << company << "+++" << model << endl;
		}*/
	};

	class PassengerCar : virtual public Car {
	public:
		PassengerCar(string c, string m) : Car() {
			cout << c << "*" << m << endl;
		}
	};

	class Bus : virtual public Car {
	public:
		Bus(string c, string m) : Car() {
			cout << c << "=" << m << endl;
		}
	};

	class Minivan : public PassengerCar, public Bus {
	public:
		Minivan(string c, string m) : PassengerCar(c,m), Bus(c,m) {
			cout << c << "-" << m << endl;
		}
	};

//=================Task_3=====================

	class Fraction {
	public:
		double numenator;
		double denomenator;
	public:
		Fraction(double num, double den) : numenator(num), denomenator(den) {
			if (den == 0)
				cout << "Ошибка - знаменатель не может быть 0!!!" << endl;
			
		}
		
		int getNum() const {
		return numenator;
		}
		int getDen() const {
		return denomenator;
		}
		
		
		friend Fraction operator+ (const Fraction& n1, const Fraction& n2);
		friend Fraction operator- (const Fraction& n1, const Fraction& n2);
		friend Fraction operator* (const Fraction& n1, const Fraction& n2);
		friend Fraction operator/ (const Fraction& n1, const Fraction& n2);
	};

	Fraction operator+ (Fraction& n1, Fraction& n2)	{
		return Fraction(n1.numenator * n2.denomenator + n2.numenator * n1.denomenator, n1.denomenator * n2.denomenator);
	}

	Fraction operator- (Fraction& n1, Fraction& n2) {
		return Fraction(n1.numenator * n2.denomenator + n2.numenator * n1.denomenator, n1.denomenator * n2.denomenator);
	}
	/*
	class Fraction {
	private:
		int number;
	public:
		Fraction(int num) : number(num) {}
		int getNum() const {
			return number;
		}
		friend Fraction operator+ (const Fraction& n1, const Fraction& n2);
	};

	Fraction operator+ (const Fraction& n1, const Fraction& n2) {
		return Fraction(n1.number + n2.number);
	}
	*/


int main()
{	
	{
		setlocale(0, "rus");

		//=================Task_1=================

		cout << "==========Task 1==========" << ".\n" << endl;

		Parallelogram parallelogram;
		parallelogram.area();

		Circle circle;
		circle.area();

		Rectangle rectangle;
		rectangle.area();

		Square square;
		square.area();

		Rhombus rhombus;
		rhombus.area();

		//=================Task_2=====================

		cout << endl << "==========Task 2==========" << ".\n" << endl;


		PassengerCar sedan("Audi", "A4");
		Bus bus("МАЗ", "105");
		Minivan car("VW", "Multivan"); //обращается к обоим базовым классам, а если сделать конструктор с данными к классу Car то и к нему 

	}
	//=================Task_3=====================
	cout << endl << "==========Task 3==========" << ".\n" << endl;

	Fraction n1(1,5), n2(3,4);
	Fraction res = n1 + n2;
	cout << res.getNum() << "/" << res.getDen() << endl;
	return 0;
}

