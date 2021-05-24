// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include <iostream>
#include <string>
#include <stdexcept>         // for std::out_of_bounds exception


//Array

//Changing it to be a template so it could take data of any type, defult constructor with
//defult size of 50 assigning intizilizin the data pointer to 0 and
//seting it to null and alocating a new max_size_ array
//#include"Array.h"

template <typename T>
Array <T>::Array(void)
	:Base_Array<T>()
{

}


//Array (size_t)

//Changing it to be a template so it could take data of any type, Initializing constructor with
//setting the data to 0 and have it point to null, current size will
//be set to the length of and max size to length of the Array
template <typename T>
Array <T>::Array(size_t length)
	:Base_Array<T>(length)
{
	
}


//Array (size_t, char)

//Initializing constructor, will take 2 parametares first for set the lenght the the second will fill
//the lenght the array with the giving lenght and the givin character
//@param[in]      =>        Array(3,3)     =>       [3,3,3]
template <typename T>
Array <T>::Array(size_t length, T fill)
	:Base_Array<T>(length)

{
	Base_Array<T>::fill(fill);

	std::cout << "Array has been filled with[" << length << "]" << Base_Array<T>::data_ << std::endl;
}


//Array (const Array &)

//a copy constructor that will take the source array and will set it's state to the state
//of another ADT of the same type
template <typename T>
Array <T>::Array(const Array& array)
	:Base_Array<T>(array)
{
	for (size_t i = 0; i < array.cur_size_; i++) {
		Base_Array<T>::data_[i] = array.data_[i];
	}
}


// ~Array

//Intializing destructor, will free the memory taken by the the private class member data and will
template <typename T>
Array <T>::~Array(void)
{
	
}


//operator =

//Operator overloading '=' will assign the current array to the assigned rhs array, Assignig same Array
//objects could be dangerours so to avoid them getting assigned to each other a simple check is made to return
//the assigned lhs array, then a simple check to see if current size is less than rhs, created a temp array to
//hold total of current size and the rhs current size, then created a char pointer called data_copy to do a swap
//operation, relase memory from the temp array 'temp_arr'
template <typename T>
const Array <T>& Array <T>::operator = (const Array& rhs)
{
	if (this != &rhs) {
		Base_Array<T>::operator = (rhs);
		Base_Array<T>::max_size_ = rhs.max_size_;
	}

	return (*this);
}



// set

//set method that will take a parameter index and character and will check first if the index
//is out of the range of the max size of the array, if true it will throw an exeption, if not it will set
//the value of the specified index with the charater
//@param    (index,value)     =>      A1.set(2, 'z');     =>     Value at index [2] is: z */
template <typename T>
void Array <T>::set(size_t index, T value)
{
	if (Base_Array<T>::max_size_ < index) {
		throw std::out_of_range("Index out of range");
	}
	else {
		Base_Array<T>::data_[index] = value;
	}
}


//resize

//will take a new size and resize the array, if current size is > than new size then a swap operation takes
//place to copy data to a bigger array by creating a temp array of size_t then a data pointer called data_copy
//to do the swap and then assigning the new current size and max size to the temp current size and temp max size,
//then finanly with print the new size, the size is the same then nothing happens, and if the current size is > than new
//size then no need for any memory alocation, assign current size to new size*/
template <typename T>
void Array <T>::resize(size_t new_size)
{
	if (Base_Array<T>::cur_size_ < new_size) {

		T* temp_arr = new T[new_size];
		T* data_copy = Base_Array<T>::data_;
		Base_Array<T>::data_ = temp_arr;
		temp_arr = data_copy;

		std::cout << "=>Array size changed to " << new_size << std::endl;

	}
	else if (Base_Array<T>::cur_size_ == new_size) {
		std::cout << "=>Array already has a size of " << new_size << std::endl;

	}
	else if (Base_Array<T>::cur_size_ > new_size) {

		Base_Array<T>::cur_size_ = new_size;
		std::cout << "=>Array size changed to " << new_size << std::endl;

	}
}


//operator ==

//Always show the positive outcome first,Created a nested for loop, one will go over the lhs current size
//and the other will go over the rhs current size, a simple check is created to see if data in both sides are equal 
//and if the current size in both sides are equal, if both conditions are true, return true otherwise return false
template <typename T>
bool Array <T>::operator == (const Array& rhs) const
{
	if (this->max_size_ != rhs.max_size_)
		return (false);

	return (Base_Array<T>::operator == (rhs));
}


// operator !=

//Always show the positive outcome first,Created a nested for loop, one will go over the lhs current size
//and the other will go over the rhs current size, a simple check is created to see if data in both sides are not equal 
//and if the current size in both sides are not equal if either conditions are true, return true otherwise return false
template <typename T>
bool Array <T>::operator != (const Array& rhs) const
{
	return !(*this == rhs);
}


//fill

//Fill method will fill the array with a specidef character and will set the array to be filled with that
//character then will print the newly filled array*/
template <typename T>
void Array <T>::fill(T ch)
{
	for (size_t i = 0; i < Base_Array<T>::cur_size_; i++) {
		this->set(i, ch);
		Base_Array<T>::data_[i] = ch;
	}
}


//shrink method will check if there's unused space, if it does it checks to see if
//the array can be shrunk. an array to point to the old data(data which will be deleted)
//a temp pointer to make the bigger array
//then will copy the data
template <typename T>
void Array<T>::shrink(void)
{
	if (Base_Array<T>::max_size_ > Base_Array<T>::cur_size_) {

		T* data_copy = Base_Array<T>::data_;
		T* temp = new T[Base_Array<T>::cur_size_];
		for (int i = 0; i < Base_Array<T>::cur_size_; i++) {
			temp[i] = Base_Array<T>::data_[i];
		}

		Base_Array<T>::data_ = temp;
		Base_Array<T>::max_size_ = Base_Array<T>::cur_size_;

		temp = 0;
		delete[] data_copy;
		data_copy = 0;
	}
}


//=>reverse

//reverse the contants of the array*/
//['a','b','c']    =>    ['c','b','a']
template <typename T>
void Array<T>::reverse(void)
{
	std::cout << "Reversed array is: ";
	for (size_t i = Base_Array<T>::cur_size_ - 1; i > 0; i--) {
		std::cout << this->data_[i];
	}
	std::cout << std::endl;

}


//Slice

//This method will slice the array from a starting point, My train of through was to 
//as the documation says, create an array that will refrance the sliced data, so i started of by
//creating the array 'data_copy', assign data copy to data to create the shallow copy of data_
//start the for loop from begin,insert elements in the refranced array and finally and
//return the the refranced array
template <typename T>
T Array<T>::slice(size_t begin) const
{
	T* data_copy = new T[Base_Array<T>::cur_size_];
	data_copy = Base_Array<T>::data_;
	for (size_t i = begin; i < Base_Array<T>::cur_size_; i++) {
		data_copy[i];
		std::cout << *data_copy;
	}
	return *data_copy;
	delete[] data_copy;
}


//Slice

//This method will slice the array from a starting point, My train of through was to 
//as the documation says, create an array that will refrance the sliced data, so i started off by
//creating the array 'data_copy', assign data_copy to data_ to create the shallow copy of data_
//start the for loop from 'begin' and have it stop at 'end',insert elements in the refranced array
//and finally and return the the refranced array
template <typename T>
T Array<T>::slice(size_t begin, size_t end) const
{
	T* data_copy = new T[Base_Array<T>::cur_size_];
	data_copy = Base_Array<T>::data_;
	for (size_t i = begin; i < end; i++) {
		data_copy[i];
		std::cout << *data_copy;
	}
	return *data_copy;
	delete[] data_copy;
}