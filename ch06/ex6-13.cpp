// 6.5.2 변수 선언과 정수 상수 판정

var a[2];	   // (1) OK
var b[2+3];	   // (2) 오류
var c[n];	   // (3) 오류


void set_aryLen()  // 배열 크기 설정
{
  토큰이 [인 것을 확인
  if (다음 토큰이 IntNum이 아님)
    '배열 길이는 정수 상수로 지정해 주세요.'라는 오류 표시
  배열 길이 (token.dblVal)을 tmpTb.aryLen에 설정
  다음 토큰이 ]임을 확인
}
