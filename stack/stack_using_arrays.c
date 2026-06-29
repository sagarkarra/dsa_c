#include <stdio.h>
#include <stdlib.h>
#define max 10
void push(int);
void pop(void);
int peek(void);
void disp(void);
void overflow(void);
void underflow(void);
int stack[max],top=-1;
int main()
{
    int ch,data;
    do
    {
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.peek\n");
        printf("4.disp\n");
        printf("5.overflow\n");
        printf("6.underflow\n");
        printf("7.exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter data to push:");
            scanf("%d",&data);
            push(data);
            break;
            case 2:
            pop();
            break;
            case 3:
            printf("Top element is %d\n",peek());
            break;
            case 4:
            disp();
            break;
            case 5:
            overflow();
            break;
            case 6:
            underflow();
            break;
            case 7:
            exit(0);
            default:
            printf("Invalid choice entered\n");
        }
    }
    while (ch!=7);
    return 0;
}
    void underflow(void)
    {
        if(top==-1)
        {
            printf("Stack is underflow\n");
        }
        else
        {
            printf("Stack is not underflow\n");
        }
    }
    void overflow(void)
    {
        if(top==max-1)
        {
            printf("Stack is overflow\n");
        }
        else
        {
            printf("Stack is not overflow\n");
        }
    }
    void push(int item)
    {
        if(top==max-1)
        {
            printf("Stack overflow\n");
        }
        else
        {
            stack[++top]=item;
            printf("Element is pushed succesfully\n");
        }
    } 
    void pop(void)
    {
        if(top==-1)
        {
            printf("Stack underflow\n");
        }
        else
        {
            printf("Popped element is %d\n",stack[top--]);
        }
    }
    int peek(void)
    {
        if(top==-1)
        {
            printf("Stack is underflow\n");
        }
        else
        {
            return stack[top];
        }
    }
    void disp(void)
    {
        int i;
        for(i=top;i>=0;i--)
        {
            printf("%d",stack[i]);
        }
    }