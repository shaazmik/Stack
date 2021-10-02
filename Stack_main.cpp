#include "Stack.h"

#define $(value)     { printf ("got result: " #value " = %d", value); printf ("\n"); }

#ifdef Double_t
    void dump_pop (double value)          {printf ("pop = %lg\n", value);  }
#endif

#ifdef Int_t
    void dump_pop (int value)          {printf ("pop = %d\n", value);  }
#endif // Int_t

#ifdef Str_t
    void dump_pop (const char* str)    {printf ("pop = %s\n", str);    }
#endif // Str_t

int main()
{
    //printf("Input your command:");

    struct pstack_info pstack {};

    int capacity = 0;
    printf ("Input stack capacity:\n");
    scanf ("%d", &capacity);
    stack_constructor (&pstack, capacity);
    //$( destructor  (&pstack) );

    //stack_constructor (&pstack, capacity);

    $( stack_pushka(&pstack, 5.4));

    dump_loud(&pstack, __FILE__, __PRETTY_FUNCTION__);

    $( stack_pushka(&pstack, 7.6));

    dump_pop( stack_popka(&pstack) );

    dump_pop( stack_popka(&pstack) );

    //$( stack_popka(&pstack));


    $( destructor  (&pstack) );

    return OK;
}
