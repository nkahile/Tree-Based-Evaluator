#ifndef _ADD_NODE_H_
#define _ADD_NODE_H_

#include"Expr_Node.h"
#include"Stack.h"


class Add_Node : public Expr_Node {
public:

	// Add_Node Contructor
	Add_Node(void);

	// Add_Node Destructor
	~Add_Node (void);

	virtual void accept(Expr_Node_Visitor& visitor);
};

#endif