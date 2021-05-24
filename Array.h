// -*- C++ -*-
// $Id: Array.h 819 2011-01-17 15:24:45Z hillj $

//==============================================================================
/**
 * @file       Array.h
 *
 * $Id: Array.h 819 2011-01-17 15:24:45Z hillj $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
 //==============================================================================

#ifndef _ARRAY_H_
#define _ARRAY_H_
#include "Base_Array.h"
#include <cstring>          // for size_t definition

/**
 * @class Array
 *
 * Basic implementation of a standard array class for chars.
 */
template <typename T>
class Array : public Base_Array<T>
{
public:
	/// Default constructor.
	typedef T type;
	Array(void);

	/**
	 * Initializing constructor.
	 *
	 * @param[in]      length        Initial size
	 */
	Array(size_t length);

	/**
	 * Initializing constructor.
	 *
	 * @param[in]      length        Initial size
	 * @param[in]      fill          Initial value for each element
	 */
	Array(size_t length, T fill);

	/**
	 * Copy constructor
	 *
	 * @param[in]     arr         The source array.
	 */
	Array(const Array& arr);

	/// Destructor.
	~Array(void);

	/**
	 * Assignment operation
	 *
	 * @param[in]       rhs      Right-hand side of equal sign
	 * @return          Reference to self
	 */
	const Array& operator = (const Array& rhs);

	/**
	 * Retrieve the current size of the array.
	 *
	 * @return          The current size
	 */
	size_t size(void) const;

	/**
	 * Retrieve the maximum size of the array.
	 *
	 * @return          The maximum size
	 */
	size_t max_size(void) const;


	/**
	 * Set the character at the specified \a index. If the \a index is not
	 * within range of the array, then std::out_of_range exception is
	 * thrown.
	 *
	 * @param[in]       index                 Zero-based location
	 * @param[in]       value                 New value for character
	 * @exception       std::out_of_range     Invalid \a index value
	 */
	void set(size_t index, T value);

	/**
	 * Set a new size for the array. If \a new_size is less than the current
	 * size, then the array is truncated. If \a new_size if greater then the
	 * current size, then the array is made larger and the new elements are
	 * not initialized to anything. If \a new_size is the same as the current
	 * size, then nothing happens.
	 *
	 * The array's original contents are preserved regardless of whether the
	 * array's size is either increased or decreased.
	 *
	 * @param[in]       new_size              New size of the array
	 */
	void resize(size_t new_size);

	/// Shrink the array to reclaim unused space.
	void shrink();

	/**
	 * Test the array for equality.
	 *
	 * @param[in]       rhs                  Right hand side of equal to sign
	 * @retval          true                 Left side is equal to right side
	 * @retval          false                Left side is not equal to right side
	 */
	bool operator == (const Array& rhs) const;

	/**
	 * Test the array for inequality.
	 *
	 * @param[in]       rhs                  Right-hand size of not equal to sign
	 * @retval          true                 Left side is not equal to right side
	 * @retval          false                Left size is equal to right side
	 */
	bool operator != (const Array& rhs) const;

	/**
	 * Fill the contents of the array.
	 *
	 * @param[in]       ch                   Fill character
	 */
	void fill(T ch);

	/// Reverse the contents of the array such that the first element is now
	/// the last element and the last element is the first element.
	void reverse(void);

	/**
	 * The slice() method returns a shallow copy of a portion of an array into
	 * a new array object selected from begin to end (end not included). The original
	 * array will not be modified.
	 *
	 * @param[in]       begin           The starting index
	 * @return          A new Array object
	 */
	T slice(size_t begin) const;

	/**
	 * @overload
	 *
	 * @param[in]       begin           The starting index
	 * @param[in]       end             The ending index
	 * @return          A new Array object
	 */
	T slice(size_t begin, size_t end) const;
};

#include "Array.cpp"
//#include "Array.inl"

#endif   // !defined _ARRAY_H_