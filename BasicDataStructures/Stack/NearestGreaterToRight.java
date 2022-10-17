import java.util.Vector;
import java.util.Stack;

//Nearest Greater to right finds the nearest greater element to the right of the array element 
//if it is the last element then its greater to right is -1
//Nearest Greater to Right is an application of the stack 
public class NearestGreaterToRight {

	public static void main(String[] args) {
		
		
		//vector is used as an array here so that it can increase or decrease the size of the array dynamically
		Vector<Integer> v = new Vector<Integer>();
		//stack is implemented here using the java collection framework 
		Stack<Integer> s = new Stack<Integer>();
		
		//in this array it will return the answer with nearest greater to right of that particular element if present otherwise will give -1
		int [] arr = {1,3,0,0,1,2,4};
		
		for(int i=6;i>=0;i--)
		{
			if(s.size()==0)			
				v.add(-1);
			else if(s.size()>0 && s.peek() > arr[i])	
				v.add(s.peek());
			else if(s.size()>0 && s.peek() <= arr[i])
			{
				while(s.size()>0 && s.peek() <= arr[i])
					s.pop();
				if(s.size() == 0)	
					v.add(-1);
				else				
					v.add(s.peek());
			}
			
			s.push(arr[i]);
		}

		for(int i=v.size()-1;i>=0;i--)
			System.out.print(v.get(i) + " ");
	}

}
