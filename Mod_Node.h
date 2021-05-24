#ifndef _MOD_NODE_H_
#define _MOD_NODE_H_

#include"Expr_Node.h"

class Mod_Node : public Expr_Node {
public:

	// Mod_Node constructor
	Mod_Node(void);

	virtual void accept(Expr_Node_Visitor& visitor);

};

#endif

