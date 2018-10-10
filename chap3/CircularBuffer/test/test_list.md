# CircularBufferTestList

- [] バッファを初期化したらすべての領域が0になる
- [x] バッファのサイズが取得できる
- [x] バッファ初期化時に番兵があるか
- [] バッファのサイズを超えて書き込んでいないか
- [x] 1回PUSHできる
- [x] 1回POPできる
- [x] 複数回PUSHできる
- [x] 複数回POPできる
- [x] POPした分だけPUSHできる
- [] FIFOになっている
- [x] バッファが空であることを確認できる
- [] バッファがフルであることを確認できる
- [] PUSHしてPOPすると同じ値が取得できる
- [x] バッファが空のときにPOPするとエラーを返す
- [x] バッファサイズが0のバッファは作成できない
- [x] バッファがフルのときにPUSHするとエラーを返す

<script>var d=document.body;d.innerHTML=d.innerHTML.replace(/<li>\[(x| )\]/g,m=>`<li>${m=="<li>[x]"?"🔳":"◻️"}`);</script>