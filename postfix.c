#include <stdio.h>
#include <ctype.h>
#define MAX 100

float st[MAX];
int top = -1;

void push(float st[], float val);
float pop(float st[]);
float evaluatePostfixExp(char exp[]);

int main()
{
    float val;
    char exp[100];

    printf("\nEnter any postfix expression: ");
    fgets(exp, sizeof(exp), stdin); // safer than gets()

    val = evaluatePostfixExp(exp);
    printf("\nValue of the postfix expression = %.2f\n", val);

    return 0;
}

float evaluatePostfixExp(char exp[])
{
    int i = 0;
    float op1, op2, value;

    while (exp[i] != '\0' && exp[i] != '\n')  // ignore newline
    {
        if (isdigit(exp[i]))
        {
            push(st, (float)(exp[i] - '0'));  // convert char -> int -> float
        }
        else
        {
            op2 = pop(st);
            op1 = pop(st);

            switch (exp[i])
            {
            case '+':
                value = op1 + op2;
                break;
            case '-':
                value = op1 - op2;
                break;
            case '/':
                value = op1 / op2;
                break;
            case '*':
                value = op1 * op2;
                break;
            case '%':
                value = (int)op1 % (int)op2;
                break;
            default:
                continue; // skip spaces or invalid chars
            }
            push(st, value);
        }
        i++;
    }
    return pop(st);
}

void push(float st[], float val)
{
    if (top == MAX - 1)
        printf("\nSTACK OVERFLOW");
    else
    {
        top++;
        st[top] = val;
    }
}

float pop(float st[])
{
    float val = -1;
    if (top == -1)
        printf("\nSTACK UNDERFLOW");
    else
    {
        val = st[top];
        top--;
    }
    return val;
}


