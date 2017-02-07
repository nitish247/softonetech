package com.softonetech.appyblaze.hitball;

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
	
	@TargetApi(Build.VERSION_CODES.HONEYCOMB)
	@SuppressLint("NewApi")
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_mainmenu);
		
		if(Build.VERSION.SDK_INT>=Build.VERSION_CODES.HONEYCOMB)
		{
			ActionBar actionBar=getActionBar();
			actionBar.hide();
		}
		
		View play=findViewById(R.id.imageView_play);
		View about=findViewById(R.id.imageView_about);				
		
		play.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View v) {
				Intent intent=new Intent(MainMenuActivity.this,FullscreenActivity.class);
				startActivity(intent);
			}
		});						
		
		final AlertDialog.Builder ad = new AlertDialog.Builder(MainMenuActivity.this);
		ad.setTitle("About Game");
		ad.setMessage("Hitball\nVersion: 1.0.0\nMinimum supported SDK: Android 2.2 Froyo\nGame Developed by AppyBlaze @ SoftOne Tech\nVisit Us at: www.softonetech.com\nWrite Us Feedback: support@softonetech.com");
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
}
