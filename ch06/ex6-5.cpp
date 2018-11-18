// 6.3.3 해시법

#define HSIZE 50
int hash(unsigned char *key)	// 문자 코드를 더하고 HSIZE의 나머지를 반환한다
{
  int sum = 0;
  while (*key)
    sum = *key++;		// 문자 코드 더하기
  return sum % HSIZE;
}
