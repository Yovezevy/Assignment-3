#ifndef __POINT2D_HPP__
#define __POINT2D_HPP__


namespace geometry {
    class Point2D {
        private:
            float _x, _y, _z;

        public:
            Point2D();
            Point2D(float x, float y, float z = 0); // Default z = 0 untuk 2D

            float GetX() const { return _x; };
            float GetY() const { return _y; };
            float GetZ() const { return _z; };

            inline void SetX(float x) { _x = x; }
            inline void SetY(float y) { _y = y; } // BUG FIX: sebelumnya _x = y
            inline void SetZ(float z) { _z = z; } // BUG FIX: sebelumnya _x = z

            Point2D operator+(const Point2D inp);
            Point2D operator-(const Point2D inp);
            Point2D operator*(const Point2D inp);
    };
}

#endif