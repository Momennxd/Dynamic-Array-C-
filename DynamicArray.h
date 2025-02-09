#pragma once

#include "INCL.h"



class DynamicArray {

private:

	long _t_size;
	long _t_capacity;
	int* _array;

	const long DEFAULT_CAPACITY = 1000;
	const short DEFAULT_GROWTH_RATE = 2;
	int* _copy(const int* originalArray, const int orign_Size, const int new_Size);
	int* _resize(int* array, int size, const int newCapacity);
	void _shift(int* array, int size,  int start, int end, int steps);
	void _init(int capacity);

public:

	void insertAt(int index, int value);

	void push(int value);

	void deleteAt(int index);

	void deleteElement(int value);

	void clear();

	void reset();

	int indexOf(int value);
	
	int Update(int index, int newValue);

	int at(int index) const;

	int size() const;

	int capacity() const;

	DynamicArray();
	DynamicArray(int capacity);
	bool operator==(const DynamicArray& arr1) const;
	bool operator!=(const DynamicArray& arr1) const;

	int operator [] (int index) const;
	int& operator[](int index);   

	


	 ~DynamicArray();

};
