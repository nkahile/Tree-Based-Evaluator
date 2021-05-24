#include "Mod_Node.h"
#include"Expr_Node_Visitor.h"
//#include"Stack.h"


Mod_Node::Mod_Node(void)
{
}

void Mod_Node::accept(Expr_Node_Visitor& visitor)
{
	visitor.Visit_Modulus_Node(*this);
}
