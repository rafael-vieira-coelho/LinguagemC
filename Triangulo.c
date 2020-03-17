#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
struct Vertice{
  float x;
  float y;
};
 
struct Triangulo{
  struct Vertice A;
  struct Vertice B;
  struct Vertice C;
};
 
float Distancia(struct Vertice A, struct Vertice B){
  float dx, dy, d;
  dx = (B.x - A.x);
  dy = (B.y - A.y);
  d = sqrtf(dx*dx + dy*dy);
  return d;
}
 
 
float Perimetro(struct Triangulo T){
  float d = 0.0;
  d += Distancia(T.A, T.B);
  d += Distancia(T.A, T.C);
  d += Distancia(T.B, T.C);
  return d;
}
