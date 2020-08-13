#ifndef EC_VECTOR_H
#define EC_VECTOR_H

#include "ec.h"


typedef struct
{
  float x;
  float y;
} Vector2D;


Vector2D ec_add (const Vector2D vec1, const Vector2D vec2);
Vector2D ec_sub (const Vector2D vec1, const Vector2D vec2);
Vector2D ec_mul (const Vector2D vec1, const Vector2D vec2);
Vector2D ec_div (const Vector2D vec1, const Vector2D vec2);


#endif // EC_VECTOR_H
