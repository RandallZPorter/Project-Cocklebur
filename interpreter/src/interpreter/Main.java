package interpreter;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;

public class Main {
	
	private static LinkedList<Object> STACK = new LinkedList<Object>();
	private static LinkedList<Object> MATH_STACK = new LinkedList<Object>();
	private static LinkedList<Integer> CALL_STACK = new LinkedList<Integer>();
	private static Map<CharSequence, CharSequence> OBJECTS = new HashMap<CharSequence, CharSequence>();
	//private static CharSequence code = "#12!#13!!~@42~$5?~$5!!~$5!!~$5!!~$5!;#9!@42@~$9?@42@...";
	private static CharSequence code = ",..";
	private static int returnIndex;
	private static int i;
	
	public static void main(String args[]){
		loadCode();
		CharSequence obName = "";
		CharSequence value = "";
		for (i = 0; i < code.length(); i++){
			char token = t();
			switch (token){
				case '~':
					i++;
					token = t();
					i++;
					obName = getObjectNameOrValue();
					if (token == '$'){
						if (t() == '?'){
							value = (CharSequence)(STACK.pop().toString());
							OBJECTS.put(obName, value);
						} else if (t() == '!'){
							STACK.push(OBJECTS.get(obName));;
						}
					} else if (token == '@'){
						OBJECTS.put(obName, ((Number)(i-1)).toString());
						value = getFunctionBody();
					}
					break;
				case '#':
					i++;
					value = getObjectNameOrValue();
					if (t() == '!'){
						STACK.push(value);
					}
					break;
				case '@':
					i++;
					obName = getObjectNameOrValue();
					//returnIndex = i;
					CALL_STACK.push(i);
					i = new Integer((String)OBJECTS.get(obName));
					break;
				case ';':
					//i = returnIndex;
					i = CALL_STACK.pop();
					break;
				case '`':
					i++;
					evaluateExpression();
					i--;
					break;
				case '!':
					
					i++;
					char nextToken = t();
					boolean isNewLine = nextToken == 'v';
					if (!isNewLine) { i--; }
					
					i++;
					nextToken = t();
					boolean isDoAscii = nextToken == '.';
					if (!isDoAscii) { i--; }
					
					
					String printVal = STACK.pop().toString();
					try {
						int intVal = new BigDecimal(printVal).intValue();
						System.out.print((isDoAscii ? (Character.toString((char)intVal)) : intVal) + (isNewLine ? "\n" : ""));
					} catch (Exception e) {
						System.out.print(printVal  + (isNewLine ? "\n" : ""));
					}
					break;
				case '?':
					STACK.push(MATH_STACK.pop());
					break;
				case '‽':
					i++;
					double a = new BigDecimal(STACK.pop().toString()).doubleValue();
					double b = new BigDecimal(STACK.pop().toString()).doubleValue();
					//if((t() == '>' & a > b) || (t() == '<' & a < b) || (t() == '=' & a == b)) {
					if((t() == ')' & a < b) || (t() == '(' & a > b) || (t() == '=' & a == b) ||
					   (t() == ']' & a <= b) || (t() == '[' & a >= b) || (t() == '!' & a != b)) {
						i++;
						obName = getObjectNameOrValue();
						//returnIndex = i;
						CALL_STACK.push(i);
						i = new Integer(OBJECTS.get(obName).toString());
					} else {
						while(t() != '*') {
							i++;
						}
						//i++;
					}
					break;
				case '"':
					while(t() != '"') {
						i++;
					}
				default:
					break;
			}
		}
	}
	private static void evaluateExpression() {
		char buffer = t();i++;
		CharSequence expression = getObjectNameOrValue();//i++;
		expression = decode(expression);
		if (buffer == '1') { expression = ((String)expression).substring(1); }
		//System.out.println(expression);
		for (int n = 0; n < expression.length(); n++) {
			char token = expression.charAt(n);
			switch (token) {
				case '?':
					MATH_STACK.push(STACK.pop());
					break;
				case '/':
					double val1 = new BigDecimal(MATH_STACK.pop().toString()).doubleValue();
					double val2 = new BigDecimal(MATH_STACK.pop().toString()).doubleValue();
					if (val2 != 0) {
						MATH_STACK.push(val1 / val2);
					} else {
						MATH_STACK.push(val1 + (Math.random() > 0.5 ? 1 : -1));;
					}
					break;
			}
		}
	}
	private static CharSequence decode(CharSequence exp) {
		String out = "";
		for (int i = 0; i < exp.length(); i++) {
			char hex = exp.charAt(i);
			switch (hex) {// 0 = / ; 1 = ? ; 2 = ( ; 3 = ) ;
				case '0': out += "//"; break;
				case '1': out += "/?"; break;
				case '2': out += "/("; break;
				case '3': out += "/)"; break;
				case '4': out += "?/"; break;
				case '5': out += "??"; break;
				case '6': out += "?("; break;
				case '7': out += "?)"; break;
				case '8': out += "(/"; break;
				case '9': out += "(?"; break;
				case 'A': out += "(("; break;
				case 'B': out += "()"; break;
				case 'C': out += ")/"; break;
				case 'D': out += ")?"; break;
				case 'E': out += ")("; break;
				case 'F': out += "))"; break;
			}
		}
		return out;
	}
	private static char t(){
		return code.charAt(i);
	}
	private static CharSequence getObjectNameOrValue(){
		String stringVal = "";
		while (!"~!$@#?;>`*".contains(String.valueOf(t()))){
			stringVal += t();
			i++;
		}
		return (CharSequence)stringVal;
	}
	private static CharSequence getFunctionBody(){
		String stringVal = "";
		while (t() != ';'){
			stringVal += t();
			i++;
		}
		return (CharSequence)stringVal;
	}
	private static void loadCode() {
		FileReader fr = null;
		StringBuilder out = new StringBuilder();
		try {
			fr = new FileReader("C:\\Users\\s524409\\eclipse-workspace\\interpreter\\src\\interpreter\\source.txt");
		} catch (FileNotFoundException e1) {
			e1.printStackTrace();
		}
	    int i;
	    try {
	    	while ((i=fr.read()) != -1) {
	    		out.append((char)i);
	    	}
		} catch (IOException e) {
			e.printStackTrace();
		}
	    code = out.toString().replaceAll("\\s", "");
	}
}
 