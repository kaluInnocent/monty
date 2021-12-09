#ifndef __MONTY__H
#define __MONTY__H
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>


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
* struct data_t - argument for current opcode
* @data: default satck and queue
* @arg: Argument containing strings
* Description: global structure used to pass data around the functions easily
*/
typedef struct data_t
{
	int data;
	char *arg;
} data_s;

data_s global;
extern int status;

#define OPERATORS {\
	{"push", push},\
	{"pall", pall},\
	{"pint", pint},\
	{"pop", pop},\
	{"swap", swap},\
	{"nop", nop},\
	{"div", div_node},\
	{"mul", mul_node},\
	{"add", add_node},\
	{"sub", sub_node},\
	{"mod", mod_node},\
	{"pchar", pchar},\
	{"pstr", pstr},\
	{"rotl", rotl},\
	{"rotr", rotr},\
	{"stack", push},\
	{"queue", push},\
	{NULL, NULL} \
}

/* operators */
void op_func(stack_t **node, char *str, unsigned int);
void pall(stack_t **, unsigned int);
void push(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);
void pint(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);
void pchar(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
void rotr(stack_t **, unsigned int);
void pstr(stack_t **, unsigned int);

/* calculators */
void add_node(stack_t **, unsigned int);
void sub_node(stack_t **, unsigned int);
void div_node(stack_t **, unsigned int);
void mul_node(stack_t **, unsigned int);
void mod_node(stack_t **, unsigned int);

/* Doubly linked list operations */
stack_t *add_end_node(stack_t **, int n);
void delete_end_node(stack_t **);
void free_list(stack_t *);
stack_t *make_node(int);
stack_t *queue(stack_t **, int);

/* others */
int is_num(char *str);
int is_digit(char *str);
#endif
