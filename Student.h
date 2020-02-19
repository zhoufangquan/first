//
// Created by molin on 2020/2/15.
//

#ifndef LIBRARY_STUDENT_H
#define LIBRARY_STUDENT_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Student {
private:
    double overall_evaluation_grade;
public:
    string Sno, Sn;
    double Usual_grades, Exp_grades, Final_grade;

    Student() {}

    Student(string Sno1, string Sn1, double Usual_grades1, double Exp_grades1, double Final_grade1) {
        Sno = Sno1;
        Sn = Sn1;
        Usual_grades = Usual_grades1;
        Exp_grades = Exp_grades1;
        Final_grade = Final_grade1;
        overall_evaluation_grade = 0.3 * Usual_grades + 0.3 * Exp_grades + 0.4 * Final_grade;
    }

    /*Student(string Sno1 = "", string Sn1="", double Usual_grades1=0.0, double Exp_grades1=0.0, double Final_grade1=0.0):
        Sno(Sno1),Sn(Sn1),Usual_grades(Usual_grades1),Exp_grades(Exp_grades1),Final_grade(Final_grade1){}*/

    double get_OER() {
        return 0.3 * Usual_grades + 0.3 * Exp_grades + 0.4 * Final_grade;
    }
};

using ElemType = Student;

class Vector {
    ElemType *data{nullptr};
    int capacity = 0, n = 0;
public:
    Vector(const int cap = 5)
            : capacity{cap}, data{new ElemType[cap]} {};

    bool insert(const int i, const ElemType &e);

    bool erase(const int i);

    bool push_back(const ElemType &e);

    bool pop_back();

    bool get(const int i, ElemType &e) const;

    bool set(const int i, const ElemType e);

    /*ElemType &get_bata() {
        return *data;
    }*/
    int size() const { return n; }

private:
    bool add_capacity();
};
/*
侠客行 金庸 广州出版社 59.6
岛上书店 加不瑞埃拉•泽文 江苏出版社 26.2
流浪地球 刘慈欣 xx电子出版社 43.4
C语言 张桂珠 北邮 36.8
大秦帝国 孙皓晖 上海人民出版社 35.2
*/

#endif //LIBRARY_STUDENT_H
