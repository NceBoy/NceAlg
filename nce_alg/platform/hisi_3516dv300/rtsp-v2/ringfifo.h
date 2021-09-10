#include "sample_comm.h"


typedef struct
{
    unsigned long long timeTick;        //时间(ms)
    unsigned int dataLen;               //数据长度
    unsigned char dataType;             //数据类型(DataType_E)
    unsigned char rsv[3];   
    unsigned long long timeStamp;       //编码时间戳(us)
    unsigned char iFrame;               //是否为关键帧
    unsigned char frameRate;            //帧率
    int encodeType;                     //编码类型VideoEncodeType_E
    unsigned short width;               //视频宽度
    unsigned short height;              //视频高度
    unsigned char rsv1[8];
    unsigned char data[0];
}IFVFrameHeader_S;

struct ringbuf {
    unsigned char *buffer;
    int frame_type;
    int size;
};

int addring (int i);
int ringget(struct ringbuf *getinfo);
void ringput(unsigned char *buffer,int size,int encode_type);
void ringfree();
void ringmalloc(int size);
void ringreset();
HI_S32 HisiPutH264DataToBuffer(VENC_STREAM_S *pstStream);

