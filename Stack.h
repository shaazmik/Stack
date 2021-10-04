#ifndef STACK_H
#define STACK_H

#include <math.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#define FATAL_ERROR assert(0)


#define Double_t


#ifdef Double_t

typedef double type_array;

#endif


#ifdef Int_t

typedef int type_array;

#endif


#ifdef Str_t

typedef char* type_array;

#endif



enum errors
{
    OK = 0,
    CON_STATUS_OK = 3,
    STACK_IS_CONSTURCTED = 4,
    DES_STATUS_OK = 13,
    ERROR_OUT_RANGE = 1488,
    ERROR_FULL_STACK = 1945,
    ERROR_NULLPTR = 228,
    ERROR_DOUBLE_CONSTRUCT = 1555,
    ERROR_DOUBLE_DESTRUCT = 1337,
    ERROR_WRONG_CAPACITY = 1861,
    WARNING_SIZE_INC = 666,
    WARNING_SIZE_DEC = 999,
    LEFT_CANAREA_DEAD = 0xB1EA,
    RIGHT_CANAREA_DEAD = 0xB2EA,
    ERROR_MEMORY_RESIZE_FAILED = 0xBABADED
};


struct pstack_info
{
    long long Golub_left;

    type_array* pstack_pointer;
    int         pstack_size;
    ssize_t     pstack_capacity;

    int pstack_error   = 0;
    int pstack_inc     = 0;
    size_t con_status  = CON_STATUS_OK;
    size_t des_status;
    size_t inc_counter = 1;
    long long p_hash   = 0;


    long long Golub_right;
};



const int Pstack_inc_max = 3;

static const long long Dog = 0x1ABE;

const int Pstack_multiplier = 2;

const int Default_size_of_pstack = 100;


int stack_constructor(struct pstack_info* pstack, int pstack_user_size);


void check_construct(struct pstack_info* pstack);


int check_memory(type_array* data);


void check_nullptr(struct pstack_info* pstack);


int stack_pushka(struct pstack_info* pstack, type_array new_element);


type_array stack_popka(struct pstack_info* pstack);


int verification(struct pstack_info* pstack);


int pstack_resizemo(struct pstack_info* pstack);


int pstack_resizele(struct pstack_info* pstack);


int dump_loud(struct pstack_info* pstack, const char* name_of_file, const char* name_of_function);


void print_err_loud(int err_num, const char* name_of_file, const char* name_of_function, pstack_info* pstack, int line_number);


int destructor(struct pstack_info* pstack);


void check_destruct(struct pstack_info* pstack);


#endif // STACK_H
