#include"main.h"

//*******************************************************************************************************************************************
// ������� ����������� ����� Figure(������).��� ������������ �������� ������ Parallelogram(��������������) � Circle(����).
// ����� Parallelogram � ������� ��� ������� Rectangle(�������������), Square(�������), Rhombus(����).��� ���� ������� ������� ������������.
// ��� ������ Figure �������� ����� ����������� ������� area() (�������).�� ���� ��������� ������� �������������� ��� �������,
// ������ �� �������������� ������ ���������� �������.
//*******************************************************************************************************************************************

using namespace std;

//*******************************************************************************************************************************************
//   ������� �����
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
//  ����� ��������������
//*******************************************************************************************************************************************
class Parallelogram : public Figure {
protected:
	double sizeA;
	double sizeB;
	int angle_alpha;
public:

	Parallelogram (double a, double b, int ang) : Figure(a * b  * sin(ang)), sizeA(a), sizeB(b), angle_alpha(ang) {} // ����  ����� (������)

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
//   �����  ����  
//*******************************************************************************************************************************************
class Circle : public Figure {
private:
	int radius;        // ������ �����
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
//  ����� �������������
//*******************************************************************************************************************************************
class  Rectangle : public Parallelogram {
private:
	// ��������� ��������� ��������������
	// ���� ����� = 90 �������� ,����  sin(90) = 1  ������������� setArea() ��� ������ � �������
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
// �����  �������
//*******************************************************************************************************************************************
class  Square : public Parallelogram {
private:
	// ��������� ��������� ��������������
	// sizeA = sizeB
	// ���� ����� = 90 �������� ,����  sin(90) = 1  ������������� setArea() ��� ������ � �������
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
// ���� ����
//*******************************************************************************************************************************************
class  Rhombus : public Parallelogram {
private:
	// ��������� ��������� ��������������
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

	cout <<"������� ����� �����          "<<romb.getArea() << endl<<endl;
	cout <<"������� �������� �����       "<<sqr.getArea() << endl<< endl;
	cout <<"������� ����� �����          "<< cir.getArea() << endl << endl;
	cout <<"������� �������������� ����� "<<retr.getArea() << endl << endl;

system("pause");
return 0;
}


