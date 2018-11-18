// 6.3.1 선형 탐색

int linear_search(int ary[], int n, int key)
{
  int i, pos = -1;
  for (i=0; i<n; i++) {
    if (ary[i] == key) { pos = i; break; }
  }
  return pos;
}
