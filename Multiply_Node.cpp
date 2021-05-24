#include "Multiply_Node.h"
#include "Expr_Node_Visitor.h"
//#include"Stack.h"

Multiply_Node::Multiply_Node(void)
{

}

void Multiply_Node::accept(Expr_Node_Visitor& visitor)
{
	visitor.Visit_Multiplication_Node(*this);
}
