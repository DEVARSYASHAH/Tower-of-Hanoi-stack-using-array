#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int p1[90000000],p2[90000000],p3[90000000],top1=0,top2=0,top3=0;
void push_p1(int);
void push_p2(int);
void push_p3(int);
int pop_p1(void);
int pop_p2(void);
int pop_p3(void);
void display_p1(void);
void display_p2(void);
void display_p2(void);
int main()
{
	int n,i,x,a,b;
	printf("|*|Tower of hanoi|*|");
	printf("\nEnter the no. of Disks(recomended 1 to 30): ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	    push_p1(n-i);
	}
	x=pow(2,n)-1;
	display_p1();
	display_p2();
	display_p3();
	printf("---------------------------------------");
	for(i=1;i<=x;i++)
	{
		if(i%3==1)
		{
	    	a=pop_p1();
	 	    b=pop_p3();
		    if(a==0)
			{
				push_p1(b);
			}
			else if(b==0)
			{
			    push_p3(a);
			}
			else if(a>b)
			{
				push_p1(a);
				push_p1(b);
			}
			else
			{
				push_p3(b);
				push_p3(a);
			}
			display_p1();
			display_p2();
			display_p3();
			printf("---------------------------------------");
			continue;
		}
        else if(i%3==2)
		{
			a=pop_p1();
			b=pop_p2();
			if(a==0)
        	{
        	    push_p1(b);
        	}
        	else if(b==0)
        	{
        		push_p2(a);
			}	
        	else if(a>b)
        	{
        	    push_p1(a);
        	    push_p1(b);
        	}
        	else
        	{
            	push_p2(b);
            	push_p2(a);
        	}	
        	display_p1();
        	display_p2();
        	display_p3();
        	printf("---------------------------------------");
        	continue;
    	}		
    	else if(i%3==0)
    	{
			a=pop_p2();
			b=pop_p3();
			if(a==0)
	        {
	            push_p2(b);
	        }
	        else if(b==0)
	            push_p3(a);
	        else if(a>b)
	        {
	            push_p2(a);
	            push_p2(b);
	        }
	        else
	        {
	            push_p3(b);
	            push_p3(a);
	        }
	        display_p1();
	        display_p2();
	        display_p3();
	        printf("---------------------------------------");
	        continue;
	    }
	}
	printf("\n---------------------------------------");
	printf("\nCompleted\nFinal Position\n");
	printf("---------------------------------------");
	display_p1();
	display_p2();
    display_p3();
    printf("---------------------------------------");
    printf("\n Total steps to shift %d disk from Tower 1 to Tower 3 is %d",n,x);
    return 0;
}
void push_p1(int a)
{
	if(a!=0)
	{
		p1[top1++]=a;
	}
}
int pop_p1(void)
{
	if(top1==0)
	{
		return 0;
	}	
	else
	{
		return p1[--top1];
	}
}
void display_p1(void)
{
	int i;
	printf("\nTower 1 ->> |");
	if(top1==0)
	{
		printf("Empty|");
		printf("\n");
	}
	else
	{
		for(i=0;i<top1;i++)
		{
			printf("%d|",p1[i]);
		}
		printf("\n");
	}
}
void push_p2(int a)
{
	if(a!=0)
	{
		p2[top2++]=a;
	}
}
int pop_p2(void)
{
	if(top2==0)
	{
		return 0;
	}
	else
	{
		return p2[--top2];
	}
}
void display_p2(void)
{
	int i;
	printf("Tower 2->> |");
	if(top2==0)
	{
		printf("Empty|");
		printf("\n");
	}
	else
	{
		for(i=0;i<top2;i++)
		{
			printf("%d|",p2[i]);
		}
		printf("\n");
	}
}
void push_p3(int a)
{
	if(a!=0)
	{
		p3[top3++]=a;
	}
}
int pop_p3(void)
{
	if(top3==0)
	{
		return 0;
	}
	else
	{
		return p3[--top3];
	}
}
void display_p3(void)
{
	int i;
	printf("Tower 3 ->> |");
	if(top3==0)
	{
		printf("Empty|");
		printf("\n");
	}
	else
	{
		for(i=0;i<top3;i++)
		{
			printf("%d|",p3[i]);
		}
		printf("\n");
	}
}
