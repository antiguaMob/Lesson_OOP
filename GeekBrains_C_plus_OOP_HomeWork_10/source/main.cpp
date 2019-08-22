#include"main.h"

using namespace std;
//*******************************************************************************************************************************************
//                                          ���� 4. ��������� ����� ��������� � �++
//
// ����������� ������������ ����� ArrayInt.� ���� ������ ������ ���� ����������� �� ���������, ����������� � �����������, ����������,
// ����� size(�� ���������������� ��������� vector), ����� clear, ���������� ���������[], ����� resize, ����� push_back, ������� ��� 
// �������� ���������� �������� �������(������ ������� pop_back() � ��������), ����� ���� ������� ������� �������� ������ �������� � �������.
// ����� �������� ������� ��� ���������� ������� ������� � ����� ����� ���������. ���������� ������� ���������� ��������� �������.
//*******************************************************************************************************************************************


int main(){
	setlocale(LC_ALL, "rus");
		// ��������� ������ � 10 ����������
		ArrayInt array(10);

		// ��������� ������ ������� �� 1 �� 10
		for (int i = 0; i < 10; i++)
			array[i] = i + 1;

		// �������� ������ ������� �� 7 ���������
		array.resize(7);

		// ��������� ����� 15 ����� ��������� � �������� 4
		array.insertBefore(15, 4);

		// ������� ������� � �������� 5
		array.remove(5);

		// ��������� ����� 35 � 50 � ����� � � ������
		array.insertAtEnd(35);
		array.insertAtBeginning(50);

		// ������� ��� �������� �������
		for (int j = 0; j < array.getLength(); j++)
			 cout << array[j] << " ";


system("pause");
return 0;
}


