// 6.8.5 인수 주소 설정

void func( p1, p2)
{
  var d1, d2
  ...
}


localAdrs = 0;			// 로컬 영역 할당 카운터 초기화


if (isLocal) {			// 인수 및 로컬 변수라면
  tb.adrs = localAdrs;		// 로컬 주소 설정
  localAdrs += mem_size;
} else {			// 글로벌 변수라면
  ...				// 글로벌 어드레스 설정
}
