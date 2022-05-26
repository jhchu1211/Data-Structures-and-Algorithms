// Infix2Postfix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "IntStack.h"
#include "OpStack.h"
#include <string>
using namespace std;

double compute(string postFix);
string convert_to_postFix(string infix);
int priority(char c);

int main()
{
    string infixExp;
    string postfixExp;
    cout << "\nEnter a Infix Expression :";
    getline(cin, infixExp);
    cout << "\nThe infix expression you entered is : " << infixExp;
    postfixExp = convert_to_postFix(infixExp);
    cout << "\nThe postfix is " << postfixExp;
    cout << "\nThe postfix expression is evaluated as " << compute(postfixExp);
    return 0;
}

int priority(char c)
{
    if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string convert_to_postFix(string infix)
{
    string postfix_exp = "";
    OpStack my_stack;
    char token; 
    for (int i = 0; i < infix.length(); i++)
    {
        token = infix[i];
        switch (token)
        {
        case ' ':break;
        case '(':my_stack.push(token); break;
        case ')':
            token = my_stack.pop();
            while (token != '(')
            {
                postfix_exp = postfix_exp.append(1, token);
                token = my_stack.pop();
            }
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
            if (my_stack.empty() || priority(token) > priority(my_stack.check()) )
            {
                my_stack.push(token);
            } 
            else
            {
                while (!my_stack.empty())
                {
                    postfix_exp = postfix_exp.append(1, my_stack.pop());
                }
                my_stack.push(token);
            }
            break;

        default:
            postfix_exp = postfix_exp.append(1, token);
        }
    }
    token = my_stack.pop();
    while (token != '\0')
    {
        postfix_exp = postfix_exp.append(1, token);
        token = my_stack.pop();
    }
    cout << postfix_exp.length() << "\n";
    return postfix_exp;
}

/*
string convert_to_postFix(string infix)
{
    string postfix_exp = "";
    OpStack my_stack;
    OpStack lowPrio;
    char token;
    char ptoken;
    int priority = 0; int notP = 0;
    int paren = 0;
    for (int i = 0; i < infix.length(); i++)
    {
        token = infix[i];
        if (i > 0)
            ptoken = infix[i - 1];
        switch (token)
        {
        case ' ':break;
        case '(':my_stack.push(token); priority = 3; break;
        case ')':
            token = my_stack.pop();
            while (token != '(')
            {
                postfix_exp = postfix_exp.append(1, token);
                token = my_stack.pop();
            }
            priority = 0;
            break;
        case '+':
        case '-':
            notP++;
            if (notP > 1)
            {
                ptoken = lowPrio.pop();
                postfix_exp = postfix_exp.append(1, ptoken);
                notP = 0;
            }
            lowPrio.push(token);
            notP++;
            break;
        case '*':
        case '/':
        case '%':
            my_stack.push(token);
            notP--;
            if(priority ==0)
            priority = 2;
            break;
        default:
            if (priority == 2)
            {
                postfix_exp = postfix_exp.append(1, token);
                token = my_stack.pop();
                postfix_exp = postfix_exp.append(1, token);
                priority = 0;
                notP++;
            }
            else //Normal 
            {
                postfix_exp = postfix_exp.append(1, token);
            }
        }
    }
    //take care of last token
    //token = my_stack.pop();
    token = lowPrio.pop();
    while (token != '\0')
    {
        postfix_exp = postfix_exp.append(1, token);
        token = lowPrio.pop();
    }
    cout << postfix_exp.length() << "\n";
    return postfix_exp;
}
*/
double compute(string postFix)
{
    IntStack opStack;
    char token;
    double answer = 0;
    int x;
    int y;
    for (int i = 0; i < postFix.length(); i++)
    {
        token = postFix[i];
        switch (token)
        {
        case '*':
            x = opStack.pop();
            y = opStack.pop();
            opStack.push(y * x);
            break;
        case '+':
            x = opStack.pop();
            y = opStack.pop();
            opStack.push(y + x);
            break;
        case '/':
            x = opStack.pop();
            y = opStack.pop();
            opStack.push(y / x);
            break;
        case '-':
            x = opStack.pop();
            y = opStack.pop();
            opStack.push(y - x);
            break;
        case '0':
            opStack.push(0);
            break;
        case '1':
            opStack.push(1);
            break;
        case '2':
            opStack.push(2);
            break;
        case '3':
            opStack.push(3);
            break;
        case '4':
            opStack.push(4);
            break;
        case '5':
            opStack.push(5);
            break;
        case '6':
            opStack.push(6);
            break;
        case '7':
            opStack.push(7);
            break;
        case '8':
            opStack.push(8);
            break;
        case '9':
            opStack.push(9);
            break;
        default:
            answer = opStack.pop();
        }
    }
    answer = opStack.pop();
    return answer;
}
