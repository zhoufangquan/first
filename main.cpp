#include "Student.h"

void input(ElemType &e) {
    cout << "请输入学生信息：学号   姓名   平时成绩   实验成绩   期末成绩：\n";
    cin >> e.Sno >> e.Sn >> e.Usual_grades >> e.Exp_grades >> e.Final_grade;
}

void print(ElemType &e) {
    cout << e.Sno << "\t" << e.Sn << "\t" << e.Usual_grades << "\t  " << e.Exp_grades << "\t  " << e.Final_grade
         << '\n';
}

void print(const Vector &v) {
    ElemType e;
    for (int i = 0; i < v.size(); i++) {
        v.get(i, e);
        print(e);
    }
    cout << endl;
}

bool cmp1(ElemType a, ElemType b) {
    double x = a.get_OER(), y = b.get_OER();
    return x - y > 1e-6;
}

bool cmp2(ElemType a, ElemType b) {
    int i = a.Sno.compare(b.Sno);
    return i < 0;
}

void help() {
    cout << "请输入命令:\n\n";
    cout << "   i--插入某个学生信息  e--删除某个学生信息    a--追加                 b--删除最后元素 \n";
    cout << "   m--修改某学生信息    q--查询某学生信息      p--打印全部学生信息     o--查看最终成绩 \n";
    cout << "   d--删除所有学生信息  1--各阶段学生成绩占比  2--按总评成绩排列打印   3--按学号顺序打印\n";
    cout << "   X--退出 \n\n";
}

//("0001", "张三", 12, 13, 14),
//("0002", "李四", 34, 53, 74),
//("0003", "王五", 12, 13, 14),
//("0004", "赵六", 54, 1, 88),
//("0005", "胜七", 100, 100, 100)
int main() {
    Vector students;
    students.push_back(ElemType{"0001", "张三", 12, 13, 14});
    students.push_back(ElemType{"0002", "李四", 34, 53, 74});
    students.push_back(ElemType{"0003", "王五", 12, 13, 14});
    students.push_back(ElemType{"0004", "赵六", 54, 1, 88});
    students.push_back(ElemType{"0005", "胜七", 90, 60, 80});
    students.push_back(ElemType{"0007", "赵", 85, 86, 95});
    students.push_back(ElemType{"0008", "魏", 77, 88, 99});
    students.push_back(ElemType{"0014", "慕容", 77, 77, 75});
    students.push_back(ElemType{"0015", "南宫", 99, 60, 60});
    students.push_back(ElemType{"0010", "燕", 100, 60, 92});
    students.push_back(ElemType{"0009", "楚", 99, 93, 94});
    students.push_back(ElemType{"0016", "独孤", 100, 100, 100});
    students.push_back(ElemType{"0013", "皇甫", 99, 90, 100});
    students.push_back(ElemType{"0006", "韩", 93, 91, 88});
    students.push_back(ElemType{"0011", "齐", 88, 88, 88});
    students.push_back(ElemType{"0012", "欧阳", 15, 51, 99});
    ElemType e;
    char cmd;
    help();
    while (cin >> cmd) {
        cout << '\n';
        if (cmd == 'I' || cmd == 'i') {
            while (1) {
                cout << "请输入插入的位置（从0开始）： ";
                int i;
                cin >> i;
                input(e);
                students.insert(i, e);
                cout << "\n是否继续插入了? (Y/N) --";
                string YN;
                cin >> YN;
                if (YN[0] == 'N' || YN[0] == 'n') break;
            }
        } else if (cmd == 'e' || cmd == 'E') {
            while (1) {
                cout << "请输入需要删除的学生的学号（‘XXXX’）： ";
                string s0;
                cin >> s0;
                ElemType e0;
                for (int i = 0; i < students.size(); i++) {
                    students.get(i, e0);
                    if (e0.Sno.compare(s0) == 0) {
                        students.erase(i);
                        break;
                    }
                }
                cout << "\n是否继续删除了? (Y/N) --";
                string YN;
                cin >> YN;
                if (YN[0] == 'N' || YN[0] == 'n') break;
            }
        } else if (cmd == 'a' || cmd == 'A') {
            while (1) {
                input(e);
                students.push_back(e);
                cout << "\n是否继续追加学生信息了? (Y/N) --";
                string YN;
                cin >> YN;
                if (YN[0] == 'N' || YN[0] == 'n') break;
            }
        } else if (cmd == 'b' || cmd == 'B') {
            while (1) {
                students.pop_back();
                cout << "\n是否继续删除学生信息了? (Y/N) --";
                string YN;
                cin >> YN;
                if (YN[0] == 'N' || YN[0] == 'n') break;
            }
        } else if (cmd == 'm' || cmd == 'M') {
            while (1) {
                cout << "请输入要修改的学生的学号（'XXXX'）：";
                string sno;
                cin >> sno;
                for (int j = 0; j < students.size(); j++) {
                    ElemType e0;
                    students.get(j, e0);
                    if (e0.Sno.compare(sno) == 0) {
                        input(e);
                        students.set(j, e);
                    }
                }
                cout << "\n是否继续修改学生信息了? (Y/N) --";
                string YN;
                cin >> YN;
                if (YN[0] == 'N' || YN[0] == 'n') break;
            }
        } else if (cmd == 'q' || cmd == 'Q') {
            while (1) {
                cout << "请输入要查询的学生信息的学号（‘XXXX’）： ";
                ElemType e0;
                string s0;
                cin >> s0;
                for (int i = 0; i < students.size(); i++) {
                    students.get(i, e0);
                    if (e0.Sno.compare(s0) == 0) {
                        cout << "学号\t姓名\t平时成绩 实验成绩 期末成绩：\n\n";
                        print(e0);
                        break;
                    }
                }
                cout << "\n是否继续查询学生信息了? (Y/N) --";
                string YN;
                cin >> YN;
                if (YN[0] == 'N' || YN[0] == 'n') break;
            }
        } else if (cmd == 'p' || cmd == 'P') {
            cout << "学号\t姓名\t平时成绩 实验成绩 期末成绩：\n\n";
            print(students);
        } else if (cmd == 'o' || cmd == 'O') {
            cout << "学号\t姓名\t最终成绩\n\n";
            ElemType e0;
            for (int i = 0; i < students.size(); i++) {
                students.get(i, e0);
                cout << e0.Sno << "\t" << e0.Sn << "\t" << e0.get_OER() << "\n";
            }
        } else if (cmd == 'd' || cmd == 'D') {
            int n0 = students.size();
            cout << "确认要删除所有的学生信息吗？(Y/N) --";
            string yn;
            cin >> yn;
            if (yn[0] == 'Y' || yn[0] == 'y') {
                for (int i = 0; i < n0; i++) {
                    students.pop_back();
                }
                cout << "清空完成！\n";
            }
        } else if (cmd == '1') {
            int grades[5] = {0, 0, 0, 0, 0};
            ElemType e0;
            for (int i = 0; i < students.size(); i++) {
                students.get(i, e0);
                if (e0.get_OER() < 60) grades[0]++;
                else if (60 <= e0.get_OER() && e0.get_OER() < 70) grades[1]++;
                else if (70 <= e0.get_OER() && e0.get_OER() < 80) grades[2]++;
                else if (70 <= e0.get_OER() && e0.get_OER() < 90) grades[3]++;
                else grades[4]++;
            }
            for (int i = 0; i < 5; i++) {
                if (i == 0) {
                    cout << "成绩不及格人数及百分比：" << grades[i] << "  "
                         << (int) (10000.0 * grades[i]) / (students.size() * 100.0 + 1e-6) << "%\n";
                } else if (i == 1) {
                    cout << "成绩合格人数及百分比：" << grades[i] << "  "
                         << (int) (10000.0 * grades[i]) / (students.size() * 100.0 + 1e-6) << "%\n";
                } else if (i == 2) {
                    cout << "成绩中等人数及百分比：" << grades[i] << "  "
                         << (int) (10000.0 * grades[i]) / (students.size() * 100.0 + 1e-6) << "%\n";
                } else if (i == 3) {
                    cout << "成绩良好人数及百分比：" << grades[i] << "  "
                         << (int) (10000.0 * grades[i]) / (students.size() * 100.0 + 1e-6) << "%\n";
                } else {
                    cout << "成绩优秀人数及百分比：" << grades[i] << "  "
                         << (int) (10000.0 * grades[i]) / (students.size() * 100.0 + 1e-6) << "%\n";
                }
            }
        } else if (cmd == '2') {
            vector<ElemType> S0;
            ElemType e0;
            for (int i = 0; i < students.size(); i++) {
                students.get(i, e0);
                S0.push_back(e0);
            }
            cout << "名次\t学号\t姓名\t平时成绩 实验成绩 期末成绩 总评成绩：\n\n";
            sort(S0.begin(), S0.end(), cmp1);
            for (int i = 0; i < S0.size(); i++) {
                cout << i + 1 << "\t" << S0[i].Sno << "\t" << S0[i].Sn << "\t" << S0[i].Usual_grades << "\t  "
                     << S0[i].Exp_grades << "\t  " << S0[i].Final_grade << "\t  " << S0[i].get_OER() << '\n';
            }
            S0.clear();
        } else if (cmd == '3') {
            vector<ElemType> S0;
            ElemType e0;
            for (int i = 0; i < students.size(); i++) {
                students.get(i, e0);
                S0.push_back(e0);
            }
            cout << "学号\t姓名\t平时成绩 实验成绩 期末成绩 总评成绩：\n\n";
            sort(S0.begin(), S0.end(), cmp2);
            for (int i = 0; i < S0.size(); i++) {
                cout << S0[i].Sno << "\t" << S0[i].Sn << "\t" << S0[i].Usual_grades << "\t  "
                     << S0[i].Exp_grades << "\t  " << S0[i].Final_grade << "\t  " << S0[i].get_OER() << '\n';
            }
            S0.clear();
        } else if (cmd == 'X') {
            return 0;

        }
        cout << '\n';
        help();
    }
}
