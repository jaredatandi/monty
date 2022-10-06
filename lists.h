#ifndef LISTS_H
#define LISTS_HLISTS_H

void push_h(stack_t **stack, unsigned int line_number);
int count_ws(char *str);
char **tokens(char *str);
void run_cmd(args_a *args);
void (*get_func(char **parse))(stack_t **, unsigned int);
void release(char **args);
void release_all(int all);
void free_stack(char *stack);

#endif /* LISTS_HLISTS_H */
