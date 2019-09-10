#include"main.h"

//*******************************************************************************************************************************************
//                                            Урок 6. Потоки ввода-вывода в С++
//
//  Добавить перегрузку операторов ввода - вывода для класса Fraction из предыдущих заданий так, чтобы при выполнении этого кода :
//  int main() {
//
//	Fraction f1;
//	cout << "Enter fraction 1: ";
//	cin >> f1;
//
//	Fraction f2;
//	cout << "Enter fraction 2: ";
//	cin >> f2;
//
//	cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n';
//
//	return 0;
// }
//
//  ... выводилось на экран :
//  Enter fraction 1 : 3 / 4
//  Enter fraction 2 : 4 / 9
//  3 / 4 * 4 / 9 is 1 / 3
//
//*******************************************************************************************************************************************

using namespace std;

//*******************************************************************************************************************************************
class Fraction {
protected:
	int chislitel;    // числитель
	int znamenatel;   // знаменатель

public:

	Fraction(Fraction& other);
	Fraction(int i, int c, int z) ;
	Fraction(int c, int z) ;
	Fraction() {

		chislitel = 0;
		znamenatel = 1;
	};

	~Fraction() {}

	int getChislitel()  const { return chislitel; }
	int getZnamenatel() const { return znamenatel; }
	
	bool isEqual(Fraction const& b) const;
	bool isLower(Fraction const& b) const;

	bool isSameDenominator(Fraction const& other) const;
	bool Fraction::convertStringToFraction(std::string FractionString);
	int hcf(int a, int b);

	void reduce();
	void printFraction();
	// Унарный минус
	Fraction operator- ();
	// Сложение Fraction* fraction
	Fraction operator+ (const Fraction& a);
	// Умножение Fraction* fraction
	Fraction operator* (Fraction const& a);
	// Деление
	Fraction operator/ (Fraction const& a);
	// Вычитание
	Fraction operator- (const Fraction& a);
	

};

//*******************************************************************************************************************************************
//                                        Перегрузка операторов ввода вывода    >> <<
//*******************************************************************************************************************************************

std::ostream& operator<<(std::ostream& out, const Fraction& a) {

	if (a.getChislitel() == 0) { return out << "0"; }
	return out << a.getChislitel()<< " / " << a.getZnamenatel();
}

std::istream& operator>>(std::istream& in, Fraction& Fraction) {

	std::string input;

	in >> input;
	try{
		if (false==Fraction.convertStringToFraction(input)) 
		     throw exception("Не корректный ввод данных...\n");
	}
	catch (const std::exception & e) {

		std::cerr << e.what() << std::endl;
	
    }
	return in;	
}
//*******************************************************************************************************************************************



bool Fraction::convertStringToFraction(std::string FractionString) {     // Конвертация строки в дробь
	std::size_t pos = FractionString.find("/");

	if (pos != std::string::npos) {
		try {
			this->chislitel  = atol(FractionString.substr(0, pos).c_str());
			this->znamenatel = atol(FractionString.substr(pos + 1).c_str());
		}
		catch (...) {
			return false;
		}
		return (this->znamenatel == 0) ? false : true;
	}
	return false;
}
//*******************************************************************************************************************************************
Fraction::Fraction(Fraction& other) {

	this->chislitel = other.chislitel;
	this->znamenatel = other.znamenatel;
}

Fraction::Fraction(int chislitel, int znamenatel) {
	try {
		if (znamenatel != 0)
		{
			int sign = chislitel * znamenatel / abs(chislitel * znamenatel);   // -1 если отрицательное , 1 если положительное.
			znamenatel = abs(znamenatel);                                     // Удаление знака из знаменателя
			chislitel = sign * abs(chislitel);
			this->chislitel = chislitel;
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

Fraction::Fraction(int celoe, int chislitel, int znamenatel) {
	try {
		if (znamenatel != 0)
		{

			int sign = chislitel * znamenatel / abs(chislitel * znamenatel);   // -1 если отрицательное , 1 если положительное.
			znamenatel = abs(znamenatel);                                                         // Удаление знака из знаменателя
			if (celoe < 0) sign == -1 ? 1 : -1;
			chislitel = sign * (abs(chislitel) + abs(celoe * znamenatel));
			this->chislitel = sign * chislitel;
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

void Fraction::printFraction() {
	reduce();
	cout << chislitel << " / " << znamenatel << endl;
}

Fraction Fraction::operator-()
{
	return Fraction(-1 * this->chislitel, this->znamenatel);
}

Fraction Fraction::operator+(const Fraction& a)
{
	Fraction temp((this->chislitel * a.znamenatel + this->znamenatel * a.chislitel), (this->znamenatel * a.znamenatel));
	temp.reduce();	
	return temp;   
}

Fraction Fraction::operator*(Fraction const& a)
{
	Fraction temp((this->chislitel * a.chislitel), (this->znamenatel * a.znamenatel));
	temp.reduce();
	return temp;
}

Fraction Fraction::operator/(Fraction const& a)
{
	Fraction temp((this->chislitel * a.znamenatel), (this->znamenatel * a.chislitel));
	temp.reduce();
	return temp;
}

Fraction Fraction::operator-(const Fraction& a)
{
	Fraction temp((this->chislitel * a.getZnamenatel() - this->znamenatel * a.getChislitel()), (this->znamenatel * a.getZnamenatel()));
	temp.reduce();
	return temp;
}


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

bool operator== (Fraction const& a, Fraction const& b) {
	return a.isEqual(b);
}

bool operator!= (Fraction const& a, Fraction const& b) {
	return !(a == b);
}

bool operator< (Fraction const& a, Fraction const& b) {
	return a.isLower(b);
}

bool operator> (Fraction const& a, Fraction const& b) {
	return !(a.isLower(b));
}

bool operator<= (Fraction const& a, Fraction const& b) {
	return !(b.isLower(a));
}

bool operator>= (Fraction const& a, Fraction const& b) {
	return !(a.isLower(b));
}
//*******************************************************************************************************************************************


//*******************************************************************************************************************************************
int main(){
	setlocale(LC_ALL, "rus");

		Fraction f1;
		cout << "Enter fraction 1: ";
		cin >> f1;
		cout << endl;

		Fraction f2;
		cout << "Enter fraction 2: ";
		cin >> f2;
		cout << endl;
	//    3 / 4 * 4 / 9 is 1 / 3
		cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n';
		cout << endl;
system("pause");
return 0;
}

