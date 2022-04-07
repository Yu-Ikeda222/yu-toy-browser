#ifndef LayoutConstants_hpp
#define LayoutConstants_hpp

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
#endif /* LayoutConstants_hpp */
