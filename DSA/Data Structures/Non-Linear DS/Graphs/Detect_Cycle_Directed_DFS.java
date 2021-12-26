
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
        // mp.get(v).add(u);
    }
    
    public boolean isCycleDFSUtil(int[] visited, int[] dfsvisited,int node, int V){
        visited[node]=1;
        dfsvisited[node]=1;
        
        for(Integer it: mp.get(node)){
            if(visited[it]==0){
                if(isCycleDFSUtil(visited,dfsvisited,it,V)==true){
                    return true;
                }   
            }else if(dfsvisited[it]==1){
                return true;
            }
        }
        dfsvisited[node]=0;
        return false;
    }
   
    public boolean isCycleDFS(int V){
        int[] visited = new int[V+1];
        int[] dfsvisited = new int[V+1];
        
        for(int i=1;i<=V;i++){
            if(visited[i]==0){
                if(isCycleDFSUtil(visited,dfsvisited,i,V)==true){
                return true;
                }
            }
        }
        
        return false;
    }
    
    public void solnFunc(int V, int arr[][]){
        for(int i=0;i<arr.length;i++){
            addEdge(Integer.valueOf(arr[i][0]),Integer.valueOf(arr[i][1]));
        }
        
        System.out.print(isCycleDFS(V));
    }
}

public class Main {
    public static void main(String[] args) {
        int[][] arr = {{1,2}, {2,4}, {2,7}, {4,6}, {7,6}, {3,5}, {4,8}};
        Solution soln = new Solution();
        
        soln.solnFunc(8,arr);
    
    }
}