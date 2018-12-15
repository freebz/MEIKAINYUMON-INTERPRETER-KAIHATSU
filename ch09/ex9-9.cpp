var Adrs = get_memAdrs(code);	          // 주소 구하기

Dmem.set(varAdrs, val);		          // 변수 대입
stk.push(Dmem.get(get_memAdrs(code)));    // 변수 참조
