#include "sample_comm.h"


typedef struct
{
    unsigned long long timeTick;        //ʱ��(ms)
    unsigned int dataLen;               //���ݳ���
    unsigned char dataType;             //��������(DataType_E)
    unsigned char rsv[3];   
    unsigned long long timeStamp;       //����ʱ���(us)
    unsigned char iFrame;               //�Ƿ�Ϊ�ؼ�֡
    unsigned char frameRate;            //֡��
    int encodeType;                     //��������VideoEncodeType_E
    unsigned short width;               //��Ƶ���
    unsigned short height;              //��Ƶ�߶�
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

