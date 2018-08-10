/*
*	JSONParser
*	class Vector 
*/

#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>

template <class DataType>
class Vector
{
public:
	Vector();
	Vector(int initCapacity);
	Vector(const Vector& other);
	Vector(const DataType *arr, int arrSize);
	~Vector();

	int getSize()const { return size; }
	int getCapacity()const { return capacity; }
    bool isEmpty()const { return !size; }

	void append(DataType newElement);
	void remove(int index);

	Vector<DataType>& operator=(const Vector& other);
	const DataType& operator[](int index)const;
	DataType& operator[](int index);
	Vector<DataType>& operator+=(const DataType newElement);
	Vector<DataType>& operator+=(const Vector& other);
	Vector<DataType> operator+(const Vector& other);
	Vector<DataType> operator+(const DataType newElement);

private:
	void clear();
	void resize();

protected:
	DataType * data;	
	int size;
	int capacity;
};

template <class DataType>
Vector<DataType>::Vector()
	:data(nullptr)
	,size(0)
	,capacity(0)
{}

template <class DataType>
Vector<DataType>::Vector(int initCapacity)
	:size(0)
	, capacity(initCapacity)
{
	if (initCapacity <= 0)
	{
		throw std::invalid_argument("negative value for size");
	}

	data = new DataType[capacity];
}

template <class DataType>
Vector<DataType>::Vector(const Vector& other)
	:size(other.getSize())
	,capacity(other.getCapacity())
{
	capacity = !capacity * 1 + capacity;
	data = new DataType[capacity];
	for (int i = 0; i < size; ++i)
		data[i] = other[i];
}

template <class DataType>
Vector<DataType>::Vector(const DataType *arr, int arrSize)
	:size(arrSize)
	,capacity(arrSize)
{
	if (!arr)
		throw std::invalid_argument("array is invalid");
	data = new DataType[capacity];
	for (int i = 0; i < size; ++i)
		data[i] = arr[i];
}

template <class DataType>
Vector<DataType>::~Vector()
{
	clear();
}

template<class DataType>
void Vector<DataType>::append(DataType newElement)
{
	if (size >= capacity)
		resize();

	data[size] = newElement;
	++size;
}

template<class DataType>
void Vector<DataType>::remove(int index)
{
	if (index < 0 && index >= size)
		throw std::invalid_argument("invalid index");

	for (int i = index; i < size - 1; ++i)
		data[i] = data[i + 1];

	--size;
}

template<class DataType>
Vector<DataType>& Vector<DataType>::operator=(const Vector & other)
{
	if (this != &other) {
		clear();
		size = other.getSize();
		capacity = other.getCapacity();
		data = new DataType[capacity];
		for (int i = 0; i < size; ++i)
			data[i] = other[i];
	}

	return *this;
}

template<class DataType>
const DataType & Vector<DataType>::operator[](int index)const
{
	 if (index < 0 && index >= size)
		 throw std::invalid_argument("invalid index");
	 return data[index];
}

template<class DataType>
DataType & Vector<DataType>::operator[](int index)
{
	if (index < 0 && index >= size)
		throw std::invalid_argument("invalid index");
	return data[index];
}

template<class DataType>
Vector<DataType>& Vector<DataType>::operator+=(const DataType newElement)
{
	append(newElement);
	return *this;
}

template<class DataType>
Vector<DataType>& Vector<DataType>::operator+=(const Vector & other)
{
	while (capacity < size + other.getSize())
		resize();

	int otherSize = other.getSize();
	for (int i = 0; i < otherSize; ++i)
		data[i + size] = other[i];

	size += other.getSize();
	return *this;
}

template<class DataType>
Vector<DataType> Vector<DataType>::operator+(const Vector &other)
{
	Vector<DataType> temp(*this);
	temp += other;
	return temp;
}

template<class DataType>
Vector<DataType> Vector<DataType>::operator+(const DataType newElement)
{
	Vector<DataType> temp(*this);
	temp += newElement;
	return temp;
}

template <class DataType>
void Vector<DataType>::clear()
{
	delete[] data;
	data = nullptr;
	size = capacity = 0;
}

template <class DataType>
void Vector<DataType>::resize()
{
	int newCapacity = !capacity ? 1 : capacity * 2;
	DataType *tempData = new DataType[newCapacity];
	
	for (int i = 0; i < size; ++i)
		tempData[i] = data[i];

	delete[] data;
	data = tempData;
	capacity = newCapacity;
}

#endif /*VECTOR_H*/
