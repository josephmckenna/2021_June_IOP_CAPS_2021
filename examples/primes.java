public class Main {
    static boolean IsPrime(int n)
    {
        for ( int i = 2; i <= n / 2; ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static void main(String args[]) {   
        for (int i = 2; i< 100; i++)
        {
            if (IsPrime(i))
               System.out.println(i);
        }
    }
}