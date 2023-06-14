/*
 * lefl.h
 */

#ifndef LEFL_H_
#define LEFL_H_

#include "stdint.h"
#include "stddef.h"

/*
 * lefl_cursor.c
 */

typedef struct __lefl_cursor_t
{
    float x;
    float y;
    float w;
    float h;
    void (* draw_cb)(struct __lefl_cursor_t *cursor);
} lefl_cursor_t;

extern lefl_cursor_t cursor;
extern lefl_cursor_t target_cursor;

void lefl_cursor_draw(lefl_cursor_t *c);
void lefl_cursor_move(lefl_cursor_t *c,lefl_cursor_t *tc);
void lefl_cursor_set(lefl_cursor_t *c,float x,float y,float w,float h);

/*
 * lefl_menu.c
 */
#define LEFL_MENU_MAX_LENGTH 8

typedef struct __lefl_menu_t
{
  const char *items[LEFL_MENU_MAX_LENGTH];
  int8_t selected_index;
  uint8_t len;
  void (* menu_cb)(struct __lefl_menu_t *menu);
} lefl_menu_t;

void lefl_menu_index_increase(lefl_menu_t *menu,int8_t delta);
void lefl_menu_click(lefl_menu_t *menu);
void lefl_menu_update_selection(lefl_menu_t *menu);
void lefl_menu_draw(lefl_menu_t *menu);

/*
 * lefl_keyboard.c
 */
#define LEFL_KEYBOARD_MAX_X 17
#define LEFL_KEYBOARD_MAX_Y 6
typedef struct __lefl_keyboard_t
{
  int8_t x;
  int8_t y;
  void (* keyboard_cb)(struct __lefl_keyboard_t *keyboard);
} lefl_keyboard_t;
extern char *ansi_104_keymap[6][17];

void lefl_keyboard_x_increase(lefl_keyboard_t *keyboard,int8_t delta);
void lefl_keyboard_y_increase(lefl_keyboard_t *keyboard,int8_t delta);
void lefl_keyboard_draw(lefl_keyboard_t *keyboard);

/*
 * lefl_nav.c
 */
#define LEFL_PAGE_MAX 8

typedef struct __lefl_page_t
{
  void (* page_logic_cb)(struct __lefl_page_t *page);
  void (* page_draw_cb)(struct __lefl_page_t *page);
  struct __lefl_page_t  *forward;
  struct __lefl_page_t  *back;
} lefl_page_t;

typedef struct __lefl_frame_t
{
  lefl_page_t *pages[LEFL_PAGE_MAX];
  int8_t index;
  int8_t len;
  void (* frame_cb)(struct __lefl_frame_t *frame);
} lefl_frame_t;

void lefl_frame_go_forward(lefl_frame_t* frame);
void lefl_frame_go_back(lefl_frame_t* frame);
void lefl_frame_go_home(lefl_frame_t* frame);
void lefl_frame_navigate(lefl_frame_t* frame,lefl_page_t* page);
void lefl_frame_logic(lefl_frame_t* frame);
void lefl_frame_draw(lefl_frame_t* frame);

typedef struct __lefl_link_frame_t
{
  lefl_page_t *current_page;
  void (* link_frame_cb)(struct __lefl_link_frame_t *frame);
} lefl_link_frame_t;

void lefl_link_frame_go_home(lefl_link_frame_t* frame);
void lefl_link_frame_go_forward(lefl_link_frame_t* frame);
void lefl_link_frame_go_back(lefl_link_frame_t* frame);
void lefl_link_frame_navigate(lefl_link_frame_t* frame,lefl_page_t* page);
void lefl_link_frame_logic(lefl_link_frame_t* frame);
void lefl_link_frame_draw(lefl_link_frame_t* frame);

/*
 * lefl_easing.c
 */
#define LEFL_ANIMATION_SPEED       (1/5.0)
void lefl_easing_pid(float *f,float target);

/*
 * lefl_datastruct.c
 */

#define LEFL_ARRAY_MAX 200
typedef uint16_t lefl_array_t;

typedef struct __lefl_loop_array_t
{
    lefl_array_t list[LEFL_ARRAY_MAX];
    int16_t index;
    int16_t len;
} lefl_loop_array_t;

typedef struct __lefl_loop_array_iterator_t
{
    lefl_loop_array_t* lefl_loop_array_t;
    int16_t index;
} lefl_loop_array_iterator_t;

lefl_array_t lefl_loop_array_get(lefl_loop_array_t *arr,int16_t j);
void lefl_loop_array_push_back(lefl_loop_array_t *arr,lefl_array_t t);
lefl_array_t lefl_loop_array_max(lefl_loop_array_t *arr);


/*
 * lefl_input.c
 */


#endif /* LEFL_H_ */
