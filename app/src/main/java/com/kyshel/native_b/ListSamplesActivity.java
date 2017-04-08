package com.kyshel.native_b;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

public class ListSamplesActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_list_samples);
    }

    Intent sampleIntent;

    public void tutorial1(View v) {
        sampleIntent = new Intent(this, Tutorial1Activity.class);
        startActivity(sampleIntent);
    }

    public void tutorial2(View v) {
        sampleIntent = new Intent(this, Tutorial2Activity.class);
        startActivity(sampleIntent);
    }

    public void tutorial3(View v) {
        sampleIntent = new Intent(this, Tutorial3Activity.class);
        startActivity(sampleIntent);
    }

    public void imageManipulations(View v) {
        sampleIntent = new Intent(this, ImageManipulationsActivity.class);
        startActivity(sampleIntent);
    }

    public void faceDetection(View v) {
        sampleIntent = new Intent(this, FaceDetectionActivity.class);
        startActivity(sampleIntent);
    }

    public void colorBlobDetection(View v) {
        sampleIntent = new Intent(this, ColorBlobDetectionActivity.class);
        startActivity(sampleIntent);
    }
//
//    public void cameraCalibration(View v) {
//        sampleIntent = new Intent(this, CameraCalibrationActivity.class);
//        startActivity(sampleIntent);
//    }
//
    public void puzzle15(View v) {
        sampleIntent = new Intent(this, Puzzle15Activity.class);
        startActivity(sampleIntent);
    }

    public void sampleSalt(View v) {
        sampleIntent = new Intent(this, SaltActivity.class);
        startActivity(sampleIntent);
    }



}
