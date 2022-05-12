#include "node.h"
#include "monom.h"
#include "polinom.h"
#include <iostream>
#include <string>

using namespace std;

void Calculation(TPolinom& a, TPolinom& b) {
    int calc = -1;
    double x, y, z;
    cout << "1. ��������� ��� ������� ��������\n";
    cout << "2. ��������� ��� ������� ��������\n";
    cout << "0. �����\n";
    cout << ">";
    cin >> calc;
    cout << std::endl;
    cout << "������� �������� x, y, z:" << std::endl;
    cin >> x;
    cout << "\t";
    cin >> y;
    cout << "\t";
    cin >> z;
    cout << std::endl;
    switch (calc) {
    case 1:
        cout << "����������.." << std::endl;
        cout << a(x, y, z) << std::endl;
        break;
    case 2:
        cout << "����������.." << std::endl;
        cout << b(x, y, z) << std::endl;
        break;
    case 0:
        break;
    default:
        cout << "Error, bad input\n";
        break;
    }
}


void Change(TPolinom& a, TPolinom& b) {
    string str1;
    string str2;
    
    int change = -1;
    while (change != 0)
    {
        cout << "1. �������� ������ ������ �������\n";
        cout << "2. �������� ������ ������ �������\n";
        cout << "3. �������� ��� ��������\n";
        cout << "0. �����\n";
        cout << ">";
        cin >> change;
        switch (change) {
        case 1:
            cout << "������� ������ �������:";
            cin >> str1;
            cout << std::endl;
            a = str1;
            cout << "��������� �������: \n";
            cout << a << std::endl;

            break;
        case 2:
            cout << "������� ������ �������:";
            cin >> str2;
            cout << std::endl;
            b = str2;
            cout << "��������� �������: \n";
            cout << b << std::endl;
            break;
        case 3:
            cout << "������� ������ �������:";
            cin >> str1;
            cout << std::endl;
            a = str1;
            cout << "������� ������ �������:";
            cin >> str2;
            cout << std::endl;
            b = str2;
            cout << "��������� ��������: \n";
            cout << a << std::endl;
            cout << b << std::endl;
            break;
        case 0:
            break;
        default:
            cout << "Error, bad input\n";
            break;
        }
    }
}

int main()
{
    int input = -1;

    setlocale(LC_ALL, "Russian");
    cout << "START" << std::endl;
    TPolinom p1;
    TPolinom p2;
    while (input != 0)
    {
        cout << "\t ===MENU=== \t" << std::endl;
        cout << "������� 1 = " << p1 << "\t" << "������� 2 = " << p2 << std::endl;
        cout << "1. �������� ��������\n";
        cout << "2. ��������\n";
        cout << "3. ��������� �� ������� �������� �������\n";
        cout << "4. ���������\n";
        cout << "5. ��������� �������� �������� 1 ��� 2 ��� �������� ���������\n";
        cout << "0. �����\n";
        cout << "�����: ";
        cin >> input;
        cout << std::endl;
        while (!(-1 < input < 6)) {
            cout << "������������ ����. ���������� ��� ���: ";
            cin >> input;
            cout << std::endl;
        }
        switch (input) {
          case 1:
              Change(p1, p2);
              break;
          case 2:
              cout << "��������.." << std::endl;
              cout << p1 + p2 << std::endl;
              break;
          case 3:
              cout << "���������.." << std::endl;
              cout << p1 - p2 << std::endl;
              break;
          case 4:
              cout << "���������.." << std::endl;
              cout << p1 * p2 << std::endl;
              break;
          case 5:
              Calculation(p1, p2);
              break;
          case 0:
              break;
          default:
              cout << "������, ������������ ����\n";
              break;
    }
    }
    cout << "FINISH" << std::endl;
	return 0;
}
