/*
 * Name: Grayson Whitaker
 * Date Submitted: 2/14/2023
 * Section: 003
 * Assignment Name: Stack-based Postfix Expression Calculator
 */

#include <string>
#include <stack>

using namespace std;

// Function determines if a symbol is an operator, returns:
//      0: not an operator
//      1: operator
bool isOperator(string symbol){
    if(symbol == "+" || symbol == "-" || symbol == "*" || symbol == "/" || symbol == "%") return 1;
    else return 0;
}

//Calculates a postfix expression with integer operands using a stack
//The expression is represented using an array of strings
//Each string is either an operand or operator symbol
//Operator symbols:
//"+" addition
//"-" subtraction
//"*" multiplication
//"/" divison
//"%" remainder
//Example expression: "8", "5", "-" evaluates to a result of 3:
//1: push 8, 2: push 5,
//3: "-"-> pop top two values, earlier value is the left-side operand: 8 - 5
//The result of the operation (8-5) is 3, push 3 onto stack
//After evaluation of the expression, the final result should be
//the only value on the stack, return 0 if the stack is
//non-empty after popping the result
//Return 0 if expression is zero-length or if there are insufficient operands
//for an operation
//The STL Stack class can be used
//To easily convert a numeric string to an int you may use the stoi() function
//which takes a string as a parameter and returns a string
int calculatePostfixExpression(string expression[], int length){
    // initialize stack
    stack<string> numStack;

    // loop through string array containing symbols from postfix expression
    for(int i = 0; i < length; i++){
        // if expression[i] is an operator
        if(isOperator(expression[i])){
            // if stack is not empty, continue
            if(!numStack.empty()){
                int operand1, operand2, result;
                // pop value for "second" value
                operand2 = stoi(numStack.top());
                numStack.pop();
                // pop value for "first" value, if stack is empty, invalid expression was input, return error
                if(!numStack.empty()){
                    operand1 = stoi(numStack.top());
                    numStack.pop();
                }
                else return 0;

                // perform operations based on operator type
                if(expression[i] == "+"){
                    result = operand1 + operand2;
                    numStack.push(to_string(result));
                }
                else if(expression[i] == "-"){
                    result = operand1 - operand2;
                    numStack.push(to_string(result));
                }
                else if(expression[i] == "*"){
                    result = operand1 * operand2;
                    numStack.push(to_string(result));
                }
                else if(expression[i] == "/"){
                    result = operand1 / operand2;
                    numStack.push(to_string(result));
                }
                else if(expression[i] == "%"){
                    result = operand1 % operand2;
                    numStack.push(to_string(result));
                }
            }
            // stack is empty, invalid expression was input, return error
            else return 0;
        }
        else{
            // push numbers onto stack
            numStack.push(expression[i]);
        }
    }

    // if stack is not empty, pop final result, else return error
    int finalResult;
    if(!numStack.empty()){
        finalResult = stoi(numStack.top());
        numStack.pop();
    }
    else return 0;

    // if there is anything remaining in stack, an invalid operation was input, return error
    if(!numStack.empty()) return 0;
    else return finalResult;
}