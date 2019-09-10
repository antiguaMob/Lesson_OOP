#include"main.h"

//*******************************************************************************************************************************************
//                                          Урок 7. Поддержка модульности. Написание игры Blackjack в С++
//
//  По условию предыдущей задачи создайте два умных указателя date1 и date2. 
//  ** Создайте функцию, которая принимает в качестве параметра два умных указателя типа Date и сравнивает их между собой(сравнение происходит по датам).
//  Функция должна вернуть более позднюю дату.
//  ** Создайте функцию, которая обменивает ресурсами(датами) два умных указателя, переданных в функцию в качестве параметров.
//  Примечание: обратите внимание, что первая функция не должна уничтожать объекты, переданные ей в качестве параметров.
//
//*******************************************************************************************************************************************

using namespace std;

class Date {
protected:
	int day;
	int month;
	int year;

public:
	Date(int d, int m, int y) : day(d), month(m), year(y) {}
	Date() {
		day = 3;
		month = 9;
		year = 2019;
	}

	int getDay() const;
	int getMonth() const;
	int getYear() const;

	void setDay(int d) { day = d; }
	void setMonth(int m) { month = m; }
	void setYear(int y) { year = y; }

	friend ostream& operator << (ostream& out, const  Date& date);
	friend void swapData(Date& first, Date& second);
	~Date() {}

	Date* swapData(Date date1, Date date2) {

	}
	
};

void swapData(Date& first, Date& second) {
	using std::swap;
	swap(first.day, second.day);
	swap(first.month, second.month);
	swap(first.year, second.year);
}

Date& checkData( Date& date1, Date& date2) {
	if (date1.getYear() > date2.getYear()) return date1;
	else if (date1.getMonth() > date2.getMonth()) return date1;
	else if (date1.getDay() > date2.getDay()) return date1;
	else return date2;
}

ostream& operator << (ostream& out, const  Date& date) {
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
int main() {
	setlocale(LC_ALL, "rus");

	unique_ptr<Date> date1 = make_unique<Date>(3,9,2019); 
	unique_ptr<Date> date2 = make_unique<Date>(1,6,2018);
	cout << *date1 << endl;
	cout << *date2 << endl;
	cout << endl;
	cout <<"Эта более поздняя "<< checkData(*date1, *date2)<<endl;

	//data1.swap(data2);   // unigue_ptr
	swapData(*date1,*date2);
	
	cout << *date1 << endl;
	cout << *date2 << endl;

	system("pause");
	return 0;
}
