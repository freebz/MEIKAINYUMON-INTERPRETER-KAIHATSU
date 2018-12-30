case For:			    /* for 제어 변수, 초깃값, 최종값, 증분식 */
   save = netCode();
   varAdrs = get_memAdrs(save);     /* 제어 변수 주소 구하기 */

   expression('=', 0);		    /* 초기값  */
   set_dtTyp(save, DBL_T);          /* 형 확정 */
   Dmem.set(varAdrs, stk.pop());    /* 초깃값을 설정 */

   endDt = get_expression(To, 0);   /* 최종값을 보존 */
                                    /* 증분값을 보존 */

   if (code.kind == Step) stepDt = get_expression(Step, 0);
   else stepDt = 1.0;

   for (;; Pc=top_line) {                         /*                   */
     if (stepDt >= 0) {                           /*    증가 루프      */
       if (Dmem.get(varAdrs) > endDt) break;      /*    거짓이면 종료  */
     } else {                                     /*    감소 루프      */
       if (Dmem.get(varAdrs) < endDt) break;      /*    거짓이면 종료  */
     }                                            /*                   */
     ++Pc; block();
     if (break_Flg || return_Flg || exit_Flg) {   /*    [실행]         */
       break_Flg = false; break;                  /*    중단           */
     }                                            /*                   */
     Dmem.add(varAdrs, stepDt);                   /*    값 갱신        */
     Pc = end_line + 1;                           /*                   */
     break;
