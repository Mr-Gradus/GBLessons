#include <iostream>
#include <locale>
#include <string>

using namespace std;
//=================Task_1=====================

class Person 
{
protected:
	string m_name;
	int m_age;
	string m_gender;
	int m_weight;
public:
	Person(string name, int age, string gender, int weight) : m_name(name), m_age(age), m_gender(gender), m_weight(weight)
	{	}

	~Person() {}
};

class Student : private Person
{
private:
	int m_years;
	static int count;
public:
	static int getCount()
	{
		return count;
	}
	
	Student(string name, int age, string gender, int weight, int years) : m_years(years), Person(name, age, gender, weight) {
			count++;
	}
		
	
	~Student() {}

	void print() const
	{
		cout << "Имя студента: " << m_name << ".\n" << "Возраст: " << \
			m_age << ".\n" << "Пол: " << m_gender << ".\n" << \
			"Вес: " << m_weight << ".\n" << "Курс: " << m_years << ".\n" << endl;
	}
};

int Student::count = 0;


//=================Task_2=====================

class Fruit {
protected:
	string name;
	string color;
	Fruit() {}


	~Fruit() {}
};
class Apple : private Fruit {
public:
	Apple() {}

	string getName() const { return name; }
	string getColor() const { return color; }
	class Banana : private Fruit {
		Banana() {}
		string getName() const { return name; }
		string getColor() const { return color; }

		class GrannySmith : private Apple {

		public:
			GrannySmith() {}



//=================Task_3=====================




int main()
{	
	setlocale(0, "rus");

	//=================Task_1=====================
	cout << "==========Task 1==========" << endl;

	Student student("Иван",21,"муж",55,4);
	student.print();
	Student student2("Михаил", 19, "муж", 50, 2);
	student2.print();
	Student student3("Алиса", 18, "жен", 47, 1);
	student3.print();
	cout << "Количество студентов: " <<Student::getCount() << endl;
	
	
	//=================Task_2=====================
	
	cout << endl << "===Task 2===" << endl;

	
	//=================Task_3=====================
	cout << endl << "===Task 3===" << endl;


	return 0;
}

