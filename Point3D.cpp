#include "Point3D.h"
#include <iostream>
#include <cmath>
using namespace std;

// 构造函数实现：调用基类构造函数初始化x,y，再初始化z
Point3D::Point3D() : Point2D(), z(0.0) {
	// cout << "Point3D默认构造函数调用" << endl;
}

Point3D::Point3D(double x_val, double y_val, double z_val)
	: Point2D(x_val, y_val), z(z_val) {
	// cout << "Point3D带参数构造函数调用" << endl;
}

// 析构函数实现
Point3D::~Point3D() {
	// cout << "Point3D析构函数调用" << endl;
}

// 重写move函数：支持z方向移动
Point3D& Point3D::move(double dx, double dy, double dz) {
	// 调用基类的move函数修改x,y
	Point2D::move(dx, dy);
	z += dz;
	return *this;
}

// 重写show函数：输出三维坐标
void Point3D::show() const {
	cout << "三维点坐标：(" << getX() << ", " << getY() << ", " << z << ")" << endl;
}

// 友元函数：计算三维欧式距离（√[(x2-x1)² + (y2-y1)² + (z2-z1)²]）
double distance(const Point3D& p1, const Point3D& p2) {
	double dx = p2.getX() - p1.getX();
	double dy = p2.getY() - p1.getY();
	double dz = p2.getZ() - p1.getZ();
	return sqrt(dx * dx + dy * dy + dz * dz);
}