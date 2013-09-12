#ifndef TRACEBOX_H
#define TRACEBOX_H

// structs definition

struct line{
  double m, q;
};

struct point{
  double x;
  double y;
};

struct box{
  point start;
  point end;
  double angle;
  double ray_length;
  point ray_source;
  int ix, iy;
};


// methods definition

point tracebox( box &b );
box create_box();
line generate_line( point a, point b );
point calculate_intersection( line a, line b );
double compute_length( point a, point b );

#endif
