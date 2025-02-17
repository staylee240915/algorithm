package baekjoon;

import java.util.*;

public class boj_1260 {

    public static int nodeNum;
    public static int row;
    public static int start;
    public static boolean[] isVisit;
    
    // 그래프를 저장할 배열 생성.
    public static List<Integer>[] graph;

    private static void dfs(int node){
        
        isVisit[node]=true;
        System.out.print(node + " ");
        
        for(int next : graph[node]) {
            // 아직 방문하지 않았다면 재귀 호출
            if(!isVisit[next]) {
                dfs(next);
            }
        }

    }
    private static void bfs(int node){
        Queue<Integer> queue = new LinkedList<>();
        
        //시작노드 방문처리
        isVisit[start] = true;
        queue.offer(start);
        
        //bfs 시작
        while(!queue.isEmpty()) {
            int current = queue.poll();
            System.out.print(current + " ");
            
            
            for(int next : graph[current]) {
                //방문x 시 방문
                if(!isVisit[next]) {
                    isVisit[next] = true;
                    queue.offer(next);
                }
            }
        }
    }
    public static void main(String[] args) {
     
        Scanner sc = new Scanner(System.in);

        nodeNum = sc.nextInt();
        row = sc.nextInt();
        start = sc.nextInt();

        graph = new ArrayList[nodeNum+1];
        for(int i=1;i<nodeNum+1;i++){
            graph[i] = new ArrayList<Integer>();
        }

        // 그래프 생성.
        for(int i=0;i<row;i++){
            int t1 = sc.nextInt();
            int t2 = sc.nextInt();

            // 양방향 그래프로 생성.
            graph[t1].add(t2);
            graph[t2].add(t1);
        }

        // 문제 조건상 방문 시 작은 정점부터 방문하므로 인접 리스트 정렬
        for(int i = 1; i <= nodeNum; i++){
            Collections.sort(graph[i]);
        }

        isVisit = new boolean[nodeNum+1];
        dfs(start);
        System.out.println();
        //dfs

        isVisit = new boolean[nodeNum+1];
        bfs(start);
        System.out.println();
        //bfs

    }
}
