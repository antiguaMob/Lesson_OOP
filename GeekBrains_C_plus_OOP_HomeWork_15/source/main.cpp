#include"main.h"

//*******************************************************************************************************************************************
//                                            ���� 6. ������ �����-������ � �++
//
//  �������� ���������� ���������� ����� - ������ ��� ������ Fraction �� ���������� ������� ���, ����� ��� ���������� ����� ���� :
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
//  ... ���������� �� ����� :
//  Enter fraction 1 : 3 / 4
//  Enter fraction 2 : 4 / 9
//  3 / 4 * 4 / 9 is 1 / 3
//
//*******************************************************************************************************************************************

using namespace std;

//*******************************************************************************************************************************************
class Fraction {
protected:
	int chislitel;    // ���������
	int znamenatel;   // �����������

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
	// ������� �����
	Fraction operator- ();
	// �������� Fraction* fraction
	Fraction operator+ (const Fraction& a);
	// ��������� Fraction* fraction
	Fraction operator* (Fraction const& a);
	// �������
	Fraction operator/ (Fraction const& a);
	// ���������
	Fraction operator- (const Fraction& a);
	

};

//*******************************************************************************************************************************************
//                                        ���������� ���������� ����� ������    >> <<
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
		     throw exception("�� ���������� ���� ������...\n");
	}
	catch (const std::exception & e) {

		std::cerr << e.what() << std::endl;
	
    }
	return in;	
}
//*******************************************************************************************************************************************



bool Fraction::convertStringToFraction(std::string FractionString) {     // ����������� ������ � �����
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
			int sign = chislitel * znamenatel / abs(chislitel * znamenatel);   // -1 ���� ������������� , 1 ���� �������������.
			znamenatel = abs(znamenatel);                                     // �������� ����� �� �����������
			chislitel = sign * abs(chislitel);
			this->chislitel = chislitel;
			this->znamenatel = znamenatel;
			
		}
		else throw exception("����������� ����� ����� 0. '������� �� 0 �� ���������.'\n");
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

			int sign = chislitel * znamenatel / abs(chislitel * znamenatel);   // -1 ���� ������������� , 1 ���� �������������.
			znamenatel = abs(znamenatel);                                                         // �������� ����� �� �����������
			if (celoe < 0) sign == -1 ? 1 : -1;
			chislitel = sign * (abs(chislitel) + abs(celoe * znamenatel));
			this->chislitel = sign * chislitel;
			this->znamenatel = znamenatel;
		}
		else throw exception("����������� ����� ����� 0. '������� �� 0 �� ���������.'\n");
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

void Fraction::reduce() {                                //  ��������� ����� 
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

