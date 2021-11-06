#include <iostream>
#include "Point.h"

using namespace std;

int main(void) {
   int i{4};
   int x[]{1, 2, 3};
   cout << i << " " << x[0] << endl;
   Point a{7, 8};
   Point d{8, 9};
   cout << a.x << " " << a.y << endl;
   //Point b{9};
   //cout << b.x << " " << b.y << endl;
   Point p[]{{1, 2}, {3, 4}, {5, 6}};
   cout << p[1].x << " " << p[1].y << endl;
   cout << a.distance(d) << endl;
   Point c = a.swapXY();
   cout << c.x << " " << c.y << endl;
   return 0;
}