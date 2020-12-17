import Java.util.Scanner;

public class Bank{

	public static void main (String[] args){

	    Scanner input = new Scanner(System.in);
	    int bank = scan.nextInt();
	    System.out.print("Enter the number of banks: ");
	    int numBanks = input.nextInt();
	    System.out.print("Enter minimum limit: ");
	    int limit = input.nextInt();
	    double Banks = scan.nextInt();

	    double Borrowers = new double[numBanks][numBanks];
	    double Banks = new int[bank];
	    	    
	    for (int l =0;l<Banks.length;l++){
	    	System.out.print("Enter the data\n");
	    	Banks[l] = scan.nextDouble();
	  		int howmany = scan.nextInt();
	 		for (int n =0;n<howmany;n++){
	    		Borrowers[l][scan.nextInt()] = scan.nextDouble();
	  		}
		}
	    for (int k = 0; k < bank; k++){
	    	for (int i =0; i < bank; i++){
	    		int total = 0;
	    		for(int j=0; j< bank; j++){
	    			total += Borrowers[i][j];
	    		}
	    		if (total + Banks[i] < limit){
	    			for (int m =0;m<bank;m++){
	      				Borrowers[m][i] = 0;
	   				}
	  			}
			}
		}
		System.out.print("The unsafe banks are: ");
		for (int k =0; k<bank;k++){
			int total =0;
			for (int l =0;l<bank;l++){
	  			total += Borrowers[k][l];
			}
			if (total + Banks[i] < limit){
	  			System.out.print(k + " and ");
	  		}
		}
	}
}
