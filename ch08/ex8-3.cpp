#define SHORT_SIZ sizeof(short int)
#define SHORT_P(p) (short int *)(p)

CodeSet firstCode(int line)                /* 코드 가져오기 */
{
  code_ptr = intercode[line];	           // 분석용 포인터를 행의 맨 앞으로 설정
  return nextCode();
}

CodeSet nextCode()                         /* 코드 가져오기 */
{
  TknKind kd;
  short int jmpAdrs, tblNbr;

  if (*code_ptr == '\0') return CodeSet(EofLine);

  kd = (TknKind)*UCHAR_P(code_ptr++);
  switch(kd) {
  case Func:
  case While: case For: case If: case Elif: case Else:
    jmpAdrs = *SHORT_P(code_ptr); code_ptr += SHORT_SIZ;
    return CodeSet(kd, -1, jmpAdrs);
  case String:
    tblNbr = *SHORT_P(code_ptr); code_ptr += SHORT_SIZ;
    return CodeSet(kd, strLITERAL[tblNbr].c_str());  // 문자열 리터럴 위치
  case IntNum: case DblNum:
    tblNbr = *SHORT_P(code_ptr); code_ptr += SHORT_SIZ;
    return CodeSet(kd, nrbLITERAL[tblNbr]);  // 수치 리터럴
  case Fcall: case Gvar: case Lvar:
    tblNbr = *SHORT_P(code_ptr); code_ptr += SHORT_SIZ;
    return CodeSet(kd, tblNbr, -1);
  default:
    return CodeSet(kd);
  }
}
