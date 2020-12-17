import java.util.Scanner;

public class bankss
{
  public static void main (String[] args)
  {
    Scanner scan = new Scanner (System.in);
    int banks = scan.nextInt();
    double[] b = new double[banks];
    double[][] borrowsers = new double[5][5];
    int limit = scan.nextInt();
    for (int i =0;i<b.length;i++)
    {
      b[i] = scan.nextDouble();
      int howmany = scan.nextInt();
      for (int j =0;j<howmany;j++)
      {
        borrowsers[i][scan.nextInt()] = scan.nextDouble();
      }
    }
    
  for (int j =0;j<banks;j++)
  {
    for (int k =0; k<banks;k++)
    {
      int total =0;
      //Calculating total number of loans given by k
      for (int l =0;l<banks;l++)
      {
        total +=borrowsers[k][l];
      }
      if (total + b[k] < limit)
      {
        for (int m =0;m<banks;m++)
        {
          borrowsers[m][k] = 0;
        }
      }
    }
  }
  
  System.out.print("Unsafe banks are ");
  for (int k =0; k<banks;k++)
  {
    int total =0;
    //Calculating total number of loans made by k
    for (int l =0;l<banks;l++)
    {
      total +=borrowsers[k][l];
    }
    if (total + b[k] < limit)
    {
      System.out.print(k + " ");
    }
  }
}
}