package com.appyblaze.snake;

import java.util.Random;

import com.appyblaze.snake.SimpleGestureFilter.SimpleGestureListener;

import android.annotation.SuppressLint;
import android.annotation.TargetApi;
import android.app.*;
import android.content.DialogInterface;
import android.content.Intent;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.view.MotionEvent;
import android.view.View;
import android.widget.Button;
import android.widget.RadioButton;
import android.widget.Toast;
import android.graphics.*;

public class FullscreenActivity extends Activity implements SimpleGestureListener {
	public static int delayInterval= 150; //delay between frames in milliseconds
	private SimpleGestureFilter detector;
	private Thread t;
	private DrawView drawView;	
	int x=10,y=10,xdir=1,ydir=0;
	int foodCnt=0,foodEaten=1;
	private Handler handler=new Handler();
	private Random randomGenerator = new Random();	
	long score=0;
	boolean splFood=false;
	int splFoodCnt=0;	
	
	@TargetApi(Build.VERSION_CODES.HONEYCOMB)
	@SuppressLint("NewApi")
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		
		super.onCreate(savedInstanceState);
		if(Build.VERSION.SDK_INT>=Build.VERSION_CODES.HONEYCOMB){
			ActionBar actionBar=getActionBar();
			actionBar.hide();	
		}		
		
		drawView = new DrawView(getApplicationContext());
        drawView.setBackgroundColor(Color.BLACK);    
        detector = new SimpleGestureFilter(this,this);

        buildSnake();
        
                     
        try{
        	drawBitmap();	
        }catch(Exception ex){
        	Log.d("Exception000", ex.toString());
        }
	}
	
	private void drawBitmap() throws InterruptedException{

		t=new Thread(new Runnable() {
			
			@Override
			public void run() {
				int i,prevx,prevy,tempx,tempy;
				int randomX,randomY,randomColor,lostcnt=0;
				boolean lost=false,first=true;
				SnakeNode prevNode;
				
				while(true)
				{
					if(foodEaten==1){														
						randomX = randomGenerator.nextInt(((DrawView.maxx/10)-4)+((DrawView.minx/10)*4))*10;
						randomY = randomGenerator.nextInt(((DrawView.maxy/10)-4)+((DrawView.miny/10)*4))*10;
						if(randomX<DrawView.minx)
							randomX+=10;
						if(randomX>DrawView.maxx)
							randomX-=10;
						if(randomY<DrawView.miny)
							randomY+=10;
						if(randomY>DrawView.maxy)
							randomY-=10;
						
				        for(i=0;i<DrawView.snake.size();i++){
				        	tempx=DrawView.snake.get(i).x;
					        tempy=DrawView.snake.get(i).y;
					        if((randomX==tempx)&&(randomY==tempy))
					        	continue;
				        }
						randomColor = randomGenerator.nextInt(8);
						DrawView.foodx=randomX;
						DrawView.foody=randomY;
						DrawView.foodColor=randomColor;
					}
					
					if(splFood){
						if(DrawView.foodColor<7)
							DrawView.foodColor++;
						else
							DrawView.foodColor=0;
						splFoodCnt--;
						DrawView.splFoodCnt=splFoodCnt;
					}

					
			        DrawView.xdir=xdir;
			        DrawView.ydir=ydir;
			        
			        prevx=DrawView.snake.get(0).x;
			        prevy=DrawView.snake.get(0).y;
			        
			        for(i=1;i<DrawView.snake.size();i++){
			        	tempx=DrawView.snake.get(i).x;
				        tempy=DrawView.snake.get(i).y;
				        if((prevx==tempx)&&(prevy==tempy))
				        {
				        	if(lostcnt<9){
				        		lostcnt++;
				        	}else{
					        	Log.d("Gameover", "Game over!");
					        	lost=true;				        	
					        	break;
				        	}
				        }
			        }
			        
			        if(lost){
			        	handler.post(gameOverMsg);
			        	break;
			        }
			        
			        if((prevx==DrawView.foodx) && (prevy==DrawView.foody))
			        {			        	
			        	foodEaten=1;			        				        				        			        				        	
			        	
			        	if(splFood){
			        		score+=MainMenuActivity.level*splFoodCnt;
			        		splFoodCnt=1;
			        		DrawView.splFoodCnt=1;
				        	splFood=false;
				        	DrawView.splFood=false;
			        	}
			        	else
			        		score+=MainMenuActivity.level;
			        	
			        	foodCnt++;
			        	if(foodCnt%5==0)
			        	{
			        		splFood=true;
			        		DrawView.splFood=true;
			        		splFoodCnt=100;
			        		DrawView.splFoodCnt=100;
			        		
			        	}
			        				        	
			        	DrawView.score=score;
			        }
			        else{
			        	foodEaten=0;
			        }			       			       
			        
			        tempx=prevx+10*xdir;
			        tempy=prevy+10*ydir;
			        
			        if(tempx<=DrawView.minx-10)
			        	tempx=DrawView.maxx-10;
			        
			        if(tempx>=DrawView.maxx)
			        	tempx=DrawView.minx;
			        
			        if(tempy<=DrawView.miny-10)
			        	tempy=DrawView.maxy-10;
			        
			        if(tempy>=DrawView.maxy)
			        	tempy=DrawView.miny;
			        			        
			        DrawView.snake.get(0).setxy(tempx, tempy);
			        for(i=1;i<DrawView.snake.size();i++){
			        	tempx=DrawView.snake.get(i).x;
				        tempy=DrawView.snake.get(i).y;
				        DrawView.snake.get(i).setxy(prevx, prevy);
				        prevx=tempx;
				        prevy=tempy;
			        }
			        
			        if(foodEaten==1){
			        	SnakeNode newNode=new SnakeNode(prevx,prevy);
			        	DrawView.snake.add(newNode);
			        }
			        
			        handler.post(drawUI);			        			       
			        
			        try {
						Thread.sleep(delayInterval);
					} catch (InterruptedException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}
			}
		});			
		
		t.start();
	}
		
	Runnable drawUI=new Runnable() {
		
		@Override
		public void run() {
			setContentView(drawView);
		}
	};
	
	Runnable gameOverMsg=new Runnable() {
		
		@Override
		public void run() {
			//Toast.makeText(getApplicationContext(), "Game over!", Toast.LENGTH_LONG).show();
			
			AlertDialog.Builder ad = new AlertDialog.Builder(FullscreenActivity.this);
			ad.setTitle("Game Over");
			ad.setMessage("Your Score: "+String.valueOf(DrawView.score));
			ad.setCancelable(false);
			ad.setNegativeButton("Replay", new DialogInterface.OnClickListener() {
				
				@Override
				public void onClick(DialogInterface dialog, int arg1) {
					x=10;
					y=10;
					xdir=1;
					ydir=0;
					foodCnt=0;
					foodEaten=1;					
					score=0;
					splFood=false;
					splFoodCnt=0;
					DrawView.splFood=false;
					DrawView.splFoodCnt=0;
					score=0;
					DrawView.score=0;
					buildSnake();
					try {
						drawBitmap();						
					} catch (InterruptedException e) {				
						e.printStackTrace();
					}
				}
			});
			
			ad.setPositiveButton("Main Menu", new DialogInterface.OnClickListener() {
				
				@Override
				public void onClick(DialogInterface dialog, int arg1) {
					Intent intent=new Intent(FullscreenActivity.this,MainMenuActivity.class);
					startActivity(intent);
				}
			});		
			ad.show();
		}
	};
	
	private void buildSnake(){
		int xc=50,yc=50;
		DrawView.snake.clear();
        for(int i=0;i<DrawView.minNodes;i++){
        	SnakeNode sn=new SnakeNode(xc,yc);
        	xc+=10;
        	DrawView.snake.add(sn);        	
        }	
	}
	
	@Override
	protected void onPostCreate(Bundle savedInstanceState) {
		super.onPostCreate(savedInstanceState);
	}
	
    @Override
    public boolean dispatchTouchEvent(MotionEvent me){
    	// Call onTouchEvent of SimpleGestureFilter class
         this.detector.onTouchEvent(me);
       return super.dispatchTouchEvent(me);
    }
    
	@Override
	 public void onSwipe(int direction) {		
	 
	  switch (direction) {
	 
	  case SimpleGestureFilter.SWIPE_RIGHT :// str = "Swipe Right";
	  										if(xdir!=-1){
	  										xdir=1; ydir=0;}
	                                           break;
	  case SimpleGestureFilter.SWIPE_LEFT : // str = "Swipe Left";
	  										if(xdir!=1){
	  										xdir=-1; ydir=0;}
	                                                 break;
	  case SimpleGestureFilter.SWIPE_DOWN : // str = "Swipe Down";
											if(ydir!=-1){
	  										xdir=0; ydir=1;}
	                                                 break;
	  case SimpleGestureFilter.SWIPE_UP :  //  str = "Swipe Up";
											if(ydir!=1){
	  										xdir=0; ydir=-1;}
	                                                 break;
	 
	  }
	   //Toast.makeText(this, str, Toast.LENGTH_SHORT).show();
	 }
	 
	 @Override
	 public void onDoubleTap() {
	    
	 }


}