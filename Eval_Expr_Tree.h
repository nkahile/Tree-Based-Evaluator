#ifndef _EVAL_EXPR_TREE_H_
#define _EVAL_EXPR_TREE_H_

#include"Expr_Node_Visitor.h"
#include"Stack.h"
class Eval_Expr_Tree : public Expr_Node_Visitor
{
public:

	//Constructor
	Eval_Expr_Tree(void);

	//Destructor
	virtual ~Eval_Expr_Tree(void);

	// Methods for visiting concrete nodes
	// visit left node, visit right node, then perform addition
	virtual void Visit_Addition_Node(const Add_Node& node);

	// visit left node, visit right node, then perform Subtraction
	virtual void Visit_Subtraction_Node(const Subtract_Node& node);

	// visit left node, visit right node, then perform Division
	virtual void Visit_Division_Node(const Divide_Node& node);

	// visit left node, visit right node, then perform Multiplication
	virtual void Visit_Multiplication_Node(const Multiply_Node& node);

	// visit left node, visit right node, then perform Modulus operation
	virtual void Visit_Modulus_Node(const Mod_Node& node);


	virtual void Visit_Number_Node(const Num_Node& node);

	// Return the results
	int result(void) const;

private:
	Stack<int> stack_;
	int result_;

};

#endif

