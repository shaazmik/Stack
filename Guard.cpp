#include "Stack.h"


void check_nullptr(struct pstack_info* pstack)
{
    if (pstack == nullptr)
    {
            FILE* log = fopen("log.txt", "a");
            fprintf(log, "Stack [NULL_PTR_ERROR #%d] [0x000000]\n ", ERROR_NULLPTR);

            fflush(log);

            assert(0);
    }
}

