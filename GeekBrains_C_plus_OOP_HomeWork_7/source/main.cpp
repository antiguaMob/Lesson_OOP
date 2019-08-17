#include"main.h"

//*******************************************************************************************************************************************
// Создать абстрактный класс Figure(фигура).Его наследниками являются классы Parallelogram(параллелограмм) и Circle(круг).
// Класс Parallelogram — базовый для классов Rectangle(прямоугольник), Square(квадрат), Rhombus(ромб).Для всех классов создать конструкторы.
// Для класса Figure добавить чисто виртуальную функцию area() (площадь).Во всех остальных классах переопределить эту функцию,
// исходя из геометрических формул нахождения площади.
//*******************************************************************************************************************************************

using namespace std;

//*******************************************************************************************************************************************
//   Базовый класс
//*******************************************************************************************************************************************
class Figure {
protected:
	double FigureArea;   //static_cast<float>

public:
	Figure (double a = 0) : FigureArea(a) {

	}

	~Figure() {

	}

	virtual double getArea() {

		cout << "class Figure" << endl;
		return FigureArea;
	}
	virtual void setArea() { FigureArea = 0; }
};
//*******************************************************************************************************************************************
//  Класс Параллелограмм
//*******************************************************************************************************************************************
class Parallelogram : public Figure {
protected:
	double sizeA;
	double sizeB;
	int angle_alpha;
public:

	Parallelogram (double a, double b, int ang) : Figure(a * b  * sin(ang)), sizeA(a), sizeB(b), angle_alpha(ang) {} // Угол  альфа (острый)

	double getArea() override
	{
		cout << "class Parallelogram" << endl;
		return FigureArea ;
	}
	void setArea () override
	{
		FigureArea = sizeA * sizeB * sin(angle_alpha);
		cout << "Set Figure Area Parallelogram = " << FigureArea << endl;
	}
	~Parallelogram() {

	}
};
//*******************************************************************************************************************************************
//   Класс  Круг  
//*******************************************************************************************************************************************
class Circle : public Figure {
private:
	int radius;        // Радиус круга
public:
	Circle( int rad ): Figure( PI* pow(rad, 2) ), radius(rad) { 
		// FigureArea = PI * pow(rad, 2);
	    // radius = rad;
	}

	double getArea() override
	{
		cout << "Class Circle" << endl;
		return FigureArea;
	}
	void setArea() override
	{
		FigureArea = PI * pow(radius, 2);
		cout << "Set Figure Area Circle = "<< FigureArea << endl;
	}
	~Circle() {

	}
};
//*******************************************************************************************************************************************
//  Класс Прямоугольник
//*******************************************************************************************************************************************
class  Rectangle : public Parallelogram {
private:
	// Наследует параметры Параллелограмм
	// Угол альфа = 90 градусов ,хоть  sin(90) = 1  переопределил setArea() для вывода в консоль
public:
	Rectangle (int a, int b) : Parallelogram(a, b, 90) {}

	double getArea() override
	{
		cout << "class Rectangle" << endl;
		return FigureArea;
	}
	void setArea() override
	{
		FigureArea = sizeA * sizeB;
		cout << "Set Figure Area Rectangle = "<< FigureArea << endl;
	}
	~Rectangle () {

	}
};
//*******************************************************************************************************************************************
// Класс  Квадрат
//*******************************************************************************************************************************************
class  Square : public Parallelogram {
private:
	// Наследует параметры Параллелограмм
	// sizeA = sizeB
	// Угол альфа = 90 градусов ,хоть  sin(90) = 1  переопределил setArea() для вывода в консоль
public:
	Square (int a) : Parallelogram(a, a, 90) {}

	double getArea() override
	{
		cout << "class Square" << endl;
		return FigureArea;
	}
	void setArea() override
	{
		FigureArea = pow(sizeA,2);
		cout << "Set Figure Area Square = " << FigureArea << endl;
	}
	~Square() {

	}
};
//*******************************************************************************************************************************************
// Клас Ромб
//*******************************************************************************************************************************************
class  Rhombus : public Parallelogram {
private:
	// Наследует параметры Параллелограмм
	// sizeA = sizeB = sizeC = sizeD
public:
	Rhombus(int a, int ang) : Parallelogram(a, a, ang) {}

	double getArea() override
	{
		cout << "class Rhombus" << endl;
		return FigureArea;
	}
	void setArea() override
	{
		FigureArea = pow(sizeA, 2)* sin(angle_alpha);
		cout << "Set Figure Area Square = " << FigureArea << endl;
	}
	~Rhombus() {

	}
};

//*******************************************************************************************************************************************
int main(){
	setlocale(LC_ALL, "rus");

	Rhombus romb(10,45);
	Square sqr(8);
	Circle cir(12);
	Rectangle retr(10, 14);

	cout <<"Площадь ромба равна          "<<romb.getArea() << endl<<endl;
	cout <<"Площадь квадрата равна       "<<sqr.getArea() << endl<< endl;
	cout <<"Площадь круга равна          "<< cir.getArea() << endl << endl;
	cout <<"Площадь Прямоугольника равна "<<retr.getArea() << endl << endl;

system("pause");
return 0;
}


