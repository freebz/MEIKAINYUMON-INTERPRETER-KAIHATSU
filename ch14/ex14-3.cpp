// 14.3 vector 컨테이너

int d[100];
d[0] = 1;
d[99] = 2;


vector<int> a;       // int 형 가변 길이 배열
vector<double> b;    // double 형 가변 길이 배열


#include <iostream>
#include <vector>		// vector 사용
using namespace std;

int main()
{
  vector<int> v;		          // int 형 vector
  vector<int>::iterator p;	          // 반복자

  v.push_back(10);		          // int 추가 값
  v.push_back(20);
  v.push_back(30);

  for (p=v.begin(); p != v.end(); ++p) {  // 반복자로 처리
    cout << *p << " ";			  // 출력: 10 20 30
  }
  cout << endl;

  for ( int i=0; i < (int)v.size(); i++)  // 첨자로 처리
    cout << v[i] << " ";		  // 출력: 10 20 30
  cout << endl;
  return 0;
}
