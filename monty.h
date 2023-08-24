#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 2000809L


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>


/* DATA STRACTURES*/

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - this is global struct
 * @count_line: counts the line
 * @arg: argument count
 * buff: the buffer for store instructions
 * @bytecode_file: file pointer
 * @head: the head of the list
 *
 * Descript: a global variable
 */

typedef struct global_s
{
	int q_s_alt;
	unsigned int count_line;
	char *arg;
	char *buff;
	FILE *bytecode_file;
	stack_t *head;
} global_data_t;

extern global_data_t globe;

/* file handle */
int ini_file(int argc, char **argv);
FILE *file_open(char *name_f);

/* instruction handle */
char *rd_line(FILE *bytecode_file);

/* Global variable for the stack head */
void global_data(void);
void trm_global(void);

stack_t *stack_head = NULL;

/* function selector */
void(*get_opcode(char *opc))(stack_t **stack, unsigned int line_number);

/* opcode function */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stcak, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stcak, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

/* doubly linked list */
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void free_dlistint(stack_t *head);

#endif 
