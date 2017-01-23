import java.util.Scanner;
import java.util.Stack;

public class Solution{
	private static class Tag{
		public String tagName;
		public boolean valid;

		public Tag( String name ){
			tagName = name;
			valid = true;
		}
	}

   public static void main(String[] args){
      
      Scanner in = new Scanner(System.in);
      int testCases = Integer.parseInt(in.nextLine());
      while(testCases-->0){
         String line = in.nextLine();
         Stack<Tag> stack = new Stack<Tag>();
         StringBuilder content =  new StringBuilder();
         
         int i = 0;

         boolean printed = false;
         while( i < line.length()){
        	 if( line.charAt(i) == '<' ){
        		 if( (i+1 < line.length()) && line.charAt(i+1) != '/' ){
        			 
        			 // Open bracket.
        			 int j = i+1;
        			 while( j < line.length() && line.charAt(j) != '>' ) j++;

        			 stack.push(new Tag(line.substring(i+1, j)));
        			 i = j +1;
        			 content = new StringBuilder(); // clear the contents
        		 }
        		 else if( i+2 < line.length() ){
        			 // Close Bracket
        			 // 1. Print valid closing.
        			 // 2. Print none if not a valid.
        			 int j = i+2;
        			 while( j < line.length() && line.charAt(j) != '>' ) j++;
        			 String tagName = line.substring(i+2,j);
        			 
        			 if( stack.peek().tagName.equals(tagName) && !tagName.isEmpty()){
        				 if( stack.peek().valid  && content.length() > 0 ) {
        					 System.out.println(content.toString());
        					 printed = true;
        				 }
        			 }
        			 stack.pop();
        			 content = new StringBuilder();
        			 i = j+1;
        			 if( !stack.isEmpty() ) stack.peek().valid = false;
        		 }
        		 else 
        			 i++;
        	 }
        	 else{
        		 content.append(line.charAt(i++));
        	 }
         }
         
         if( !printed ){
        	 System.out.println("None");
         }
      }
   }
}
