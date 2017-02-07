package com.softonetech.appyblaze.hitball;

import java.util.ArrayList;

import android.annotation.SuppressLint;
import android.annotation.TargetApi;
import android.app.ActionBar;
import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.graphics.Color;
import android.os.Build;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.view.MotionEvent;
import android.view.View;
import android.widget.Toast;

public class FullscreenActivity extends Activity {

	DrawView drawView;
	int tx,ty,prevtx=0,prevty=0;
	Handler handler=new Handler();
	public static int delayInterval=60;
	public static boolean lost=false,levelCompleted=false;
	
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
        
        drawBricks();
        
        t.start();    		     
        t1.start();        
		t2.start();
        
        setContentView(drawView);
	}
	
	private void drawBricks(){		
		int i,j,xc=45,yc=40,cid=0,col=Color.RED,pow=0,cnt=0,tgh=1;
		DrawView.bricks.clear();
        for(i=0;i<5;i++){
        	xc=45;        	
        	for(j=0;j<5;j++){        		
        		tgh=1;
        		if(cid%4==0)
        			col=Color.rgb(25, 0, 50);
        		if(cid%4==1)
        			col=Color.rgb(0, 51, 51);
        		if(cid%4==2)
        		{
        			col=Color.DKGRAY;
        			tgh=2;
        		}
        		if(cid%4==3)
        		{
        			col=Color.rgb(100, 50, 0);
        		}
        		
				if(cnt%7==0)
					pow=1;
				else
				if(cnt%15==0)
					pow=2;
				else
				if(cnt==5)
					pow=3;
				else
				if(cnt==11)
					pow=4;
				else
				if(cnt%8==0)
					pow=5;
				else
					pow=0;
													
				Brick br=new Brick(xc,yc,col,pow);
				br.toughness=tgh;
        		DrawView.bricks.add(br);
        		xc+=DrawView.brickWidth;
        		cid++;
        		cnt++;
        	}
        	yc+=DrawView.brickHeight;
        }
        delayInterval=60;
	}
	

	Thread t=new Thread(new Runnable() {
		
		@Override
		public void run() {
			int i,j,xc,yc,r,minx,miny,maxx,maxy,wd,ht;				
			Brick br=null;				
			
			r=DrawView.radius;
			minx=DrawView.minx;
			miny=DrawView.miny;
			maxx=DrawView.maxx;
			maxy=DrawView.maxy;
			wd=DrawView.brickWidth;
			ht=DrawView.brickHeight;
			
			while(true)
			{
				if(lost||levelCompleted)
					continue;
				
				xc=DrawView.xc;
				yc=DrawView.yc;
				if((xc>=maxx-r-1)||(xc<=r+minx+1))
					DrawView.xdir*=-1;

				if(yc<=r+miny+1)
					DrawView.ydir*=-1;
				else
					if((yc>=(DrawView.bary-r-1))||(yc<=r))
						if((xc>=DrawView.barx)&&(xc<=(DrawView.barx+DrawView.barlen)))
						{
							DrawView.ydir*=-1;
						}
						else
						{
							lost=true;
							handler.post(lostAction);
							continue;
						}
				
				if(DrawView.bricks.size()==0)
				{
					levelCompleted=true;
					handler.post(levelCompleteAction);
					continue;
				}
				
				for(i=0;i<DrawView.bricks.size();i++)
				{
					br=DrawView.bricks.get(i);
					if(((xc+r+1)>=br.x)&&((xc-r-1)<=(br.x+wd))&&(((br.y+r+1)>=br.y)&&((yc-r-1)<=(br.y+ht))))
					{						
							DrawView.xdir*=-1;
							DrawView.ydir*=-1;
							br.hit();
							
							
							if(br.toughness==0 && br.hiddenPower!=0)	     //Checks if any hidden power is present in brick
							{
								Power powp=new Power(xc,yc,DrawView.brickColors[br.hiddenPower],br.hiddenPower);
								//Log.d("hpower", String.valueOf(br.hiddenPower));
								DrawView.powers.add(powp);
								DrawView.powerActive=true;
							}						
							
							if(br.toughness==0){
								DrawView.bricks.remove(i);
							}
							else{
								br.color=Color.LTGRAY;
							}
							DrawView.score+=20;
							break;
					}
					
				}

		        try {
					Thread.sleep(delayInterval);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}
	});			
	
	Thread t1=new Thread(new Runnable() {
		
		@Override
		public void run() {
			while(true){			
				handler.post(drawUI);
				try {						
					Thread.sleep(delayInterval/2);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}					
			
		}
	});
	
	Thread t2=new Thread(new Runnable() {
		
		@Override
		public void run() {						
			int j,powx,powy,minx,miny,maxx,maxy,wd,ht;				
			Power powi=null;														
			
			minx=DrawView.minx;
			miny=DrawView.miny;
			maxx=DrawView.maxx;
			maxy=DrawView.maxy;
			wd=DrawView.brickWidth;
			ht=DrawView.brickHeight;							
			
			while(true){			
				
				if(lost||levelCompleted)
					continue;
				
				if(DrawView.powerActive){
					for(j=0;j<DrawView.powers.size();j++){
						powi=DrawView.powers.get(j);
						powi.y+=5;
						powx=powi.x;
						powy=powi.y;

						if(((powy+ht+1)>DrawView.bary)&&(powx+wd>=DrawView.barx)&&(powx+wd<=DrawView.barx+DrawView.barlen))
						{	//Checks whether the Stick catches the Power
							DrawView.powers.remove(j);
							
							if(DrawView.powers.size()==0)	//If there is no Power Sliding Down
								DrawView.powerActive=false;
							
							switch(powi.hiddenPower){
							case 1:
								DrawView.barlen+=20;
								DrawView.score+=100;
								handler.post(action1);
								break;
								
							case 2:
								lost=true;
								handler.post(lostAction);
								break;
								
							case 3:									
								delayInterval=30;
								DrawView.score+=50;
								handler.post(action3);
								break;
								
							case 4:
								if(DrawView.barlen-20>0)
									DrawView.barlen-=20;
								DrawView.score+=50;
								handler.post(action4);
								break;
								
							case 5:
								DrawView.score+=500;
								handler.post(action5);
								break;
							}
							break;
						}

						if(powy+ht>DrawView.maxy+3)		//If power crosses the stick, delete the power from memory
						{
							DrawView.powers.remove(j);
							if(DrawView.powers.size()==0)
								DrawView.powerActive=false;
							break;
						}
					}
				}
				try {
					Thread.sleep(30);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}
	});
	
	Runnable levelCompleteAction=new Runnable() {
		
		@Override
		public void run() {
			AlertDialog.Builder ad = new AlertDialog.Builder(FullscreenActivity.this);
			ad.setTitle("Level Completed!");
			ad.setMessage("Your Score: "+String.valueOf(DrawView.score));
			ad.setCancelable(false);
			ad.setNegativeButton("Replay", new DialogInterface.OnClickListener() {
				
				@Override
				public void onClick(DialogInterface dialog, int arg1) {
						drawBricks();
						
						drawView.initialize();						
						levelCompleted=false;
						lost=false;						
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
		
	Runnable lostAction=new Runnable() {
		
		@Override
		public void run() {
			AlertDialog.Builder ad = new AlertDialog.Builder(FullscreenActivity.this);
			ad.setTitle("Game Over");
			ad.setMessage("Your Score: "+String.valueOf(DrawView.score));
			ad.setCancelable(false);
			ad.setNegativeButton("Replay", new DialogInterface.OnClickListener() {
				
				@Override
				public void onClick(DialogInterface dialog, int arg1) {					
						drawView.initialize();
						drawBricks();
						levelCompleted=false;
						lost=false;
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
	
	Runnable action1=new Runnable() {
		
		@Override
		public void run() {
			Toast.makeText(getApplicationContext(), "Stick length increased by 10%", Toast.LENGTH_SHORT).show();
		}
	};
	
	Runnable action3=new Runnable() {
		
		@Override
		public void run() {
			Toast.makeText(getApplicationContext(), "Speed increased by 50%", Toast.LENGTH_SHORT).show();		
		}
	};
	
	Runnable action4=new Runnable() {
		
		@Override
		public void run() {
			Toast.makeText(getApplicationContext(), "Stick length decreased by 10%", Toast.LENGTH_SHORT).show();
		}
	};
	
	Runnable action5=new Runnable() {
		
		@Override
		public void run() {
			Toast.makeText(getApplicationContext(), "+500", Toast.LENGTH_SHORT).show();
		}
	};
	
	Runnable drawUI=new Runnable() {
		
		@Override
		public void run() {
			setContentView(drawView);			
		}
	};

	@Override
	protected void onPostCreate(Bundle savedInstanceState) {
		super.onPostCreate(savedInstanceState);
	}

	@Override
	public boolean onTouchEvent(MotionEvent event) {
		tx=(int)event.getRawX();
		ty=(int)event.getRawY();
		
		if(tx>prevtx)
		{
			if((DrawView.barx+DrawView.barlen+(tx-prevtx))<DrawView.maxx)
			DrawView.barx+=tx-prevtx;
		}
		else
			if(DrawView.barx-(prevtx-tx)>DrawView.minx)
				DrawView.barx-=prevtx-tx;
			
		prevtx=tx;
		prevty=ty;
		
		return super.onTouchEvent(event);
	}
}
