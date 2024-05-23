class Solution {
    public void dfs(List<List<Integer>>list,List<Integer>l,int[] nums,int ind,int k){
        list.add(new ArrayList<Integer>(l));
        for(int i=ind;i<nums.length;i++){
            int f=0;
            for(int j:l){
                if(Math.abs(j-nums[i])==k){
                    f=1;
                    break;
                }
            }
            if(f==1){
                continue;
            }
            l.add(nums[i]);
            dfs(list,l,nums,i+1,k);
            l.remove(l.size()-1);
        }
    }
    public int beautifulSubsets(int[] nums, int k) {
        List<List<Integer>>list=new ArrayList<List<Integer>>();
        Arrays.sort(nums);
        dfs(list,new ArrayList<>(),nums,0,k);
        return list.size()-1;
    }
}