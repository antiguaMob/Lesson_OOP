#include"main.h"

//*******************************************************************************************************************************************
// Создать абстрактный класс Figure(фигура).Его наследниками являются классы Parallelogram(параллелограмм) и Circle(круг).
// Класс Parallelogram — базовый для классов Rectangle(прямоугольник), Square(квадрат), Rhombus(ромб).Для всех классов создать конструкторы.
// Для класса Figure добавить чисто виртуальную функцию area() (площадь).Во всех остальных классах переопределить эту функцию,
// исходя из геометрических формул нахождения площади.
//*******************************************************************************************************************************************

using namespace std;

//*******************************************************************************************************************************************
class Fruit {
protected:
	string name;
	string color;
   
public:
    Fruit(string n = "", string c = ""): name(n) ,color(c) {
   
    }

    ~Fruit(){

    }
	string getName() const {

		return name;
	}

	string getColor() const {

		return color;
	}
	
};
//*******************************************************************************************************************************************
class Apple : public Fruit {
private:

public:
	Apple() {
		name = "apple";
		color = "green";
	}
	Apple(string n) {
		name = "apple";
		color = n;
	}

	~Apple() {

	}
};
//*******************************************************************************************************************************************
class Banana : public Fruit {
private:

public:
	Banana() {
		name = "banana";
		color = "yellow";
	}

	Banana(string n) {
		name = "banana";
		color = n;
	}
	~Banana() {

	}
};
//*******************************************************************************************************************************************
class  GrannySmith : public Apple {
private:

public:
	GrannySmith() {
		name = "Granny Smith apple";
		color = "green";
	}

	GrannySmith(string n) {
		name = "Granny Smith apple";
		color = n;
	}

	~GrannySmith() {

	}
};
//*******************************************************************************************************************************************
int main(){

Apple a("red");
Banana b;
GrannySmith c;

  cout << "My " << a.getName() << " is " << a.getColor() << endl;
  cout << "My " << b.getName() << " is " << b.getColor() << endl;
  cout << "My " << c.getName() << " is " << c.getColor() << endl;

system("pause");
return 0;
}


