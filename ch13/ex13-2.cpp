struct stkData {
  union {
    int    i;			// int 형 데이터
    double d;			// double 형 데이터
  };
  char typ;			// 저장형을 표현. 예) i는 int형, d는 double 형
};
