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



typedef struct abys_Point
{
    int x, y;
} abys_Point;



typedef struct abys_Color
{
    int r, g, b, a;
} abys_Color;


typedef struct abys_Colorf
{
    float r, g, b, a;
} abys_Colorf;











/* macros for types casting */


#define ABYS_RGBA(r, g, b, a)   ((abys_Color){r, g, b, a})
#define ABYS_RECT(x, y, w, h)   ((abys_Rect){x, y, w, h})
#define ABYS_POINT(x, y)        ((abys_Point){x, y})
#define ABYS_COLORF(r, g, b, a) ((abys_Colorf){r, g, b, a})