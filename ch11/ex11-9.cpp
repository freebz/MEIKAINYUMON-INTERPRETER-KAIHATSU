// 11.7.3 로컬 메모리 크기 검사

Dmem.auto_resize(spReg);	// 메모리 유효 영역을 확보


class Mymemory {
  ...
  void auto_resize(int n) {	// 크기 n 이상을 확보
    if (n >= (int)mem.size()) { n = (n/256+1) * 256; mem.resize(n); }
  }
  ...
};
