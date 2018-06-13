#pragma once
#include <string.h>
#include <assert.h>

typedef struct util_stack {
	void *memory;
	int top;
	int max_count;
	int item_size;
} util_stack;

static inline util_stack util_stack_create(int max_size, int item_size) {
	util_stack s = {
		.memory = malloc(max_size * item_size),
		.top = 0,
		.max_count = max_size,
		.item_size = item_size,
	};

	return s;
}

static inline void __util_stack_push(util_stack *s, void *item, int size) {
	assert(s->item_size == size);

	s->top += 1;
	assert(s->top < s->max_count);

	memcpy(s->memory + s->top * size, item, size);
}
#define util_stack_push(s, x) __util_stack_push(&s, &x, sizeof(x))

static inline void *__util_stack_top(util_stack *s) {
	return s->memory + s->top * s->item_size;
}

// This does not copy the element out it just returns the memory
// where that element is, do not store the result of this without,
// first copying it out
#define util_stack_top(s) __util_stack_top(&s)

static inline void __util_stack_pop(util_stack *s) {
	s->top -= 1;

	if(s->top < 0) s->top = 0;
}
#define util_stack_pop(s) __util_stack_pop(&s)
