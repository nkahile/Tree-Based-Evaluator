// $Id: Fixed_Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
#include<iostream>

//
// Fixed_Array
//

//calling the base array with a new size for the fixed array
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array(void)
	:Base_Array<T>(N)
{
	std::cout << "Fixed Array has been filled with[" << N << "]" 
		<< Base_Array<T>::cur_size_ << std::endl;
}

//
// Fixed_Array
//

//copy constructor
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array(const Fixed_Array <T, N>& arr)
	:Base_Array<T>(arr)
{
	for (size_t i = 0; i < arr.cur_size_; i++) {
		this->data_[i] = arr.data_[i];
	}
}

//
// Fixed_Array
//

template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array(T fill)
	:Base_Array<T>(N, fill)
{
	
}

//
// ~Fixed_Array
//

template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array(void)
{
	//no memory to free here
}

//
// operator =
//

template <typename T, size_t N>
const Fixed_Array <T, N>& Fixed_Array <T, N>::operator = (const Fixed_Array <T, N>& rhs)
{
	Array<T>::operator = (rhs);
	return (*this);
}
