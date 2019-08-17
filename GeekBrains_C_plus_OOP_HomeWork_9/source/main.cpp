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
	int celoe;
	int chislitel;
	int znamenatel;
	
public:
	Fraction();
	~Fraction();
	virtual void printFraction() = 0;
	
	virtual Fraction& operator =  (Fraction& other) = 0;
	virtual Fraction& operator +  (Fraction& other) = 0;
	virtual Fraction& operator *  (Fraction& other) = 0;
	virtual Fraction& operator /  (Fraction& other) = 0;
	virtual Fraction& operator == (Fraction& other) = 0;
	virtual Fraction& operator != (Fraction& other) = 0;
	virtual Fraction& operator <  (Fraction& other) = 0;
	virtual Fraction& operator >  (Fraction& other) = 0;
	virtual Fraction& operator <= (Fraction& other) = 0;
	virtual Fraction& operator >= (Fraction& other) = 0;
	virtual Fraction& operator -  () = 0;
};
//*******************************************************************************************************************************************
//   Класс SimpleFraction
//*******************************************************************************************************************************************
class SimpleFraction : public Fraction {
protected:
	
public:
	SimpleFraction (int c, int z) : Fraction (c, z, 0) {
	
	
	}
	SimpleFraction();
	SimpleFraction(SimpleFraction& other);
	SimpleFraction(int chislitel, int znamenatel);




	SimpleFraction() {

	}


	~SimpleFraction() {

	}
};
//*******************************************************************************************************************************************
SimpleFraction::SimpleFraction()
{
	chislitel = 0;
	znamenatel = 1;
}
SimpleFraction::SimpleFraction(SimpleFraction& other)
{
	this-> chislitel  = other.chislitel;
	this-> znamenatel = other.znamenatel;
}

SimpleFraction::SimpleFraction(int chislitel, int znamenatel)
{
	//normalize(numerator, denominator);
	this->chislitel  = chislitel;
	this->znamenatel = znamenatel;
}


//*******************************************************************************************************************************************
//   Класс MixedFraction
//*******************************************************************************************************************************************
class MixedFraction : public Fraction {
private:
	
public:
	MixedFraction(int c, int z,int i ) : Fraction(c, z, i) {

	}

	MixedFraction();
	MixedFraction(MixedFraction& other);
	MixedFraction(int chislitel, int znamenatel);

	~MixedFraction() {

	}
};
//*******************************************************************************************************************************************
MixedFraction::MixedFraction()
{
	celoe = 0;
	chislitel = 0;
	znamenatel = 1;
}
MixedFraction::MixedFraction(MixedFraction& other)
{
	this->celoe = other.celoe;
	this->chislitel = other.chislitel;
	this->znamenatel = other.znamenatel;
}

MixedFraction::MixedFraction(int chislitel, int znamenatel, int celoe)
{
	//normalize(numerator, denominator);
	this->celoe = celoe;
	this->chislitel = chislitel;
	this->znamenatel = znamenatel;
}

//*******************************************************************************************************************************************
int main(){



system("pause");
return 0;
}


