#include"main.h"

//*******************************************************************************************************************************************
//                                            ���� 6. ������ �����-������ � �++
//
//  ������� ���������, ������� �� ����������� � ������������ ������ �� ��� ���, ���� �� �� ������ ������ ������.����� ����� ��������� ������
//  ������� ������ ��������� ����� � ��� �������, ������ �� ������� �������� �� ������ ����, � ������ � �� ������� ����.
//
//*******************************************************************************************************************************************

using namespace std;

//*******************************************************************************************************************************************
int main(){
	setlocale(LC_ALL, "rus");
	string str;
	vector< string > str_vec;
	cout << " ������� ��������� ����� " << endl<<endl;
	while(getline(cin, str)&&(str != "")) {
		
		str_vec.push_back(str);
	}

	int length = 10;
	for (int i = 0; i < str_vec.size(); i++) {
		int count =	str_vec[i].size();
		if (length < (count * 2)) {
			length = count * 2;
		}
	}

	for (int i = 0; i < str_vec.size(); i++) {
		if (i % 2)
		{
			cout<< setw(length) <<right<< str_vec[i] << endl;
		}
		else 
		{
		    cout << setw(length) <<left<< str_vec[i];
		}		
	}
	cout << endl;
system("pause");
return 0;
}

