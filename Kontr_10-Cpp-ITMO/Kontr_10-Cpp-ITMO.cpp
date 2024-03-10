// Kontr_10-Cpp-ITMO.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <cmath>
#include <iostream>
#include <stdexcept>
#include <math.h>
#include "Dot.h"
# include <windows.h>

using namespace std;

// class TriangleComposition - класс в котором треугольник - композиция точек
class TriangleComposition {
public:
    explicit TriangleComposition(
        // точки для треугольника
        double x1,
        double y1,
        double x2,
        double y2,
        double x3,
        double y3
    )
        : point_x1y1(x1, y1),
        point_x2y2(x2, y2),
        point_x3y3(x3, y3) {
        side1_2 = Side_1_2_Length(); // Нахождение длины стороны 1_2 (от точек x1 y1 до точек x2 y2)
        side2_3 = Side_2_3_Length(); //  Нахождение длины стороны 2_3 (от точек x2 y2 до точек x3 y3)
        side3_1 = Side_3_1_Length();  //  Нахождение длины стороны 3_1 (от точек x3 y3 до точек x1 y1)
        if (side1_2 > side2_3 + side3_1 ||
            side2_3 > side1_2 + side3_1 ||
            side3_1 > side1_2 + side2_3) {
            wcout << L"Одна сторона треугольника не может быть больше суммы двух других сторон !\nВведите точки занова !" << endl;
            chak_saids1 = true;
        }
        else {
            chak_saids1 = false;
        }
    }
    // Проверка сторон треугольника
    bool chack() {
        return chak_saids1;
    }

    // Нахождение длины стороны 1_2 (от точек x1 y1 до точек x2 y2)
    double Side_1_2_Length() {
        return point_x1y1.DistanceTo(point_x2y2);
    }

    //  Нахождение длины стороны 2_3 (от точек x2 y2 до точек x3 y3)
    double Side_2_3_Length() {
        return point_x2y2.DistanceTo(point_x3y3);
    }

    //  Нахождение длины стороны 3_1 (от точек x3 y3 до точек x1 y1)
    double Side_3_1_Length() {
        return point_x3y3.DistanceTo(point_x1y1);
    }

    // Нахождение периметра треугольника
    double Perimeter() {
        return side1_2 + side2_3 + side3_1;
    }

    // Нахождение площади треугольника
    double Square() {
        double p = Perimeter() / 2;
        return sqrt( p * (p - side1_2) * (p - side2_3) * (p - side3_1)
        );
    }

private:
    Dot point_x1y1;
    Dot point_x2y2;
    Dot point_x3y3;

    double side1_2;
    double side2_3;
    double side3_1;

    bool chak_saids1 = false;
};

// class TriangleAggregation - класс в котором треугольник - агрегация точек
class TriangleAggregation {
public:
    explicit TriangleAggregation(Dot first, Dot second, Dot third)
        : point_x1y1(first), point_x2y2(second), point_x3y3(third) {
        side1_2 = Side_1_2_Length(); // Нахождение длины стороны 1_2 (от точек x1 y1 до точек x2 y2)
        side2_3 = Side_2_3_Length(); //  Нахождение длины стороны 2_3 (от точек x2 y2 до точек x3 y3)
        side3_1 = Side_3_1_Length();  //  Нахождение длины стороны 3_1 (от точек x3 y3 до точек x1 y1)
        if (side1_2 > side2_3 + side3_1 ||
            side2_3 > side1_2 + side3_1 ||
            side3_1 > side1_2 + side2_3) {
            wcout << L"Одна сторона треугольника не может быть больше суммы двух других сторон !\nВведите точки занова !" << endl;
            chak_saids2 = true;
        }
        else {
            chak_saids2 = false;
        }
    }
    // Проверка сторон треугольника
    bool chack() {
        return chak_saids2;
    }
        // Нахождение длины стороны 1_2 (от точек x1 y1 до точек x2 y2)
    double Side_1_2_Length() {
        return point_x1y1.DistanceTo(point_x2y2);
    }

    //  Нахождение длины стороны 2_3 (от точек x2 y2 до точек x3 y3)
    double Side_2_3_Length() {
        return point_x2y2.DistanceTo(point_x3y3);
    }

    //  Нахождение длины стороны 3_1 (от точек x3 y3 до точек x1 y1)
    double Side_3_1_Length() {
        return point_x3y3.DistanceTo(point_x1y1);
    }

    // Нахождение периметра треугольника
    double Perimeter() {
        return side1_2 + side2_3 + side3_1;
    }

    // Нахождение площади треугольника
    double Square() {
        double p = Perimeter() / 2;
        return sqrt(p * (p - side1_2) * (p - side2_3) * (p - side3_1)
        );
    }

private:
    Dot point_x1y1;
    Dot point_x2y2;
    Dot point_x3y3;

    double side1_2;
    double side2_3;
    double side3_1;

    bool chak_saids2 = false;
};

int main() {
    setlocale(LC_CTYPE, "rus");

    double x1;
    double y1;
    double x2;
    double y2;
    double x3;
    double y3;

label1:
    wcout << L"Введите точки для сторон треугольника:" << endl;
    wcout << L"-введите точку x1(композиция): ";
    cin >> x1;
    wcout << L"-введите точку y1(композиция): ";
    cin >> y1;
    wcout << L"-введите точку x2(композиция): ";
    cin >> x2;
    wcout << L"-введите точку y2(композиция): ";
    cin >> y2;
    wcout << L"-введите точку x3(композиция): ";
    cin >> x3;
    wcout << L"-введите точку y3(композиция): ";
    cin >> y3;
    cout << "- - - - - - - - - - - - - - - -" << endl;

    TriangleComposition treangle1(x1, y1, x2, y2, x3, y3);
    bool chak_saids = treangle1.chack();
    if (chak_saids == true) {
        goto label1;
    }
    wcout << L"-сторона 1 (композиция) = " << treangle1.Side_1_2_Length() << endl;
    wcout << L"-сторона 2 (композиция) = " << treangle1.Side_2_3_Length() << endl;
    wcout << L"-сторона 3 (композиция) = " << treangle1.Side_3_1_Length() << endl;
    wcout << L"-Периметр (композиция) = " << treangle1.Perimeter() << endl;
    wcout << L"-Площадь (композиция) = " << treangle1.Square() << endl;
    cout << "------------------------------" << endl;

label2:
    wcout << L"Введите точки для сторон треугольника:" << endl;
    wcout << L"-введите точку x1(агрегация): ";
    cin >> x1;
    wcout << L"-введите точку y1(агрегация): ";
    cin >> y1;
    wcout << L"-введите точку x2(агрегация): ";
    cin >> x2;
    wcout << L"-введите точку y2(агрегация): ";
    cin >> y2;
    wcout << L"-введите точку x3(агрегация): ";
    cin >> x3;
    wcout << L"-введите точку y3(агрегация): ";
    cin >> y3;
    cout << "- - - - - - - - - - - - - - - -" << endl;
    TriangleAggregation treangle2(Dot{ x1, y1 }, Dot{ x2, y2 }, Dot{ x3, y3 });

    chak_saids = treangle2.chack();
    if (chak_saids == true) {
        goto label2;
    }
    wcout << L"-сторона 1 (агрегация) = " << treangle2.Side_1_2_Length() << endl;
    wcout << L"-сторона 2 (агрегация) = " << treangle2.Side_2_3_Length() << endl;
    wcout << L"-сторона 3 (агрегация) = " << treangle2.Side_3_1_Length() << endl;
    wcout << L"-Периметр (агрегация) = " << treangle2.Perimeter() << endl;
    wcout << L"-Площадь (агрегация) = " << treangle2.Square() << endl;
    cout << "------------------------------" << endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
