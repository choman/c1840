/* Chad Homan
   $Author: ff006 $
   $Date: 1994/11/18 05:24:37 $
   $Source: /u/ff006/hw10/RCS/c12n12.c,v $
   $Id: c12n12.c,v 1.7 1994/11/18 05:24:37 ff006 Exp ff006 $
   $Revision: 1.7 $
   Matt Payne
   CSCI-1840
   ff006@thor
   choman@corona @guinness or @s-cwis or @ccsn.edu
*/

/*      This program convererts a INFIX algorithm to a POSTFIX algorithm
	For example, the INFIX algorithm of
			(6 + 2) * 5 - 8 / 4
	would be converted to POSTFIX and printed to the screen to look as 
			6 2 + 5 * 8 4 / -
	this is the POSTFIX algorithm that this program should also comeup
	with as a final answer
*/ 

/* dynamic stack program */
#include <stdio.h>
#include <stdlib.h>

struct stackNode {  /* self-referential structure */
   char data;
   struct stackNode *nextPtr;
};

typedef struct stackNode STACKNODE;
typedef STACKNODE *STACKNODEPTR;

void push(STACKNODEPTR *, char);
char stackTop(STACKNODEPTR);
int isOperator(char);
char pop(STACKNODEPTR *);
int precedence(char, char);
char isEmpty(STACKNODEPTR);
void convertToPostfix(char infix[], char postfix[]);
void printStack(STACKNODEPTR);

main(){

	char infix[20], postfix[20];
	char value;
	int p;
	
        printf("Enter in an infix equation: ");
	    while ((infix[p++] = getchar()) != '\n');
		infix[--p] = '\0';
	printf("\n");
	convertToPostfix(infix, postfix);
	printf("\n The postfix is %s", postfix);
	printf("\n");
	return 0;

} /* main */

void convertToPostfix(char infix[], char postfix[])

{
   STACKNODEPTR stackPtr = NULL;  /* points to the stack top */
   int i, x, higher;
   char popValue;

           /* push value onto stack */
            		push(&stackPtr, '(');
			strcat(infix,")");
	/* coversion */
		for (x = 0, i = 0; stackTop(stackPtr); x++){
		   if (isdigit(infix[x]))
			postfix[i++] = infix[x];
		   	else if (infix[x] == '(')
		  	    {  	
            		    push(&stackPtr, infix[x]); 
			    }
		         else if (isOperator(infix[x]))
			    {
			    higher = 1;
			    while (higher)
			     {
			       if (isOperator(stackTop(stackPtr)))
			         if (precedence(stackTop(stackPtr), infix[x]))
				  {
				     postfix[i++] = pop(&stackPtr);
				   }
				 else
				      higher = 0; /* false */
			        else
			              higher = 0; /* false */
				}
            		    push(&stackPtr, infix[x]);
			}
		     else if ( infix[x] == ')')
			{
			while ((popValue = pop(&stackPtr)) != '(')
			   {
				postfix[i++] = popValue;
			   }
			 } /* else if infix */
			}
		     postfix[i] = '\0';
		} /* covert */

/* Is Operator */

/* checks to see if operator */
int isOperator(char c)
{
	if ((c == '+') ||
	    (c == '-') ||
	    (c == '*') ||
	    (c == '/') ||
	    (c == '%') ||
	    (c == '^'))
	   return 1; /* true */
	else
	   return 0; /* false */

} /* is operator */ 
	
/* checks precedence */
int precedence(char oper1, char oper2)
{	
	if (oper1 == '^')
	     return 1;
	  else if (oper2 =='^')
	     return 0;
	  else if (oper1 == '*' || oper1 == '/')
	     return 1;
	  else if (oper1 == '+' || oper1 == '-')
	     if (oper2 == '*' || oper2 == '/')
	         return 0;
	  else return 1;

	return 0;
} /* precedence */


/* Insert a node at the stack top */
void push(STACKNODEPTR *topPtr, char info)
{
   STACKNODEPTR newPtr;

   newPtr = malloc(sizeof(STACKNODE));
   if (newPtr != NULL) {
      newPtr->data = info;
      newPtr->nextPtr = *topPtr;
      *topPtr = newPtr;
   }
   else
      printf("%c not inserted. No memory available.\n", info);
}

/* Remove a node from the stack top */
char pop(STACKNODEPTR *topPtr)
{
   STACKNODEPTR tempPtr;
   char popValue;

   tempPtr = *topPtr;
   popValue = (*topPtr)->data;
   *topPtr = (*topPtr)->nextPtr;
   free(tempPtr);
   return popValue;
}

/* Print the stack */
void printStack(STACKNODEPTR currentPtr)
{
   if (currentPtr == NULL)
      printf("The stack is empty.\n\n");
   else {
      printf("The stack is:\n");

      while (currentPtr != NULL) {
         printf("%s---> ", currentPtr->data);
         currentPtr = currentPtr->nextPtr;
      }

      printf("NULL\n\n");
   }
}

/* Is the stack empty? */
char isEmpty(STACKNODEPTR topPtr)
{
   return topPtr == NULL;
}

/* Show what is on top w/o popping */

char stackTop(STACKNODEPTR topPtr)
{
	if (!isEmpty(topPtr))
		return topPtr->data;
	else
		return 0;
} /* stackTop */

