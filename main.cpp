#include "Point2D.h"
#include "Point3D.h"
#include "Base.h"
#include <iostream>
using namespace std;

int main() {
	// ------------------------------
	// 测试一：Point2D与Point3D类功能
	// ------------------------------
	cout << "===== 测试二维/三维点类 =====" << endl;
	// 二维点测试
	Point2D p2d1(1.0, 2.0);
	Point2D p2d2(4.0, 6.0);
	p2d1.show();
	p2d2.show();
	cout << "p2d1与p2d2的欧式距离：" << distance(p2d1, p2d2) << endl;

	p2d1.move(2.0, 3.0);  // 移动p2d1
	cout << "p2d1移动后：";
	p2d1.show();

	// 三维点测试
	Point3D p3d1(1.0, 2.0, 3.0);
	Point3D p3d2(4.0, 6.0, 8.0);
	p3d1.show();
	p3d2.show();
	cout << "p3d1与p3d2的欧式距离：" << distance(p3d1, p3d2) << endl;

	p3d1.move(2.0, 3.0, 4.0);  // 移动p3d1
	cout << "p3d1移动后：";
	p3d1.show();
	cout << endl;

	// ------------------------------
	// 测试二：基类与派生类（继承特性、访问权限、构造/析构次序）
	// ------------------------------
	cout << "===== 测试基类与派生类 =====" << endl;
	// 1. 测试公有继承Derived1
	cout << "\n----- 公有继承Derived1 -----" << endl;
	Derived1 d1(10, 20, 30);
	d1.testAccess();  // 类内访问基类成员
	cout << "类外访问Derived1的基类公有成员a: " << d1.a << "（公有继承可访问）" << endl;
	d1.print();  // 类外调用基类公有成员函数

	// 2. 测试私有继承Derived2
	cout << "\n----- 私有继承Derived2 -----" << endl;
	Derived2 d2(40, 50, 60);
	d2.testAccess();  // 类内访问基类成员
	// cout << d2.a;  // 错误：私有继承，基类公有成员在类外不可见

	// 3. 测试保护继承Derived3
	cout << "\n----- 保护继承Derived3 -----" << endl;
	Derived3 d3(70, 80, 90);
	d3.testAccess();  // 类内访问基类成员
	// cout << d3.a;  // 错误：保护继承，基类公有成员在类外不可见

	// 4. 验证构造/析构次序（观察控制台输出）
	cout << "\n----- 验证构造/析构次序 -----" << endl;
	{
		Derived1 temp(1, 2, 3);  // 局部对象，作用域结束后析构
	}

	// 5. 静态成员（对象计数）测试
	cout << "当前总对象数：" << Base::Manage() << endl;

	return 0;
}