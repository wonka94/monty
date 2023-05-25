#ifndef header_h
#define header_h
#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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

void add(stack_t **s, unsigned int ln);
void sub(stack_t **s, unsigned int ln);
void mul(stack_t **s, unsigned int ln);
void mod(stack_t **s, unsigned int ln);
void divide(stack_t **s, unsigned int ln);

void free_stack(stack_t *s);

void nop(stack_t **s, unsigned int ln);

void pall(stack_t **s, unsigned int ln);
void pchar(stack_t **s, unsigned int ln);
void pop(stack_t **s, unsigned int ln);
void pint(stack_t **s, unsigned int ln);
void push(stack_t **top, unsigned int ln);
void pstr(stack_t **s, unsigned int ln);
void rotl(stack_t **s, unsigned int ln);
void rotr(stack_t **s, __attribute__((unused)) unsigned int ln);
void swap(stack_t **s, unsigned int ln);

char *get_command(char *c);
int get_value(char *c);

#endif