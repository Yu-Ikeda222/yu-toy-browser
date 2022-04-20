#ifndef YU_TOY_BROWSER_LAYOUTCONSTANTS_H
#define YU_TOY_BROWSER_LAYOUTCONSTANTS_H

#include <stdio.h>

struct Rect {
    int x;
    int y;
    int width;
    int height;
};
struct EdgeSizes {
    int left;
    int right;
    int top;
    int bottom;
};
struct Dimensions {
    Rect content;
    EdgeSizes padding;
    EdgeSizes border;
    EdgeSizes margin;

};
#endif /* YU_TOY_BROWSER_LAYOUTCONSTANTS_H */
