#pragma once


#include <stdint.h>





typedef uint8_t     abys_Uint8;
typedef uint16_t    abys_Uint16;
typedef uint32_t    abys_Uint32;
typedef uint64_t    abys_Uint64;



typedef int8_t      abys_Int8;
typedef int16_t     abys_Int16;
typedef int32_t     abys_Int32;
typedef int64_t     abys_Int64;








typedef enum abys_Bool
{
    ABYS_YES = 1,
    ABYS_TRUE = 1,
    ABYS_FALSE = 0,
    ABYS_NO = 0,
} abys_Bool;





typedef struct abys_Rect
{
    int x;
    int y;
    int width;
    int height;
} abys_Rect;




