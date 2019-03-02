// 13.2 데이터형 추가

double mem[MEM_SIZE];


char mem[MEM_SIZE];


// C 형식 형 변환

*((int*) (mem+20)) = 1234;	// 20번지부터 4바이트 저장
*((double*) (mem+24)) = 56.78;	// 24번지부터 8바이트 저장


// C++ 형식 형 변환

*(reinterpret_cast<int*>(mem+24)) = 1234;
*(reinterpret_cast<double*>(mem+32)) = 56.78;
