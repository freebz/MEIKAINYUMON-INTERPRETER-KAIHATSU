// 형 정보 부가 클래스

struct Tobj {    /* 형 정보 부가 obj */
  char type;     /* 저장 형식: 'd':double 's':string '-':미정 */
  double d;
  string s;
  Tobj()                  { type = 'e'; d = 0.0; s = ""; }
  Tobj(double dt)         { type = 'd'; d = dt;  s = ""; }
  Tobj(const string& st)  { type = 's'; d = 0.0; s = st; }
};


// 함수 선언에서 디폴트 인수를 지정

void err_exit(Tobj a, Tobj b, Tobj d)
{
  Tobj ob[5];
  ob[1] = a; ob[2] = b; ob[3] = c; ob[4] = d;
  cerr << "line:" << get_lineNo() << " ERROR ";

  for (int i=1; i<=4 && obj[i].s!="\1"; i++) {
    if (ob[i].type == 'd') cout << ob[i].d;    // 수치 정보
    if (ob[i].type == 's') cout << ob[i].s;    // 문자열 정보
  }
  cout << endl;
  exit(1);
}


// 이용 예
err_exit("잘못된 break입니다.");
err_exit("잘못된 기술입니다:", token.text);
err_exit(index, "는 첨자 범위 밖입니다(첨자 범위:0-", len-1, ")");
