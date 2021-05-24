#include "Add_Node.h"
#include "Expr_Node_Visitor.h"
//#include"Stack.h"


Add_Node::Add_Node ()
	:Binary_Expr_Node ( ADDSUBTRACTPRECEDENCE )
{

}


Add_Node::~Add_Node (void)
{

}


void Add_Node::accept(Expr_Node_Visitor& visitor)
{
	visitor.Visit_Addition_Node(*this);
}
