// 10.7.1 break 문의 처리

case Break:
  code = nextCode();
  post_if_set(break_Flg);	// break_Flg 세트
  if (!break_Flg) ++Pc;		// 중단하지 않을 때는 다음 행으로
  break;

void post_if_set(bool& flg)
{
  if (code.kind == EofLine) { flg = true; return; } /* ?가 없으면 flg를 참으로 */
  if (get_expression('?', 0)) flg = true;	    /* 조건식으로 처리 */
}
