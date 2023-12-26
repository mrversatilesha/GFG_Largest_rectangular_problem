class Solution {
    public static ArrayList<ArrayList<Integer>> sumZeroMatrix(int[][] a) {
        int n=a.length;
        int m=a[0].length;
        int[][] sum= new int[n][m];
        for( int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum[i][j] = a[i][j] + (j>0 ? sum[i][j-1] : 0);
            }
        }
        int maxarea=0,startrow=0,endrow=-1,startcol=0,endcol=-1;
        for(int c1=0;c1 < m;c1++){
            for(int c2=c1;c2 < m;c2++){
                int[] temp= new int[n];
                for( int i=0;i<n;i++){
                    temp[i]=sum[i][c2] - (c1>0 ? sum[i][c1-1]: 0);
                }
                Map <Integer,Integer> map= new HashMap();
                map.put(0,-1);
                int currsum=0;
                for(int i=0;i<n;i++){
                    currsum+=temp[i];
                    if(map.containsKey(currsum)){
                        int area=(c2-c1+1)*(i - map.get(currsum));
                        if(area>maxarea){
                            maxarea=area;
                            startrow=map.get(currsum)+1;
                            endrow=i;
                            startcol=c1;
                            endcol=c2;
                        }
                    }
                    else{
                        map.put(currsum,i);
                    }
                }
            }
        }
        ArrayList <ArrayList<Integer>> ans = new ArrayList<>();
        if(maxarea==0)
        return ans;
       
        for(int i=startrow;i<=endrow;i++){
            ArrayList<Integer> row= new ArrayList();
            for(int j=startcol;j<=endcol;j++){
                row.add(a[i][j]);
            }
            ans.add(row);
        }
        return ans;
    }
}
  
