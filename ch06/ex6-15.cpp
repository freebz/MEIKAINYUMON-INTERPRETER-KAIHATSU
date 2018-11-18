// 6.5.4 변수 주소 설정

if (변수 또는 인수 등록)
  메모리를 할당하고 주소를 tb.adrs에 설정


int enter(SymTbl& tb, SymKind kind)
{
  bool isLocal = is_localName(tb.name, kind);    // 로컬 판정
  ...
  if (kind == fncId)		                 // 함수명
    함수 어드레스 설정
  else {			                 // 변수명 
    if (isLocal) {				 // 로컬 이름
      tb.adrs = localAdrs; localAdrs += mem_size();    // 로컬 주소 설정
    } else {					 // 글로벌 이름
      tb.adrs = Dmem.size();			 // 글로벌 주소 설정
      Deme.resize(Deme.size() + mem_size);	 // 글로벌 메모리 영역 확보
    }
  }
  ...
}


tb.adrs = localAdrs;
localAdrs += mem_size;
