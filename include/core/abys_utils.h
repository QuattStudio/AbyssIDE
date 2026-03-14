#pragma once



#include <stdio.h>
#include <string.h>




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






#define ABYS__RET_NOTHING

#define ABYS__CHECK_WINDOW(window, msg, ret)\
    if (ABYS_NOT window) {\
        ABYS_LOG_ERROR(msg);\
        return ret;\
    }













#define ERR_MSG_LEN 256

// Set/overwrite the last error
void abys_SetError(const char* msg);


// Clear the last error
void abys_ResetError();

// Get the last error (returns NULL if empty)
const char* abys_GetError();