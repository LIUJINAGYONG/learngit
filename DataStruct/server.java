import java.io.InputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;
//import java.*;
public class server {
    public static void main(String[] args) {
        //创建socket对象并指定端口
    ServerSocket myserver = ServerSocket(6000);
    //与客户端建立连接
    Socket ser = myserver.accept();
    //获取输入流
    InputStream ss = ser.getInputStream();
    byte[] rcv = new byte[1024];
    //将输入流读取到rcv数组中，并返回读取的长度；
    int len = ss.read(rcv);
    String msg = new String(rcv, 0, len);
    
    System.out.println(msg);
    System.out.println("kai shi fa song!");
    OutputStream out = ser.getOutputStream();
    String tString = new String("nihaowo");
    out.write(tString.getBytes());

    ss.close();
    out.close();
    myserver.close();
    }
    


}


