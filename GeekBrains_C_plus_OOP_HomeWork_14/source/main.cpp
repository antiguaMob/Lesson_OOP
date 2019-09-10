#include"main.h"

//*******************************************************************************************************************************************
//                                            ���� 5. ���������� ������������� ������� � ������� � �++
//
// �������� ������ ������ StringValuePair, � ������� ������ �������� ������ ���� string, � ������ � ������ ����.���� ������ ������ ������ ����������� 
// �������� ������������������ ����� Pair, � ������� ������ �������� � string, � ������ � ������ ���� ������.
//
//   ��������� ��� :
//  int main(){
//
//	StringValuePair<int> svp("Amazing", 7);
//	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
//	return 0;
//  }
//
//� ������ ����������� ��������� ��������� :
//Pair: Amazing 7
//	��������� : ��� ������ ������������ ������ Pair �� ������������ ������ StringValuePair �� �������� �������, ��� ��������� ��������� � ������ Pair.

//*******************************************************************************************************************************************

using namespace std;

template<class T, class D>
class Pair {
public:
	Pair(T a, D b) : num1(a), num2(b) {

	}
	Pair(T a) : num1(a) {

	}
	T first()  const { return num1; }
	D second() const { return num2; }

	~Pair() {}

protected:
	T num1;
	D num2;
};

template<class T>
class StringValuePair : public Pair<string ,T> {
public:
	StringValuePair(string S, T a) : Pair(S , a) {
		
	}
	~StringValuePair() {}
private:
	
};

//*******************************************************************************************************************************************
int main(){
	setlocale(LC_ALL, "rus");

	StringValuePair<int> svp("Amazing", 7);

	cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
		
	cout << endl;


system("pause");
return 0;
}

