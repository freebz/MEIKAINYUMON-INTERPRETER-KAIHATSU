// 6.8.1 함수 정의 처리 방법

void fncDecl()			            // 함수 정의 처리
{
  ...
  fncDecl_F = true;		            // 함수 처리 시작 프래그
  localAdrs = 0;		            // 로컬 영역 할당 카운터 초기화
  set_startLtable();	                    // 로컬 심볼 테이블 등록 시작 위치 설정
  patch_line = setCode(Func, NO_FIX_ADRD);  // 내부 코드 Func를 출력

  fncTbNbr = searchName(함수명, 'F');       // 함수명의 심볼 테이블 위치 찾기
  Gtable[fncTblNbr].dtTyp = DEL_T;	    // 형 설정(형은 고정)

  for (가인수가 있는 동안) {
    이름을 tmpTb에 설정
    tblNbr = enter(tmpTb, paraId);          // 인수 등록
    setCode(Lvar, tblNbr);		    // 내부 코드 Lvar을 출력
    이 함수의 인수 개수를 +1
  }

  convert_block();		            // 함수 본체 처리
  내부 코드 Func의 NO_FIX_ADRS를 '현재 행'으로 수정
  Gtable[fncTblNbr].frame = localAdrs;      // 프레임 크기 설정

  함수명이 main이면 사양을 확인
  fncDecl_F = false;		            // 함수 처리 종료
}
