class Point {
public:
    double x;
    double y;
    void mirrorX(double xValue);
    void mirrorY(double yValue);
    Point(double x, double y);
    double distance(Point other);
    Point swapXY();
};