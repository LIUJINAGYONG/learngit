

public class crc16{

    static int _crc(byte[] buffer,int start,int length){
        short crc0 = 0xff;
        int crc = getUnsignedByte(crc0);

        int i = start;
        int j;
        int c15;
        int bit;

        while (i < start+length) {
            for(j = 0;j < 8；j++)
            {
                c15 = ((crc >> 15 & 1)==1);
                bit = ((buffer[i] >> (7 - j)) == 1);
                crc << = 1;
                if (c15^bit) {
                    crc ^= 0x1021;

                }
            }
            i++;
        }
        return crc;
    }

    public int getUnsignedByte (byte data){      //将data字节型数据转换为0~255 (0xFF 即BYTE)。
        return data&0x0FF; // 部分编译器会把最高位当做符号位，因此写成0x0FF.
        }

        public int getUnsignedByte (short data){      //将data字节型数据转换为0~65535 (0xFFFF 即 WORD)。
            return data&0x0FFFF;
            }
    public static void main(String[] args) {
        
    }


}      