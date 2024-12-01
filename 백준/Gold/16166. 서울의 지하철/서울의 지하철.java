import java.io.*;
import java.util.*;

public class Main {
    static int N, start, end;

    static Mapper mapper = new Mapper();
    static Map<Integer, List<Integer>> station = new HashMap(); // station 번호 넣으면 어떤 라인에 속하는지 알려줌
    static List<Integer>[] line = new ArrayList[11]; // line 넣으면 어떤 station있는지 알려줌

    static int solve() {
        int answer = 0;

        if(start == -1 || end == -1) {
            return -1;
        }

        for(final int endLine : station.get(end)) {
            for(final int startLine : station.get(start)) {
                if(endLine == startLine)
                    return 0;
            }
        }

        int firstLine = station.get(start).get(0);

        Queue<Integer> q = new ArrayDeque<>();
        q.add(firstLine);

        boolean[] lineVisited = new boolean[11];
        lineVisited[firstLine] = true;

        while(!q.isEmpty()) {
            int qSize = q.size();
            while(qSize-- > 0) {
                int nowLine = q.poll();
                for(int nextStation : line[nowLine]) {
                    if(nextStation == end) return answer;
                    for(int nextLine : station.get(nextStation)) {
                        if(lineVisited[nextLine]) continue;
                        lineVisited[nextLine] = true;
                        q.offer(nextLine);
                    }
                }
            }
            ++answer;
        }
        return -1;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        start = end = -1;
        N = Integer.parseInt(st.nextToken());

        for(int i=0; i<N; ++i)
            line[i] = new ArrayList<>();

        for(int _line=0; _line<N; ++_line) {
            st = new StringTokenizer(br.readLine());
            int K = Integer.parseInt(st.nextToken());
            for(int j=0; j<K; ++j) {
                Long inp = Long.parseLong(st.nextToken());
                int stationIdx = mapper.setMapper(inp);

                if(inp == 0L)
                    start = stationIdx;

                line[_line].add(stationIdx); // _line호선에 어떤 역이 있는지 저장
                List<Integer> lines = station.get(stationIdx);
                if (lines == null) {
                    lines = new ArrayList<>(); // 새로운 리스트 생성
                    station.put(stationIdx, lines); // station에 추가
                }
                lines.add(_line); // _line 추가

            }
        }
        end = mapper.getIdx(Long.parseLong(br.readLine()));


        System.out.print(solve());

    } // main


    static class Mapper {
        static int INDEX = 0;
        HashMap<Long, Integer> mapper; // 역번호를 인덱스로

        Mapper() {
            mapper = new HashMap<>();
        }

        int setMapper(final long num) {
            mapper.putIfAbsent(num, ++INDEX);
            return getIdx(num);
        }

        int getIdx(final long num) {
            return mapper.getOrDefault(num, -1);
        }
    }
}