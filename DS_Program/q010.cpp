#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

// Function to check if a character is an operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Function to get the precedence of an operator
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0; // Default case for '('
}

// Function to convert infix expression to postfix
string infixToPostfix(const string& infix) {
    string postfix = "";
    stack<char> operators;

    for (char ch : infix) {
        // If character is an operand, append it to the postfix string
        if (isalnum(ch))
            postfix += ch;
        // If character is an opening parenthesis, push it to the stack
        else if (ch == '(')
            operators.push(ch);
        // If character is a closing parenthesis, pop operators from stack until a matching '(' is found
        else if (ch == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Pop '('
        }
        // If character is an operator
        else if (isOperator(ch)) {
            // Pop operators from stack with higher or equal precedence and append them to the postfix string
            while (!operators.empty() && precedence(ch) <= precedence(operators.top())) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(ch); // Push current operator to stack
        }
    }

    // Pop remaining operators from stack and append them to the postfix string
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

int main() {
    string infix = "a+b*(c-d)/e";
    string postfix = infixToPostfix(infix);
    cout << "Infix expression: " << infix << endl;
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}
