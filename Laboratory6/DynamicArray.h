#pragma once
#include <string>
#include <ostream>
#include "Offer.h"
#include "OutOfBoundsException.h"
using namespace std;

template <class T>
class DynamicArray
{
public:
	DynamicArray(int capacity = 100); // = default parameter

	// RULE OF THREE 
	// destructor
	~DynamicArray();

	// copy constructor
	DynamicArray(const DynamicArray<T>& other);

	// assignment operator
	DynamicArray<T>& operator=(const DynamicArray<T>& other);
	// end RULE OF THREE 

	// getter for the length
	// inline - it MUST be implemented in the header
	inline unsigned int getLength() const { return length; }

	inline unsigned int getCapacity() const { return capacity; }

	// adds an element at the end
	void append(T v, bool* err = nullptr);

	// remove the element from the end
	// pre: the array is not empty
	T popBack();

	// remove an element from position i
	// index >= 0 and index < length
	T remove(unsigned int index);

	// get the element on a position
	// a[10]
	// index >= 0 and index < length
	// -1 is returned if the index is not valid
	T& get(unsigned int index);

	// print the array
	friend ostream& operator<< <T>(ostream& s, const DynamicArray<T>& arr);

	// operator+ -> append a value to the array
	// opertaor belongs to the class
	// param v -> get appened at the end of the array
	//DynamicArray& operator+(int v); // operator+ -> is a method of DynamicArray

	// second way - friends (the operator does not belong to the class)
	// friend DynamicArray& operator+(DynamicArray& arr, int v);

private:
	// static -> it belongs to the class
	static int count;
	// Length – how many elements do we have(0)
	unsigned int length;
	//	Capacity – the max number of elements
	unsigned int capacity;
	// data - array itself
	T* data;

	void resize(unsigned int newCapacity);
};

template <class T>
DynamicArray<T>::DynamicArray(int capacity) {
	length = 0;
	this->capacity = capacity;
	this->data = new T [capacity]();

	if (this->data == nullptr) {
		cerr << "DynamicArray(): failed to allocate memory" << endl;
		exit(-1);
	}
}

template <class T>
DynamicArray<T>::~DynamicArray() {
	//free the allocated memory
	delete[] this->data;
}

template <class T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& other) {

	if (this != &other) { // self assignment check
		// deep copy of other
		length = other.length;
		capacity = other.capacity;

		delete[] this->data;
		// !! data 
		// data = other.data; NOO! this is shallow copy
		// deep copy of data
		this->data = new T[other.capacity]();

		if (this->data == nullptr) {
			cerr << "operator=(): failed to allocate memory" << endl;
			exit(-1);
		}

		for (unsigned int i = 0; i < length; i++)
			this->data[i] = other.data[i];
	}
	return *this; // the type of this is DynamicArray* -> dereferencing
}

template <class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other) {
	// deep copy of other
	length = other.length;
	capacity = other.capacity;

	// !! data 
	// data = other.data; NOO! this is shallow copy
	// deep copy of data
	this->data = new T[other.capacity]();

	if (this->data == nullptr) {
		cerr << "DynamicArray(const DynamicArray& other): failed to allocate memory" << endl;
		exit(-1);
	}

	for (unsigned int i = 0; i < length; i++)
		this->data[i] = other.data[i];
}

//template <class T>
//DynamicArray<T>::DynamicArray(const DynamicArray<T>& other) {
//	// deep copy of other
//	length = other.length;
//	capacity = other.capacity;
//
//	// !! data 
//	// data = other.data; NOO! this is shallow copy
//	// deep copy of data
//	data = new T[other.capacity]();
//
//	if (data == nullptr) {
//		cerr << "DynamicArray(const DynamicArray& other): failed to allocate memory" << endl;
//		exit(-1);
//	}
//
//	for (unsigned int i = 0; i < length; i++)
//		data[i] = other.data[i];
//}

template <class T>
void DynamicArray<T>::append(T v, bool* err)
{
	// todo 
	// check if the length < capacity
	if (length == capacity) {
		// double the capacity
		resize(capacity * 2);
	}
	this->data[length] = v;
	length++;
}

template <class T>
ostream& operator<<(ostream& s, const DynamicArray<T>& arr) {
	// [1 2 3 4 5 ]
	s << "[";
	for (unsigned int i = 0; i < arr.length; i++) {
		s << arr.data[i] << " ";
	}
	s << "]";
	return s;
}

template <class T>
T DynamicArray<T>::popBack() {
	// delete and return the last element in the array
	// pre array is not empty
	if (length == 0) {
		// unfriendly way of handling corner cases
		cerr << "Precondition does not hold: popBack()" << endl;
		exit(-1);
	}

	// convention 0 - elements that were not set

	T v = this->data[length - 1];
	length--;

	return v;
}

template <class T>
T DynamicArray<T>::remove(unsigned int index)
{
	//  index >= 0 and index < length
	// pre index >=0 and index < length
	if (index >= 0 && index < length) {
		T v = this->data[index];
		for (unsigned int i = index; i < length - 1; i++)
			this->data[i] = this->data[i + 1];
		length--;
		return v;
	}
	else {
		// unfriendly way of handling corner cases
		cerr << "Precondition does not hold: remove()" << endl;
		exit(-1);
	}
}

template <class T>
T& DynamicArray<T>::get(unsigned int index) {

	// pre index >=0 and index < length
	if (index >= 0 && index < length) {
		return this->data[index];
	}
	throw OutOfBoundsException(0, this->getLength());
}

template <class T>
void DynamicArray<T>::resize(unsigned int newCapacity) {

	this->capacity = newCapacity;
	// no realloc  in c++

	T* newData = new T[newCapacity]();
	if (newData == nullptr) {
		cerr << "resize(): failed to allocate memory" << endl;
		exit(-1);
	}
	// previous elements located in data
	// copy them in newData
	for (unsigned int i = 0; i < length; i++) {
		newData[i] = this->data[i];
	}

	delete[] this->data;
	this->data = newData;
}