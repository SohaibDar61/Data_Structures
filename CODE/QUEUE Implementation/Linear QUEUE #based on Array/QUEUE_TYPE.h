
#ifndef _QUEUE_H
#define _QUEUE_H

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef signed char sint8_t;
typedef signed short sint16_t;
typedef signed int sint32_t;

typedef enum{
    Queue_Empty,
    Queue_Full,
    Queue_NOTFUll,
    DONE
}STATUS_Queue;

#endif
