package com.appyblaze.snake;

import java.util.ArrayList;
import java.util.List;

import android.annotation.TargetApi;
import android.content.Context;
import android.graphics.*;
import android.os.Build;
import android.util.Log;
import android.view.Display;
import android.view.View;
import android.view.WindowManager;

public class DrawView extends View {
	
	Paint paint = new Paint();
	Paint wpaint=new Paint();
	Paint textPaint=new Paint();
	
	public static ArrayList<SnakeNode> snake=new ArrayList<SnakeNode>();;
	public static int minNodes=20;	
	public static int xdir=1,ydir=0;
	public static int foodx,foody,foodColor;	
	public static int minx=10,miny=10,maxx,maxy;
	public static long score=0;
	public int[] colors={Color.BLUE,Color.CYAN,Color.GRAY,Color.GREEN,Color.MAGENTA,Color.RED,Color.WHITE,Color.YELLOW};
	public static boolean splFood;
	public static int splFoodCnt=0;
	
	Display display;
	
    @TargetApi(Build.VERSION_CODES.HONEYCOMB_MR2)
	public DrawView(Context context) {
        super(context);        
        paint.setColor(Color.GREEN);
        textPaint.setColor(Color.WHITE);
        textPaint.setTextSize(16);
        WindowManager wm = (WindowManager) context.getSystemService(Context.WINDOW_SERVICE);
        Display display = wm.getDefaultDisplay();      
        if(Build.VERSION.SDK_INT>=Build.VERSION_CODES.HONEYCOMB){
        	Point size = new Point();
            display.getSize(size);
            if(size.x < size.y){
            	maxx=size.x-10;
                maxy=size.y-100;
            }else { 
            	maxy=size.x-10;
                maxx=size.y-50;
            }                        
        }
        else{
        	maxx=display.getWidth()-10;
        	maxy=display.getHeight()-50;
        }
    }

    @Override
    public void onDraw(Canvas canvas) {
    	wpaint.setColor(Color.WHITE);
    	canvas.drawRect(minx-2, miny-2, maxx+2,maxy+2,wpaint);
    	wpaint.setColor(Color.BLACK);
    	canvas.drawRect(minx, miny, maxx,maxy,wpaint);
    	wpaint.setColor(Color.WHITE);
    	int i,xc,yc;
    	for(i=0;i<snake.size();i++){
    		xc=snake.get(i).x;
    		yc=snake.get(i).y;
        	canvas.drawRect(xc,yc,xc+10,yc+10, paint);
        	canvas.drawText("Score: "+String.valueOf(score), minx, maxy+20, textPaint);
        	if(splFood)
        		canvas.drawText(String.valueOf(splFoodCnt) + " x "+MainMenuActivity.level, maxx-50, maxy+20, textPaint);        	
        	xc+=10*xdir;
        	yc+=10*ydir;        	
    	}
    	    	    	
    	wpaint.setColor(colors[foodColor]);
    	canvas.drawRect(foodx,foody,foodx+10,foody+10,wpaint);
    }
}
