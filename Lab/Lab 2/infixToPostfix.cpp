/*
 * Name: Grayson Whitaker
 * Date Submitted: 1/6/2023
 * Lab Section: 002
 * Assignment Name: Lab 2: Infix to Postfix Conversion
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

// function takes one parameter of the string type which is a symbol from the infix array
// and returns:
//      0: symbol is low precendence operator
//      1: symbol is high precedence operator
//      2: symbol is number
int symbolType(string symbol){
    if(symbol == "+" || symbol == "-") return 0;
    else if(symbol == "*" || symbol == "/" || symbol == "%") return 1;
    else if(symbol != "(" && symbol != ")") return 2;

    else return -1;
}

//Converts an infix arithmetic expression into postfix
//The function takes 3 parameters
//First parameter: array of strings for infix expression
//    each string is either an integer number or operator symbol
//Second parameter: number of strings in infix expression
//Third parameter: array of strings for postfix expression
//    generated by function, same format as first parameter
//    assumes that postfix is at least the size of postfix
//Return value: int, number of strings in postfix expression
//    Returns 0 if an error is encountered when converting expression
//    An error occurs with a mismatched parenthesis, e.g. ( ( ) or ( ) ) etc.
//Operator symbols:
// ( : left parenthesis, all operations between this and ")" take place first
// ) : right parenthesis, all op.s back to previous "(" take place first
// * : multiplication, higher precedence - takes place before "+" and "-"
// / : division, higher precedence - takes place before "+" and "-"
// % : remainder, higher precedence - takes place before "+" and "-"
// + : addition, lower precedence - takes place after "*" , "/" , "%"
// - : subtraction, lower precedence - takes place after "*" , "/" , "%"
//The function is not specified to work with any other operator symbols
//Any string in infix may be assumed to be an integer operand if none
// of the above symbols
int infixToPostfix(string infix[], int length, string postfix[]){
    // initialize operator stack and postfix length
    stack<string> operatorStack;
    int postfixLength = 0;

    // loop through infix expression
    for(int i = 0; i < length; i++){
        // if the current character is a number, add it to the postfix expression
        if(symbolType(infix[i]) == 2){
            postfix[postfixLength] = infix[i];
            postfixLength++;
        }
        // if the current character is a left parenthesis, push it to the operator stack
        else if(infix[i] == "("){
            operatorStack.push(infix[i]);
        }
        // if the current character is a right parenthesis, pop the operator stack until a left parenthesis is found
        else if(infix[i] == ")"){
            while(!operatorStack.empty() && operatorStack.top() != "("){
                postfix[postfixLength] = operatorStack.top();
                postfixLength++;
                operatorStack.pop();
            }
            // if a left parenthesis is not found, there is a mismatched parenthesis
            if(operatorStack.empty()){
                return 0;
            }
            // pop the left parenthesis
            operatorStack.pop();
        }
        // if the current character is an operator, pop the operator stack until an operator with a lower precedence is found
        else{
            while(!operatorStack.empty() && operatorStack.top() != "("){
                // if the current operator has a lower precedence than the top of the stack, pop the stack
                if(symbolType(infix[i]) < symbolType(operatorStack.top())){
                    postfix[postfixLength] = operatorStack.top();
                    postfixLength++;
                    operatorStack.pop();
                }
                // if the current operator has the same precedence as the top of the stack, pop the stack
                else if(symbolType(infix[i]) == symbolType(operatorStack.top())){
                    postfix[postfixLength] = operatorStack.top();
                    postfixLength++;
                    operatorStack.pop();
                }
                // if the current operator has a higher precedence than the top of the stack, break the loop
                else{
                    break;
                }
            }
            // push the current operator to the stack
            operatorStack.push(infix[i]);
        }
    }

    // pop the operator stack until it is empty
    while(!operatorStack.empty()){
        // if a left parenthesis is found, there is a mismatched parenthesis
        if(operatorStack.top() == "("){
            return 0;
        }
        postfix[postfixLength] = operatorStack.top();
        postfixLength++;
        operatorStack.pop();
    }

    return postfixLength;
}

//Main function to test infixToPostfix()
//Should convert 2 + 3 * 4 + ( 5 - 6 + 7 ) * 8
//            to 2 3 4 * + 5 6 - 7 + 8 * +
// int main()
// {
//     string infixExp[] = {"2", "+", "3", "*", "4", "+", "(",
//                          "5", "*", "6", "+", "7", ")", "*", "8"};
//     string postfixExp[15];
//     int postfixLength;

//     cout << "Infix expression: ";
//     for (int i=0; i<15; i++)
//     {
//         cout << infixExp[i] << " ";
//     }
//     cout << endl;
//     cout << "Length: 15" << endl << endl;

//     postfixLength = infixToPostfix(infixExp, 15, postfixExp);

//     cout << "Postfix expression: ";
//     for (int i=0; i<postfixLength; i++)
//     {
//         cout << postfixExp[i] << " ";
//     }
//     cout << endl;
//     cout << "Length: " << postfixLength << endl;
    
//     return 0;
// }