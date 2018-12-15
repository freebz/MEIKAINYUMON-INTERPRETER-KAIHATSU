// 9.1.4 변수의 글로벌·로컬 판정

int get_topAdrs(const CodeSet& cd)
{
  switch (cd.kind) {
  case Gvar: return tableP(cd)->adrs;		   // 글로벌 변수
  case Lvar: return tableP(cd)->adrs + baseReg;    // 로컬 변수
  ...
  }
  return 0;
}
