#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct point {
    int x,y;
    point(int x_, int y_): x{x_}, y{y_} {}
};

bool comp(const point & a, const point & b) {
    if(a.x == b.x) return a.y < b.y;
    else return a.x < b.x;
}

ostream & operator << ( ostream & out, const point & p) {
    return (out << p.x << ", " << p.y << "\n");
}

int main() {
    vector<point> points;
    points.push_back(point(3,5));
    points.push_back(point(5,2));
    points.push_back(point(-2,2));
    points.push_back(point(1,3));
    points.push_back(point(1,2));

    sort(begin(points),end(points),comp);
    for(auto x: points) {
        cout << x ;
    }
}
