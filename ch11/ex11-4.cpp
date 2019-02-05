// 11.4 프레임 처리

// 프레임 확보

int save_baseReg = baseReg;	// 현재의 baseReg를 저장
int save_spReg = spReg;		// 현재의 spReg를 저장

baseReg = spReg;		// 새로운 베이스 레지스터 설정
spReg += 20;			// 프레임 크기 확보


// 프레임 해제

baseReg = save_baseReg;		// 이전 값으로 되돌린다
spReg = save_spReg;		// 이전 값으로 되돌린다


// 프로그램
func myfunc(p1, p2)
  d1 = 10
  d2 = 20
  ...
end


char memory[MEM_SIZE];
