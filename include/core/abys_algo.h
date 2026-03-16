#pragma once



#include "core/abys_utils.h"
#include "core/abys_types.h"






ABYS_INLINE int abys_PointRectCollision(abys_Rect* rect, abys_Point* point)
{
    return 
        point->x >= rect->x &&
        point->y >= rect->y &&
        point->x <= rect->x + rect->width &&  
        point->y <= rect->y + rect->height;
}





