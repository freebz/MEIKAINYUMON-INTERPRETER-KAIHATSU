// 6.8.8 main 함수 처리

int mainTblNbr = -1;

void fncDecl()			// 함수 정의
{
  ...
  if (Gtable[fncTblNbr].name == "main") {
    mainTblNbr = fncTblNbr;
    if (Gtable[mainTblNbr].args != 0)
      err_exit("main 함수에서는 가인수를 지정할 수 없습니다.");
  }
  fncDecl_F = false;		// 함수 처리 종료
}


void convert_to_internalCode(char *fname)     // 코드 변환 시작
{
  문자 종류표 등 초기화
  함수 정의명만 먼저 등록한다
  내부 코드로 변환한다

  // main() 함수가 있으면 그 호출 코드를 설정
  set_startPc(1);  		              // 1행부터 실행 시작
  if (mainTblNbr != -1) {
    set_startPc(intercode.size());            // main()으로부터 실행 시작
    setCode(Fcall, mainTblNbr); setCode('('); setCode(')');
    push_intercode();
  }
}
