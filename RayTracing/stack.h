#ifndef STACK_H
#define STACK_H

#define MAX_STACK_SIZE 64
template<typename NodeType>
class Stack
{
private:
    NodeType data_[MAX_STACK_SIZE];
    int stack_pointer_;
public:
    __host__ __device__ Stack():stack_pointer_(-1) {}
    __inline__ __host__ __device__ bool Full() 
    {
        return stack_pointer_ >= MAX_STACK_SIZE;
    }

    __inline__ __host__ __device__ bool Empty()
    {
        return stack_pointer_ == -1;
    }

    __inline__ __host__ __device__ NodeType Top()
    {
        return data_[stack_pointer_];
    }

    __inline__ __host__ __device__ void Push(const NodeType& node)
    {
        data_[++stack_pointer_] = node;
    }

    __inline__ __host__ __device__ NodeType Pop()
    {
        return data_[stack_pointer_--];
    }
};

#endif