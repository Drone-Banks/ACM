
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created by 22810 on 2016/11/26.
 */
public class Main {
    public static void main(String [] args)
    {
        int T;
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        BigInteger mod = new BigInteger("1000000007");
        BigInteger two = new BigInteger("2");
        BigInteger one = new BigInteger("1");
        BigInteger three = new BigInteger("3");
        BigInteger six = new BigInteger("6");
        for(int t=1;t<=T;t++)
        {
            BigInteger a,b,tmp,ans;
            a = sc.nextBigInteger();
            b = sc.nextBigInteger();
            a = a.subtract(one);
            b = b.subtract(one);
            if(a.compareTo(b)>0)
            {
                BigInteger cnt;
                cnt = a;
                a = b;
                b = cnt;
            }
            tmp = a.multiply(a).add(a).divide(two);
            ans = tmp.multiply(tmp).mod(mod);
            //System.out.println(ans);

            tmp = a.add(b).add(two);
            tmp = tmp.multiply( a.multiply(a.add(one)).multiply(two.multiply(a).add(one)));
            tmp = tmp.divide(six);
            ans = ans.subtract(tmp).mod(mod);
            //System.out.println(ans);

            tmp = (a.multiply(b).add(a).add(b).add(one));
            tmp = tmp.multiply(a.multiply(a).add(a).divide(two));
            ans = ans.add(tmp).mod(mod);
            System.out.println("Case #"+t+": "+ans);
    }
}
