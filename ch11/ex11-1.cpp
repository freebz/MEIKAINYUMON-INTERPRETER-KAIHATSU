// 11.1 BBI 인터프리터의 함수

void statement()		// 문
{
  ...
  case Fcall:
    fncCall(code.symbr);	// 대입이 없는 함수 호출
    (void) stk.pop();		// 반환 값을 버린다
    ++Pc;
    break;
  ...
}

void factor()			// 인자
{
  ...
  case Fcall:			// 일반적인 함수 호출
    fncCall(code.symNbr);
    break;
  ...
}
