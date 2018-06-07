//Shiv Pratap Singh Pratap Singh (iit2014121@iiita.ac.in)

/*P4.11 Program for conversion of infix to postfix and evaluation of postfix.
It will evaluate only single digit numbers*/

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

#define BLANK ' '
#define TAB '\t'
#define MAX 1000000

void push(long int symbol);
long int pop();
void infix_to_postfix();
//long int eval_post();
int priority(char symbol);
int isEmpty();
int white_space(char symbol);

char infix[MAX], postfix[MAX];
long int stack[MAX];
int top;

int main()
{
	long int value,i;
	scanf("%d", &i);
	
	top=-1;
	while(i--){
//	printf("Enter infix : ");
	scanf("%s",infix);
	infix_to_postfix();
	printf("%s\n",postfix);
//	value=eval_post();
//	printf("Value of expression : %ld\n",value);
}
return 0;
}/*End of main()*/

void infix_to_postfix()
{
	unsigned int i,p=0;
	char next;
	char symbol;	
	for(i=0;i<strlen(infix);i++)
	{
		symbol=infix[i];
		if(!white_space(symbol))
		{
			switch(symbol)
			{
			case '(':
				push(symbol);
				break;
			case ')':
				while((next=pop())!='(')
					postfix[p++] = next;
				break;
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
			case '^':
				while( !isEmpty( ) &&  priority(stack[top])>= priority(symbol) )
					postfix[p++]=pop();
				push(symbol);
				break;
			default: /*if an operand comes*/
			     postfix[p++]=symbol;
			}
		}
	}
	while(!isEmpty( )) 
		postfix[p++]=pop();
	postfix[p]='\0'; /*End postfix with'\0' to make it a string*/
}/*End of infix_to_postfix()*/

/*This function returns the priority of the operator*/
int priority(char symbol)
{
	switch(symbol)
	{
	case '(':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
	case '%':
		return 2;
	case '^':
		return 3;
	default :
		return 0;
	}
}/*End of priority()*/

void push(long int symbol)
{
	if(top>MAX)
	{
		printf("Stack overflow\n");
		exit(1);
	}
	stack[++top]=symbol;
}/*End of push()*/

long int pop()
{
	if( isEmpty() )
	{
		printf("Stack underflow\n");
		exit(1);
	}
	return (stack[top--]);
}/*End of pop()*/
int isEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}/*End of isEmpty()*/

int white_space(char symbol)
{
	if( symbol == BLANK || symbol == TAB )
		return 1;
	else
		return 0;
}/*End of white_space()*/