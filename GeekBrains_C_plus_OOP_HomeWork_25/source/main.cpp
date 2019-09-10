#include"main.h"

//*******************************************************************************************************************************************
//                                           ���� 8. �������� �������������� �������� � �++
//
//  �������� ����� ������, ������������ ����������� ������ �� ����� 10x10, � �������� ���� �����, ���������� ������� ������������� �� 
//  �������� �������.��� ������ ������ ��������� ���������� OffTheField, ���� ����� ������ ���� � �����, � IllegalCommand, ���� ������ 
//  �������� �������(����������� �� ��������� � ������ ���������).������ ���������� ������ ��������� ��� ����������� ���������� � ������� �������
//  � ����������� ��������.�������� ������� main, ������������ ���� ������� � ��������������� ��� ���������� �� ��� �������, � ����� ��������� 
//  ��������� ���������� � ���� ����������� �������.

//*******************************************************************************************************************************************

using namespace std;


class Robot {
private:
	int curPositionX;
    int curPositionY;
	int MaxFieldX;
	int MaxFieldY;
public:
	Robot(int x, int y) :curPositionX(x), curPositionY(y) {
		MaxFieldX = 10;
		MaxFieldY = 10;
	}
	Robot(int x, int y,int fieldX,int fieldY) :curPositionX(x), curPositionY(y), MaxFieldX(fieldY), MaxFieldY(fieldY){
		MaxFieldX = 10;
		MaxFieldY = 10;
	}
	void SetField(int fieldX, int fieldY) {
		MaxFieldX = fieldX;
		MaxFieldY = fieldY;
	}
	void SetPosition(int x, int y) {
		curPositionX= x;
	    curPositionY= y;
	}
	int getPositionX() const {
		return curPositionX;
	}
	int getPositionY() const {
		return curPositionY;
	}

	void Left () {
		if ((curPositionX - 1) < 0) throw 1;  // "�������� � ���� �� ��������";
		curPositionX -= 1;
		cout << "����� ������������ �� ���� ������� �����" << endl;
	}
	void Right () {
		if ((curPositionX + 1) > MaxFieldX) throw 2;// "�������� � ����� �� ��������";
		curPositionX += 1;
		cout << "����� ������������ �� ���� ������� ������" << endl;
	}
	void Up () {
		if ((curPositionY + 1) > MaxFieldY) throw 3;// "�������� � ������ �� ��������";
		curPositionY += 1;
		cout << "����� ������������ �� ���� ������� ������" << endl;
	}
	void Down() {
		if ((curPositionY - 1) < 0) throw 4;// "�������� � ����� �� ��������";
		curPositionY -= 1;
		cout << "����� ������������ �� ���� ������� �����" << endl;
	}
	void printPosition() {
		cout << "��� ������� ���������� ��  X " << curPositionX << " � �� ��� Y " << curPositionY << endl;
	
	}
	~Robot(){}
};


//*******************************************************************************************************************************************
int main() {
	setlocale(LC_ALL, "rus");
	Robot arny(2, 4); // ������� ��������� ��������� �� ���� �� ��������� 10�10
	cout << "��� ������������ ����� ����" << endl;
	arny.printPosition();
	cout << "��� ����������� �� ����  �����������  ������� :"<<endl;
	cout << "�����   - ������ '�'" << endl;
	cout << "������  - ������ 'D'" << endl;
	cout << "������  - ������ 'W'" << endl;
	cout << "�����   - ������ 'S'" << endl;
	cout << "��� ����������� ���� ������� ������� ������ 'P" << endl;
	cout << "��� ���������� ������ ������� ������ 'X" << endl;
	cout << "******************************************************" << endl;
	while (true) {
		char ent;	
		cin >> ent;
		try {
			if (ent == 'A'|| ent == 'a')
			{
				arny.Left();
			}
			else if (ent == 'D' || ent == 'd') {
				arny.Right();
			}
			else if (ent == 'W' || ent == 'w') {
				arny.Up();
			}
			else if (ent == 'S' || ent == 's') {
				arny.Down();
			}
			else if (ent == 'X' || ent == 'x') {
				break;
			}
			else if (ent == 'P' || ent == 'p') {
				arny.printPosition();
			}
			else  throw 5;
        }
		catch (int a) {
			switch (a) {
			case 1:
				cout<<"�������� � ���� �� ��������"<<endl;
				arny.printPosition();
				break;
			case 2:
				cout<< "�������� � ����� �� ��������"<<endl;
				arny.printPosition();
				break;
			case 3:
				cout << "�������� � ������ �� ��������" << endl;
				arny.printPosition();
				break;
			case 4:
				cout << "�������� � ����� �� ��������" << endl;
				arny.printPosition();
				break;
			case 5:
				cout << "�� ���������� ������� " << endl;
				break;
		    }	
		
		}

	}
	system("pause");
	return 0;
}
