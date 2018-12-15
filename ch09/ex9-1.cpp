// 9.1.1 일차식이란

void factor()
{
  switch(code.kind) {
  case Minus:
    - 단항 연산자 처리
    break;
  case Plus:
    + 단항 연산자 처리
    break;
  case Not:
    ! 단항 연산자 처리
    break;
  case Lparen:
    ( 식 ) 처리
    break;
  case IntNum: case DblNum:
    정수 상수와 실수 상수 처리
    break;
  case Input:
    input 내장 함수 처리
    break;
  case Fcall:
    한수 호출 처리
    break;
  case EofLine:
    오류 처리
  default:
    오류 처리
  }
}
