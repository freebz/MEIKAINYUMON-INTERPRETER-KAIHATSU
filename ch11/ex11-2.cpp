// 11.2 함수 호출 방법

void factor()			// 인자
{
  switch (code.kind) {
  ...
  case Fcall:
    fncCall(code.symNbr);
    break;
  ...
  }
}

void fncCall(int fncNbr)	// 함수 호출
{
  실인수 저장
  fncExec(fncNbr);
}

void fncExec(int fncNbr)	// 함수 실행
{
  함수 입구 처리
  함수 본체 처리
  함수 출구 처리
}
