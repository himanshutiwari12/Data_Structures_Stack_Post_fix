#include <stdio.h>
#include <stdbool.h>

unsigned char pop_from_stack(void);
void push_to_stack(unsigned char val);
//expression (X AND Y) OR (A AND B)
//XY ANDAB AND OR
#define AND '&'
#define OR '|'

#define FALSE false 
#define TRUE true 
typedef struct
{
    unsigned char stack[10];
    signed int current_ptr; 
}stack_hold;

static stack_hold operand_stack = {.stack ="\0",.current_ptr = -1};

int main()
{
    unsigned char  array[10] = {FALSE, FALSE, AND,TRUE ,TRUE,AND, OR};
    unsigned char temp1;
    unsigned char temp2;
    
     for(int i = 0; i < 7; i++)//upto number of cases and operators
     {
        if((array[i] != AND)&&(array[i] != OR))
        {
            push_to_stack(array[i]);
        }
        else if(array[i] == AND)
        {
            temp1 = pop_from_stack();
            temp2 = pop_from_stack();
            push_to_stack(temp1 & temp2);
        }
        else
        {
            temp1 = pop_from_stack();
            temp2 = pop_from_stack();
            push_to_stack(temp1 | temp2);
        }
         
     }  
    printf(" result %d\n",operand_stack.stack[operand_stack.current_ptr]);        
    

    return 0;
}

void push_to_stack(unsigned char val)
{
    operand_stack.current_ptr++;
    operand_stack.stack[operand_stack.current_ptr] = val;
}

unsigned char pop_from_stack(void)
{ 
    unsigned char ret;
    ret = operand_stack.stack[operand_stack.current_ptr];
    operand_stack.stack[operand_stack.current_ptr] = 0xff;
    operand_stack.current_ptr--;
    return ret;
}
