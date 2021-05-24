#include "Num_Node.h"
#include "Expr_Node_Visitor.h"


//
Num_Node::Num_Node(int n)
{

}

void Num_Node::accept(Expr_Node_Visitor& visitor)
{
	visitor.Visit_Number_Node(*this);
}



