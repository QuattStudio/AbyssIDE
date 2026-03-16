#pragma once



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "core/abys_types.h"




/* macros */

#define ABYS_LOG_INFO(fmt, ...) \
    printf("[INFO] > " fmt "\n", ##__VA_ARGS__)


#define ABYS_LOG_WARN(fmt, ...) \
    printf("[WARN] > {%s:%d} > " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__)


#define ABYS_LOG_ERROR(fmt, ...) \
    printf("[ERR] > {%s:%d} > " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__)


#define ABYS_LOG_CRITICAL(fmt, ...) \
    printf("[CRITICAL] > {%s:%d} > " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__); exit(1)






#ifndef ABYS_DISABLE_VERBOSE_LOGS_I


#define ABYS_LOGV_INFO(fmt, ...) \
    printf("[INFO-V] > " fmt "\n", ##__VA_ARGS__)


#define ABYS_LOGV_WARN(fmt, ...) \
    printf("[WARN-V] > {%s:%d} > " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__)



#endif







#define ABYS_CONCAT(x, y) x##y
#define ABYS_TO_STR(x) #x

#define ABYS_GL_VERSION_MAJOR 3
#define ABYS_GL_VERSION_MINOR 3
#define ABYS__GL_VERSION  \
    ABYS_CONCAT(ABYS_GL_VERSION_MAJOR, ABYS_CONCAT(., ABYS_GL_VERSION_MINOR))

#define ABYS_GL_VERSION_STRING  ABYS_TO_STR(ABYS__GL_VERSION)





#define ABYS_NOT    !
#define ABYS_OR     ||
#define ABYS_AND    &&




#define ABYS_MAX_OPACITY_INT        255
#define ABYS_MAX_OPACITY_FLOAT      1.0f





#define ABYS__RET_NOTHING

#define ABYS__CHECK_WINDOW(window, msg, ret)\
    if (ABYS_NOT window) {\
        ABYS_LOG_ERROR(msg);\
        return ret;\
    }



#define ABYS__EXCEPT_WINDOW_NOT_FOUND   "No Window Found!"


#define ABYS__INIT_WITH_ZERO(obj)   memset(obj, 0, sizeof(obj))
#define ABYS__INIT_WITH_ZERO_F(obj)   memset(obj, 0.0f, sizeof(obj))


#define ABYS_INLINE     static inline
#define ABYS_MALLOC(obj)  ((obj*)malloc(sizeof((obj))))


/* flags */

#define ABYS_FLAG_SHIFT(n)      (1 << n)



#define ABYS_WINDOW_MAXIMIZED       ABYS_FLAG_SHIFT(0)
#define ABYS_WINDOW_RESIZABLE       ABYS_FLAG_SHIFT(1)
#define ABYS_WINDOW_DECORATED       ABYS_FLAG_SHIFT(2)
#define ABYS_WINDOW_UNDECORATED     ABYS_FLAG_SHIFT(3)
#define ABYS_WINDOW_FLOATING     ABYS_FLAG_SHIFT(4)









/* functions */


#define ERR_MSG_LEN 256

// Set/overwrite the last error
void abys_SetError(const char* msg);


// Clear the last error
void abys_ResetError();

// Get the last error (returns NULL if empty)
const char* abys_GetError();










void abys_Delay(abys_Uint32 ms);
