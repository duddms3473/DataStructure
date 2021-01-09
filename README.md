# DataStructure

2019년 복수전공을 처음 시작할 때 들었던 자료구조 수업<br/>
과제 제한조건 : STL 사용불가능, 터미널에서 실행<br/>
<br/>
1.<br/>
두 integer sparse matrix a, b를 파일에서 입력받아 d = ab를 계산한 후 d를 stdout으로 출력하는 프로그램 구현.<br/>
수행 형태:<br/>
a.out a.txt b.txt > out.txt<br/>
<br/>
2.<br/>
Infix 형태로 표현된 수식을 stdin에서 입력받아 postfix 형태로 바꾼 후 stdout으로 출력한다.<br/>
수행 형태:<br/>
a.out < infix.txt > postfix.txt <br/>
<br/>
3.<br/>
Pair 형태로 입력되는 equivalence relation을 stdin에서 입력받아 equivalence class를 stdout으로 출력한다.<br/>
수행 형태:<br/>
a.out < epairs.txt > eclass.txt<br/>
<br/>
4.<br/>
서로 다른 정수로 구성되는 Max Heap을 처리하는 프로그램 (교과서 5.6절 참조). stdin에서 command를 입력받으며, 각 command 수행 후 적절한 답을 stdout에 출력.<br/>
Command 종류: (단, 아래에서 x는 중복되지 않는 임의의 정수)<br/>
I x: Max Heap에 x를 삽입[push]<br/>
D: 삭제[pop]<br/>
T: 가장 큰 값 출력[top]<br/>
D i: i번째 큰 값 삭제<br/>
T i: i번째 큰 값 출력<br/>
P: Max Heap 내용 출력 (root부터 노드 순서 차례로)<br/>
<br/>
5.<br/>
Undirected graph의 biconnected component를 찾는 프로그램 (교과서 6.2.5절 참조). stdin에서 undirected graph를 입력받으며, 결과를 stdout에 출력.<br/>
수행 형태:<br/>
a.out < in.txt > out.txt<br/>
<br/>
6.<br/>
1) 3가지 정렬 알고리즘 구현 (Insertion, Quick, Merge)<br/>
2) 각 알고리즘의 worst case 데이터 생성 및 만든 방법 설명<br/>
3) 각 알고리즘의 worst case running time 측정 (0.001초 단위, 교재에 나오는 n에 대해)<br/>
4) Running time 측정 후, 각 n에 대해서 3가지 정렬 알고리즘 중 어느 것이 우수한지 평가<br/>
5) 각 n에 대해 가장 빠른 정렬 함수를 결정한 다음, 모든 n값에 대해서 가장 좋은 성능을 가질 것으로 보이는 복합 함수 작성 (n 값에 따라 어느 정렬 방법을 적용할지 결정)<br/>
<br/>
