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
	void clear() {                                                       //  ������� ������

		delete[] m_data;
		m_data = nullptr;
		m_length = 0;
	}
	//********************************************************************************************************************
	int size() { return m_length; }                                        //  ���������� ������ �������

	int& operator[](int index) {                                           //  ����������  ������ [ ]
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}                                        

 	void deleteElement(int index) {                                        // ������� ������ ������ ������� 
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
	void resize(int newLength) {                                            // ������� resize �������� ������ �������.
		if (newLength == m_length)                                          // ������ ������
			return;

		if (newLength <= 0)
		{ 
			clear();                                                        // �������� ������  ����� ���� ,��� ������������ ��������
			return;
		}

		int* data = new int[newLength];

		if (m_length > 0)
		{
			int elementsToCopy = (newLength > m_length) ? m_length : newLength;
			for (int index = 0; index < elementsToCopy; ++index)
				data[index] = m_data[index];
		}

		delete[] m_data;                                                     // ������� ������ ������
		m_data = data;
		m_length = newLength;
	}
	//********************************************************************************************************************
		void push_back (int value) { 
			
			int* data = new int[ m_length + (unsigned __int64)1];	           // ������ ����� ������ �� ���� ������� ������ ������� �������
			for (int i = 0; i < m_length; ++i) {                               // �������� ��� ��������
				data[i] = m_data[i];
			}
			data[m_length] = value;                                            // ��������� ������� � ����� �������
			m_length += 1;
			delete[] m_data;                                                   // ������� ������ ������ � 
			m_data = data;                                                     // ���������� ������ ���� ����� ������
			

		}
	//********************************************************************************************************************
	void pop_back() {

		int index = m_length - 1;
		int* data = new int[index];                                           // C����� ����� ������ �� ���� ������� ������ ������ ������� �������

		for (int i = 0; i < index; ++i) {                                     // �������� ��� ��������
			data[i] = m_data[i];
		}
		delete[] m_data;                                                      // ������� ������ ������ � ���������� ������ ���� ����� ������
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
			int* data = new int [length];                                       // C����� ����� ������ �� ���� ������� ������ ������ ������� �������
			int before = 0;
			for (; before < index; ++before) {                                  // �������� ��� �������� �� �� index
				data[before] = m_data[before];
			}
			int after = before;
			before++;
			//assert(after < length);
			//assert(before < m_length);
			for (; before < m_length; ++before,++after) {                      // �������� ��� �������� ����� ���������� ��������
				data[after] = m_data[before];

				//********************************************************************************************************************
				//data[i] = m_data[i];  � ���� ����� ���� ��������� C6386 
				//������������ ������ ��� ������ � "data":  ��������� ��� ������ ����� ����� "lehgth*4" ����, 
				//������ �������� ����� ������ "8" ����.
				//********************************************************************************************************************
				// !!! ���� ����������� ���� ���������� ��� ���������� � ������ ������ ���������.!!!
				//********************************************************************************************************************
			}
			
			m_length -=1;
			delete[] m_data;                                                    // ������� ������ ������ 
			m_data = data;                                                      // ���������� ������ ���� ����� ������
			
		}

	//********************************************************************************************************************
		void insertBefore (int index, ArrayInt const &other ) {

			int lehgth = this->m_length + other.m_length;
			int* data;
			data = new int[lehgth];                                                // ������ ����� ������ (unsigned __int64)                                  
			assert(index < lehgth);
				int before = 0;
				int  j = 0;
			assert(other.m_length < lehgth);
				for (; before < index; ++before, j++) 	                           // �������� ��� �������� �� index
			  		data[before] = m_data[before];

				for (int i = 0; i < other.m_length; ++i, ++before)
					data[before] = other.m_data[i];

				for (; before < lehgth; ++before, j++)                              // �������� ��� �������� ����� ������������ �������
					data[before] = m_data[j];                                       // ��������� ��� ����� ������  � ��� ������
                     
				delete[] m_data;                                                    // ������� ������ ������ 
				m_data = data;                                                      // ���������� ������ ���� ����� ������
				m_length = lehgth;
			
		}
	//********************************************************************************************************************
	void qSort() {

		int temp;                                                                 // ���������� ��� �������� ���-���� �������� � ������� �������
		for (int i = 0; i < m_length; i++)
		{ 
			temp = m_data[i];                                                     // �������������� ����. ����������
			for (int j = i; j < m_length; j++)
				if (temp > m_data[j])                                             // ������� ����������� �������
				{
					temp = m_data[j];                                             // ������ ������������
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
		// ��������� ������ � 10 ����������
		ArrayInt array(20);
		ArrayInt arrayInsert(15);

		// ��������� ������ ������� �� 1 �� 10
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


