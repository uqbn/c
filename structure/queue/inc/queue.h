#ifndef __QUEUE_H__
#define __QUEUE_H__

typedef int queue_t;
typedef struct Queue Queue;
struct Queue
{
    queue_t data;
    struct Queue *next;
};

extern Queue *queue_init(void);
extern void queue_free(Queue *_ph);

extern int queue_push(Queue *_ph, queue_t _data);
extern int queue_pop(Queue *_ph, queue_t *_dest);
extern int queue_front(Queue *_ph, queue_t *_dest);
extern unsigned int queue_len(Queue *_ph);

#endif