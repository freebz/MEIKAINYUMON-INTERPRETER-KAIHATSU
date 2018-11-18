// 구현할 구조체의 예

enum SymKind { noId, varId, fncId, paraId }; /* 종류   */
enum DtType { NON_T, DBL_T };		     /* 타입명 */

struct SymTbl {			/* 심볼 테이블 구성       */
  string  name;			/* 변수나 함수 이름       */
  SymKind nmKind;		/* 종류                   */
  char    dtTyp;		/* 변수형(NON_T,DBL_T)    */
  int     aryLen;		/* 배열 길이. 0:단순 변수 */
  short   args;			/* 함수의 인수 개수       */
  int     adrs;			/* 변수, 함수의 주소      */
  int     frame;		/* 함수용 로컬 영역 크기  */
  SymTbl() { clear(); }
  void clear() {
    name=""; nmKind=noId; dtTyp=NON_T;
    aryLen=0; args=0; adrs=0; frame=0;
  }
};

vector<SymTbl> Gtable;		/* 글로벌 심볼 테이블 */
vector<SymTbl> LTable;		/* 로컬 심볼 테이블   */
