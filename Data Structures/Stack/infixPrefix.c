#include <stdio.h>
#include <ctype.h>

char st[50], infix[50], prefix[50];
int top = -1, size = 50;
void push(int val)
{
    if (top == size - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        top++;
        st[top] = val;
    }
}

char pop()
{
    char x;
    if (top == -1)
    {
        printf("Stack empty\n");
    }
    else
    {
        x = st[top];
        top--;
    }
    return x;
}

int priority(char p)
{
    if (p == '/' || p == '*' || p == '%')
        return 3;
    else if (p == '+' || p == '-')
        return 2;
    else if ('(')
        return 1;
    else
        return 0;
}

void revInfix(char str[])
{
    int i = 0;
    char x, y;
    while (str[i] != '\0')
    {
        x = str[i];
        i++;
        push(x);
    }
    i = 0;
    while (top != -1)
    {
        y = pop();
        if (y == '(')
        {
            str[i] = ')';
        }
        else if (y == ')')
        {
            str[i] = '(';
        }
        else
        {

            str[i] = y;
        }
        i++;
    }
    i = 0;
    while (str[i] != '\0')
    {
        printf("%c", str[i]);
        i++;
    }
}

void infixPrefix()
{
    int i = 0, j = 0;
    char x, y;
    while (infix[i] != '\0')
    {
        x = infix[i];
        if (isalpha(x) || isdigit(x))
        {
            prefix[j] = x;
            j++;
        }
        else if (x == '(')
        {
            push(x);
        }
        else if (x == '+' || x == '-' || x == '/' || x == '%' || x == '*')
        {
            if (top == -1 || (priority(st[top]) <= priority(x)))
            {
                push(x);
            }
            else
            {
                while (top != -1 && priority(x) < priority(st[top]))
                {
                    y = pop();
                    prefix[j] = y;
                    j++;
                }
                push(x);
            }
        }
        else if (x == ')')
        {
            while (st[top] != '(')
            {
                y = pop();
                prefix[j] = y;
                j++;
            }
            y = pop();
        }
        else
        {
            printf("error");
        }
        i++;
    }
    while (top != -1)
    {
        y = pop();
        prefix[j] = y;
        j++;
    }
    int z = 0;
    while (prefix[z] != '\0')
    {
        printf("%c", prefix[z]);
        z++;
    }
}

float evaluate()
{
    int i = 0, z;
    char x;
    float op1, op2, result;
    while (prefix[i] != '\0')
    {
        x = prefix[i];
        if (isdigit(x) || isalpha(x))
        {
            z = (float)x - '0';
            push(z);
        }
        else if (x == '+' || x == '-' || x == '/' || x == '*' || x == '%')
        {
            op1 = pop();
            op2 = pop();
            if (x == '-')
                result = op1 - op2;
            else if (x == '+')
                result = op1 + op2;
            else if (x == '*')
                result = op1 * op2;
            else if (x == '%')
                result = (int)(op1) % (int)op2;
            else if (x == '/')
                result = op1 / op2;
            else
            {
            }
            push(result);
        }
        else
        {
        }
        i++;
    }

    return result;
}

void main()
{
    float result;
    printf("\nenter infix exp:");
    scanf("%s", infix);
    printf("\n");
    printf("REVERSED INFIX:");
    revInfix(infix);
    printf("\n");
    printf("REVERSED PREFIX:");
    infixPrefix();
    printf("\n");
    result = evaluate();
    printf("\n");
    printf("PREFIX EXPRESSION:");
    revInfix(prefix);
    printf("\n\n");
    printf("final result:%f\n\n", result);
}