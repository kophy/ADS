#ifndef __MEMORY_POOL_H__
#define __MEMORY_POOL_H__

#define DEBUG

template <typename T, size_t seed = 16>
class MemoryPool {
    public:
        MemoryPool(void);
        ~MemoryPool(void);
        
        // Allocate/deallocate one T object at a time.
        T *allocate(void);
        void deallocate(T *sp); 
    private:
        typedef union slot {
            T data;
            slot *next;
        } slot;

        typedef slot* slot_pointer;
        typedef char* block_pointer;

        int block_size;
        
        block_pointer head_block;
        
        slot_pointer current_slot;
        slot_pointer last_slot;
        slot_pointer free_slot;
};

#include "MemoryPool.cpp"

#endif // __MEMORY_POOL_H__
