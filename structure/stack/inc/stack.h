#ifndef __STACK_H__
#define __STACK_H__

typedef int stackn_t;
typedef struct Stackn
{
    stackn_t n;
    struct Stackn *next;
} Stackn;

typedef struct Stacks
{
    char *str;
    struct Stacks *next;
} Stacks;

//stack_t
Stackn *stackn_init(void);
void stackn_free(Stackn *_ph);

int stackn_push(Stackn *_ph, stackn_t _data);
int stackn_pop(Stackn *_ph, stackn_t *_dst);
int stackn_top(Stackn *_ph, stackn_t *_dst);
unsigned int stackn_len(Stackn *_ph);
int stackn_empty(Stackn *_ph);
unsigned int stackn_dispaly(Stackn *_ph);
unsigned int stackn_dispalyn(Stackn *_ph, unsigned int _count);

//char *
Stacks *stacks_init(void);
void stacks_free(Stacks *_ph);

int stacks_push(Stacks *_ph, char *_str);
int stacks_pop(Stacks *_ph, char **_dst);
int stacks_top(Stacks *_ph, char **_dst);
unsigned int stacks_len(Stacks *_ph);
int stacks_empty(Stacks *_ph);
unsigned int stacks_dispaly(Stacks *_ph);
unsigned int stacks_dispalyn(Stacks *_ph, unsigned int _count);

#endif