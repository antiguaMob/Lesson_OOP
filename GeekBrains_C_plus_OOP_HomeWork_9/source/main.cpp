#include"main.h"

//*******************************************************************************************************************************************
// ������� ����������� ����� Fraction(�����).�� ���� ��������� ��� ������ : SimpleFraction(������������ �����) � MixedFraction(��������� �����).
// ������������ ����� ����� ������ ��������� � �����������(��������, 3 / 7 ��� 9 / 2), � ��������� � ��� � ����� �����(��������, 312).�������������,
// ����� ����������� �� ��� ����� 0. ����������� �������������� �������� ���������(+, -, *, / ) ��� ���������� �������� � �������, � ����� ������� 
// ��������(-).����������� ���������� ��������� ��������� ���� ������(== , != , <, >, <= , >= ).��������� ��������� < � >= , > � <= � ��� ���������� 
// �����������������, ���������� ����������� ���� ����� ������.
//*******************************************************************************************************************************************

using namespace std;

//*******************************************************************************************************************************************
class Fraction {
protected:
	int celoe;        // �����
	int chislitel;    // ���������
	int znamenatel;   // �����������
	bool sign;        // ����( ���� ����  �� ����������  �������������  - ����� �������������,
	                  // ���� ��� ��������� ������������� ,�� ����� �������������).
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
//   ����� SimpleFraction
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
//   ����� MixedFraction
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
//   �������� ������� �����
//*******************************************************************************************************************************************
	SimpleFraction frac1( 1, 2);    // �����  =   1 / 2
	SimpleFraction frac2( 2, 4);    // �����  =   2 / 4
	SimpleFraction frac3( 3,-8);    // �����  = - 3 / 8
	SimpleFraction frac4(-2, 4);    // �����  = - 2 / 4
	//SimpleFraction frac9();
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
	cout << "����� 5: "; print(&frac5);
	cout << "����� 6: "; print(&frac6);
	cout << "����� 7: "; print(&frac7);
	cout << "����� 8: "; print(&frac8);
	//cout << "����� 9: "; print(&frac9);
	cout << endl;
//*******************************************************************************************************************************************
// �������� ���������	
//*******************************************************************************************************************************************
	//cout << "1==1: " << (frac1 == frac1) << endl;  
	//cout << "1==2: " << (frac1 == frac2) << endl;
	//cout << "1==3: " << (frac1 == frac3) << endl;
	//cout << "1==4: " << (frac1 == frac4) << endl;

//*******************************************************************************************************************************************	


system("pause");
return 0;
}


