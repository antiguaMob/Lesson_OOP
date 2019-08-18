#include"main.h"

//*******************************************************************************************************************************************
// Создать абстрактный класс Fraction(дробь).От него наследуют два класса : SimpleFraction(обыкновенная дробь) и MixedFraction(смешанная дробь).
// Обыкновенная дробь имеет только числитель и знаменатель(например, 3 / 7 или 9 / 2), а смешанная — еще и целую часть(например, 312).Предусмотреть,
// чтобы знаменатель не был равен 0. Перегрузить математические бинарные операторы(+, -, *, / ) для выполнения действий с дробями, а также унарный 
// оператор(-).Перегрузить логические операторы сравнения двух дробей(== , != , <, >, <= , >= ).Поскольку операторы < и >= , > и <= — это логические 
// противоположности, попробуйте перегрузить один через другой.
//*******************************************************************************************************************************************

using namespace std;

//*******************************************************************************************************************************************
class Fraction {
protected:
	int celoe;        // целое
	int chislitel;    // числитель
	int znamenatel;   // знаменатель
	bool sign;        // знак( если один  из параметров  отрицательный  - дробь отрицательная,
	                  // если два аргумента отрицательные ,то дробь положительная).
public:
	//Fraction();
    Fraction(int c = 0,int z = 1,int i = 0,bool s = false):chislitel(c),znamenatel(z),celoe(i),sign(s) { }
	virtual ~Fraction() {}
	
	virtual void printFraction () = 0;
	
	//virtual Fraction& operator =  (Fraction& other) = 0;
	//virtual Fraction& operator +  (Fraction& other) = 0;
	//virtual Fraction& operator *  (Fraction& other) = 0;
	//virtual Fraction& operator /  (Fraction& other) = 0;
	//virtual Fraction& operator == (Fraction& other) = 0;
	//virtual Fraction& operator != (Fraction& other) = 0;
	//virtual Fraction& operator <  (Fraction& other) = 0;
	//virtual Fraction& operator >  (Fraction& other) = 0;
	//virtual Fraction& operator <= (Fraction& other) = 0;
	//virtual Fraction& operator >= (Fraction& other) = 0;
	//virtual Fraction& operator -  () = 0;

	friend void print (Fraction* fraction) {
		fraction->printFraction();
	}
};

//void print(Fraction* fraction) {
//	fraction->printFraction();
//}
//*******************************************************************************************************************************************
//   Класс SimpleFraction
//*******************************************************************************************************************************************
class SimpleFraction : public Fraction {
protected:
	
public:
	//SimpleFraction (int c, int z) : Fraction (c, z, 0) { }

	//SimpleFraction();
	SimpleFraction(SimpleFraction& other);
	SimpleFraction(int chislitel, int znamenatel);

	void printFraction();

	~SimpleFraction() {

	}
	
};

//*******************************************************************************************************************************************
//SimpleFraction::SimpleFraction() {
//	chislitel  = 0;
//	znamenatel = 1;
//	celoe = 0;
//	sign = false;
//    }

SimpleFraction::SimpleFraction(SimpleFraction& other) {
	this->celoe = other.celoe;
	this-> chislitel  = other.chislitel;
	this-> znamenatel = other.znamenatel;
	this->sign = other.sign;
}

SimpleFraction::SimpleFraction(int chislitel, int znamenatel) {
	//normalize(numerator, denominator);
	this->chislitel  = chislitel;
	this->znamenatel = znamenatel;
	this->celoe = 0;
	this->sign = false;
}

void SimpleFraction::printFraction() {
	cout << chislitel<< " / "<< znamenatel << endl;
}

//*******************************************************************************************************************************************
//   Класс MixedFraction
//*******************************************************************************************************************************************
class MixedFraction : public Fraction {
private:
	
public:
	//MixedFraction(int c, int z,int i ) : Fraction(c, z, i) { }
	//MixedFraction();
	MixedFraction(MixedFraction& other);
	MixedFraction(int chislitel, int znamenatel, int celoe);

	void printFraction();

	~MixedFraction() {

	}
	
};
//*******************************************************************************************************************************************
//MixedFraction::MixedFraction() {
//	chislitel = 0;
//	znamenatel = 1;
//	celoe = 0;
//	sign = false;
//}

MixedFraction::MixedFraction(MixedFraction& other) {
	this->celoe = other.celoe;
	this->chislitel = other.chislitel;
	this->znamenatel = other.znamenatel;
	this->sign = other.sign;
}

MixedFraction::MixedFraction(int chislitel, int znamenatel, int celoe) {
	//normalize(numerator, denominator);
	this->celoe = celoe;
	this->chislitel = chislitel;
	this->znamenatel = znamenatel;
	this->sign = false;
}

void MixedFraction::printFraction() {
	cout <<celoe<<" "<< chislitel << " / " << znamenatel << endl;
}

//*******************************************************************************************************************************************
int main(){
	setlocale(LC_ALL, "rus");

//*******************************************************************************************************************************************
//   Создание простой дроби
//*******************************************************************************************************************************************
	SimpleFraction frac1( 1, 2);    // Дробь  =   1 / 2
	SimpleFraction frac2( 2, 4);    // Дробь  =   2 / 4
	SimpleFraction frac3( 3,-8);    // Дробь  = - 3 / 8
	SimpleFraction frac4(-2, 4);    // Дробь  = - 2 / 4
	//SimpleFraction frac9();
//*******************************************************************************************************************************************
//   Создание смешанной дроби
//*******************************************************************************************************************************************
	MixedFraction frac5( 1, 1, 2);  // Дробь  =   1  1 / 2
	MixedFraction frac6( 2, 3, 4);  // Дробь  =   2  3 / 4
	MixedFraction frac7( 1, 3,-8);  // Дробь  = - 1  3 / 8
	MixedFraction frac8(-2, 1, 4);  // Дробь  = - 2  1 / 4
//*******************************************************************************************************************************************
//  Вывод дробей в консоль.
//*******************************************************************************************************************************************
	cout << "Дробь 1: "; print(&frac1);
	cout << "Дробь 2: "; print(&frac2);
	cout << "Дробь 3: "; print(&frac3);
	cout << "Дробь 4: "; print(&frac4);
	cout << "Дробь 5: "; print(&frac5);
	cout << "Дробь 6: "; print(&frac6);
	cout << "Дробь 7: "; print(&frac7);
	cout << "Дробь 8: "; print(&frac8);
	//cout << "Дробь 9: "; print(&frac9);
	cout << endl;
//*******************************************************************************************************************************************
// Проверка равенства	
//*******************************************************************************************************************************************
	//cout << "1==1: " << (frac1 == frac1) << endl;  
	//cout << "1==2: " << (frac1 == frac2) << endl;
	//cout << "1==3: " << (frac1 == frac3) << endl;
	//cout << "1==4: " << (frac1 == frac4) << endl;

//*******************************************************************************************************************************************	


system("pause");
return 0;
}


