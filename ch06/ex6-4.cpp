// 6.3.2 이진 탐색

int bin_search(int ary[], int n, int key)
{
  int left, right, mid;

  left = 0;			       // 탐색 범위의 시작 첨자
  right = n - 1;		       // 탐색 범위의 마지막 첨자
  while (left <= right) {
    mid = (left+right) / 2;	       // 탐색 범위 중앙 첨자
    if (key == ary[mid]) return mid;   // 찾음
    if (key < ary[mid])		       // 키가 중앙값보다 작으면
      right = mid - 1;		       // 다음은 절반을 조사
    else			       // 그렇지 않으면
      left = mid + 1;		       // 다음은 오른쪽 절반을 조사
  }
  return -1;			       // 찾지 못함
}
