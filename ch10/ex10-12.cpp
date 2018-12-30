// 10.9.1 return 문의 처리

case Return:
  wkVal = returnValue;		                // returnValue의 초기값은 1.0
  code = nextCode90;
  if (code.kind!='?' && code.kind!=EofLine)     // 식이 있으면 반환 값 계산
    wkVal = get_expression();
  post_if_set(return_Flg);                      // ?가 있으면 처리
  if (return_Flg) returnValue = wkVal;          // 반환 값 저장
  if (!return_Flg) ++Pc;
  break;
