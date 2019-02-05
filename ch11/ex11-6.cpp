// 11.6.2 인수의 저장 순서

void fncCall(int fncNbr)	        // 함수 호출
{
  int n, argCt = 0;
  vector<double> vc;

  // 실인수 저장
  nextCode(); code = nextCode();        // 함수명 ( 건너뛰기
  if(code.kind != ')') {	        // 인수가 있다
    for (; ; code = nextCode()) {
      expression();		        // 인수 식 처리와 인수 개수      
      ++argCt;			        // 인수 개수 카운트
      if ( code.kind != ',') break;     // ,이면 인수가 계속된다
    }
  }
  code = nextCode()		        // ) 건너뛰기

  // 인수 저장 순서 변경
  for (n=0; n < argCt; n++) vc.push_back(stk.pop());
  for (n=0; n < argCt; n++) { stk.push(vc[n]); }

  // 함수 실행
  fncExec(fncNbr);
}
