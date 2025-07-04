# [Gold I] 화물차 - 1400 

[문제 링크](https://www.acmicpc.net/problem/1400) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

너비 우선 탐색, 데이크스트라, 그래프 이론, 그래프 탐색, 구현, 최단 경로

### 제출 일자

2025년 6월 20일 23:35:41

### 문제 설명

<p>화물차가 출발지 창고에서 짐을 싣고 배송지 창고까지 짐을 운반하려고 한다. 이 도시의 도로망을 나타낸 지도의 예는 다음과 같다.</p>

<pre>#A##0##1#
.#..#..#.
.#..#..#.
.###2#.B.</pre>

<p>도로망에서 차들은 동, 서, 남, 북의 방향으로만 이동할 수 있고, 지도의 각 문자는 다음과 같은 의미를 가진다.</p>
<ul>
<li>'A'는 출발지 창고를 나타내고, 지도에서 유일하다.</li>
<li>'B'는 배송지 창고를 나타내고, 지도에서 유일하다.</li>
<li>'.'은 차가 들어갈 수 없는 곳을 나타낸다.</li>
<li>'#'은 각 도로 셀을 나타낸다. '#'은 기껏해야 두 개의 다른 도로 셀, 또는 교차로, 창고와 인접하다.</li>
<li>숫자 [0-9]는 신호등에 의해 제어되는 교차로를 나타낸다. 교차로는 적어도 세 개의 도로 셀과 인접하다. 교차로들은 0부터 9까지의 번호로 표시된다. 만일 번호 k를 가진 교차로가 있으면, 반드시 0부터 k까지 번호를 가진 교차로가 존재한다. 교차로의 신호등에 대한 설명은 아래에 나온다.</li>
</ul>
<p>차량의 이동은 다음과 같은 방식으로 분석된다.</p>
<ul>
<li>화물차가 인접한 도로 셀, 또는 교차로, 창고로 이동하는 데 걸리는 시간을 단위 시간이라고 가정한다. 차량이 어떤 위치에서 멈춰 서 있는 시간도 단위 시간으로 측정된다.</li>

<li>화물차가 진입하려는 방향으로 파란불이 켜져 있을 때만 교차로로 들어갈 수 있다. 그러나 교차로에 들어간 차량은 언제든지 임의의 방향으로 나갈 수 있다.</li>
<li>교차로의 신호등은 동서 방향과 남북 방향, 두 개의 신호가 주기적으로 켜진다. 교차로의 신호는 초기에 동서 방향 또는 남북 방향이 될 수 있다. 교차로의 신호 주기를 나타내는 값 "a b"는 동서 방향의 신호가 a 시간 켜지고, 남북 방향의 신호가 b 시간 켜짐을 의미한다. 예를 들어, 초기에 남북 방향의 신호가 켜지고 주기 값이 "2 3"이면, 차량이 1-3 시간에 남북 방향의 신호가 켜지고, 4-5 시간은 동서 방향, 6-8 시간은 다시 남북 방향의 신호가 켜진다.</li>

<p>출발지 창고에서 배송지 창고까지 최단 경로를 구하는 프로그램을 작성하시오.</p>
				</ul>

### 입력 

 <p>입력은 여러 개의 테스트 케이스로 구성된다. 각 테스트 케이스의 첫째 줄에는 두 개의 정수 m과 n이 주어진다, 여기서 m은 지도를 나타내는 행렬의 행의 크기이고 n은 열의 크기이다(2 ≤ m, n ≤ 20).</p>

<p>그 다음 m개의 줄에는 각 줄마다 n개의 문자가 주어진다. 각 문자는 지도를 구성하는 문자인 '#', '.', 'A', 'B', [0-9]로 구성된다.</p>

<p>그 다음 줄부터는 각 교차로에 대한 정보가 주어진다. 교차로 번호가 0인 것부터 오름차순으로 한 줄에 하나씩 주어진다. 각 줄에는 교차로 번호 i와 '-' 또는 '|', 그 다음으로 두 개의 정수 ai와 bi (1 ≤ ai, bi ≤ 20) 가 빈칸을 사이에 두고 주어진다, 여기서 '-'는 신호등이 초기에 동서 방향의 신호가 켜짐을 나타내고, '|'는 남북 방향의 신호가 켜짐을 나타낸다. ai와 bi는 각각 동서 방향 신호가 켜 있는 시간과 남북 방향 신호가 켜 있는 시간을 나타낸다.</p>

<p>각 테스트 케이스 사이에는 빈 줄 하나가 들어 있고, 두 개의 0으로 시작되는 테스트 케이스는 입력의 끝을 나타낸다. 테스트 케이스는 20개를 넘지 않는다고 가정해도 된다.<br>
 </p>

### 출력 

 <p>각 테스트 케이스에 대해, 한 줄에 한 개의 정수를 출력한다. 이 정수는 출발지 창고에서 배송지 창고까지 차량으로 이동하는 데 걸리는 최소 시간이다. 만일 차량이 배송지 창고까지 도달할 수 없으면 "impossible"을 출력한다.<br>
 </p>

