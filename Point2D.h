#ifndef POINT2D_H
#define POINT2D_H

// 二维空间点类
class Point2D {
private:
	double x;  // x坐标
	double y;  // y坐标
public:
	// 构造函数：默认构造（初始化为原点）、带参数构造
	Point2D();
	Point2D(double x_val, double y_val);
	// 析构函数
	~Point2D();
	// 移动点的位置：返回自身引用，支持链式调用
	Point2D& move(double dx, double dy);
	// 常成员函数：输出点的坐标信息（不修改对象状态）
	void show() const;
	// 友元函数：计算两个Point2D对象的欧式距离
	friend double distance(const Point2D& p1, const Point2D& p2);

	// 保护成员函数：供派生类访问基类私有坐标（Point3D需要计算距离）
protected:
	double getX() const { return x; }
	double getY() const { return y; }
};

#endif // POINT2D_H#pragma once
