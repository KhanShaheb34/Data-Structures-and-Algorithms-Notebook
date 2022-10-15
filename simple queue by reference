#include<stdio.h>
void enqueue(int[],int*);
void dequeue(int[],int*);
void display(int[],int*,int*);
#define MAX 5
int main()
{
    int a[MAX],front=-1,rear=-1,choice;
    printf("Enter 1 for enqueue\nEnter 2 for dequeue\nEnter 3 for display\nEnter 4 to exit");
    do
    {
        printf("\n\nEnter the choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:if(rear==MAX-1)
            {
                printf("Queue is Full");
                break;
            }
            else
            {
                enqueue(a,&rear);
                if(front==-1)
                {
                    front++;
                }
                 break;
            }


           case 2:if(front==-1 && rear==-1)
           {
            printf("Queue is Empty");
            break;
           }
           else
           {
              dequeue(a,&front);
            if(front==MAX)
            {
                front=rear=-1;
            }
            break;
           }


           case 3: display(a,&rear,&front);
           break;


           case 4: break;

        }
    }while(choice!=4);

}


void enqueue(int a[],int* rear)
{
    int x;
    printf("Enter the element x: ");
    scanf("%d",&x);
    (*rear)++;
    a[*rear]=x;
    
}


void dequeue(int a[],int* front)
{
    printf("The element which is dequeued is %d",a[*front]);
    (*front)++;
    
}


void display(int a[],int* rear,int* front)
{
    if((*front)==-1 && (*rear)==-1)
    {
        printf("Queue is empty");
    }
    else
    {
        int temp=(*front);
        while(temp!=MAX)
        {
            printf("%d ",a[temp]);
            temp++;
        }
    }
}
