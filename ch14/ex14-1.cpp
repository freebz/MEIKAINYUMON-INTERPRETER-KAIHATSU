// 14.1 함수의 다중 정의

void smp(int a) { ~ }
void smp(double a) { ~ }
void smp(int a, int b) { ~ }
void smp(double a, double b) { ~ }
void smp(int a, double b) { ~ }
void smp(double a, int b) { ~ }

smp(10);        // smp(int)를 호출한다
smp(12.34);     // smp(double)을 호출한다
smp(10, 20);    // smp(int, int)를 호출한다
