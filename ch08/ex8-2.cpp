struct CodeSet {	   /* 코드 관리 */
  TknKind  kind;	   /* 종류      */
  const char *text;	   /* 문자열 리터럴일 때의 위치 */
  double   dblVal;	   /* 수치 상수일 때의 값       */
  int      symNbr;	   /* 심볼 테이블의 첨자 위치   */
  int      jmpAdrs;	   /* 점프할 주소               */
  CodeSet() { clear(); }
  CodeSet(TknKind k)           { clear(); kind=k; }
  CodeSet(TknKind k, double d) { clear(); kind=k; dblVal=d; }
  CodeSet(TknKind k, const char *s) { clear(); kind=k; text=s; }
  CodeSet(TknKind k, int sym, int jmp) {
    clear(); kind=k; symNbr=sym; jmpAdrs=jmp;

  }
  void clear() {
    kindOthers; text=""; dblVal=0.0; jmpAdrs=0; symNbr=-1;
  }
};
