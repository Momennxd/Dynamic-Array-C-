#include "DynamicArray.h"

int* DynamicArray::_copy(const int* original_array, const int original_size, const int new_size)
{
	if (original_array == nullptr|| original_size < 0 || new_size < 0) return nullptr;
	int n = std::min(original_size, new_size);
	int* newArray = new int[new_size];
	for (int i = 0; i < n; i++) {
		newArray[i] = original_array[i];
	}

	return newArray;
}

int* DynamicArray::_resize(int* array, int size, const int newCapacity)
{
	if (newCapacity < 0) return nullptr;
	return _copy(array, size, newCapacity);
}

void DynamicArray::_shift(int* array, int size, int start, int end, int steps)
{
	if (start + steps < 0 || end + steps >= size 
		|| start < 0 || end >= size || size < 0 || array == nullptr)
		throw std::out_of_range("Shifting M&A2004 lolee siad is not possible: Out of bounds.");

	if (steps == 0 || size == 0) return;

	int startIndex = steps > 0 ? end : start;
	int endIndex = steps > 0 ? start : end;

	for (int i = startIndex; steps > 0 ? i >= endIndex : i <= endIndex; steps > 0 ? i-- : i++) {
		array[i + steps] = array[i];
	}
}

void DynamicArray::_init(int capacity)
{
	this->_array = new int[capacity];
	this->_t_size = 0;
	this->_t_capacity = capacity;
}

void DynamicArray::insertAt(int index, int value)
{
	if (index < 0 || index >= this->_t_size) throw std::out_of_range("out of bounds M&A2004 lolee siad is not possible");
	if (this->_t_size + 1 > this->_t_capacity) {
		this->_t_capacity *= this->DEFAULT_GROWTH_RATE;
		this->_array =
			this->_resize(this->_array, this->_t_size, this->_t_capacity);
	}

	//shifting elments to the right by 1
	this->_shift(this->_array, this->_t_capacity, index, this->_t_size - 1, 1);
	this->_array[index] = value;
	this->_t_size++;
}

void DynamicArray::push(int value)
{
	if (this->_t_size >= this->_t_capacity) {
		this->_t_capacity *= this->DEFAULT_GROWTH_RATE;
		int* newArray = _resize(this->_array, this->_t_size, this->_t_capacity);
		delete[] this->_array;
		this->_array = newArray;
	}
		
	this->_array[this->_t_size++] = value;
}

void DynamicArray::deleteAt(int index)
{
	if (index < 0 || index >= this->_t_size) throw std::out_of_range("Index out of bounds");

	this->_shift(this->_array, this->_t_capacity, index + 1, this->_t_size - 1, -1);

	this->_t_size--;
}

void DynamicArray::deleteElement(int value)
{
	for (int i = 0; i < this->_t_size; i++) {
		if (this->_array[i] == value) {
			this->deleteAt(i);
			return;
		}
	}
}

void DynamicArray::clear()
{
	this->_t_size = 0;
}

void DynamicArray::reset()
{
	delete[] this->_array;
	_init(this->DEFAULT_CAPACITY);
}

int DynamicArray::indexOf(int value)
{
	for (int i = 0; i < this->_t_size; i++) {
		if (this->_array[i] == value) {
			return i;
		}
	}
	return -1;
}

int DynamicArray::at(int index) const
{
	if (index < 0 || index >= this->_t_size) throw std::out_of_range("Index out of bounds");
	return this->_array[index];
}

int DynamicArray::size() const
{
	return this->_t_size;
}

int DynamicArray::capacity() const
{
	return this->_t_capacity;
}

DynamicArray::DynamicArray()
{
	_init();
}

DynamicArray::DynamicArray(int capacity)
{
	capacity = capacity < 0 ? this->DEFAULT_CAPACITY : capacity;
	_init(capacity);

}

bool DynamicArray::operator==(const DynamicArray& arr1) const
{
	if (arr1.size() != this->size()) return false;
	for (int i = 0; i < arr1.size(); i++) {
		if (arr1.at(i) != this->_array[i]) return false;
	}
	return true;
}

bool DynamicArray::operator!=(const DynamicArray& arr1) const
{
	return !(*this == arr1); 
}

int DynamicArray::operator[](int index)
{
	return this->at(index);
}

DynamicArray::~DynamicArray()
{
	delete[] this->_array;
}
