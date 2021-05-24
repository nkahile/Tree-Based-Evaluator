#ifndef _MATH_EXPR_H_
#define _MATH_EXPR_H_

class Math_Expr
{
public:
	Math_Expr(void);

	virtual ~Math_Expr(void);

	virtual int eval(void) = 0;

};
#endif
