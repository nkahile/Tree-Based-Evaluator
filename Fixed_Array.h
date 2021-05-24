// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _CS507_FIXED_ARRAY_H_
#define _CS507_FIXED_ARRAY_H_

/**
 * @class Fixed_Array
 *
 * Implementation of a fixed size array, i.e., one that is not
 * resizeable. It is derived from Array so it can inherit of
 * the Array class's methods.
 */
#include "Base_Array.h"

template <typename T, size_t N>
class Fixed_Array : public Base_Array <T>
{
public:

	/// Default constructor.
	Fixed_Array(void);

	/**
	 * Copy constructor.
	 *
	 * @param[in]      arr        Source array
	 */
	Fixed_Array(const Fixed_Array <T, N>& arr);

	/**
	 * Initializing constructor. Fills the contents of the
	 * array with the specified \a fill value.
	 *
	 * @param[in]      fill       The file value.
	 */
	Fixed_Array(T fill);

	/// Destructor.
	~Fixed_Array(void);

	/**
	 * Assignment operator
	 *
	 * @param[in]      rhs        Right-hand side of operator.
	 */
	const Fixed_Array& operator = (const Fixed_Array <T, N>& rhs);

	/**
	 * Assignment operator
	 *
	 * @param[in]      rhs        Right-hand side of operator.
	 */
};

// include the inline files
#include "Fixed_Array.inl"

// include the source file since template class
#include "Fixed_Array.cpp"

#endif  // !defined _CS507_FIXED_ARRAY_H_