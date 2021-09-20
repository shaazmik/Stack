#include "stdlib.h"
#include "malloc.h"
#include "stdio.h"
#include "string.h"



struct pstack_info
{
    const long long golub1 = 11333377;
    int* pstack_pointer;
    size_t pstack_size_now;
    size_t pstack_max_size;
    const long long golub2 = 11448888;
};

int stack_constructor(struct pstack_info* pstack, size_t pstack_user_size)
{
    pstack->pstack_size_now = -1;
    pstack->pstack_max_size = pstack_user_size;
    pstack->pstack_pointer = (int*)calloc(pstack_user_size, sizeof(int));
    return 0;
}


int stack_pushka(struct pstack_info* pstack, int new_element)
{
    pstack->pstack_size_now++;

    if ((pstack->pstack_size_now) > pstack->pstack_max_size)
    {
        pstack->pstack_size_now--;
        return -1;
    }


    *(pstack->pstack_pointer) = new_element;
    pstack->pstack_pointer++;

    return 0;
}

int stack_popka(struct pstack_info* pstack)
{

}


int main()
{

    //printf("Input your command:");

    struct pstack_info pstack;

    int pstack_capacity = 0;
    printf("Input stack capacity:\n");
    scanf("%d", &pstack_capacity);

    stack_constructor(&pstack, pstack_capacity);
    int a1, a2, a3 = 0;
    scanf("%d %d %d", &a1, &a2, &a3);
    stack_pushka(&pstack, a1);
    stack_pushka(&pstack, a2);
    stack_pushka(&pstack, a3);
    printf("%d %d %d", *(pstack.pstack_pointer-1), *(pstack.pstack_pointer-2), *(pstack.pstack_pointer-3));
}
