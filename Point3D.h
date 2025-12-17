#ifndef POINT3D_H
#define POINT3D_H

#include "Point2D.h"

// 三维空间点类（公有继承Point2D）
class Point3D : public Point2D {
private:
	double z;  // 新增z坐标（三维扩展）
public:
	// 构造函数：默认构造、带参数构造（初始化x,y,z）
	Point3D();
	Point3D(double x_val, double y_val, double z_val);
	// 析构函数
	~Point3D();
	// 重写move函数：支持x,y,z三个方向移动
	Point3D& move(double dx, double dy, double dz);
	// 重写show函数：输出三维坐标
	void show() const;
	// 友元函数：计算两个Point3D对象的欧式距离
	friend double distance(const Point3D& p1, const Point3D& p2);

	// 保护成员函数：供友元函数访问z坐标
protected:
	double getZ() const { return z; }
};

#endif // POINT3D_H#pragma once
