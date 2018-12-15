// 9.1.7 배열 변수 처리와 주소 구하기

vector<double> Dmem;


double Dmem[SIZE];


char mem[SIZE];    -- char 형 배열을 사용



var Adrs = get_memAdrs(code);	        // 단순 변수 또는 배열 주소를 구한다

int get_memAdrs(const CodeSet& cd)      // 배열이면 첨자도 더함
{
  int adr=0, index, len;
  double d;

  adr = get_topAdrs(cd);	        // 변수의 주소를 구한다
  len = tableP(cd)->aryLen;	        // 배열이면 len은 0이 아님
  code = nextCode();

  if (len == 0) return adr;	        // 단순 변수의 주소를 반환한다

  d = get_expression('[', ']');	        // 첨자 값을 구한다
  if ((int)d != d) err_exit("첨자는 끝수가 없는 수치로 지정해 주세요.");
  if (syntaxChk_mode) return adr;       // 구문 검사 시

  index = (int)d;
  if (index < 0 || len <= index)	// 첨자 범위 검사
    err_exit(index, " 는 첨자 범위 밖입니다(첨자 범위:0-", len-1, ")");
  return adr + index;		        // 배열 요소의 주소를 반환한다
}

int get_topAdrs(const CodeSet& cd)
{
  switch (cd.kind) {
  case Gvar: return tableP(cd)->adrs;		// 글로벌 변수
  case Lvar: return tableP(cd)->adrs + baseReg; // 로컬 변수
  default: err_exit("변수명이 필요합니다: ", kind_to_s(db));
  }
  return 0;
}
