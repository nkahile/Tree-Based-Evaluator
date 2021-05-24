#include "Subtract_Node.h"
#include"Expr_Node_Visitor.h"
//#include"Stack.h"

Subtract_Node::Subtract_Node(void)
{

}

void Subtract_Node::accept(Expr_Node_Visitor& visitor)
{
	visitor.Visit_Subtraction_Node(*this);
}




