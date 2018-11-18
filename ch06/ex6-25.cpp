// 6.8.7 프레임 크기 설정

localAdrs = 0;    // 로컬 영역 할당 카운터 초기화


localAdrs += mem_size;


convert_block();		        // 함수 본체 처리
...
Gtable[fncTbNbr].frame = localAdrs;     // 프레임 크기 설정
