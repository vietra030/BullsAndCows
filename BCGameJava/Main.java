package game;

public class Main {
	

	public static void main(String[] args) {
		
		Word obj=new Word();
		Bully ob=new Bully();
		boolean guessed=false;
		int guesses=0;
		ob.dic();
		int max_tries=ob.target.length()-1;
		
		do {
			int cows=0,bulls=0;
		
		System.out.println("Enter a "+ob.target.length()+ " lettered isogram");
	
		obj.getWord();
		
		
		
		if(obj.checkIsogram()==true) {
		
		
		for(int i=0;i<ob.target.length();i++) {
			if(obj.word.charAt(i)==ob.target.charAt(i))
				bulls++;
			
				}
		for(int i=0;i<ob.target.length();i++) {
			
			for(int j=i;j<ob.target.length();j++) {
				if(obj.word.charAt(i)==ob.target.charAt(j))
					cows++;
				
			}
		}
		
		if(bulls==ob.target.length()) {
			System.out.println("Bulls:"+bulls+" Cows:"+cows);
			guessed=true;}
		else {guesses++;

		
			System.out.println("Bulls:"+bulls+" Cows:"+cows);
		System.out.println("You have "+(max_tries-guesses)+" guesses remaining");
		
		}
		}
		else {
			System.out.println("In an isogram letters do not repeat ");
			System.out.println("Try again");}
		}while(!guessed && guesses<max_tries);
		if(guessed=true && guesses<max_tries)
			System.out.println("You Won!");
		else
			System.out.println("You Lost!");
			
		
		
	}
}
	
	
	
		
	


