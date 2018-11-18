// 6.4.3 식별자 설정

void set_name()                 /* 이름 설정 */
{
  if (token.kind != Ident) 오류 처리
  tmpTb.name에 token.text를 설정한다
}
