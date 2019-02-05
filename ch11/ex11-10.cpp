// 11.7.4 인수의 저장

nextCode(); code = nextCode();	// Func ( 건너뛰기
if (code.kind != ')') { 	// 인수 있음
  for (; ; code = nextCode()) {
    set_dtTyp(code, DEL_T);	// 대입 시에 형 확정
    Dmem.set(get_memAdrs(code), stk.pop()); // 실인수 값 저장
    if (code.kind != ',') break;	    // 인수 종료
  }
 }
code = nextCode();		// ) 건너뛰기
