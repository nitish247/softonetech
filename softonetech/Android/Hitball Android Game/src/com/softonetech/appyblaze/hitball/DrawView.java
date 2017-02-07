package com.softonetech.appyblaze.hitball;

import java.util.ArrayList;

import android.annotation.TargetApi;
import android.content.Context;
import android.graphics.*;
import android.os.Build;
import android.util.Log;
import android.view.Display;
import android.view.View;
import android.view.WindowManager;
import android.widget.Toast;

public class DrawView extends View {
	
	Paint paint = new Paint();
	Paint wpaint=new Paint();
	Paint textPaint=new Paint();
	
	public static int barx,bary,barlen;
	public static final int brickWidth=45,brickHeight=20;
	public static int rows,cols;
	
	public static int xc,yc,xdir,ydir;
	public static final int radius=6;
	public static int minx=10,miny=10,maxx,maxy;
	public static long score=0;
	public static int[] colors={Color.BLUE,Color.CYAN,Color.GRAY,Color.GREEN,Color.MAGENTA,Color.RED,Color.WHITE,Color.YELLOW};
	public static int[] brickColors={Color.BLACK,Color.BLUE,Color.RED,Color.CYAN,Color.DKGRAY,Color.GREEN};
	public static boolean powerActive=false;
		
	public static ArrayList<Brick> bricks=new ArrayList<Brick>();
	public static ArrayList<Power> powers=new ArrayList<Power>();
	Display display;
	
    @SuppressWarnings("deprecation")
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
                maxy=size.y-75;
            }else { 
            	maxy=size.x-10;
                maxx=size.y-50;
            }                        
        }
        else{
        	maxx=display.getWidth()-10;
        	maxy=display.getHeight()-50;
        }
        
        initialize();
    }
    
    public void initialize(){
    	barx=maxx-200;
        bary=maxy-15;
        xc=barx+20;
        yc=bary-30;
        barlen=70;
        score=0;
        xdir=-1;
        ydir=-1;        
    }

    @Override
    public void onDraw(Canvas canvas) {
    	wpaint.setColor(Color.WHITE);
    	canvas.drawRect(minx-2, miny-2, maxx+2,maxy+2,wpaint);
    	wpaint.setColor(Color.BLACK);
    	canvas.drawRect(minx, miny, maxx,maxy,wpaint);
    	
    	for(int i=0;i<bricks.size();i++){
    		wpaint.setColor(Color.WHITE);
    		canvas.drawRect(bricks.get(i).x, bricks.get(i).y, bricks.get(i).x+brickWidth, bricks.get(i).y+brickHeight, wpaint);
    		wpaint.setColor(bricks.get(i).color);
    		canvas.drawRect(bricks.get(i).x+1, bricks.get(i).y+1, bricks.get(i).x+brickWidth-1, bricks.get(i).y+brickHeight-1, wpaint);
    	}
    	    	
    	wpaint.setColor(Color.GRAY);
    	canvas.drawRect(barx,bary,barx+barlen,bary+10, wpaint);
    	wpaint.setColor(Color.RED);
    	
    	if(powerActive){
    		for(int j=0;j<powers.size();j++){
	    		wpaint.setColor(Color.WHITE);
	    		canvas.drawRect(powers.get(j).x, powers.get(j).y, powers.get(j).x+brickWidth, powers.get(j).y+brickHeight, wpaint);
	    		wpaint.setColor(powers.get(j).color);
	    		canvas.drawRect(powers.get(j).x+1, powers.get(j).y+1, powers.get(j).x+brickWidth-1, powers.get(j).y+brickHeight-1, wpaint);
    		}
    	}
    	
    	xc+=4*xdir;    	
    	yc+=4*ydir;
    	if((xc<minx)&&(yc<maxy))
    		xc=minx+radius;
    	
    	if((xc>maxx)&&(yc<maxy))
    		xc=maxx-radius;
    	
    	if(yc<miny)
    		yc=miny+radius;
    		    	
    	if((xc>barx) && (xc<barx+barlen))
    		if(yc>bary)
    			yc=bary-radius;
    	
    	wpaint.setColor(Color.RED);
    	canvas.drawCircle(xc,yc, radius, wpaint);
    	canvas.drawText("Score: "+String.valueOf(score), minx, maxy+20, textPaint);
    }
}