package com.softonetech.appyblaze.hitball;

public class Brick {	
	public int x,y,color;
	public int hiddenPower;
	public int toughness;
	
	public Brick(int xc,int yc,int col){
		x=xc;
		y=yc;
		color=col;
		toughness=1;
	}
	
	public Brick(int xc,int yc,int col,int hp){
		x=xc;
		y=yc;
		color=col;
		hiddenPower=hp;
		toughness=1;
	}
	
	public void hit(){
		toughness--;
	}
}
