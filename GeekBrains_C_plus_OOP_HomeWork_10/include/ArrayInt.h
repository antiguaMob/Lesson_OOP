#ifndef ARRAYINT_H
#define ARRAYINT_H

#include <cassert> // ��� assert()

class ArrayInt
{
private:
	int m_length;
	int* m_data;

public:
	ArrayInt() :
		m_length(0), m_data(nullptr)
	{
	}

	ArrayInt(int length) :
		m_length(length)
	{
		assert(length >= 0);
		if (length > 0)
			m_data = new int[length];
		else
			m_data = nullptr;
	}

	~ArrayInt()
	{
		delete[] m_data;
	}

	void erase()
	{
		delete[] m_data;
		// ����� ����� ������� m_data �������� nullptr, ����� �� ������ �� ���� �������� ���������
		m_data = nullptr;
		m_length = 0;
	}

	int& operator[](int index)
	{
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}

	// ������� reallocate �������� ������ �������. ��� ������������ �������� ������ ������� ����� ����������. ������� �������
	void reallocate(int newLength)
	{
		// ������� ��� ������������ �������� ������ �������
		erase();

		// ���� ��� ������ ������ ���� ������, �� ��������� ������� �����
		if (newLength <= 0)
			return;

		// ����� �������� ����� ��������
		m_data = new int[newLength];
		m_length = newLength;
	}

	// ������� resize �������� ������ �������. ��� ������������ �������� �����������. ������� ���������
	void resize(int newLength)
	{
		// ���� ������ ������ �����, �� ��������� return
		if (newLength == m_length)
			return;

		// ���� ����� ������� ������ ������, �� ������ ��� � ����� ��������� return
		if (newLength <= 0)
		{
			erase();
			return;
		}

		// ������ �� ����� ������������, ��� newLength �������, �� ������� ����, �� ������ ��������. ����������� ��������� ��������:
		// 1. �������� ����� ������.
		// 2. �������� �������� �� ������������� ������� � ���, ������ ��� ����������, ������.
		// 3. ���������� ������ ������ � ��������� m_data ��������� �� ����� ������.

		// �������� ����� ������
		int* data = new int[newLength];

		// ����� ��� ����� ����������� � ����������� ���������� ��������� � ����� ������
		// �� ����� ����������� ������� ���������, ������� �� ���� � ������� �� ��������
		if (m_length > 0)
		{
			int elementsToCopy = (newLength > m_length) ? m_length : newLength;

			// ��������� �������� ��������
			for (int index = 0; index < elementsToCopy; ++index)
				data[index] = m_data[index];
		}

		// ������� ������ ������, ��� ��� �� ��� ��� �� �����
		delete[] m_data;

		// � ���������� ������ ������� ������� �����! �������� ��������, m_data ���������
		// �� ��� �� �����, �� ������� ��������� ��� ����� ����������� ���������� ������.
		// ��������� ������ ���� ����������� ����������, �� ��� �� ����� ����������, ����� ������ �� ������� ���������
		m_data = data;
		m_length = newLength;
	}

	void insertBefore(int value, int index)
	{
		// �������� ������������ ������������� �������
		assert(index >= 0 && index <= m_length);

		// ������ ����� ������ �� ���� ������� ������ ������� �������
		int* data = new int[m_length + 1];

		// �������� ��� �������� �� �� index-�
		for (int before = 0; before < index; ++before)
			data[before] = m_data[before];

		// ��������� ��� ����� ������� � ��� ����� ������
		data[index] = value;

		// �������� ��� �������� ����� ������������ ��������
		for (int after = index; after < m_length; ++after)
			data[after + 1] = m_data[after];

		// ������� ������ ������ � ���������� ������ ���� ����� ������
		delete[] m_data;
		m_data = data;
		++m_length;
	}

	void remove(int index)
	{
		// �������� �� ������������ ������������� �������
		assert(index >= 0 && index < m_length);

		// ���� ��� ��������� ������� �������, �� ������ ������ ������ � ��������� return
		if (m_length == 1)
		{
			erase();
			return;
		}

		// C����� ����� ������ �� ���� ������� ������ ������ ������� �������
		int* data = new int[m_length - 1];

		// �������� ��� �������� �� �� index-�
		for (int before = 0; before < index; ++before)
			data[before] = m_data[before];

		// �������� ��� �������� ����� ���������� ��������
		for (int after = index + 1; after < m_length; ++after)
			data[after - 1] = m_data[after];

		// ������� ������ ������ � ���������� ������ ���� ����� ������
		delete[] m_data;
		m_data = data;
		--m_length;
	}

	// ��������� �������������� ������� ������ ��� ��������
	void insertAtBeginning(int value) { insertBefore(value, 0); }
	void insertAtEnd(int value) { insertBefore(value, m_length); }

	int getLength() { return m_length; }
};

#endif