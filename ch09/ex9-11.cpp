// 9.2 단항 연산자 처리

case Minus:
     code = nextCode(); factor();	/* 다음 값을 가져온다 */
     stk.push(-stk.pop());		/* 마이너스 처리한다 */
     break;
case Plus:			        /* 단한 + 연산자는 아무것도 하지 않는다 */
     break;
case Not:
     code = nextCode(); factor	        /* 다음 값을 가져온다 */
     stk.push(!stk.pop())		/* !를 처리한다. */
     break;
