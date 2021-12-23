public class Solution{
    Map<Integer, List<Integer>> mp = new HashMap<>();
    
    public void addEdge(Integer u, Integer v){
        
        if(!mp.containsKey(u)){
            mp.put(u, new LinkedList<>());
        }
        
        if(!mp.containsKey(v)){
            mp.put(v, new LinkedList<>());
        }
        
        mp.get(u).add(v);
        mp.get(v).add(u);
    }
    
    public void dfs(int node, boolean visited[], ArrayList<Integer> dfsList){
        dfsList.add(Integer.valueOf(node));
        visited[node]=true;
        for(Integer it:mp.get(node)){
            if(visited[it]==false){
                dfs(it,visited,dfsList);
            }
        }
    }
    
    public ArrayList<Integer> dfsOfGraph(int v){
        ArrayList<Integer> dfsList= new ArrayList<Integer>();
        
        boolean visited[] = new boolean[v+1];
        
        for(int i=1;i<=v;i++){
            if(visited[i]==false){
                dfs(i,visited,dfsList);
            }
        }
        
        return dfsList;
    }
    
    public void solnFunc(int n, int arr[][]){
        for(int i=0;i<arr.length;i++){
            addEdge(Integer.valueOf(arr[i][0]), Integer.valueOf(arr[i][1]));
        }
        
        System.out.print(dfsOfGraph(n));
        
    }
}


// "static void main" must be defined in a public class.
public class Main {
    public static void main(String[] args) {
       
        int[][] arr = {{1,2}, {2,4}, {2,7}, {4,6}, {7,6}, {3,5}};
        Solution soln = new Solution();
        
        soln.solnFunc(7,arr);
        
        // System.out.println("Graph:\n"
        //                    + soln.printGraph());
    }
}class DFS {
    
}
