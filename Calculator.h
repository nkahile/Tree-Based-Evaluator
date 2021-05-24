#ifndef CALCULATOR_H_
#define CALCULATOR_H_


#include "Array.h"
#include "Stack.h"
#include "Expr_Builder.h"
#include <sstream> 
#include <string>
#include <cstring> 				
#include "Math_Expr.h"
#include <exception>
#include <memory>
#include <map>

class Calculator
{
public:

	///Copy constructor
	Calculator(Expr_Builder& builder);

	///Destructor
	~Calculator(void);

	bool parse_expr(const std::string& infix);

	int compute(const std::string& infix);

	std::string deleteTrailingSpaces(const std::string&) const;

	void detect_vars(const std::string&);

private:
	Expr_Builder& builder_;

	//Map for storing variable values
	std::map < std::string, int >  variables;

};
#endif