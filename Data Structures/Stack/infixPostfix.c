#include <stdio.h>
#include <ctype.h>

int st[100], size = 100, top = -1;
char infix[100], postfix[100];

// push pop operations
void push(char val)
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
    else if (p == '(')
        return 1;
    else
        return 0;
}

// Infix to postfix
void infixPostfix()
{
    char x, y;
    int i = 0, j = 0;

    while (infix[i] != '\0')
    {
        x = infix[i];
        if (x == '(')
        {
            push(x);
        }
        
        else if (isalpha(x) || isdigit(x))
        {
            postfix[j] = x;
            j++;
        }
        else if (x == '/' || x == '*' || x == '%' || x == '+' || x == '-')
        {
            if (top == -1 || priority(x) > priority(st[top]))
            {
                push(x);
            }
            else
            {
                while (top != -1 && priority(x) <= priority(st[top]))
                {
                    y = pop();
                    postfix[j] = y;
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
                postfix[j] = y;
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
        postfix[j] = y;
        j++;
    }
}

void evaluate()
{
    char x;
    int z;
    int i = 0;
    float op1,op2,result;

    while (postfix[i] != '\0')
    {
        x=postfix[i];
        if(isalpha(x) || isdigit(x))
        {
            z=(float)x-'0';
            push(z);
        }
        else if(x=='%'||x=='/'||x=='*'||x=='+'||x=='-')
        {
            
            op2=pop();
            op1=pop();
            
            if(x=='-')
                result=op1-op2;
            else if(x=='+')
                result=op1+op2;
            else if(x=='*')
                result=op1*op2;
            else if(x=='%')
                result=(int)(op1)%(int)op2;
            else if(x=='/')
                result=op1/op2;
            else {}
            push(result);
        }
        else{}

        i++;
    }

    printf("\nRESULT:%d\n",st[top]);

}


void main()
{
    printf("Enter infix expression:");
    scanf("%s", infix);
    printf("%s", infix);
    printf("\n");
    infixPostfix();
    printf("%s", postfix);
    evaluate();
}