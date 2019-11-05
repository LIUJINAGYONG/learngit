package com.example.as.clienttest;
import android.os.Handler;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintStream;
import java.net.Socket;

public class MainActivity extends AppCompatActivity {
    EditText editText;
    TextView textView;
    Button button;
    Socket socket = null;
    InputStream in ;
    OutputStream outputStream;
    PrintStream printStream;
    String resulter;
Handler handler=new Handler(){
    public void handleMessage(android.os.Message msg){
        if (msg.what == 0x01){

            textView.setText(resulter);
        }
    }
};
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        editText=findViewById(R.id.editText2);
        textView=findViewById(R.id.textView2);
        button=findViewById(R.id.button2);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Toast.makeText(MainActivity.this,"start",Toast.LENGTH_SHORT).show();
                new Thread(){
                    public void run(){
                            try {
                                socket = new Socket("192.168.1.188",50000);
                                in = socket.getInputStream();
                                outputStream = socket.getOutputStream();
                                printStream = new PrintStream(outputStream);
                                int a1=0xff;
                                int a2=0xd9;
                                byte b1=(byte)a1;
                                byte b2=(byte)a2;
                                byte[] head =new byte[10];
                                head[0]=0x68;
                                head[1]=0x20;
                                head[2]=0x00;
                                head[3]=0x00;
                                head[4]=0x00;
                                head[5]=0x01;
                                head[6]=b1;
                                head[7]=0x16;
                                head[8]=b2;
                                head[9]=0x16;
                                printStream.write(head);
                               // printStream.println(head);
                               // textView.setText("nha");
                                
                                /*
                                BufferedReader reader=new BufferedReader(new InputStreamReader(inputStream,"UTF-8"));
                               // resulter=reader.readLine();
                              // BufferedReader input = new BufferedReader(new  InputStreamReader(m_conn.openInputStream()))   
                               String message = "";  
                               String line = null;  
                               while((line = m_input.readLine()) != null) {  
                                   message += line;  
                               }  
                               System.out.println(message); 
                               */
                              byte[] buffer = new byte[in.available()];
                              in.read(buffer);
                              String msg = new String(buffer);
                              msg.concat(str)
                                for(int i=0;i < msg.length();i++)
                                {
                                    resulter[i] = msg[i];
                                }
                                //resulter="liu";
                                textView.setText(resulter);
                                handler.sendEmptyMessage(0x01);

                            } catch (IOException e) {
                                e.printStackTrace();
                            }
                    }
                }.start();
            }
        });
    }
}
