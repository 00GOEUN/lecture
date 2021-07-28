#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <string>

// 리스트, 백터, 맵, 스트링 등 라이브러리 사용 시 꼭 써야함
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
	// 리스트 선언
	map<int, string> NumberList;
	NumberList.insert(make_pair(1, "일"));
	NumberList.insert(make_pair(2, "이"));
	NumberList.insert(make_pair(3, "삼"));
	NumberList.insert(make_pair(4, "사"));
	NumberList.insert(make_pair(5, "오"));
	NumberList.insert(make_pair(6, "육"));
	NumberList.insert(make_pair(7, "칠"));
	NumberList.insert(make_pair(8, "팔"));
	NumberList.insert(make_pair(9, "구"));
	*/

	// 위에서 선언하고 변경 방법
	// 이건 안됨
	//NumberList.insert(make_pair(1, "구"));
	//NumberList.insert(make_pair(2, "팔"));
	//NumberList.insert(make_pair(3, "칠"));
	//NumberList.insert(make_pair(4, "육"));
	//NumberList.insert(make_pair(5, "오"));
	//NumberList.insert(make_pair(6, "사"));
	//NumberList.insert(make_pair(7, "삼"));
	//NumberList.insert(make_pair(8, "이"));
	//NumberList.insert(make_pair(9, "일"));

	/*
	// 변경 해결 방안
	NumberList[1] = "구";
	NumberList[2] = "팔";
	NumberList[3] = "칠";
	NumberList[4] = "육";
	NumberList[5] = "오";
	NumberList[6] = "사";
	NumberList[7] = "삼";
	NumberList[8] = "이";
	NumberList[9] = "일";
	*/

	/*
	// 전체 출력
	for (map<int, string>::iterator iter = NumberList.begin();
		iter != NumberList.end(); ++iter)
	{
		cout << (*iter).first << ". " << (*iter).second << endl;
	}
	map<int, string>::iterator iter = NumberList.find(3);
	cout << iter->second << endl;
	*/

	map<int, StudentInfo> StudentList;

	//** 실습

	/*
	위 컨테이너에 테이터를 추가여 아래쪽에서 원활히 출력될 수 있도록 해보자.
	1. 홍길동
	국어점수 : 1
	영어점수 : 2
	수학점수 : 3
	2. 임꺽정
	국어점수 : 10
	영어점수 : 20
	수학점수 : 30
	3. 이몽룡
	국어점수 : 100
	영어점수 : 200
	수학점수 : 300
	*/

	/*
	// 함수를 이용 방법
	StudentList.insert(make_pair(1,
		CreateStudentInfo("일", 1, 2, 3)));
	StudentList.insert(make_pair(2,
		CreateStudentInfo("이", 10, 20, 30)));
	StudentList.insert(make_pair(3,
		CreateStudentInfo("삼", 100, 200, 300)));
	*/

	//** 복사 생성자 방법
	StudentList.insert(make_pair(1,
		StudentInfo("일", 1, 2, 3)));

	StudentList.insert(make_pair(2,
		StudentInfo("이", 10, 20, 30)));

	StudentList.insert(make_pair(3,
		StudentInfo("삼", 100, 200, 300)));





	//** 전체 출력
	for (map<int, StudentInfo>::iterator iter = StudentList.begin();
		iter != StudentList.end(); ++iter)
	{
		cout << (*iter).first << ". " << (*iter).second.Name << endl;
		cout << "국어 : " << (*iter).second.Kor << endl;
		cout << "영어 : " << (*iter).second.Eng << endl;
		cout << "수학 : " << (*iter).second.Math << endl << endl;
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