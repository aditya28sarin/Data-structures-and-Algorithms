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
    
    
    public boolean isCycleUtil(boolean visited[],int parent, int node, int V){
        visited[node]=true;
        
        for(Integer it:mp.get(node)){
            if(visited[it]==false){
                if(isCycleUtil(visited,node,it,V)==true){
                    return true;
                }
            }else if(it.intValue() != parent){
                return true;
            }
        }
        return false;
    }
    
    public boolean isCycle(int V){
        boolean[] visited = new boolean[V+1];
        
        for(int i=1;i<=V;i++){
            if(visited[i]==false){
                if(isCycleUtil(visited,-1,i,V)==true){
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
        
        System.out.print(isCycle(V));
    }
}

public class Main {
    public static void main(String[] args) {
        int[][] arr = {{1,2}, {2,4}, {2,7}, {4,6}, {7,6}, {3,5}};
        Solution soln = new Solution();
        
        soln.solnFunc(7,arr);
    
    }
}