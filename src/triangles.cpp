#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

#include "include/triangle.hpp"

namespace geometry {

    Triangle::Triangle() {}
    Triangle::Triangle(Point2D t1, Point2D t2, Point2D t3) : _t1(t1), _t2(t2), _t3(t3) {}
    
    void Triangle::SetT1(Point2D t1) { _t1 = t1; }
    void Triangle::SetT2(Point2D t2) { _t2 = t2; }
    void Triangle::SetT3(Point2D t3) { _t3 = t3; }

    float calculateDistance(Point2D p1, Point2D p2) {
        return std::sqrt(std::pow(p1.GetX() - p2.GetX(), 2) + 
                         std::pow(p1.GetY() - p2.GetY(), 2));
    }

    std::string Triangle::TriangleType() {
      
        float s1 = calculateDistance(_t1, _t2);
        float s2 = calculateDistance(_t2, _t3);
        float s3 = calculateDistance(_t3, _t1);

       
        std::vector<float> sides = {s1, s2, s3};
        std::sort(sides.begin(), sides.end());

        float a = sides[0];
        float b = sides[1];
        float c = sides[2];

       
        float epsilon = 1e-4;

        // 3. Evaluasi tipe
        bool isSamaSisi = (std::abs(a - b) < epsilon) && (std::abs(b - c) < epsilon);
        bool isSamaKaki = (std::abs(a - b) < epsilon) || (std::abs(b - c) < epsilon);
        bool isSikuSiku = std::abs((a * a + b * b) - (c * c)) < epsilon;

        if (isSamaSisi) {
            return "sama sisi";
        } else if (isSikuSiku) {
            return "siku-siku";
        } else if (isSamaKaki) {
            return "sama kaki";
        } else {
            return "sembarang";
        }
    }
}