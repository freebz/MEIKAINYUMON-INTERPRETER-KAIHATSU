// 14.4 stack 컨테이너 어댑터

#include <iostream>
#include <stack>		// stack 어댑터
using namespace std;

int main()
{
  stack<int>  st;		// 가변 길이 스택 기능을 가진 st를 선언

  st.push(10); st.push(20); st.push(30); // 10 20 30을 저장

  while (!st.empty()) {		// 비더있지 않은 동안 루프
    cout << st.top() << " " << st.size() << endl;
    st.pop();			// 탑 요소를 삭제
  }				// 출력: 30 3
  return 0;			// 20 2
}				// 10 1
