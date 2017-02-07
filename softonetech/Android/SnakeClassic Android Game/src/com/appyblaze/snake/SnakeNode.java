package com.appyblaze.snake;

public class SnakeNode {
	public int x,y;
	
	public SnakeNode(){
		x=DrawView.minx;
		y=DrawView.miny;
	}
	
	public SnakeNode(int xc,int yc) {
		x=xc;
		y=yc;
	}
	
	public void setxy(int xc,int yc){
		x=xc;
		y=yc;
	}	
	
	public int getx(){
		return x;
	}
	
	public int gety(){
		return y;
	}
}
