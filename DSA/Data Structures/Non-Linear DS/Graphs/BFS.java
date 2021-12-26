// "static void main" must be defined in a public class.

class Solution{
    Map<Integer,LinkedList<Integer>> mp = new HashMap<>();
    
    public void addEdge(Integer u, Integer v){
        if(!mp.containsKey(u)){
            mp.put(u,new LinkedList<>());
        }
        
        if(!mp.containsKey(v)){
            mp.put(v, new LinkedList<>());
        }
        
        mp.get(u).add(v);
        mp.get(v).add(u);
    }
    
    
    public void bfsUtil(ArrayList<Integer> bfs, boolean[] visited, int node, int V){
        visited[node] = true;
        Queue<Integer> q = new LinkedList<>();
        q.add(Integer.valueOf(node));
        
        while(!q.isEmpty()){
            Integer temp = q.peek(); 
            bfs.add(temp);
            q.remove();
    
            for(Integer el:mp.get(temp)){
                if(visited[el]==false){
                    visited[el]=true;
                    q.add(el);
                }
            }
        }
    }
    
    public ArrayList<Integer> bfsOfGraph(int V){
        ArrayList<Integer> bfs = new ArrayList<>();
        boolean[] visited =  new boolean[V+1];
        
        for(int i=1;i<=V;i++){
            if(visited[i]==false){
                bfsUtil(bfs,visited,i,V);
            }
        }
        
        return bfs;
    }

    public void solnFunc(int V, int arr[][]){
        for(int i=0;i<arr.length;i++){
            addEdge(Integer.valueOf(arr[i][0]),Integer.valueOf(arr[i][1]));
        }
        
        System.out.print(bfsOfGraph(V));
    }
}

public class Main {
    public static void main(String[] args) {
        int[][] arr = {{1,2}, {2,4}, {2,7}, {4,6}, {7,6}, {3,5}};
        Solution soln = new Solution();
        
        soln.solnFunc(7,arr);
    
    }
}