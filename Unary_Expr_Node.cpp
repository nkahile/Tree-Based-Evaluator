// $Id: Unary_Expr_Node.cpp 

//
// Unary_Expr_Node
//

#include "Unary_Expr_Node.h"


//
// Unary_Expr_Node (void)
//
Unary_Expr_Node::Unary_Expr_Node(void)
{
}

//
// ~Unary_Expr_Node
//
Unary_Expr_Node::~Unary_Expr_Node(void)
{
}

//
// eval
//
int Unary_Expr_Node::eval(void)
{
	if (this->child_)
		return this->child_->eval();
}