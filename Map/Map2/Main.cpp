#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <string>

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



int main(void)
{
	/*
	map<string, list<StudentInfo>> StudentList;
	StudentList["A"].push_back(StudentInfo("��", 100, 200, 300));
	StudentList["A"].push_back(StudentInfo("��", 1000000, 2000000, 3000000));
	StudentList["B"].push_back(StudentInfo("��", 1, 2, 3));
	StudentList["B"].push_back(StudentInfo("��", 10, 20, 30));
	StudentList["B"].push_back(StudentInfo("��", 100, 200, 300));
	*/


	/*
	for (map<string, list<StudentInfo>>::iterator iter = StudentList.begin();
		iter != StudentList.end(); ++iter)
	{
		cout << iter->first << " �б�" << endl;
		for (list<StudentInfo>::iterator iter2 = iter->second.begin();
			iter2 != iter->second.end(); ++iter2)
		{
			cout << iter2->Name << endl;
			cout << "���� : " << iter2->Kor << endl;
			cout << "���� : " << iter2->Eng << endl;
			cout << "���� : " << iter2->Math << endl << endl;
		}
		cout << endl << endl;
	}
	*/

	/*
	map<string, list<StudentInfo>>::iterator iter = StudentList.find("B");
	for (list<StudentInfo>::iterator iter2 = iter->second.begin();
		iter2 != iter->second.end(); ++iter2)
	{
		cout << iter2->Name << endl;
		cout << "���� : " << iter2->Kor << endl;
		cout << "���� : " << iter2->Eng << endl;
		cout << "���� : " << iter2->Math << endl << endl;
	}
	*/

	/*
	multimap<string, int> StudentList;
	StudentList.insert(make_pair("��", 10));
	StudentList.insert(make_pair("��", 20));
	StudentList.insert(make_pair("��", 30));
	StudentList.insert(make_pair("��", 40));
	StudentList.insert(make_pair("��", 50));
	for (multimap<string, int>::iterator iter = StudentList.begin();
		iter != StudentList.end(); ++iter)
	{
		cout << (*iter).first << ", " << (*iter).second << endl;
	}
	*/

	/*
	class Object;
	//** Player �� Enemy ������ �Ÿ��� Ű������ ���.  Enemy ��  value ������ ���.
	multimap<float, Object*> EnemyList;
	*/

	return 0;
}