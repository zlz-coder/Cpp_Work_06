#include "Point2D.h"
#include <iostream>
using namespace std;

// 构造函数实现
Point2D::Point2D() : x(0.0), y(0.0) {
	// cout << "Point2D默认构造函数调用" << endl;
}

Point2D::Point2D(double x_val, double y_val) : x(x_val), y(y_val) {
	// cout << "Point2D带参数构造函数调用" << endl;
}

// 析构函数实现
Point2D::~Point2D() {
	// cout << "Point2D析构函数调用" << endl;
}

// 移动点的位置：dx为x方向偏移，dy为y方向偏移
Point2D& Point2D::move(double dx, double dy) {
	x += dx;
	y += dy;
	return *this;  // 返回自身引用
}

// 输出坐标信息
void Point2D::show() const {
	cout << "二维点坐标：(" << x << ", " << y << ")" << endl;
}

// 友元函数：计算欧式距离（√[(x2-x1)? + (y2-y1)?]）
double distance(const Point2D& p1, const Point2D& p2) {
	double dx = p2.x - p1.x;
	double dy = p2.y - p1.y;
	return sqrt(dx * dx + dy * dy);
}