vector<char*> intercode;


void setCode_EofLine()    // 최종 저장 처리
{
  if (token.kind != EofLine) err_exit("잘못된 기술입니다: ", token.text);
  push_intercode();
  token = nextLine_tkn();
}


void push_intercode()          /* 변환한 내부 코드 저장 */
{
  int len;
  char *p;

  *codebuf_p++ = '\0';
  if ((len = codebuf_p-codebuf) >= LIN_SIZ)
    err_exit("변환 후의 내부 코드가 깁니다. 식을 줄여주세요.");

  try {
    p = new char[len];         /* 메모리 확보 */
    memcpy(p, codebuf, len);
    intercode.push_back(p);
  }
  catch (bad_alloc) { err_exit("메모리를 확보할 수 없습니다."); }
  codebuf_p = codebuf;         /* 다음 처리를 위해 저장한 곳의 선두로 위치 설정 */
}
