#include"main.h"

//*******************************************************************************************************************************************
// Создать классы Apple(яблоко) и Banana(банан), которые наследуют класс Fruit(фрукт).У Fruit есть две переменные - члена: name(имя) и color(цвет).
// Добавить новый класс GrannySmith, который наследует класс Apple.
//
// int main()
// {
//  	Apple a("red");
//	    Banana b;
//	    GrannySmith c;
//
//	   std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
//	   std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
//	   std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
//
//  	return 0;
// }
// Код, приведенный выше, должен давать следующий результат :
//     My apple is red.
//     My banana is yellow.
//     My Granny Smith apple is green.
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


