// 6.8.2 로컬용 심볼 테이블 준비

int startLtable;		// 로컬 심볼 테이블의 저장 시작 위치

void set_startLtable()		// 로컬 심볼 테이블의 시작 위치 설정
{
  startLtable = Ltable.size();
}
