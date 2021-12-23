// "static void main" must be defined in a public class.


class Solution {
    private Map<Integer, List<Integer>> mp = new HashMap<>();
    
    
    public void addVertex(Integer u){
        mp.put(u, new LinkedList<>());
    }
    
    public void addEdge(Integer src, Integer dest, boolean bidir){
        if(!mp.containsKey(src)){
            addVertex(src);
        }
        
        if(!mp.containsKey(dest)){
            addVertex(dest);
        }
        
        mp.get(src).add(dest);
        
        if(bidir==true){
            mp.get(dest).add(src);
        }
    }
    
    
    public String printGraph(){
        StringBuilder builder = new StringBuilder();
        
        for(Integer k: mp.keySet()){
            builder.append(k.toString() + ": ");
            for(Integer val:mp.get(k)){
                builder.append(val.toString()+ " ");
            }
            builder.append("\n");
        }
        
        return (builder.toString());
    }
    
    
    
    
    public void solnFunc(int n, int arr[][]){
        for(int i=0;i<arr.length;i++){
            addEdge(new Integer(arr[i][0]), new Integer(arr[i][1]), true);
        }
    }
}

public class Main {
    
    public static void main(String[] args) {
        
        int[][] arr = {{0,1}, {0,4}, {1,2}, {1,3}, {1,4}, {2,3}, {3,4}};
       Solution soln = new Solution();
        
        soln.solnFunc(5,arr);
        
        System.out.println("Graph:\n"
                           + soln.printGraph());
        
    }
}