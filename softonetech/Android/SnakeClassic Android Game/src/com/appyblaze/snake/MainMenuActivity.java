package com.appyblaze.snake;

import android.annotation.SuppressLint;
import android.annotation.TargetApi;
import android.app.ActionBar;
import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Build;
import android.os.Bundle;
import android.view.View;
import android.widget.RadioButton;

public class MainMenuActivity extends Activity {

	public static int level=3;
	
	@TargetApi(Build.VERSION_CODES.HONEYCOMB)
	@SuppressLint("NewApi")
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_fullscreen);
		
		if(Build.VERSION.SDK_INT>=Build.VERSION_CODES.HONEYCOMB)
		{
			ActionBar actionBar=getActionBar();
			actionBar.hide();
		}
		
		final Dialog dialog=new Dialog(MainMenuActivity.this);		
		dialog.setContentView(R.layout.dialog_levels);
		dialog.setTitle("Select Level");
		dialog.setCancelable(true);
				
		final RadioButton rlevel1=(RadioButton) dialog.findViewById(R.id.rlevel1);
		final RadioButton rlevel2=(RadioButton) dialog.findViewById(R.id.rlevel2);
		final RadioButton rlevel3=(RadioButton) dialog.findViewById(R.id.rlevel3);
		final RadioButton rlevel4=(RadioButton) dialog.findViewById(R.id.rlevel4);
		final RadioButton rlevel5=(RadioButton) dialog.findViewById(R.id.rlevel5);
		
		rlevel1.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View v) {
				level=1;
				FullscreenActivity.delayInterval=240;
				dialog.dismiss();
			}
		});
		
		rlevel2.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View v) {
				level=2;
				FullscreenActivity.delayInterval=200;
				dialog.dismiss();
			}
		});
		
		rlevel3.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View v) {
				level=3;
				FullscreenActivity.delayInterval=160;
				dialog.dismiss();
			}
		});
		
		rlevel4.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View v) {
				level=4;
				FullscreenActivity.delayInterval=120;
				dialog.dismiss();
			}
		});
		
		rlevel5.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View v) {
				level=5;
				FullscreenActivity.delayInterval=80;
				dialog.dismiss();
			}
		});

		
		View play=findViewById(R.id.imageView_play);
		View level=findViewById(R.id.imageView_level);
		View about=findViewById(R.id.imageView_about);				
		
		play.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View v) {
				Intent intent=new Intent(MainMenuActivity.this,FullscreenActivity.class);
				startActivity(intent);
			}
		});				
		
		level.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View v) {
				if(getLevel()==1)
					rlevel1.setChecked(true);
				else
					if(getLevel()==2)
						rlevel2.setChecked(true);
					else
						if(getLevel()==3)
							rlevel3.setChecked(true);
						else
							if(getLevel()==4)
								rlevel4.setChecked(true);
							else
								if(getLevel()==5)
									rlevel5.setChecked(true);
				dialog.show();
			}
		});
		
		final AlertDialog.Builder ad = new AlertDialog.Builder(MainMenuActivity.this);
		ad.setTitle("About Game");
		ad.setMessage("Snake Classic\nVersion: 1.0.0\nMinimum supported SDK: Android 2.2 Froyo\nGame Developed by AppyBlaze @ SoftOne Tech\nVisit Us at: www.softonetech.com\nWrite Us Feedback: support@softonetech.com");
		ad.setCancelable(true);
		ad.setPositiveButton("OK", new DialogInterface.OnClickListener() {

			@Override
			public void onClick(DialogInterface dialog, int arg1) {
				
			}
		});
		
		about.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View v) {
				ad.show();
			}
		});
	}

	public int getLevel(){
		return level;
	}
}
