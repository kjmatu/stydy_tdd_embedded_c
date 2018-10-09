# CircularBufferTestList

- [] バッファを初期化したらすべての領域が0になる
- [x] バッファのサイズが取得できる
- [x] 1回PUSHできる
- [x] 1回POPできる
- [x] 複数回PUSHできる
- [x] 複数回POPできる
- [x] POPした分だけPUSHできる
- [] FIFOになっている
- [x] バッファが空であることを確認できる
- [] バッファがフルであることを確認できる
- [] PUSHしてPOPすると同じ値が取得できるか
- [] バッファが空のときにPOPするとエラーを返すか
- [] バッファサイズが0のバッファは作成できない
- [] バッファがフルのときにPUSHするとエラーを返すか

<script>var d=document.body;d.innerHTML=d.innerHTML.replace(/<li>\[(x| )\]/g,m=>`<li>${m=="<li>[x]"?"🔳":"◻️"}`);</script>