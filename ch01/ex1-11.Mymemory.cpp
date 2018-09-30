class Mymemory {		       /* vector<double>의 래퍼 */
private:
  vector<double> mem;		        /* vector<>를 포함 */
public:
  void auto_resize(int n)       { ... } /* 영역 확보     */
  void set(int adrs, double dt) { ... } /* 메모리 쓰기   */
  void add(int adrs, double dt) { ... } /* 메모리 더하기 */
  double get(int adrs)          { ... } /* 메모리 읽기   */
  int  size()                   { ... } /* 저장 크기     */
  void push_back(double d)      { ... } /* 데이터 추가   */
};
Mymemory Dmem;                          /* 오브젝트 확보 */
