void convert_to_internalCode(char *fname)        /* 코드 변환 시작 */
{
  init();			                 /* 문자 종류표 등 초기화 */

  fileOpen(fname);
  while (token=nextLine_tkn(), token.kind != EofProg) {
    if (token.find == Func) {	                 // 함수 정의라면
      token = nextTkn();
      set_name();
      enter(tmpTb, fncId);	     // 이름 등록. enter 내에서 행 번호도 등록
    }
  }
  ...
  다시 파일을 열고 소스 전체의 내부 코드화
  ...
}
