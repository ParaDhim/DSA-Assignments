import java.util.*;

public class Q2 {
    public static int func(int []a,int i,int n,int dp[]){
        //int r=0;
        int l=n-i;
        
        int x=l*a[n];
        if(i>0)
            x=x-dp[n]+dp[i-1];
        else
            x=x-dp[n];
        //r=x;

        
        return x;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int [] a=new int[n];
        int k=sc.nextInt();
        for (int i=0;i<n;i++){
            a[i]=sc.nextInt();
        }
        Arrays.sort(a);
        int []dp=new int[n];
        dp[0]=a[0];
        for(int i=1;i<n;i++){
            dp[i]=a[i]+dp[i-1];
        }
        int ans=0;
        for(int i=n-1;i>=0;i--){
            int tans=0;
            for(int j=0;j<i;j++){
                int r=Math.max(tans, func(a, j, i, dp));
                if(r<k){
                    tans=Math.max(tans,i-j+1);
                    ans=Math.max(tans, ans);
                    break;
                }
            }
        }
        System.out.println(ans);

    }
}