#pragma once
#include <cassert>

template<class T>
class UnorderedArray
{
public:
	UnorderedArray(int size, int growBy = 1) :
		m_array(Null), m_maxSize(0), m_growSize(0), m_numElements(0)
	{
		if (size) {
			m_maxSize = size;
			m_array = new T[m_maxSize];
			memset(m_array, 0, sizeof(T) * m_maxSize);

			m_growSize = ((growBy > 0) ? growBy : 0);
		}
	}
	~UnorderedArray() {
		if(m_array != NULL) {
			delete[] m_array;
			m_array = NULL;
		}
	}
	void push(T val) {
		assert(m_array != NULL);

		if (m_numElements >= m_maxSize){
			Expand();
		}

		m_array[m_numElements] = val;
		m_numElements++;

	}
	void pop(){
		if (m_numElements > 0) {
			m_numElements--;
		}
	}
	void remove(int index)
	{
		assert(m_array != NULL);
		
		if(index >= m_numElements){
			return;
		}
		
		for (int i = index; i < m_numElements; i++)
		{
			if (i + 1 < m_numElements) {
				m_array[i] = m_array[i + 1];
			}
		}
		m_numElements--;
	}
	int search(T val){
		assert(m_array != array);
		for (int i = 0; i < m_numElements; i++)
		{
			if (m_array[i] == val ) {
				return i; 
			}
		}
		return -1;
	}

	T& operator[](int index)
	{
		assert(m_array != NULL && index < m_numElements);
		return m_array[index];
	}

	void clear() {
		m_numElements = 0;
	}

	int getSize(){
		return m_numElements;
	}

	int getMaxSize(){
		return m_maxSize;
	}

	int getGrowSize() {
		return m_growSize;
	}

	void setGrowSize(int val){
		assert(val >= 0);
		m_growSize = val;
	}

private:
	bool Expand(){
		if (m_growSize <= 0) {
			return false;
		}

		T* temp = new T[m_maxSize + m_growSize];
		assert(temp != NULL);

		memcpy(temp, m_array, sizeof(T) * m_maxSize);

		delete[] m_array;

		m_array = temp;
		temp = NULL;

		m_maxSize += m_growSize;

		return true;
	}



private:
	T* m_array;
	int m_maxSize, m_growSize, m_numElements;
};



