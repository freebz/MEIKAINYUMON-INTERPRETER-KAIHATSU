// 11.5 오러랜드 스택과 실행 시간 스택

// 메모리 / 실행 시간 스택 준비

class Mymemory {
private:
  vector<double> mem;
  ...
};
Mymemory Dmem;			// 메모리. 이 안에 실행 시간 스택 확보


// 오퍼랜드 스택 준비

class Mystack {
private:
  stack<double> st;
  ...
};
Mystack stk;			// 오퍼랜드 스택 준비
