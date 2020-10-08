#pragma once
#include <cassert>

template<class T>
class OrderedArray
{
public:
	OrderedArray(int size, int growBy = 1) : 
		m_array(Null), m_maxSize(0), m_growSize(0), m_numElements(0) 
	{
		if (size) {
			m_maxSize = size;
			m_array = new T[m_maxSize];
			memset(m_array, 0, sizeof(T) * m_maxSize);

			m_growSize = ((growBy > 0) ? growBy : 0);
		}
	}
	~OrderedArray() {
		if (m_array != NULL) {
			delete[] m_array;
			m_array = NULL;
		}
	}

	int push(T val) {
		assert(m_array != NULL);
		if (m_numElements >= m_maxSize) {
			expand();
		}

		int i, k;
		for (i = 0; i < m_numElements; i++) {
			if (m_array[i] > val) {
				break;
			}
		}
		for ( k = m_numElements; k > i; k--) {
			array[k] = m_array[k - 1];
		}
		m_array[i] = val;

		m_numElements++;
		return i;
	}

	void pop() {
		if (m_numElements > 0) {
			m_numElements--;
		}
	}

	void remove(int index){
		assert(m_array != NULL);
		if (index >= m_numElements) {
			return;
		}

		for (int i = index; i < m_numElements; i++)
		{
			if (i + 1 < m_numElements){
				m_array[i] = m_array[i + 1];
			}
		}
		m_numElements--;
	}

	int search(T searchKey) {
		assert(m_array != NULL);

		int lowerbound = 0, upperBound = -1, current = 0;

		while (1)
		{
			current = (lowerbound + upperBound) >> 1;

			if (m_array[current] == searchKey){
				return current;
			}
			else if(lowerbound > upperBound ) {
				return -1;
			}
			else {
				if (m_array[current] < searchKey) {
					lowerbound = current + 1;
				}
				else{
					upperBound = current - 1
				}
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

	int getSize() {
		return m_numElements;
	}

	int getMaxSize() {
		return m_maxSize;
	}

	int getGrowSize() {
		return m_growSize;
	}

	void setGrowSize(int val) {
		assert(val >= 0);
		m_growSize = val;
	}

private:
	bool expand() {
		if (m_growSize <= 0)
		{
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

