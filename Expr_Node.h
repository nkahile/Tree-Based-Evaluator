#ifndef _EXPR_NODE_H_
#define _EXPR_NODE_H_


class Expr_Node{
public:

	//constructor
	Expr_Node(void);

	//Virtual destructor
	virtual ~Expr_Node(void);

	//accept will be a Pure Virtual function, "Interface"
	virtual void accept(Expr_Node_Visitor& visitor) = 0;
};

//Forward Declaration on class Expr_Node_Visitor
class Expr_Node_Visitor;
#endif