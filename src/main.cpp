#include <iostream>
#include <string>
#include <vector>
#include <math.h>

#include "include/point2d.hpp"
#include "include/triangle.hpp"

using namespace std;
using namespace geometry; 

int main(int argc, char ** argv)
{
    vector<Triangle> triangles;
    int N;

    cout << "Masukkan jumlah segitiga: ";
    if (!(cin >> N)) return 0;

 
    --------------------------*/
    for(int i = 0; i < N; i++) {
        float x1, y1, x2, y2, x3, y3;
        
        cout << "Segitiga " << i + 1 << endl;
        cout << "Point 1 (x y): "; cin >> x1 >> y1;
        cout << "Point 2 (x y): "; cin >> x2 >> y2;
        cout << "Point 3 (x y): "; cin >> x3 >> y3;

        
        Point2D p1(x1, y1, 0);
        Point2D p2(x2, y2, 0);
        Point2D p3(x3, y3, 0);

        Triangle tri(p1, p2, p3);
        triangles.push_back(tri);
    }
    /*------------------------*/


    /*--------------------------
 
    --------------------------*/
    cout << "\n--- Output ---" << endl;
    for(size_t i = 0; i < triangles.size(); i++) {
        cout << triangles[i].TriangleType() << endl;
    }
    /*------------------------*/

    return 0;
}