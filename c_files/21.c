#define GPIO_DataAddr GPIO_BaseAddr
#define GPIO_TriAddr GPIO_BaseAddr+4
/*
IO0 SCL 
IO1 SDA
 */
bool I2CSend() 
{
    //GPIO初始化
    Xil_Out8(GPIO_DataAddr, 0x03);//初始化为高
    Xil_Out8(GPIO_TriAddr, 0x0);//输出
    delay_us(1);

    //发送起始信号 SDA从高变低 SCL为高
    Xil_Out8(GPIO_DataAddr, 0x03);
    delay_us(1);
    Xil_Out8(GPIO_DataAddr, 0x01);
    delay_us(1);

    unsigned char data = 0xc5;
    for(int i=0;i<8;i++)//从高到低传
    {
        unsigned char temp = (data >> (7-i)) & 0x1;
        Xil_Out8(GPIO_DataAddr, 0x00);//把SCL变低 
        delay_us(1);
        Xil_Out8(GPIO_DataAddr,temp << 1);
        delay_us(1);
        Xil_Out8(GPIO_DataAddr, 0x01);//把SCL变高 总线读取这一位
        delay_us(1);
    }

    //应答 SCL为高电平期间 SDA从高变低
    Xil_Out8(GPIO_TriAddr, 0x01);//SDA变为输入
    Xil_Out8(GPIO_DataAddr, 0x02);//
    delay_us(2);
    if(Xil_In8(GPIO_DataAddr) == 0x03)//收到应答
    {
        Xil_Out8(GPIO_TriAddr,0x00);    //设置为输入
        Xil_Out8(GPIO_DataAddr,0x03);   //通信结束
        return true;
    }
    else
    {
        Xil_Out8(GPIO_TriAddr,0x00);    //设置为输入
        Xil_Out8(GPIO_DataAddr,0x03);   //通信结束
        return false;
    }
    
}