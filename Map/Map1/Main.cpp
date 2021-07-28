#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <string>

// ����Ʈ, ����, ��, ��Ʈ�� �� ���̺귯�� ��� �� �� �����
using namespace std;

struct StudentInfo
{
	string Name;
	int Kor;
	int Eng;
	int Math;

	StudentInfo() {}
	StudentInfo(string _Name, int _Kor, int _Eng, int _Math)
		: Name(_Name), Kor(_Kor), Eng(_Eng), Math(_Math) {}
};

//StudentInfo CreateStudentInfo(string _name, int _kor, int _eng, int _math);

int main(void)
{
	/*
	//** [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
	int Array[10] = { 0 ,1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int* pi = Array;
	for (int i = 0; i < 10; ++i)
	{
	}
	cout << *(pi + 5) << endl;
	cout << Array[5] << endl;
	*/

	/*
	// ����Ʈ ����
	map<int, string> NumberList;
	NumberList.insert(make_pair(1, "��"));
	NumberList.insert(make_pair(2, "��"));
	NumberList.insert(make_pair(3, "��"));
	NumberList.insert(make_pair(4, "��"));
	NumberList.insert(make_pair(5, "��"));
	NumberList.insert(make_pair(6, "��"));
	NumberList.insert(make_pair(7, "ĥ"));
	NumberList.insert(make_pair(8, "��"));
	NumberList.insert(make_pair(9, "��"));
	*/

	// ������ �����ϰ� ���� ���
	// �̰� �ȵ�
	//NumberList.insert(make_pair(1, "��"));
	//NumberList.insert(make_pair(2, "��"));
	//NumberList.insert(make_pair(3, "ĥ"));
	//NumberList.insert(make_pair(4, "��"));
	//NumberList.insert(make_pair(5, "��"));
	//NumberList.insert(make_pair(6, "��"));
	//NumberList.insert(make_pair(7, "��"));
	//NumberList.insert(make_pair(8, "��"));
	//NumberList.insert(make_pair(9, "��"));

	/*
	// ���� �ذ� ���
	NumberList[1] = "��";
	NumberList[2] = "��";
	NumberList[3] = "ĥ";
	NumberList[4] = "��";
	NumberList[5] = "��";
	NumberList[6] = "��";
	NumberList[7] = "��";
	NumberList[8] = "��";
	NumberList[9] = "��";
	*/

	/*
	// ��ü ���
	for (map<int, string>::iterator iter = NumberList.begin();
		iter != NumberList.end(); ++iter)
	{
		cout << (*iter).first << ". " << (*iter).second << endl;
	}
	map<int, string>::iterator iter = NumberList.find(3);
	cout << iter->second << endl;
	*/

	map<int, StudentInfo> StudentList;

	//** �ǽ�

	/*
	�� �����̳ʿ� �����͸� �߰��� �Ʒ��ʿ��� ��Ȱ�� ��µ� �� �ֵ��� �غ���.
	1. ȫ�浿
	�������� : 1
	�������� : 2
	�������� : 3
	2. �Ӳ���
	�������� : 10
	�������� : 20
	�������� : 30
	3. �̸���
	�������� : 100
	�������� : 200
	�������� : 300
	*/

	/*
	// �Լ��� �̿� ���
	StudentList.insert(make_pair(1,
		CreateStudentInfo("��", 1, 2, 3)));
	StudentList.insert(make_pair(2,
		CreateStudentInfo("��", 10, 20, 30)));
	StudentList.insert(make_pair(3,
		CreateStudentInfo("��", 100, 200, 300)));
	*/

	//** ���� ������ ���
	StudentList.insert(make_pair(1,
		StudentInfo("��", 1, 2, 3)));

	StudentList.insert(make_pair(2,
		StudentInfo("��", 10, 20, 30)));

	StudentList.insert(make_pair(3,
		StudentInfo("��", 100, 200, 300)));





	//** ��ü ���
	for (map<int, StudentInfo>::iterator iter = StudentList.begin();
		iter != StudentList.end(); ++iter)
	{
		cout << (*iter).first << ". " << (*iter).second.Name << endl;
		cout << "���� : " << (*iter).second.Kor << endl;
		cout << "���� : " << (*iter).second.Eng << endl;
		cout << "���� : " << (*iter).second.Math << endl << endl;
	}

	return 0;
}

/*
StudentInfo CreateStudentInfo(string _name, int _kor, int _eng, int _math)
{
	StudentInfo Info;
	Info.Name = _name;
	Info.Kor = _kor;
	Info.Eng = _eng;
	Info.Math = _math;
	return Info;
}
*/