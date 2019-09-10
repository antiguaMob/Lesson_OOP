#include"main.h"

//*******************************************************************************************************************************************
//                                            Урок 7. Поддержка модульности. Написание игры Blackjack в С++
//
//  Создайте класс Date с полями день, месяц, год и методами доступа к этим полям.Перегрузите оператор вывода для данного класса.
//
//  Создайте два "умных" указателя today и date.Первому присвойте значение сегодняшней даты.
//  Для него вызовите по отдельности методы  доступа к полям класса Date, а также выведите на экран данные всего объекта
//  с помощью перегруженного оператора вывода.
//  Затем переместите  ресурс, которым владеет укзаатель today в указатель date.
//  Проверьте, являются ли нулевыми указатели today и date и выведите  соответствующую информацию об этом в консоль.
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
	out << "Дата : " << date.day << "." << date.month << "." << date.year << "\n";
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

	cout <<"День  -\t" << today->getDay() << endl;
	cout <<"Месяц -\t" << today->getMonth() << endl;
	cout <<"Год   -\t" << today->getYear() << endl;
	cout <<endl<< endl;
	if (today) cout << "Указатель 'today' не пуст" << endl;
	else cout << "Указатель 'today' пуст" << endl;
	if (date) cout << "Указатель 'date' не пуст" << endl;
	else cout << "Указатель 'date' пуст" << endl;

	date = move( today );
	cout << endl;
	if (today) cout << "Указатель 'today' не пуст" << endl;
	else cout << "Указатель 'today' пуст" << endl;
	if (date) cout << "Указатель 'date' не пуст" << endl;
	else cout << "Указатель 'date' пуст" << endl;
	//cout << *today << endl;
	cout << endl;
	cout << *date << endl;

system("pause");
return 0;
}


