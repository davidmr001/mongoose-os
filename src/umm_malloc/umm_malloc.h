/* ----------------------------------------------------------------------------
 * umm_malloc.h - a memory allocator for embedded systems (microcontrollers)
 *
 * See copyright notice in LICENSE.TXT
 * ----------------------------------------------------------------------------
 */

#ifndef CS_COMMON_UMM_MALLOC_UMM_MALLOC_H_
#define CS_COMMON_UMM_MALLOC_UMM_MALLOC_H_

/* ------------------------------------------------------------------------ */

#include "umm_malloc_cfg.h" /* user-dependent */

typedef struct UMM_HEAP_INFO_t {
  unsigned short int totalEntries;
  unsigned short int usedEntries;
  unsigned short int freeEntries;

  unsigned short int blockSize;
  unsigned short int totalBlocks;
  unsigned short int usedBlocks;
  unsigned short int freeBlocks;

  unsigned short int maxFreeContiguousBlocks;
} UMM_HEAP_INFO;

extern UMM_HEAP_INFO ummHeapInfo;

void umm_init(void);

void *umm_info(void *ptr, int force);

void *umm_malloc(size_t size);
void *umm_calloc(size_t num, size_t size);
void *umm_realloc(void *ptr, size_t size);
void umm_free(void *ptr);

size_t umm_free_heap_size(void);
size_t umm_min_free_heap_size(void);
int umm_free_entries_cnt(void);

/* ------------------------------------------------------------------------ */

#endif /* CS_COMMON_UMM_MALLOC_UMM_MALLOC_H_ */
