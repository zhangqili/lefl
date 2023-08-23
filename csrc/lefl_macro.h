/*
 * lefl_macro.h
 *
 */

#ifndef LEFL_MACRO_H_
#define LEFL_MACRO_H_

#define LAMBDA(return_type, function_body) \
({ \
      return_type $this function_body \
          $this; \
})

#define ROUND(x) ((size_t)((x)+0.5f))

#define BIT(x) (1<<x)

#define VAR_LOOP_INCREMENT(x,min,max,delta) if((x)<(max)) (x)+=(delta);else (x)=(min);

#define VAR_LOOP_DECREMENT(x,min,max,delta) if((x)>(min)) (x)-=(delta);else (x)=(max);

#endif /* LEFL_MACRO_H_ */
