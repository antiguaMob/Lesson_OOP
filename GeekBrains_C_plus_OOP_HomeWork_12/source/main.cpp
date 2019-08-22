#include"main.h"

//*******************************************************************************************************************************************
//                                            Урок 4. Отношения между объектами в С++
//
//  * Разработать функцию, принимающую два числа в виде списка(вектора) цифр в одной системе счисления, и возвращающую число — результат сложения.
//  в виде списка(вектора) цифр в другой системе счисления.Входные данные <ситема_A> : <цифра_A1>, <цифра_A2>, ... <цифра_AN> <ситема_B> : <цифра_B1>,
//  <цифра_B2>, ... <цифра_BM> <ситема_C> система A, B — системы счисления входных чисел, цифра A1..AN и цифра B1..BN — запись входных чисел в виде
//  набора цифр от старшего разряда к младшему система C — система счисления результата сложения Пример : сложить FF в 16 системе 
//  счисления и HELLO в 36 системе счисления, результат вывести в двоичной системе счисления 16 : 15, 15 36 : 17, 14, 21, 21, 24 2 По сути 
//  задача сводится к тому, чтобы реализовать функцию : std::vector<int> plus(const std::vector<int> & A, int baseA, const std::vector<int> & B,
//  int baseB, int baseResult); реализующую сложение чисел в различных системах счисления, и возвращающую результат в требуемой системе счисления.
//*******************************************************************************************************************************************

using namespace std;



//*******************************************************************************************************************************************
class Fraction {
protected:
	int celoe;        // целое
	int chislitel;    // числитель
	int znamenatel;   // знаменатель
	
public:
	
    Fraction(int c = 0,int z = 1,int i = 0) : chislitel(c), znamenatel(z), celoe(i) { }
	virtual ~Fraction() {}

	int getChislitel()  const { return chislitel; }
	int getZnamenatel() const { return znamenatel; }
	virtual void printFraction () = 0;
	bool isEqual(Fraction const& b) const;
	bool isLower(Fraction const& b) const;
    bool isSameDenominator(Fraction const& other) const;
    int hcf(int a, int b);
    void reduce();
	
	friend void print (Fraction* fraction) {
		fraction->printFraction();
	}
};
//*******************************************************************************************************************************************
bool Fraction::isEqual(Fraction const& b) const {
	return this->chislitel == b.chislitel && this->znamenatel == b.znamenatel;
}

bool Fraction::isLower(Fraction const& b) const {
	return this->chislitel * b.znamenatel < this->znamenatel * b.chislitel;
}

bool Fraction::isSameDenominator(Fraction const& other) const {
	return this->znamenatel == other.znamenatel;
}

int Fraction::hcf(int a, int b) {
	while (b != 0) {

		const int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

void Fraction::reduce() {                                //  Упрощение дроби 
	int number = hcf(this->chislitel, this->znamenatel);
	this->chislitel /= number;
	this->znamenatel /= number;
}

//*******************************************************************************************************************************************
// Равенство
bool operator== (Fraction const& a, Fraction const& b) {
	return a.isEqual(b);
}
// Не равенство
bool operator!= (Fraction const& a, Fraction const& b) {
	return !(a == b);
}
//  Меньше 
bool operator< (Fraction const& a, Fraction const& b) {
	return a.isLower(b);
}
//  Больше
bool operator> (Fraction const& a, Fraction const& b) {
	return !(a.isLower(b));
}
// Меньше или равно
bool operator<= (Fraction const& a, Fraction const& b) {
	return !(b.isLower(a));
}
// Больше или равно
bool operator>= (Fraction const& a, Fraction const& b) {
	return !(a.isLower(b));
}
//*******************************************************************************************************************************************
//   Класс SimpleFraction
//*******************************************************************************************************************************************
class SimpleFraction : public Fraction {
protected:
	
public:

	SimpleFraction(SimpleFraction& other);
	SimpleFraction(int chislitel, int znamenatel);

	void printFraction();

	~SimpleFraction() {

	}

	//bool isEqual(SimpleFraction const& b) const;
	//bool isLower(SimpleFraction const& b) const;
	//bool isSameDenominator(SimpleFraction const& other) const;
	//int hcf(int a, int b);
	//void reduce();
	//int getChislitel()  const { return chislitel;  }
	//int getZnamenatel() const { return znamenatel; }

	SimpleFraction operator- ();

};

//*******************************************************************************************************************************************
SimpleFraction::SimpleFraction(SimpleFraction& other) {
	this->celoe = other.celoe;
	this-> chislitel  = other.chislitel;
	this-> znamenatel = other.znamenatel;
}

SimpleFraction::SimpleFraction(int chislitel, int znamenatel) {
	try {
		if (znamenatel != 0)
		{
	        int sign = chislitel * znamenatel / abs( chislitel * znamenatel );   // -1 если отрицательное , 1 если положительное.
	        znamenatel = abs ( znamenatel );                                     // Удаление знака из знаменателя
	        chislitel  = sign * abs(chislitel);
			this->chislitel  = chislitel;
			this->znamenatel = znamenatel;
			//this->celoe = 0;
}
		else throw exception("Знаменатель дроби равен 0. 'Деление на 0 не допустимо.'\n");
	}
	catch (const exception& e)
	{
		cout << e.what();
		exit(0);
	}
}

void SimpleFraction::printFraction() {
	
	cout << chislitel<< " / "<< znamenatel << endl;
}
//*******************************************************************************************************************************************
//  Унарный минус
SimpleFraction SimpleFraction::operator- () {
	return SimpleFraction(-1 * this->chislitel, this->znamenatel);
}

// Сложение
SimpleFraction operator+ (const SimpleFraction& a, const Fraction& b) {

	return SimpleFraction((a.getChislitel() * b.getZnamenatel() + a.getZnamenatel() * b.getChislitel()), (a.getZnamenatel() * b.getZnamenatel()));
}
// Умножение
SimpleFraction operator*(SimpleFraction const& a, Fraction const& b) {

	return SimpleFraction((a.getChislitel() * b.getChislitel()), (a.getZnamenatel() * b.getZnamenatel()));

}
//  Деление
SimpleFraction operator/ (SimpleFraction const& a, Fraction const& b) {

	return SimpleFraction((a.getChislitel() * b.getZnamenatel()), (a.getZnamenatel() * b.getChislitel()));

}
// Вычитание
SimpleFraction operator- (const SimpleFraction& a, const Fraction& b) {

	return SimpleFraction((a.getChislitel() * b.getZnamenatel() - a.getZnamenatel() * b.getChislitel()), (a.getZnamenatel() * b.getZnamenatel()));
}
////*******************************************************************************************************************************************
////  Унарный минус
//SimpleFraction SimpleFraction::operator- () {
//	return SimpleFraction(-1 *this->chislitel,this->znamenatel);
//}
//
//// Сложение
//SimpleFraction operator+ (const SimpleFraction& a, const SimpleFraction& b) {
//
//	return SimpleFraction ((a.getChislitel() * b.getZnamenatel() + a.getZnamenatel() * b.getChislitel() ), (a.getZnamenatel() * b.getZnamenatel() ));
//}
//// Умножение
//SimpleFraction operator*(SimpleFraction const& a, SimpleFraction const& b) {              
//
//	return SimpleFraction((a.getChislitel() * b.getChislitel() ), (a.getZnamenatel() * b.getZnamenatel() ));
//
//}
////  Деление
//SimpleFraction operator/ (SimpleFraction const& a, SimpleFraction const& b) {                
//
//	return SimpleFraction((a.getChislitel() * b.getZnamenatel()), (a.getZnamenatel() * b.getChislitel() ));
//
//}
//// Вычитание
//SimpleFraction operator- (const SimpleFraction& a, const SimpleFraction& b) {
//
//	return SimpleFraction((a.getChislitel() * b.getZnamenatel() - a.getZnamenatel() * b.getChislitel()), (a.getZnamenatel() * b.getZnamenatel() ));
//}
//*******************************************************************************************************************************************
//// Равенство
//bool operator== (SimpleFraction const& a, SimpleFraction const& b) {
//	return a.isEqual(b);
//}
//// Не равенство
//bool operator!= (SimpleFraction const& a, SimpleFraction const& b) {
//	return !(a == b);
//}
////  Меньше 
//bool operator< (SimpleFraction const& a, SimpleFraction const& b) {
//	return a.isLower(b);
//}
////  Больше
//bool operator> (SimpleFraction const& a, SimpleFraction const& b) {
//	return !(a.isLower(b));
//}
//// Меньше или равно
//bool operator<= (SimpleFraction const& a, SimpleFraction const& b) {
//	return !(b.isLower(a));
//}
//// Больше или равно
//bool operator>= (SimpleFraction const& a, SimpleFraction const& b) {
//	return !(a.isLower(b));
//}
//*******************************************************************************************************************************************
//*******************************************************************************************************************************************
//bool SimpleFraction::isEqual(SimpleFraction const& b) const {
//	return this->chislitel == b.chislitel && this->znamenatel == b.znamenatel;
//}
//
//bool SimpleFraction::isLower(SimpleFraction const& b) const {
//	return this->chislitel * b.znamenatel < this->znamenatel * b.chislitel;
//}
//
//bool SimpleFraction::isSameDenominator(SimpleFraction const& other) const {
//	return this->znamenatel == other.znamenatel;
//}
//
//int SimpleFraction::hcf(int a, int b) {
//	while (b != 0) {
//
//		const int t = b;
//		b = a % b;
//		a = t;
//	}
//	return a;
//}
//
//void SimpleFraction::reduce() {                                //  Упрощение дроби 
//	int number = hcf(this->chislitel, this->znamenatel);
//	this->chislitel /= number;
//	this->znamenatel /= number;
//}
//*******************************************************************************************************************************************
//   Класс MixedFraction
//*******************************************************************************************************************************************
class MixedFraction : public Fraction {
private:
	
public:

	MixedFraction(MixedFraction& other);
	MixedFraction(int celoe ,int chislitel, int znamenatel);
	MixedFraction(int chislitel, int znamenatel);
	void printFraction();

	~MixedFraction() {

	}

	//bool isEqual(MixedFraction const& b) const;
	//bool isLower(MixedFraction const& b) const;
	//bool isSameDenominator(MixedFraction const& other) const;
	//int hcf(int a, int b);
	//void reduce();
	//int getChislitel()  const { return chislitel; }
	//int getZnamenatel() const { return znamenatel; }

	MixedFraction operator- ();
};
//*******************************************************************************************************************************************
MixedFraction::MixedFraction(MixedFraction& other) {

	this->celoe = other.celoe;
	this->chislitel = other.chislitel;
	this->znamenatel = other.znamenatel;
}
MixedFraction::MixedFraction(int chislitel, int znamenatel) {
	try {
		if (znamenatel != 0)
		{
			int sign = chislitel * znamenatel / abs(chislitel * znamenatel);   // -1 если отрицательное , 1 если положительное.
			znamenatel = abs(znamenatel);                                     // Удаление знака из знаменателя
			chislitel = sign * abs(chislitel);
			this->chislitel = chislitel;
			this->znamenatel = znamenatel;
			//this->celoe = 0;
		}
		else throw exception("Знаменатель дроби равен 0. 'Деление на 0 не допустимо.'\n");
	}
	catch (const exception& e)
	{
		cout << e.what();
		exit(0);
	}
}

MixedFraction::MixedFraction(int celoe, int chislitel, int znamenatel) {
	//this->sign = normalize(chislitel, znamenatel, celoe);
	try {
		if (znamenatel != 0)
		{
			//cout << 10 / znamenatel << "\n";

		   int sign = chislitel  * znamenatel / abs(chislitel  * znamenatel);   // -1 если отрицательное , 1 если положительное.
		   znamenatel = abs(znamenatel);                                                         // Удаление знака из знаменателя
		   if (celoe < 0) sign == -1 ? 1 : -1 ;
		   chislitel = sign * (abs(chislitel) + abs(celoe*znamenatel));
		   this->chislitel = sign*chislitel;
		   this->znamenatel = znamenatel;		
		}
		else throw exception("Знаменатель дроби равен 0. 'Деление на 0 не допустимо.'\n");
	}
	catch (const exception& e)
	{
		cout << e.what();
		exit(0);
	}
}

void MixedFraction::printFraction() {
	//if (sign) cout << "- ";
	cout << chislitel << " / " << znamenatel << endl;
}
////*******************************************************************************************************************************************
//  Унарный минус
MixedFraction MixedFraction::operator- () {
	return MixedFraction(-1 * this->chislitel, this->znamenatel);
}
// Сложение Fraction* fraction
MixedFraction operator+ (const Fraction& a, const Fraction& b) {

	return MixedFraction((a.getChislitel() * b.getZnamenatel() + a.getZnamenatel() * b.getChislitel()), (a.getZnamenatel() * b.getZnamenatel()));
}
// Умножение Fraction* fraction
MixedFraction operator*(Fraction const& a, Fraction const& b) {

	return MixedFraction((a.getChislitel() * b.getChislitel()), (a.getZnamenatel() * b.getZnamenatel()));

}
//  Деление
MixedFraction operator/ (Fraction const& a, Fraction const& b) {

	return MixedFraction((a.getChislitel() * b.getZnamenatel()), (a.getZnamenatel() * b.getChislitel()));

}
// Вычитание
MixedFraction operator- (const Fraction& a, const Fraction& b) {

	return MixedFraction((a.getChislitel() * b.getZnamenatel() - a.getZnamenatel() * b.getChislitel()), (a.getZnamenatel() * b.getZnamenatel()));
}
//// Сложение
//MixedFraction operator+ (const MixedFraction& a, const MixedFraction& b) {
//
//	return MixedFraction((a.getChislitel() * b.getZnamenatel() + a.getZnamenatel() * b.getChislitel()), (a.getZnamenatel() * b.getZnamenatel()));
//}
//// Умножение
//MixedFraction operator*(MixedFraction const& a, MixedFraction const& b) {
//
//	return MixedFraction((a.getChislitel() * b.getChislitel()), (a.getZnamenatel() * b.getZnamenatel()));
//
//}
////  Деление
//MixedFraction operator/ (MixedFraction const& a, MixedFraction const& b) {
//
//	return MixedFraction((a.getChislitel() * b.getZnamenatel()), (a.getZnamenatel() * b.getChislitel()));
//
//}
//// Вычитание
//MixedFraction operator- (const MixedFraction& a, const MixedFraction& b) {
//
//	return MixedFraction((a.getChislitel() * b.getZnamenatel() - a.getZnamenatel() * b.getChislitel()), (a.getZnamenatel() * b.getZnamenatel()));
//}

//// Равенство
//bool operator== (MixedFraction const& a, MixedFraction const& b) {
//	return a.isEqual(b);
//}
//// Не равенство
//bool operator!= (MixedFraction const& a, MixedFraction const& b) {
//	return !(a == b);
//}
////  Меньше 
//bool operator< (MixedFraction const& a, MixedFraction const& b) {
//	return a.isLower(b);
//}
////  Больше
//bool operator> (MixedFraction const& a, MixedFraction const& b) {
//	return !(a.isLower(b));
//}
//// Меньше или равно
//bool operator<= (MixedFraction const& a, MixedFraction const& b) {
//	return !(b.isLower(a));
//}
//// Больше или равно
//bool operator>= (MixedFraction const& a, MixedFraction const& b) {
//	return !(a.isLower(b));
//}
//*******************************************************************************************************************************************
//*******************************************************************************************************************************************
//bool MixedFraction::isEqual(MixedFraction const& b) const {
//	return this->chislitel == b.chislitel && this->znamenatel == b.znamenatel;
//}
//
//bool MixedFraction::isLower(MixedFraction const& b) const {
//	return this->chislitel * b.znamenatel < this->znamenatel * b.chislitel;
//}
//
//bool MixedFraction::isSameDenominator(MixedFraction const& other) const {
//	return this->znamenatel == other.znamenatel;
//}
//
//int MixedFraction::hcf(int a, int b) {
//	while (b != 0) {
//
//		const int t = b;
//		b = a % b;
//		a = t;
//	}
//	return a;
//}
//
//void MixedFraction::reduce() {                                //  Упрощение дроби 
//	int number = hcf(this->chislitel, this->znamenatel);
//	this->chislitel /= number;
//	this->znamenatel /= number;
//}
//*******************************************************************************************************************************************
int main(){
	setlocale(LC_ALL, "rus");

//*******************************************************************************************************************************************
//   Создание простой дроби
//*******************************************************************************************************************************************
	SimpleFraction frac1( 1, 2);    // Дробь  =   1 / 2
	SimpleFraction frac2( 3, 4);    // Дробь  =   2 / 4
	SimpleFraction frac3( 3,-8);    // Дробь  = - 3 / 8
	SimpleFraction frac4(-2, 4);    // Дробь  = - 2 / 4
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
	cout << endl;
	cout << "Дробь 5: "; print(&frac5);
	cout << "Дробь 6: "; print(&frac6);
	cout << "Дробь 7: "; print(&frac7);
	cout << "Дробь 8: "; print(&frac8);
	cout << endl;
//*******************************************************************************************************************************************
// Проверка равенства	
//*******************************************************************************************************************************************
	cout << "Дробь '1'=='1' : " << (frac1 == frac1) << endl;  
	cout << "Дробь '1'=='2' : " << (frac1 == frac2) << endl;
	cout << "Дробь '1'=='3' : " << (frac1 == frac3) << endl;
	cout << "Дробь '1'=='4' : " << (frac1 == frac4) << endl;
	cout << endl;
//*******************************************************************************************************************************************	
// Математические операции
//*******************************************************************************************************************************************
	SimpleFraction frac9 = frac1 + frac3;
	cout << "Сложение '1' + '3' : "; print(&frac9);
	               frac9 = frac2 - frac3;
	cout << "Вычитание '2' + '3': "; print(&frac9);
	               frac9 = frac4 * frac3;
	cout << "Умножение '4' + '3': "; print(&frac9);
	cout << endl;
	cout << "Проверка унарный минус : "; print(&frac9);
	frac9 = -frac9;
	cout << "Унарный минус -'Дробь' : "; print(&frac9);
//*******************************************************************************************************************************************	
// Математические операции  с разными дробями
//*******************************************************************************************************************************************
	SimpleFraction frac10 = frac1 + frac5;
	cout << "Сложение '1' + '3' : "; print(&frac10);
	frac9 = frac2 - frac6;
	cout << "Вычитание '2' + '3': "; print(&frac9);
	frac9 = frac4 * frac8;
	cout << "Умножение '4' + '3': "; print(&frac9);


system("pause");
return 0;
}


