// 6.4.1 글로벌 영역 처리

int main(int argc, char *argv[])
{
  ...
  convert_to_internalCode(argv[1]);           // 내부 코드화
  syntaxChk();				      // 행 단위 구문 검사
  execute();				      // 실행
  return 0;
}

void convert_to_internalCode(char *fname)     /* 코드 변환 시작 */
{
  문자 종류표 등 초기화
  
  파일을 연단
  함수 정의명만 먼저 등록

  다시 파일을 연다
  while (파일 종료까지) {
    convert();			              /* 내부 코드로 변환 */
  }

  main() 함수가 있으면 그 호출 코드를 설정
}

void convert()			              // 코드 변환
{
  switch (토큰 종류) {
  case Option:   optionSet();     break;      /* 옵션 처리 */
  case Var:      varDecl();       break;      /* 변수 선언 */
  case Func:     fncDecl();       break;      /* 함수 선언 */
  case While: case For: while, for 문 처리; break;
  case If:       if문 처리;       break;
  case Break:    break 문 처리;   break;
  case Return:   return 문 처리;  break;
  case Exit:     exit 문 처리;    break;
  case Print:    case Println: print, println 문 처리; break;
  default:       그 밖의 처리;    break;
  }
}


void syntaxChk()		              // 구문 검사
{
  syntaxChk_mode = true;
  for ( Pc=1; Pc<(int) intercode.size(); Pc++) {
    행 단위로 정적 구문 검사
  }
  syntaxChk_mode = false;
}

void execute()			              // 실행 관리
{
  Pc를 실행 시작행으로 설정
    while (Pc<=maxLine && !exit_Flg) {
      statement();
    }
}

void statement()		              // 문의 실행
{
  ...
  switch (토큰 종류) {
  case If:                    if 실행;            break;
  case While:                 while 실행;         break;
  case For:                   for 실행;           break;
  case Fcall:                 함수 호출 실행;     break;
  case Func:                  함수 정의는 건너뜀; break;
  case Print: case Println:   출력문 실행;        break;
  case Gvar: case Lvar:       대입문 실행;        break;
  case Return:                return 문 실행;     break;
  case Break:                 break 실행;         break;
  case Exit:                  exit 실행;          break;
  case Option: case Var: case EofLine: 실행 시 무시한다;  break;
  default:                    오류 처리
  }
}
