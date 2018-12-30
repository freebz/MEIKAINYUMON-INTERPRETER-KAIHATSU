// 10.4 while 문

code = firstCode(Pc);
top_line = Pc;			// while 문 시작 행
end_line = code.jmpAdrs;	// while 문 마지막 행

case While:
for ( ; ; ) {			                /*                    */
  if (!get_expression(While, 0)) break;         /*    거짓이면 종료   */
  ++Pc; block();                                /*    블록 실행       */
  if (break_Flg || return_Flg || exit_Flg) {    /*    종료 지시라면   */
    break_Flg = false; break;                   /*    중단            */
  }                                             /*                    */
  pc = top_line; code = firstCode(Pc);          /*    처음으로        */
}                                               /*                    */
pc = end_line + 1;                              /*    끝으로          */
break;
