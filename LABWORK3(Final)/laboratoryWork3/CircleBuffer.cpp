#include "CircleBuffer.h"
#include <stdexcept>

using namespace std;

CircleBuffer* CreateCircleBuffer()
{
    CircleBuffer* buffer = new CircleBuffer();
    buffer->BufferSize = SIZE;
    buffer->Buffer = new int[buffer->BufferSize];
    buffer->Head = 0;
    buffer->Tail = 0;
    buffer->Count = 0;
    return buffer;
}

void AddElement(CircleBuffer* buffer, int item)
{
    if (buffer->Count == buffer->BufferSize)
    {
        buffer->Head = (buffer->Head + 1) % buffer->BufferSize;
    }
    else
    {
        buffer->Count++;
    }

    //buffer->Buffer[buffer->Tail] = item;
    //buffer->Tail = (buffer->Tail + 1) % buffer->BufferSize;
    buffer->Buffer[buffer->Tail] = item;
    buffer->Tail = (buffer->Head - 1 + buffer->BufferSize) % buffer->BufferSize; 
}

int Remove(CircleBuffer* buffer)
{
    if (buffer->Count == 0)
    {
        return 0;
    }

    else
    {
        int value = buffer->Buffer[buffer->Head];
        buffer->Head = (buffer->Head + 1) % buffer->BufferSize;
        buffer->Count--;
        return value;
    }
}

int FreeSpace(CircleBuffer* buffer)
{
    return buffer->BufferSize - buffer->Count;
}

int OccupiedSpace(CircleBuffer* buffer)
{
    return buffer->Count;
}

void FreeBuffer(CircleBuffer* buffer)
{
    delete[] buffer->Buffer;
    delete buffer;
}