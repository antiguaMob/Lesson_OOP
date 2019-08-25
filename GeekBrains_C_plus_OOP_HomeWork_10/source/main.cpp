#include"main.h"

using namespace std;
//*******************************************************************************************************************************************
//                                          Урок 4. Отношения между объектами в С++
//
// Реализовать контейнерный класс ArrayInt.В этом классе должны быть конструктор по умолчанию, конструктор с параметрами, деструктор,
// метод size(по функциональности наподобие vector), метод clear, перегрузка оператора[], метод resize, метод push_back, функция для 
// удаления последнего элемента массива(аналог функции pop_back() в векторах), перед этим написав функцию удаления любого элемента в массиве.
// Также напишите функцию для добавления другого массива в любое место исходного. Реализуйте функцию сортировки элементов массива.
//*******************************************************************************************************************************************
class ArrayInt
{
private:
	int m_length;
	int* m_data;

public:
	ArrayInt() : m_length(0), m_data(nullptr) {

	}

	ArrayInt(int length) : m_length(length) {

		if (length > 0)
			m_data = new int[length];
		else
			m_data = nullptr;
	}

	~ArrayInt() { delete[] m_data; }
	//********************************************************************************************************************
	void clear() {                                                       //  Очищает данные

		delete[] m_data;
		m_data = nullptr;
		m_length = 0;
	}
	//********************************************************************************************************************
	int size() { return m_length; }                                        //  Возвращает размер массива

	int& operator[](int index) {                                           //  Перегрузка  скобок [ ]
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}                                        

 	void deleteElement(int index) {                                        // Удаляем только нужный элемент 
		assert(index >= 0 && index < m_length);
		m_data[index] = NULL; 
	}              

//********************************************************************************************************************
	void print() {
		for (int i = 0; i < m_length; i++)
			cout << m_data[i] << " ";
		    cout << endl;
	}
	//********************************************************************************************************************
	void resize(int newLength) {                                            // Функция resize изменяет размер массива.
		if (newLength == m_length)                                          // Нужный размер
			return;

		if (newLength <= 0)
		{ 
			clear();                                                        // Заданный массив  равен нулю ,или неправильное значение
			return;
		}

		int* data = new int[newLength];

		if (m_length > 0)
		{
			int elementsToCopy = (newLength > m_length) ? m_length : newLength;
			for (int index = 0; index < elementsToCopy; ++index)
				data[index] = m_data[index];
		}

		delete[] m_data;                                                     // Удаляем старый массив
		m_data = data;
		m_length = newLength;
	}
	//********************************************************************************************************************
		void push_back (int value) { 
			
			int* data = new int[ m_length + (unsigned __int64)1];	           // Создаём новый массив на один элемент больше старого массива
			for (int i = 0; i < m_length; ++i) {                               // Копируем все элементы
				data[i] = m_data[i];
			}
			data[m_length] = value;                                            // Вставляем элемент в конец массива
			m_length += 1;
			delete[] m_data;                                                   // Удаляем старый массив и 
			m_data = data;                                                     // Используем вместо него новый массив
			

		}
	//********************************************************************************************************************
	void pop_back() {

		int index = m_length - 1;
		int* data = new int[index];                                           // Cоздаём новый массив на один элемент меньше нашего старого массива

		for (int i = 0; i < index; ++i) {                                     // Копируем все элементы
			data[i] = m_data[i];
		}
		delete[] m_data;                                                      // Удаляем старый массив и используем вместо него новый массив
		m_length = index;        
		m_data = data;	
	}
	//********************************************************************************************************************
		void remove(int index) {
			assert(index < m_length);
			if (m_length == 1)
			{
				clear();
				return;
			}
			int length = m_length - 1;	
			assert(index < length);
			int* data = new int [length];                                       // Cоздаём новый массив на один элемент меньше нашего старого массива
			int before = 0;
			for (; before < index; ++before) {                                  // Копируем все элементы аж до index
				data[before] = m_data[before];
			}
			int after = before;
			before++;
			//assert(after < length);
			//assert(before < m_length);
			for (; before < m_length; ++before,++after) {                      // Копируем все значения после удаляемого элемента
				data[after] = m_data[before];

				//********************************************************************************************************************
				//data[i] = m_data[i];  в этой стоке дает сообщение C6386 
				//Переполнение буфера при записи в "data":  доступный для записи объем равен "lehgth*4" байт, 
				//однако записать можно только "8" байт.
				//********************************************************************************************************************
				// !!! Буду признателен если подскажете как необходимо в данном случае поступить.!!!
				//********************************************************************************************************************
			}
			
			m_length -=1;
			delete[] m_data;                                                    // Удаляем старый массив 
			m_data = data;                                                      // Используем вместо него новый массив
			
		}

	//********************************************************************************************************************
		void insertBefore (int index, ArrayInt const &other ) {

			int lehgth = this->m_length + other.m_length;
			int* data;
			data = new int[lehgth];                                                // Создаём новый массив (unsigned __int64)                                  
			assert(index < lehgth);
				int before = 0;
				int  j = 0;
			assert(other.m_length < lehgth);
				for (; before < index; ++before, j++) 	                           // Копируем все элементы до index
			  		data[before] = m_data[before];

				for (int i = 0; i < other.m_length; ++i, ++before)
					data[before] = other.m_data[i];

				for (; before < lehgth; ++before, j++)                              // Копируем все значения после вставляемого массива
					data[before] = m_data[j];                                       // Вставляем наш новый массив  в наш массив
                     
				delete[] m_data;                                                    // Удаляем старый массив 
				m_data = data;                                                      // Используем вместо него новый массив
				m_length = lehgth;
			
		}
	//********************************************************************************************************************
	void qSort() {

		int temp;                                                                 // переменные для хранения мин-ного значения и индекса массива
		for (int i = 0; i < m_length; i++)
		{ 
			temp = m_data[i];                                                     // инициализируем врем. переменную
			for (int j = i; j < m_length; j++)
				if (temp > m_data[j])                                             // находим минимальный элемент
				{
					temp = m_data[j];                                             // делаем перестановку
					m_data[j] = m_data[i];
					m_data[i] = temp;
				}
		}
	}

	int max() {
		qSort();
		return m_data[m_length - 1];
	}
	int min() {
		qSort();
		return m_data[0];
	}


};

int main(){
	setlocale(LC_ALL, "rus");
	srand(static_cast<int>(time(NULL)));
		// Объявляем массив с 10 элементами
		ArrayInt array(20);
		ArrayInt arrayInsert(15);

		// Заполняем массив числами от 1 до 10
		for (int i = 0; i < 20; i++)
			array[i] = (rand() % 100);
		for (int i = 0; i < 15; i++)
		    arrayInsert[i] = (rand() % 100);

		array.print();	
		array.resize(15);   
		array.print();
		cout << endl;

		array.remove(4);
		array.print();
		cout << endl;

		array.pop_back();
		array.print();
		cout << endl;

		array.push_back(45);
		array.push_back(33);
		array.print();
		cout << endl;

		array.qSort();
		array.print();
		cout << endl;

		array.deleteElement(5);
		array.deleteElement(2);
		array.print();
		cout << endl;

		arrayInsert.print();
		array.insertBefore(5, arrayInsert);
		array.print();
		cout << endl;
	
		array.qSort();
		array.print();
		cout << endl;
		
system("pause");
return 0;
}


