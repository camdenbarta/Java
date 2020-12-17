import java.util.Scanner;
public class lend{
    public static void main (String[] args){
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter the entire array including initial bank and limit");
        int bank = scan.nextInt();
        double[] z = new double[bank];
        double[][] lends = new double[5][5]; //2d array for banks 
        int minimumR = scan.nextInt();  //Scanning next integer
        for (int i =0;i<z.length;i++)
        {
        z[i] = scan.nextDouble();
        int all = scan.nextInt();
        for (int j =0;j<all;j++)
        {
            lends[i][scan.nextInt()] = scan.nextDouble();
        }
    }
  for (int j =0;j<bank;j++)
  {
    for (int k =0; k<bank;k++)
    {
      int total =0;
      //Calculating total number of loans given by k
      for (int l =0;l<bank;l++)
      {
        total +=lends[k][l];
      }
      if (total + z[k] < minimumR)
      {
        for (int m =0;m<bank;m++)
        {
          lends[m][k] = 0;
        }
      }
    }
  }
  System.out.print("Banks less than the limit ");
  for (int k =0; k<bank;k++)
  {
    int total =0;
    //Calculating total number of loans made by k
    for (int l =0;l<bank;l++)
    {
      total +=lends[k][l];
    }
    if (total + z[k] < minimumR)
    {
      System.out.print(k + " ");
    }
  }
}
}