class Mystack {			      // stack<double>의 래퍼
private:
  stack<double> st;
public:
  void push(double n) { st.push(n); } // 스택에 넣기
  int size { return (int)st.size(); } // 크기
  bool empty() { return st.empty(); } // 비었는지 판정
  double pop() {		      // 읽어내기 & 삭제
    if (st.empty()) err_exit("stack underflow");
    double d = st.top();	      // 최상위 값
    st.pop; return d;		      // 하나 삭제
  }
};
Mystack stk;


용법
PUSH 처리: stk.push(n);
POP 처리 : n = stk.pop();
