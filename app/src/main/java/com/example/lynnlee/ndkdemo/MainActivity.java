package com.example.lynnlee.ndkdemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);
        TextView tv2 = findViewById(R.id.sample_text2);
        tv.setText(JniUtils.stringFromJNI());
        tv.setText("" + JniUtils.addFromJNI(1, 2));
    }
}
