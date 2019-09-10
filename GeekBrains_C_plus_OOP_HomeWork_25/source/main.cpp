#include"main.h"

//*******************************************************************************************************************************************
//                                           Урок 8. Механизм исключительных ситуаций в С++
//
//  Написать класс «робот», моделирующий перемещения робота по сетке 10x10, у которого есть метод, означающий задание переместиться на 
//  соседнюю позицию.Эти методы должны запускать исключение OffTheField, если робот должен уйти с сетки, и IllegalCommand, если подана 
//  неверная команда(направление не находится в нужном диапазоне).Объект исключения должен содержать всю необходимую информацию — текущую позицию
//  и направление движения.Написать функцию main, пользующуюся этим классом и перехватывающую все исключения от его методов, а также выводящую 
//  подробную информацию о всех возникающих ошибках.

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
		if ((curPositionX - 1) < 0) throw 1;  // "Движение в Лево не возможно";
		curPositionX -= 1;
		cout << "Робот переместился на одну позицию влево" << endl;
	}
	void Right () {
		if ((curPositionX + 1) > MaxFieldX) throw 2;// "Движение в Право не возможно";
		curPositionX += 1;
		cout << "Робот переместился на одну позицию вправо" << endl;
	}
	void Up () {
		if ((curPositionY + 1) > MaxFieldY) throw 3;// "Движение в Вперед не возможно";
		curPositionY += 1;
		cout << "Робот переместился на одну позицию вперед" << endl;
	}
	void Down() {
		if ((curPositionY - 1) < 0) throw 4;// "Движение в Назад не возможно";
		curPositionY -= 1;
		cout << "Робот переместился на одну позицию назад" << endl;
	}
	void printPosition() {
		cout << "Мои текущии координаты по  X " << curPositionX << " и по оси Y " << curPositionY << endl;
	
	}
	~Robot(){}
};


//*******************************************************************************************************************************************
int main() {
	setlocale(LC_ALL, "rus");
	Robot arny(2, 4); // Задание начальных координат на поле по умолчанию 10х10
	cout << "Вас приветствует робот Арни" << endl;
	arny.printPosition();
	cout << "Для перемещения по полю  используйте  команды :"<<endl;
	cout << "Влево   - кнопка 'А'" << endl;
	cout << "Вправо  - кнопка 'D'" << endl;
	cout << "Вперед  - кнопка 'W'" << endl;
	cout << "Назад   - кнопка 'S'" << endl;
	cout << "Для отображения моей позиции нажмите кнопку 'P" << endl;
	cout << "Для останорвки робота нажмите кнопку 'X" << endl;
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
				cout<<"Движение в Лево не возможно"<<endl;
				arny.printPosition();
				break;
			case 2:
				cout<< "Движение в Право не возможно"<<endl;
				arny.printPosition();
				break;
			case 3:
				cout << "Движение в Вперед не возможно" << endl;
				arny.printPosition();
				break;
			case 4:
				cout << "Движение в Назад не возможно" << endl;
				arny.printPosition();
				break;
			case 5:
				cout << "Не правильная команда " << endl;
				break;
		    }	
		
		}

	}
	system("pause");
	return 0;
}
