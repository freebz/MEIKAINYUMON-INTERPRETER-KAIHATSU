// 11.7.2 프레임 확보

baseReg = spReg;		// 새로운 베이스 레지스터 설정
spReg += Gtable[fncNbr].frame;	// 프레임 확보
