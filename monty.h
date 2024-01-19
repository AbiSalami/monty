/* monty.h */

#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <stddef.h>
#include <unistd.h>
#include <ctype.h>
#include <stdarg.h>
#include <sys/types.h>

extern int mode;


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

/* Function to parse Monty byte code files */
void parseFile(FILE *file);
void free_stack(stack_t **stack);
void free_close_exit(char *line, stack_t *stack, FILE *file);
char **tokenize(char *line);
void free_array(char **tokens);
int lenOfStack(const stack_t *head);
int selectOpcode(char **tokens, stack_t **stack, unsigned int line_fig);
int is_valid_integer(char *str);

/* Opcode functions */
void pushIt(stack_t **stack, unsigned int line_fig, int thing);
void pallIt(stack_t **stack, unsigned int line_fig);
void pintIt(stack_t **stack, unsigned int line_fig);
void nopera(stack_t **stack, unsigned int line_fig);
void popIt(stack_t **stack, unsigned int line_fig);
void swapIt(stack_t **stack, unsigned int line_fig);
void subOpera(stack_t **stack, unsigned int line_fig);
void addOpera(stack_t **stack, unsigned int line_fig);
void divOpera(stack_t **stack, unsigned int line_fig);
void mulOpera(stack_t **stack, unsigned int line_fig);
void modOpera(stack_t **stack, unsigned int line_fig);

   
#endif /* MONTY_H */
