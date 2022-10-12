#ifndef TRY_CATCH_H__
#define TRY_CATCH_H__

#include <setjmp.h>

jmp_buf buf_state;

#define TRY do { switch (setjmp(buf_state)) { while(1) { case 0:
#define CATCH(x) break; case x:
#define ENDTRY }} while(0)
#define THROW(x) longjmp(buf_state, x)
#define FINALLY break; } default:

#endif