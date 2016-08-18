#ifndef __MEMORY_POOL_CPP__
#define __MEMORY_POOL_CPP__

#include <iostream>
#include <cstdlib>

#include "MemoryPool.h"

using namespace std;

template <typename T, size_t seed>
MemoryPool<T, seed>::MemoryPool() {
    block_size = seed;
    while (block_size < sizeof(block_pointer) + sizeof(T))
        block_size <<= 1;
    
    #ifdef DEBUG
        cout << "T size = " << sizeof(T) << endl;
        cout << "slot size = " << sizeof(slot) << endl;
        cout << "block pointer size = " << sizeof(block_pointer) << endl;
        cout << "block size = " << block_size << endl;
    #endif

    head_block = nullptr;
    current_slot = nullptr;
    last_slot = nullptr;
    free_slot = nullptr;
}

template <typename T, size_t seed>
MemoryPool<T, seed>::~MemoryPool(void) {
    slot_pointer curr = reinterpret_cast<slot_pointer>(head_block);
    while (curr) {
        
        #ifdef DEBUG
            cout << "---free block " << static_cast<const void *>(curr) << endl;
        #endif
        
        slot_pointer tail = curr->next;
        operator delete(reinterpret_cast<void*>(curr));
        curr = tail;
    }
}

template <typename T, size_t seed>
T *MemoryPool<T, seed>::allocate(void) {
    slot_pointer sp = nullptr;
    if (free_slot) {
        sp = free_slot;
        free_slot = free_slot->next;
    } else {
        if (current_slot < last_slot) {
            sp = current_slot;
            ++current_slot;
        } else {
            block_pointer new_block = reinterpret_cast<block_pointer>(operator new(block_size));
            
            #ifdef DEBUG
                cout << "+++allocate block " << static_cast<const void *>(new_block) << endl;
            #endif
            
            reinterpret_cast<slot_pointer>(new_block)->next = reinterpret_cast<slot_pointer>(head_block);
            head_block = new_block;
            sp = reinterpret_cast<slot_pointer>((char *)head_block + sizeof(block_pointer));
            current_slot = sp + 1;
            last_slot = reinterpret_cast<slot_pointer>(head_block + block_size);
        }
    }

    #ifdef DEBUG
        cout << "head block = " << static_cast<const void *>(head_block) << endl;
        cout << "current slot = " << static_cast<const void *>(current_slot) << endl;
        cout << "last slot = " << static_cast<const void *>(last_slot) << endl;
    #endif
    
    new (sp) T; // Call class T's constructor.
    return reinterpret_cast<T *>(sp);
}

template <typename T, size_t seed>
void MemoryPool<T, seed>::deallocate(T *sp) {
    sp->~T();   // Call class T's destructor.
    reinterpret_cast<slot_pointer>(sp)->next = free_slot;
    free_slot = reinterpret_cast<slot_pointer>(sp);
}

#endif // __MEMORY_POOL_CPP__
