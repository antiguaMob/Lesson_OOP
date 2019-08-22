#include"main.h"

//*******************************************************************************************************************************************
//                                            ���� 4. ��������� ����� ��������� � �++
//
//  * ����������� �������, ����������� ��� ����� � ���� ������(�������) ���� � ����� ������� ���������, � ������������ ����� � ��������� ��������.
//  � ���� ������(�������) ���� � ������ ������� ���������.������� ������ <������_A> : <�����_A1>, <�����_A2>, ... <�����_AN> <������_B> : <�����_B1>,
//  <�����_B2>, ... <�����_BM> <������_C> ������� A, B � ������� ��������� ������� �����, ����� A1..AN � ����� B1..BN � ������ ������� ����� � ����
//  ������ ���� �� �������� ������� � �������� ������� C � ������� ��������� ���������� �������� ������ : ������� FF � 16 ������� 
//  ��������� � HELLO � 36 ������� ���������, ��������� ������� � �������� ������� ��������� 16 : 15, 15 36 : 17, 14, 21, 21, 24 2 �� ���� 
//  ������ �������� � ����, ����� ����������� ������� : std::vector<int> plus(const std::vector<int> & A, int baseA, const std::vector<int> & B,
//  int baseB, int baseResult); ����������� �������� ����� � ��������� �������� ���������, � ������������ ��������� � ��������� ������� ���������.
//*******************************************************************************************************************************************

using namespace std;



//*******************************************************************************************************************************************
class Fraction {
protected:
	int celoe;        // �����
	int chislitel;    // ���������
	int znamenatel;   // �����������
	
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

void Fraction::reduce() {                                //  ��������� ����� 
	int number = hcf(this->chislitel, this->znamenatel);
	this->chislitel /= number;
	this->znamenatel /= number;
}

//*******************************************************************************************************************************************
// ���������
bool operator== (Fraction const& a, Fraction const& b) {
	return a.isEqual(b);
}
// �� ���������
bool operator!= (Fraction const& a, Fraction const& b) {
	return !(a == b);
}
//  ������ 
bool operator< (Fraction const& a, Fraction const& b) {
	return a.isLower(b);
}
//  ������
bool operator> (Fraction const& a, Fraction const& b) {
	return !(a.isLower(b));
}
// ������ ��� �����
bool operator<= (Fraction const& a, Fraction const& b) {
	return !(b.isLower(a));
}
// ������ ��� �����
bool operator>= (Fraction const& a, Fraction const& b) {
	return !(a.isLower(b));
}
//*******************************************************************************************************************************************
//   ����� SimpleFraction
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
	        int sign = chislitel * znamenatel / abs( chislitel * znamenatel );   // -1 ���� ������������� , 1 ���� �������������.
	        znamenatel = abs ( znamenatel );                                     // �������� ����� �� �����������
	        chislitel  = sign * abs(chislitel);
			this->chislitel  = chislitel;
			this->znamenatel = znamenatel;
			//this->celoe = 0;
}
		else throw exception("����������� ����� ����� 0. '������� �� 0 �� ���������.'\n");
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
//  ������� �����
SimpleFraction SimpleFraction::operator- () {
	return SimpleFraction(-1 * this->chislitel, this->znamenatel);
}

// ��������
SimpleFraction operator+ (const SimpleFraction& a, const Fraction& b) {

	return SimpleFraction((a.getChislitel() * b.getZnamenatel() + a.getZnamenatel() * b.getChislitel()), (a.getZnamenatel() * b.getZnamenatel()));
}
// ���������
SimpleFraction operator*(SimpleFraction const& a, Fraction const& b) {

	return SimpleFraction((a.getChislitel() * b.getChislitel()), (a.getZnamenatel() * b.getZnamenatel()));

}
//  �������
SimpleFraction operator/ (SimpleFraction const& a, Fraction const& b) {

	return SimpleFraction((a.getChislitel() * b.getZnamenatel()), (a.getZnamenatel() * b.getChislitel()));

}
// ���������
SimpleFraction operator- (const SimpleFraction& a, const Fraction& b) {

	return SimpleFraction((a.getChislitel() * b.getZnamenatel() - a.getZnamenatel() * b.getChislitel()), (a.getZnamenatel() * b.getZnamenatel()));
}
////*******************************************************************************************************************************************
////  ������� �����
//SimpleFraction SimpleFraction::operator- () {
//	return SimpleFraction(-1 *this->chislitel,this->znamenatel);
//}
//
//// ��������
//SimpleFraction operator+ (const SimpleFraction& a, const SimpleFraction& b) {
//
//	return SimpleFraction ((a.getChislitel() * b.getZnamenatel() + a.getZnamenatel() * b.getChislitel() ), (a.getZnamenatel() * b.getZnamenatel() ));
//}
//// ���������
//SimpleFraction operator*(SimpleFraction const& a, SimpleFraction const& b) {              
//
//	return SimpleFraction((a.getChislitel() * b.getChislitel() ), (a.getZnamenatel() * b.getZnamenatel() ));
//
//}
////  �������
//SimpleFraction operator/ (SimpleFraction const& a, SimpleFraction const& b) {                
//
//	return SimpleFraction((a.getChislitel() * b.getZnamenatel()), (a.getZnamenatel() * b.getChislitel() ));
//
//}
//// ���������
//SimpleFraction operator- (const SimpleFraction& a, const SimpleFraction& b) {
//
//	return SimpleFraction((a.getChislitel() * b.getZnamenatel() - a.getZnamenatel() * b.getChislitel()), (a.getZnamenatel() * b.getZnamenatel() ));
//}
//*******************************************************************************************************************************************
//// ���������
//bool operator== (SimpleFraction const& a, SimpleFraction const& b) {
//	return a.isEqual(b);
//}
//// �� ���������
//bool operator!= (SimpleFraction const& a, SimpleFraction const& b) {
//	return !(a == b);
//}
////  ������ 
//bool operator< (SimpleFraction const& a, SimpleFraction const& b) {
//	return a.isLower(b);
//}
////  ������
//bool operator> (SimpleFraction const& a, SimpleFraction const& b) {
//	return !(a.isLower(b));
//}
//// ������ ��� �����
//bool operator<= (SimpleFraction const& a, SimpleFraction const& b) {
//	return !(b.isLower(a));
//}
//// ������ ��� �����
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
//void SimpleFraction::reduce() {                                //  ��������� ����� 
//	int number = hcf(this->chislitel, this->znamenatel);
//	this->chislitel /= number;
//	this->znamenatel /= number;
//}
//*******************************************************************************************************************************************
//   ����� MixedFraction
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
			int sign = chislitel * znamenatel / abs(chislitel * znamenatel);   // -1 ���� ������������� , 1 ���� �������������.
			znamenatel = abs(znamenatel);                                     // �������� ����� �� �����������
			chislitel = sign * abs(chislitel);
			this->chislitel = chislitel;
			this->znamenatel = znamenatel;
			//this->celoe = 0;
		}
		else throw exception("����������� ����� ����� 0. '������� �� 0 �� ���������.'\n");
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

		   int sign = chislitel  * znamenatel / abs(chislitel  * znamenatel);   // -1 ���� ������������� , 1 ���� �������������.
		   znamenatel = abs(znamenatel);                                                         // �������� ����� �� �����������
		   if (celoe < 0) sign == -1 ? 1 : -1 ;
		   chislitel = sign * (abs(chislitel) + abs(celoe*znamenatel));
		   this->chislitel = sign*chislitel;
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

void MixedFraction::printFraction() {
	//if (sign) cout << "- ";
	cout << chislitel << " / " << znamenatel << endl;
}
////*******************************************************************************************************************************************
//  ������� �����
MixedFraction MixedFraction::operator- () {
	return MixedFraction(-1 * this->chislitel, this->znamenatel);
}
// �������� Fraction* fraction
MixedFraction operator+ (const Fraction& a, const Fraction& b) {

	return MixedFraction((a.getChislitel() * b.getZnamenatel() + a.getZnamenatel() * b.getChislitel()), (a.getZnamenatel() * b.getZnamenatel()));
}
// ��������� Fraction* fraction
MixedFraction operator*(Fraction const& a, Fraction const& b) {

	return MixedFraction((a.getChislitel() * b.getChislitel()), (a.getZnamenatel() * b.getZnamenatel()));

}
//  �������
MixedFraction operator/ (Fraction const& a, Fraction const& b) {

	return MixedFraction((a.getChislitel() * b.getZnamenatel()), (a.getZnamenatel() * b.getChislitel()));

}
// ���������
MixedFraction operator- (const Fraction& a, const Fraction& b) {

	return MixedFraction((a.getChislitel() * b.getZnamenatel() - a.getZnamenatel() * b.getChislitel()), (a.getZnamenatel() * b.getZnamenatel()));
}
//// ��������
//MixedFraction operator+ (const MixedFraction& a, const MixedFraction& b) {
//
//	return MixedFraction((a.getChislitel() * b.getZnamenatel() + a.getZnamenatel() * b.getChislitel()), (a.getZnamenatel() * b.getZnamenatel()));
//}
//// ���������
//MixedFraction operator*(MixedFraction const& a, MixedFraction const& b) {
//
//	return MixedFraction((a.getChislitel() * b.getChislitel()), (a.getZnamenatel() * b.getZnamenatel()));
//
//}
////  �������
//MixedFraction operator/ (MixedFraction const& a, MixedFraction const& b) {
//
//	return MixedFraction((a.getChislitel() * b.getZnamenatel()), (a.getZnamenatel() * b.getChislitel()));
//
//}
//// ���������
//MixedFraction operator- (const MixedFraction& a, const MixedFraction& b) {
//
//	return MixedFraction((a.getChislitel() * b.getZnamenatel() - a.getZnamenatel() * b.getChislitel()), (a.getZnamenatel() * b.getZnamenatel()));
//}

//// ���������
//bool operator== (MixedFraction const& a, MixedFraction const& b) {
//	return a.isEqual(b);
//}
//// �� ���������
//bool operator!= (MixedFraction const& a, MixedFraction const& b) {
//	return !(a == b);
//}
////  ������ 
//bool operator< (MixedFraction const& a, MixedFraction const& b) {
//	return a.isLower(b);
//}
////  ������
//bool operator> (MixedFraction const& a, MixedFraction const& b) {
//	return !(a.isLower(b));
//}
//// ������ ��� �����
//bool operator<= (MixedFraction const& a, MixedFraction const& b) {
//	return !(b.isLower(a));
//}
//// ������ ��� �����
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
//void MixedFraction::reduce() {                                //  ��������� ����� 
//	int number = hcf(this->chislitel, this->znamenatel);
//	this->chislitel /= number;
//	this->znamenatel /= number;
//}
//*******************************************************************************************************************************************
int main(){
	setlocale(LC_ALL, "rus");

//*******************************************************************************************************************************************
//   �������� ������� �����
//*******************************************************************************************************************************************
	SimpleFraction frac1( 1, 2);    // �����  =   1 / 2
	SimpleFraction frac2( 3, 4);    // �����  =   2 / 4
	SimpleFraction frac3( 3,-8);    // �����  = - 3 / 8
	SimpleFraction frac4(-2, 4);    // �����  = - 2 / 4
//*******************************************************************************************************************************************
//   �������� ��������� �����
//*******************************************************************************************************************************************
	MixedFraction frac5( 1, 1, 2);  // �����  =   1  1 / 2
	MixedFraction frac6( 2, 3, 4);  // �����  =   2  3 / 4
	MixedFraction frac7( 1, 3,-8);  // �����  = - 1  3 / 8
	MixedFraction frac8(-2, 1, 4);  // �����  = - 2  1 / 4
//*******************************************************************************************************************************************
//  ����� ������ � �������.
//*******************************************************************************************************************************************
	cout << "����� 1: "; print(&frac1);
	cout << "����� 2: "; print(&frac2);
	cout << "����� 3: "; print(&frac3);
	cout << "����� 4: "; print(&frac4);
	cout << endl;
	cout << "����� 5: "; print(&frac5);
	cout << "����� 6: "; print(&frac6);
	cout << "����� 7: "; print(&frac7);
	cout << "����� 8: "; print(&frac8);
	cout << endl;
//*******************************************************************************************************************************************
// �������� ���������	
//*******************************************************************************************************************************************
	cout << "����� '1'=='1' : " << (frac1 == frac1) << endl;  
	cout << "����� '1'=='2' : " << (frac1 == frac2) << endl;
	cout << "����� '1'=='3' : " << (frac1 == frac3) << endl;
	cout << "����� '1'=='4' : " << (frac1 == frac4) << endl;
	cout << endl;
//*******************************************************************************************************************************************	
// �������������� ��������
//*******************************************************************************************************************************************
	SimpleFraction frac9 = frac1 + frac3;
	cout << "�������� '1' + '3' : "; print(&frac9);
	               frac9 = frac2 - frac3;
	cout << "��������� '2' + '3': "; print(&frac9);
	               frac9 = frac4 * frac3;
	cout << "��������� '4' + '3': "; print(&frac9);
	cout << endl;
	cout << "�������� ������� ����� : "; print(&frac9);
	frac9 = -frac9;
	cout << "������� ����� -'�����' : "; print(&frac9);
//*******************************************************************************************************************************************	
// �������������� ��������  � ������� �������
//*******************************************************************************************************************************************
	SimpleFraction frac10 = frac1 + frac5;
	cout << "�������� '1' + '3' : "; print(&frac10);
	frac9 = frac2 - frac6;
	cout << "��������� '2' + '3': "; print(&frac9);
	frac9 = frac4 * frac8;
	cout << "��������� '4' + '3': "; print(&frac9);


system("pause");
return 0;
}


