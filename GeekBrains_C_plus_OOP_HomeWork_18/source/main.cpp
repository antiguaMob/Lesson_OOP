#include"main.h"

//*******************************************************************************************************************************************
//                                            ���� 6. ������ �����-������ � �++
//
//  ������� ����������� ����������� endll ��� ������������ ������ ������, ������� ������� ��� �������� ������ � ���������� �����.
//
//*******************************************************************************************************************************************

using namespace std;

//class Output {
//public:
//	Output(){	}
//
//	~Output() {}
//	//friend ostream& operator<< (ostream& out, const Output& );
//};


//ostream& operator<< (ostream& out, const Output& ){
//	out << "\n\n";
//	return out;
//}

ostream& endll(ostream& out) {
	out << "\n\n";
	return out;

}

//*******************************************************************************************************************************************
int main(){
	setlocale(LC_ALL, "rus");
	
	cout << "*****************" << endl;
	cout << "����� ����������� "<< endll;
	cout << endll;	
	cout << "����� ������!!" << endl;

system("pause");
return 0;
}

