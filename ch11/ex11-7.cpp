// 11.7.1 실행 환경 정보 설정

// 환경 정보 저장
int save_Pc = Pc;		// 현재 실행 행을 저장
int save_baseReg = baseReg;	// 현재 baseReg를 저장
int save_spReg = spReg;		// 현재 spReg를 저장
char *save_code_ptr = code_ptr;	// 현재 실행 행 분석용 포인터를 저장
CodeSet save_code = code;	// 현재 코드를 저장

// 새로운 환경 정보 설정
Pc = Gtable[fncNbr].adrs;	// 새로운 Pc를 설정
baseReg = spReg;		// 새로운 베이스 레지스터 설정
spReg += Gtable[fncNbr].frame;	// 프레임 확보
Dmem.auto_resize(spReg);	// 메보리 유효 영역을 확보
returnValue = 1.0;		// 반환 값의 기본 설정
code = firstCode(Pc);		// 시작 코드 획득
