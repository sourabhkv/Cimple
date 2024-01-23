import java.util.Scanner;
public class CRC 
{
        public static int n;
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in); 
        CRC crc=new CRC();
        String copy,rec,code,zero="0000000000000000";
        System.out.println("enter the dataword to be sent"); 
        code=sc.nextLine();
        n=code.length();
        System.out.println("Length of the dataword="+n); 

        copy=code; 
        code+=zero; 
        code=crc.divide(code);
        System.out.println("dataword="+copy); 
        copy=copy.substring(0,n)+code.substring(n);
        System.out.print("CRC="); 
        System.out.println(code.substring(n));
        System.out.println("transmitted frame is="+copy);
        System.out.println("enter received data:"); 
        rec=sc.nextLine();
        if(zero.equals(crc.divide(rec).substring(n))) 
        System.out.println("correct bits received"); 
        else
        System.out.println("received frame contains one or more error");
        sc.close();
    }
    public String divide(String s)
    {
        String div="10001000000100001";
        int i,j;
        char x;
        for(i=0;i<n;i++)
        {
            x=s.charAt(i);
            for(j=0;j<17;j++)
            {
            if(x=='1')
            {
                if(s.charAt(i+j)!=div.charAt(j)) 
                    s=s.substring(0,i+j)+"1"+s.substring(i+j+1);
                else
                    s=s.substring(0,i+j)+"0"+s.substring(i+j+1);
            }
        }
    }
    return s;
    }
}
/*
 
Output:
# java CRC
enter the dataword to be sent
1100
dataword=1100
CRC=1100000110001100
transmitted frame is=11001100000110001100
enter received data:
11001100000110001101
received frame contains one or more error

# java CRC
enter the dataword to be sent
1100
dataword=1100
CRC=1100000110001100
transmitted frame is=11001100000110001100
enter received data:
11001100000110001100
correct bits received

 */