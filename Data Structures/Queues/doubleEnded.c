#include <stdio.h>

int q[5], size = 5, front = -1, rear = -1;
void enqueueRear(int val)
{
    if (rear == -1)
    {
        front++;
        rear++;
        q[rear] = val;
    }
    else if ((rear + 1) % size == front)
    {
        printf("Queue full\n");
    }
    else
    {
        rear = (rear + 1) % size;
        q[rear] = val;
    }
}

void enqueueFront(int val)
{
    if (front == -1)
    {
        front = 0;
        rear = 0;
        q[front] = val;
    }
    else if (front == (rear + 1) % size)
    {
        printf("Queue full");
    }
    else
    {
        front = (front + size - 1) % size;
        q[front] = val;
    }
}

void dequeueFront()
{
    int val = -1;
    if (front == -1)
    {
        printf("Queue Empty\n");
    }
    else if (front == rear)
    {
        val = q[front];
        front = -1;
        rear = -1;
        printf("%d is deleted\n", val);
    }
    else
    {
        val = q[front];
        front = (front + 1) % size;
        printf("%d is deleted\n", val);
    }
}

void dequeueRear()
{
    int val = -1;
    if (rear == -1)
    {
        printf("Queue empty\n");
    }
    else if (front == rear)
    {
        val = q[rear];
        rear = -1;
        front = -1;
        printf("Deleted value is %d", val);
    }
    else
    {
        val = q[rear];
        rear = (rear + size - 1) % size;
    }
}

void display()
{
    int i;
    i=front;
    while(i!=rear)
    {
        printf("%d\n",q[i]);
        i=(i+1)%size;
    }
    printf("%d\n",q[rear]);
}

void main()
{
    int cmain, ci, co;
    printf("---main entered---\n");
    do
    {
        printf(" 1.Input restricted \n 2.Output restricted\n 3.Display\n 4.exit\n");
        scanf("%d", &cmain);
        switch (cmain)
        {
        case 1:
        {
            printf("---Input restricted entered---\n");
            do
            {

                printf(" 1.input rear \n 2.delete front\n 3.delete rear\n 4.exit\n");
                scanf("%d", &ci);

                switch (ci)
                {
                case 1:
                {
                    int val;
                    printf("\nEnter input:");
                    scanf("%d", &val);
                    enqueueRear(val);
                    printf("\n");
                    break;
                }
                case 2:
                {
                    dequeueFront();
                    break;
                }
                case 3:
                {
                    dequeueRear();
                    break;
                }
                case 4:
                {
                    printf("Exited input restriction\n");
                    break;
                }
                default:
                {
                    printf("wrong choice input\n");
                    break;
                }
                }

            } while (ci != 4);
            break;
        }

        case 2:
        {
            printf("---Output restricted entered---\n");
            do
            {
                printf(" 1.input rear \n 2.delete front\n 3.input front\n 4.exit\n");
                scanf("%d", &co);

                switch (co)
                {
                case 1:
                {
                    int val;
                    printf("\nEnter input:");
                    scanf("%d", &val);
                    enqueueRear(val);
                    break;
                }
                case 2:
                {
                    dequeueFront();
                    break;
                }
                case 3:
                {
                    int val;
                    printf("\nEnter input:");
                    scanf("%d", &val);
                    enqueueFront(val);
                    break;
                }
                case 4:
                {
                    printf("---exited output restriction---\n");
                    break;
                }
                default:
                {
                    printf("wrong choice output\n");
                    break;
                }
                }
            } while (co != 4);
            break;
        }

        case 3:
        {
            display();
            break;
        }

        case 4:
        {
            printf("exited\n");
            break;
        }

        default:
        {
            printf("Wrong choice main\n");
            break;
        }
        }
    } while (cmain != 4);
}