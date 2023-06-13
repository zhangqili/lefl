/*
 * lefl_datastruct.c
 */
#include "lefl.h"


lefl_array_t lefl_loop_array_get(lefl_loop_array_t *arr,int16_t j)
{
    if(j>=0&&j<arr->len)
    {
        return arr->list[arr->index-j>=0?arr->index-j:arr->index-j+arr->len];
    }
    else
    {
        return 0;
    }
}

void lefl_loop_array_push_back(lefl_loop_array_t *arr,lefl_array_t t)
{
    arr->index++;
    if(arr->index>=arr->len)
    {
        arr->index=0;
    }
    arr->list[arr->index]=t;
}

lefl_array_t lefl_loop_array_max(lefl_loop_array_t *arr)
{
    lefl_array_t max = 0;
    for(uint8_t i=0;i<arr->len;i++)
    {
        if(arr->list[i]>max)
            max=arr->list[i];
    }
    return max;
}
