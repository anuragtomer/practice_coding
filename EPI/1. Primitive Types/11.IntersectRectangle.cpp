#include <iostream>
#include <vector>

using namespace std;

struct Rectangle {
    int x, y, width, height;
    Rectangle(int _x, int _y, int _w, int _h) : x(_x), y(_y), width(_w), height(_h){};
};

bool IsIntersect(const Rectangle &R1, const Rectangle &R2);

Rectangle IntersectRectangle(const Rectangle &R1, const Rectangle &R2);

int main() {
    Rectangle R1(4, 0, 1, 6);
    Rectangle R2(1, 1, 6, 4);
    Rectangle Res = IntersectRectangle(R1, R2);
    cout << Res.x << " " << Res.y << " " << Res.width << " " << Res.height << endl;
    return 0;
}

Rectangle IntersectRectangle(const Rectangle &R1, const Rectangle &R2) {
    if (!IsIntersect(R1, R2)) {
        return {0, 0, -1, -1};
    }
    return {max(R1.x, R2.x), max(R1.y, R2.y), min(R1.x + R1.width, R2.x + R2.width) - max(R1.x, R2.x),
            min(R1.y + R1.height, R2.y + R2.height) - max(R1.y, R2.y)};
    // Time complexity O(1) because all are constant operations.
}

bool IsIntersect(const Rectangle &R1, const Rectangle &R2) {
    return (R1.x <= R2.x + R2.width) && (R1.x + R1.width >= R2.x) && (R1.y <= R2.y + R2.height) &&
           (R1.y + R1.height >= R2.y);
}