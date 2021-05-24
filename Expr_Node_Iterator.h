#ifndef _EXPR_NODE_ITERATOR_
#define _EXPR_NODE_ITERATOR_

#include"Array.h"
#include "Expr_Node.h"

class Expr_Node_Iterator
{
public:
	//Constructor
	Expr_Node_Iterator(Array <Expr_Node>& iter);

	//Destructor
	~Expr_Node_Iterator(void);

	//return true if the iterator is done, otherwise return false
	bool is_done(void);

	//Move to the next element, equevlate to 'i++' in a for loop
	void advance(void);

	//Treat the interator like a pointer, return the addres of the element
	Expr_Node& operator * (void);

	//Treat the interator like a pointer, point and return the object
	Expr_Node* operator -> (void);
private:

	//A refrance to the commands that will be iterated via the iterator
	Array <Expr_Node>& iter_;

	//Current location
	size_t curr_;

};
#endif // !1
