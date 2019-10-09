// There is a problem somewhere in this code. Need to debug. Could not connect gdb in previous
// try.

#include<assert.h>
#include <string.h>
#include<unistd.h>
#include <sys/types.h>

struct malloc_block{
    size_t size;    
    struct malloc_block * next;
    int free; // bool variable. 1 denotes free, 0 denotes busy.
    //char data[1];
};

typedef struct malloc_block malloc_block;

void *global_head = NULL;
#define BLOCK_SIZE sizeof(malloc_block)

void * malloc(size_t sz);
/* void * realloc(void * ptr, size_t sz);
void * calloc(size_t sz);
*/
void free(void * ptr);

/* Internal functions to see if existing memory can be used. */
void * get_old_space(malloc_block **, size_t);

/* Function to actually allocate new memory from OS*/
void * alloc_new_space(malloc_block *, size_t);

void * malloc(size_t sz) {
    if (sz <= 0)
        return NULL;
    malloc_block * block;
    if (!global_head) {
        block = (malloc_block*)alloc_new_space(NULL, sz);
        if (!block)
            return NULL;
        global_head = block;
    } else {
        malloc_block * prev = global_head; // This is used just to see if there is a head or not.
        block = get_old_space(&prev, sz);
        if (block == NULL) {
            // We didn't get the space from previously deallocated memory.
            block = alloc_new_space(prev, sz);
            if (!block)
                return NULL;
        } else {
            block->free = 0;
        }
    }
    return block+1;//->data;
}

void * get_old_space(malloc_block ** prev, size_t sz) {
    malloc_block * orig = global_head;    
    while(orig && !(orig->free && orig->size >= sz)) {
        /* Traverse across the list to see if there is some free block of some size less than what 
         * we need.
         **/
        *prev = orig;
        orig = orig->next;
    }
    return orig;
}

void * alloc_new_space(malloc_block * last, size_t sz) {
    malloc_block * block = sbrk(0);
    void * next_head = sbrk(BLOCK_SIZE + sz);
    assert((void *)block == next_head);
    if (next_head == (void *)-1) {
        /* sbrk told us he's not giving us anymore space. */
        return NULL;
    }
    if (last) {
        last->next = block;
    }
    block->size = sz;
    block->free = 0;
    block->next = NULL;
    // block->data = ((malloc_block *)0)->data;
    return block;
}

malloc_block *
get_block_ptr(void *ptr) {
    return (malloc_block *)ptr - 1;
}

void free(void * ptr) {
    if (!ptr)
        return;
    malloc_block * block_ptr = get_block_ptr(ptr);
    block_ptr->free = 1;
    /* Might merge nearby free nodes */
    /* Would need to merge malloc_block in case of merging nearby blocks and account that in total 
     * size of the new block.*/
}