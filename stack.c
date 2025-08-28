#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 2
int st[size];

int top=-1;

void push(int item)
{

  top++;
  st[top] = item;
}
  int peek()
  {
  
    return st[top]; 
  } 
int pop()
{
    int item;
	item = st[top];
	top--;
	return(item);
}
void display()
{
	int i;
	for(i=top;i>=0;i--)
	printf("\n%d",st[i]);
}
 
int main()
{
	 int item, choice;
	 char ans;
	 printf("\n\timplementation of stack");
	 do {
	 	printf("\nMain menu");
	 	printf("\n1.Push \n2.Pop \n3.Peek \n4.Display \n5.Exit");
	 	printf("\nEnter your choice");
	 	scanf("%d", &choice);
	 	switch(choice) {
	 		case 1:
	 			if(top<size-1)
	 			{
	 				printf("\nEnter the item to be pushed");
	 				scanf("%d",&item);
	 				push(item);
				 }
				else
				 printf("overflow");
				 break;
				 
		        case 2:
				     if(top==-1)
				       printf("underflow");
			    else
				{
					 	item=pop();
					 	printf("\nThe popped element is %d",item);
				}
				 break;
		         case 3:
				if(top==-1)
				 printf("underflow");
				else
				{
					item=peek();
					printf(" the top most element is %d",item);
				}
			break;
			case 4:
				display();
				break;
			case 5:
					exit(0);
			}
			printf("\nDo you want to continue?");
			 ans = getche();
	    } while (ans == 'Y'  || ans == 'Y');
return 0;
}
					 	
		 
	 


