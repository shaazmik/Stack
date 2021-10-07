#include "Stack.h"

#define $(value)     { printf ("got result: " #value " = %d", value); printf ("\n\n"); }

#ifdef Double_t
    void dump_pop (double value)          {printf ("pop = %lg\n\n", value);  }
#endif

#ifdef Int_t
    void dump_pop (int value)             {printf ("pop = %d\n\n", value);  }
#endif

#ifdef Str_t
    void dump_pop (const char* str)       {printf ("pop = %s\n\n", str);    }
#endif

int main()
{
    //printf("Input your command:");

    struct pstack_info pstack = {};

    int capacity = 0;
    printf ("Input stack capacity:\n");
    scanf ("%d", &capacity);

    standart_command(stack_constructor(&pstack, capacity));
    stack_pushka(&pstack, 123);
    stack_pushka(&pstack, 124);
    stack_pushka(&pstack, 125);
    stack_pushka(&pstack, 126);
    stack_pushka(&pstack, 127);
    stack_pushka(&pstack, 128);
    stack_pushka(&pstack, 129);
    dump_pop(stack_popka(&pstack));
    dump_pop(stack_popka(&pstack));
    dump_pop(stack_popka(&pstack));
    dump_pop(stack_popka(&pstack));
    dump_pop(stack_popka(&pstack));
    dump_pop(stack_popka(&pstack));

    standart_command(stack_destructor(&pstack));

    return OK;
}
