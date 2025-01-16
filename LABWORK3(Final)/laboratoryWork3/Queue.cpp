#include "CircleBuffer.h"
#include "Queue.h"
#include <stdexcept>

using namespace std;

Queue* CreateQueueByBuffer()
{
    Queue* queue = new Queue;
    queue->Cbuffer = CreateCircleBuffer();
    return queue;
}


void Enqueue(Queue* queue, int item) 
{
    AddElement(queue->Cbuffer, item);
}

int Dequeue(Queue* queue) 
{
    return Remove(queue->Cbuffer);
}

void FreeQueue(Queue* queue)
{
    if (queue == nullptr)
    {
        return;
    }

    delete queue->Cbuffer;  
    queue->Cbuffer = nullptr; 
}