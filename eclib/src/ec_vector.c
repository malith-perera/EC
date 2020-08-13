#include <stdlib.h>

#include "ec_vector.h"


Vector2D* Create_Vector2D ()
{
  Vector2D* vec = malloc (sizeof (Vector2D));
  return vec;
}


Vector2D ec_add (const Vector2D vec1, const Vector2D vec2)
{
  Vector2D vec;

  vec.x = vec1.x + vec2.x;
  vec.y = vec1.y + vec2.y;

  return vec;
}


Vector2D ec_sub (const Vector2D vec1, const Vector2D vec2)
{
  Vector2D vec;

  vec.x = vec1.x - vec2.x;
  vec.y = vec1.y - vec2.y;

  return vec;
}


Vector2D ec_mul (const Vector2D vec1, const Vector2D vec2)
{
  Vector2D vec;

  vec.x = vec1.x * vec2.x;
  vec.y = vec1.y * vec2.y;

  return vec;
}


Vector2D ec_div (const Vector2D vec1, const Vector2D vec2)
{
  Vector2D vec;

  vec.x = vec1.x / vec2.x;
  vec.y = vec1.y / vec2.y;

  return vec;
}
