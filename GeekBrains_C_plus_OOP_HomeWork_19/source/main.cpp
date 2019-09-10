#include"main.h"

//*******************************************************************************************************************************************
//                                            ���� 7. ��������� �����������. ��������� ���� Blackjack � �++
//
//  �������� ����� Date � ������ ����, �����, ��� � �������� ������� � ���� �����.����������� �������� ������ ��� ������� ������.
//
//  �������� ��� "�����" ��������� today � date.������� ��������� �������� ����������� ����.
//  ��� ���� �������� �� ����������� ������  ������� � ����� ������ Date, � ����� �������� �� ����� ������ ����� �������
//  � ������� �������������� ��������� ������.
//  ����� �����������  ������, ������� ������� ��������� today � ��������� date.
//  ���������, �������� �� �������� ��������� today � date � ��������  ��������������� ���������� �� ���� � �������.
//
//*******************************************************************************************************************************************

using namespace std;

class Date {
protected :
	int day;
	int month;
	int year;

public:
	Date(int d,int m,int y) : day(d),month(m),year(y) {}
	Date() {
	    day = 3;
		month = 9;
		year = 2019;
	}

	int getDay () const;
	int getMonth () const;
	int getYear () const;
	
	void setDay ( int d ) { day = d; }
	void setMonth ( int m ) { month = m; }
	void setYear ( int y ) { year = y; } 

	friend ostream& operator << (ostream& out, const  Date& date);
	~Date(){}
};

//template<class T>
//class Auto_ptr{
//private:
//	T* m_p;
//public:
//	Auto_ptr(T* p) : m_p(p) {}
//	~Auto_ptr() { delete m_p;}
//	Auto_ptr(const Auto_ptr&) = delete;
//	Auto_ptr(Auto_ptr&& x):m_p(x.m_p) {
//		x.m_p = nullptr;
//    }
//	Auto_ptr& operator=(const Auto_ptr&) = delete;
//	Auto_ptr& operator=(Auto_ptr&&) {
//		if (&x == this) return *this;
//		delete m_p;
//		m_p = x.m_p;
//		x.m_p = nullptr;
//		return *this;
//	}
//	T& operator* () const { return *m_p; }
//	T* operator->() const { return  m_p; }
//};

ostream&   operator << (ostream& out, const  Date& date) {
	out << "���� : " << date.day << "." << date.month << "." << date.year << "\n";
	return out;
}


int Date::getDay() const {
	return day;
}

int Date::getMonth() const {
	return month;
}

int Date::getYear() const {
	return year;
}

//*******************************************************************************************************************************************
int main(){
	setlocale(LC_ALL, "rus");
	//Auto_ptr<Date> today(new Date);
	//Auto_ptr<Date> date(move (today));
	unique_ptr<Date> today = make_unique<Date>(); // (new Date);
	unique_ptr<Date> date;
	cout << *today << endl;

	cout <<"����  -\t" << today->getDay() << endl;
	cout <<"����� -\t" << today->getMonth() << endl;
	cout <<"���   -\t" << today->getYear() << endl;
	cout <<endl<< endl;
	if (today) cout << "��������� 'today' �� ����" << endl;
	else cout << "��������� 'today' ����" << endl;
	if (date) cout << "��������� 'date' �� ����" << endl;
	else cout << "��������� 'date' ����" << endl;

	date = move( today );
	cout << endl;
	if (today) cout << "��������� 'today' �� ����" << endl;
	else cout << "��������� 'today' ����" << endl;
	if (date) cout << "��������� 'date' �� ����" << endl;
	else cout << "��������� 'date' ����" << endl;
	//cout << *today << endl;
	cout << endl;
	cout << *date << endl;

system("pause");
return 0;
}


