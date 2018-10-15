package game;

import java.util.*;


public class Bully {
	
	String target;
	public void dic() {
	Map<String,String> dictionary=new HashMap<String,String>();
	dictionary.put("0","brick");
	dictionary.put("1","blind");
	dictionary.put("2","sample");
	dictionary.put("3","simple");
	dictionary.put("4","world");
	dictionary.put("5","winter" );
	dictionary.put("6", "hope");
	dictionary.put("7", "computer");
	dictionary.put("8", "flight");
	dictionary.put("9", "break");
	dictionary.put("10", "pocket");
	int rand=(int)(Math.random()*dictionary.size());
	target=dictionary.get(Integer.toString(rand));
	
	
	
	}

	}