/*
 * lefl_nav.c
 */
#include "lefl.h"

void lefl_frame_go_forward(lefl_frame_t* frame)
{
    if(frame->index<frame->len)
        frame->index++;
}
void lefl_frame_go_back(lefl_frame_t* frame)
{
    if(frame->index>0)
        frame->index--;
}
void lefl_frame_navigate(lefl_frame_t* frame,lefl_page_t* page)
{
    if(frame->len<LEFL_PAGE_MAX)
    {
        frame->index++;
        frame->pages[frame->index]=page;
        frame->len=frame->index+1;
    }
}
void lefl_frame_go_home(lefl_frame_t* frame)
{
    frame->index=0;
}
void lefl_frame_logic(lefl_frame_t* frame)
{
    frame->pages[frame->index]->page_logic_cb(frame->pages[frame->index]);
}
void lefl_frame_draw(lefl_frame_t* frame)
{
    frame->pages[frame->index]->page_draw_cb(frame->pages[frame->index]);
}
