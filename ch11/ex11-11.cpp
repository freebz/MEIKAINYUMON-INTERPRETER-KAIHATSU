// 11.7.5 복귀 주소 처리

case Fcall:
    FncCall(code.symNbr);		// 대입이 없는 함수 호출
    (void) stk.poop();			// 복귀 주소를 버린다
    ++Pc;				// 여기서 다음 행을 지정
    break;
