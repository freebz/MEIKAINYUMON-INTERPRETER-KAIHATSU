case If:
  // if
  if (get_expression(If, 0)) {                    /*  참이면    */
    ++Pc; block(); Pc = end_line + 1;             /*  실행하고  */
    return;                                       /*  종료      */
  }
  Pc = save.jmpAdrs;                              /*  다음으로  */
  // elif
  while (lookCode(Pc) == Elif) {
    save = firstCode(Pc); code = nextCode();
    if (get_expression()) {                       /*  참이면    */
      ++Pc; block(); Pc = end_line + 1;           /*  실행하고  */
      return;                                     /*  종료      */
    }
    Pc = save.jmpAdrs;                            /*  다음으로  */
  }
  // else
  if (lookCode(Pc) == Else) {                     /* else를     */
    ++Pc; block(); Pc = end_line + 1;             /* 실행하고   */
    return;                                       /* 종료       */
  }
  // end
  ++Pc;
  break;
