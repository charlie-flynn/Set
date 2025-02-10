#pragma once
#include "Pair.h"
#include <initializer_list>

template <typename T>
class Set 
{
private:
	Pair<T, T>[] m_values;
	int m_length;
	int m_arrayLength;

public:
	Set<T>();
	Set<T>(std::initializer_list<T> values);
	Set<T>(T* values, int length);
	~Set<T>();
	bool Add(T key);
	bool Remove(T key);
	bool Contains(T key);
	int GetLength();
	int GetArrayLength(); // returns m_arrayLength
	T operator[](T key);
	Pair<T, T> GetPair(T key);

private:
	void Sort();
	void GrowArray();
	bool TrimArray();
};




template<typename T>
inline Set<T>::Set() : m_length(0), m_arrayLength(0)
{
}

template<typename T>
inline Set<T>::Set(std::initializer_list<T> values) : m_length(values.size()), m_arrayLength(values.size())
{
}

template<typename T>
inline Set<T>::Set(T* values, int length) : m_values(values), m_length(length), m_arrayLength(length)
{
}

template<typename T>
inline Set<T>::~Set()
{
	delete[] m_values;
}

template<typename T>
inline bool Set<T>::Add(T key)
{
	return false;
}

template<typename T>
inline bool Set<T>::Remove(T key)
{
	return false;
}

template<typename T>
inline bool Set<T>::Contains(T key)
{
	return false;
}

template<typename T>
inline int Set<T>::GetLength()
{
	return m_length;
}

template<typename T>
inline int Set<T>::GetArrayLength()
{
	return m_arrayLength;
}

template<typename T>
inline T Set<T>::operator[](T key)
{
	return T();
}

template<typename T>
inline Pair<T, T> Set<T>::GetPair(T key)
{
	return Pair<T, T>();
}

template<typename T>
inline void Set<T>::Sort()
{
}

template<typename T>
inline void Set<T>::GrowArray()
{
	return false;
}

template<typename T>
inline bool Set<T>::TrimArray()
{
	return false;
}

// OLD STINKY CODE
/*
template<typename T>
inline Set<T>::Set(std::initializer_list<T> values)
{
	// add values to the list
	for (T item : values)
	{
		m_values.PushFront(Pair<T, T>(item, item));
	}

	Sort();
}

template<typename T>
inline Set<T>::~Set()
{

}

template<typename T>
inline bool Set<T>::Add(T key)
{
	if (this->operator[](key) != T() || m_values.GetLength() >= 1000)
		return false;

	m_values.PushFront(Pair<T, T>(key, key));

	Sort();

	return true;
}

template<typename T>
inline bool Set<T>::Remove(T key)
{
	bool isRemoved = m_values.Remove(Pair<T, T>(key, key));
	Sort();
	return isRemoved;
}

template<typename T>
inline int Set<T>::GetLength()
{
	return m_values.GetLength();
}

template<typename T>
inline T Set<T>::operator[](T key)
{
	T keys[1000] = {};
	Iterator<Pair<T, T>> iter = m_values.begin();

	for (int i = 0; i < m_values.GetLength(); i++)
	{
		keys[i] = (*iter).key;
		iter++;
	}

	int leftBound = 0;
	int rightBound = m_values.GetLength() - 1;

	while (leftBound <= rightBound)
	{
		int index = ((leftBound + rightBound) / 2);

		if (keys[index] == key)
			return keys[index];

		if (keys[index] > key)
			leftBound = index + 1;

		if (keys[index] < key)
			rightBound = index - 1;
	}

	T placeholder = T();
	return placeholder;
}

template<typename T>
inline Pair<T, T> Set<T>::GetPair(T key)
{
	if (this->operator[](key) == T())
		return Pair<T, T>();

	return Pair<T, T>(key, key);
}

template<typename T>
inline Iterator<Pair<T, T>> Set<T>::begin()
{
	return m_values.begin();
}

template<typename T>
inline Iterator<Pair<T, T>> Set<T>::end()
{
	return m_values.end();
}

template<typename T>
inline void Set<T>::Sort()
{
	int length = m_values.GetLength();

	bool swapped = false;
	do 
	{
		swapped = false;
		Iterator<Pair<T, T>> iterA = m_values.begin();
		Iterator<Pair<T, T>> iterB = m_values.begin();
		iterB++;
		for (int i = 0; i < length - 1; i++)
		{
			if ((iterA.operator*()).value > (iterB.operator*()).value)
			{
				m_values.Swap(*iterA, *iterB);
				swapped = true;
			}
			iterA++;
			iterB++;
		}
	} while (swapped);
}
*/