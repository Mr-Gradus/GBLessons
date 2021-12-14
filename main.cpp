#include <iostream>
#include <locale>
#include <string>
#include <cassert>

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
		Fraction(double num, double den) : numenator(num), denomenator(den) {}
			
			
		
		
		double getNum() const {
		return numenator;
		}
		double getDen() const {
		return denomenator;
		}
		
		//friend Fraction operator+ (const Fraction& n1, const Fraction& n2);
		friend Fraction operator- (const Fraction& una1, const Fraction& una2);
		//friend Fraction operator* (const Fraction& n1, const Fraction& n2);
		//friend Fraction operator/ (const Fraction& n1, const Fraction& n2);
		friend bool operator== (const Fraction& equ1, const Fraction& equ2);
		friend bool operator!= (const Fraction& equ1, const Fraction& equ2);
		friend bool operator< (const Fraction& les1, const Fraction& les2);
	};

	Fraction operator+ (Fraction& add1, Fraction& add2)	{
		assert(add1.getDen() != 0 && add2.getDen() != 0);
		return Fraction(add1.getNum() * add2.getDen() + add2.getNum() * add1.getDen(), add1.getDen() * add2.getDen());
	}
	
	Fraction operator- (Fraction& sub1, Fraction& sub2) {
		assert(sub1.getDen() != 0 && sub2.getDen() != 0);
		return Fraction(sub1.getNum() * sub2.getDen() - sub2.getNum() * sub1.getDen(), sub1.getDen() * sub2.getDen());
	}
	
	Fraction operator* (Fraction& mul1, Fraction& mul2) {
		assert(mul1.getDen() != 0 && mul2.getDen() != 0);
		return Fraction(mul1.getNum() * mul2.getNum(), mul1.getDen() * mul2.getDen());
	}

	Fraction operator/ (Fraction& div1, Fraction& div2) {
		assert(div1.getDen() != 0 && div2.getDen() != 0);
		return Fraction(div1.getNum() * div2.getDen(), div1.getDen() * div2.getNum());
	}
	/*
	Fraction operator- (Fraction& una1, Fraction& una2) {
		return Fraction(-una1.getNum(), una1.getDen());
	}
	*/

	bool operator== (Fraction& equ1, Fraction& equ2) {
		assert(equ1.getDen() != 0 && equ2.getDen() != 0);
		return (equ1.numenator / equ1.denomenator == equ2.numenator / equ2.denomenator);
	}
	
	bool operator< (Fraction& les1, Fraction& les2) {
		assert(les1.getDen() != 0 && les2.getDen() != 0);
		return (les1.numenator / les1.denomenator < les2.numenator / les2.denomenator);
	}

	bool operator> (Fraction& mor1, Fraction& mor2) {
		assert(mor1.getDen() != 0 && mor2.getDen() != 0);
		return (mor1.numenator / mor1.denomenator > mor2.numenator / mor2.denomenator);
	}
	int operator- (Fraction& una1, Fraction& una2) {
		//assert(una1.denomenator() != 0 && una2.denomenator() != 0);
		return (-una1.numenator, -una1.denomenator);
	}
	

int main()
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

	
	//=================Task_3=====================
	cout << endl << "==========Task 3==========" << ".\n" << endl;


	Fraction add1(1,2), add2(1,4);
	Fraction add = add1 + add2;
	cout << add.getNum() << "/" << add.getDen() << endl;
	
	Fraction sub1(1,2), sub2(1,4);
	Fraction sub = sub1 - sub2;
	cout << sub.getNum() << "/" << sub.getDen() << endl;
	
	Fraction mul1(1,4), mul2(1,4);
	Fraction mul = mul1 * mul2;
	cout << mul.getNum() << "/" << mul.getDen() << endl;
	
	Fraction div1(1,2), div2(1,4);
	Fraction div = div1 / div2;
	cout << div.getNum() << "/" << div.getDen() << endl;
	
	Fraction una1(1, 2), una2(1, 4);
	//Fraction una = 
	cout << una1.numenator << "/" << una1.denomenator << endl;
	
	
	Fraction equ1(1, 2), equ2(1, 3);
	if ((equ1.numenator / equ1.denomenator) == (equ2.numenator / equ2.denomenator))
		cout << equ1.numenator << "/" << equ1.denomenator << " Равно " << equ2.numenator << "/" << equ2.denomenator << endl;

	if ((equ1.numenator / equ1.denomenator) != (equ2.numenator / equ2.denomenator))
		cout << equ1.numenator << "/" << equ1.denomenator << " Не равно " << equ2.numenator << "/" << equ2.denomenator << endl;
	
	Fraction les1(1, 2), les2(1, 3);
	if ((les1.numenator / les1.denomenator) < (les2.numenator / les2.denomenator))
		cout << les1.numenator << "/" << les1.denomenator << " Меньше " << les2.numenator << "/" << les2.denomenator << endl;

	if ((les1.numenator / les1.denomenator) >= (les2.numenator / les2.denomenator))
		cout << les1.numenator << "/" << les1.denomenator << " Больше или равно " << les2.numenator << "/" << les2.denomenator << endl;
	
	Fraction mor1(1, 2), mor2(1, 3);
	if ((mor1.numenator / mor1.denomenator) > (mor2.numenator / mor2.denomenator))
		cout << mor1.numenator << "/" << mor1.denomenator << " Больше " << mor2.numenator << "/" << mor2.denomenator << endl;

	if ((mor1.numenator / mor1.denomenator) <= (mor2.numenator / mor2.denomenator))
		cout << mor1.numenator << "/" << mor1.denomenator << " Меньше или равно " << mor2.numenator << "/" << mor2.denomenator << endl;
	
	return 0;
}

