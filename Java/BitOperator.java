public class BitOperator{
  public static void main(String[] args){
  int num1=5, num2=7;
    int res= num1 | num2;
  System.out.println("or: "+ res);
  res= num1 & num2;
  System.out.println("or: "+ res);
  res= num1^num2; 
  System.out.println("or: "+ res);
  res= (~num1);
  System.out.println("or: "+ res);
int a=2;
    res= a<<2;
System.out.println("SIGNED LEFT_SIFT " + res);
    res= a>>2;
System.out.println("SIGNED ritht-SIFT " + res);
    res=a>>>2;
System.out.println("SIGNED LEFT_SIFT " + res);
    res=a<<<2;
System.out.println("SIGNED LEFT_SIFT " + res);
}
}
