#include"main.h"

//*******************************************************************************************************************************************
//                                ���� 4. ��������� ����� ��������� � �++
//
//    ��� ������ �����(����� �������� � ����������), ��������� ��������, ������� ����� ��� ���������.
//    ����������� ������������ ����������� ������� ��������.
//*******************************************************************************************************************************************

using namespace std;

int main(){

	setlocale(LC_ALL, "rus");
	vector <int> vec_int;
	int N;
	cout << "������� ����� �� ������ ������ ? "; cin >> N;
	while (N > 0){
		int digit;
		N--;
		cout << "������� ����� ";
		cin >> digit;
		vec_int.push_back(digit);
	} 

	set<int> s(vec_int.begin(), vec_int.end());                                // ���������, ������� ������������� ��������� ����������� ��������
	cout << endl;
	cout << "����� ��������� ����� = " << s.size() << endl << "��� ��� : ";

	copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	system("pause");
	return 0;
}