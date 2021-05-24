#ifndef _EXPR_NODE_VISITOR_H_
#define _EXPR_NODE_VISITOR_H_


#include "Add_Node.h" 
#include "Subtract_Node.h" 
#include "Multiply_Node.h" 
#include "Divide_Node.h" 
#include "Mod_Node.h" 
#include "Num_Node.h" 


class Expr_Node_Visitor
{
protected:


public:
	Expr_Node_Visitor(void);

	virtual ~Expr_Node_Visitor(void);

	// Methods for visiting concrete nodes
	virtual void Visit_Addition_Node(const Add_Node& node) = 0;

	virtual void Visit_Subtraction_Node(const Subtract_Node& node) = 0;

	virtual void Visit_Multiplication_Node(const Multiply_Node& node) = 0;

	virtual void Visit_Division_Node(const Divide_Node& node) = 0;

	virtual void Visit_Modulus_Node(const Mod_Node& node) = 0;

	virtual void Visit_Number_Node(const Num_Node& node) = 0;

};

#endif

