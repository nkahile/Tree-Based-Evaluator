#include "Divide_Node.h"
#include "Expr_Node_Visitor.h"
//#include"Stack.h"

Divide_Node::Divide_Node()
	: Binary_Expr_Node(MULTIPLYDIVIDEMODULUSPRECEDENCE)
{
}

//
// ~Divide_Node
//
Divide_Node::~Divide_Node(void)
{

}


void Divide_Node::accept(Expr_Node_Visitor& visitor)
{
	visitor.Visit_Division_Node(*this);
}
