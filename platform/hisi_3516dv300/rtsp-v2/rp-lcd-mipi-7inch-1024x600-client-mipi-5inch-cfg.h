#ifndef __RP_LCD_MIPI_7INCH_1024X600_H__
#define __RP_LCD_MIPI_7INCH_1024X600_H__
#include "sample_comm.h"
#include "hi_mipi_tx.h"
/*============================= mipi 7 inch 1024x600 lcd config ====================================*/
combo_dev_cfg_t MIPI_TX_7INCH_1024X600_60_CONFIG =
{
    .devno = 0,
    .lane_id = {0, 1, -1, -1},
    .output_mode = OUTPUT_MODE_DSI_VIDEO,
    .output_format = OUT_FORMAT_RGB_24_BIT,
    .video_mode =  BURST_MODE,

    .sync_info = {
        .vid_pkt_size     = 480, // hact
        .vid_hsa_pixels   = 4,  // hsa   //20
        .vid_hbp_pixels   = 44,  // hbp  //20
        .vid_hline_pixels = 574, // hact + hsa + hbp + hfp  //hfb=32 //972
        .vid_vsa_lines    = 2,   // vsa
        .vid_vbp_lines    = 16,  // vbp
        .vid_vfp_lines    = 15,   // vfp
        .vid_active_lines = 887,// vact
        .edpi_cmd_size    = 0,
    },

    .phy_data_rate = 367,
    .pixel_clk = 30549,
};

VO_SYNC_INFO_S MIPI_TX_7INCH_1024X600_60_SYNC_INFO = 
{
	.u16Hact	= 480,
	.u16Hbb		= 48,
	.u16Hfb		= 46,
	.u16Hpw		= 4,
	.u16Vact	= 854,
	.u16Vbb		= 18,
	.u16Vfb		= 15,
	.u16Vpw		= 2,
};

VO_USER_INTFSYNC_INFO_S MIPI_TX_7INCH_1024X600_60_USER_INTFSYNC_INFO = 
{
	.stUserIntfSyncAttr = 
	{
		.stUserSyncPll	= 
		{
			.u32Fbdiv	= 249,
			.u32Frac	= 0x7a454d,
			.u32Refdiv	= 4,
			.u32Postdiv1= 7,
			.u32Postdiv2= 7,
		},
	},

	.u32DevDiv			= 1,
	.u32PreDiv			= 1,
};

lcd_resoluton_t MIPI_TX_7INCH_1024X600_60_LCD_RESOLUTION = 
{
	.pu32W	= 480,
	.pu32H	= 854,
	.pu32Frm= 60,

};


HI_VOID InitScreen_mipi_7inch_1024x600(HI_S32 s32fd)
{
    HI_S32     fd     = s32fd;
    HI_S32     s32Ret;
    HI_U8      cmd[30];
    cmd_info_t cmd_info = {0};
	HI_U32 i = 0;

    SAMPLE_PRT("%s,%d.\n",__FUNCTION__,__LINE__);
	cmd[0] = 0xF0;
	cmd[1] = 0x5A;
	cmd[2] = 0x5A;
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x3; 
	cmd_info.data_type = 0x29;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd[0] = 0xF1;
	cmd[1] = 0xA5;
	cmd[2] = 0xA5;
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x3; 
	cmd_info.data_type = 0x29;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd[0] = 0xB4;
	cmd[1] = 0x03;
	cmd[2] = 0x03;
	cmd[3] = 0x03;
	cmd[4] = 0x06;
	cmd[5] = 0x04;
	cmd[6] = 0x0C;
	cmd[7] = 0x0E;
	cmd[8] = 0x10;
	cmd[9] = 0x12;
	cmd[10] = 0x08;
	cmd[11] = 0x0A;
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0xc; 
	cmd_info.data_type = 0x29;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd[0] = 0xB3;
	cmd[1] = 0x03;
	cmd[2] = 0x03;
	cmd[3] = 0x03;
	cmd[4] = 0x07;
	cmd[5] = 0x05;
	cmd[6] = 0x0D;
	cmd[7] = 0x0F;
	cmd[8] = 0x11;
	cmd[9] = 0x13;
	cmd[10] = 0x09;
	cmd[11] = 0x0B;
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0xc; 
	cmd_info.data_type = 0x29;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd[0] = 0xB0;
	cmd[1] = 0x54;
	cmd[2] = 0x32;
	cmd[3] = 0x23;
	cmd[4] = 0x45;
	cmd[5] = 0x44;
	cmd[6] = 0x44;
	cmd[7] = 0x44;
	cmd[8] = 0x44;
	cmd[9] = 0x60;
	cmd[10] = 0x00;
	cmd[11] = 0x60;
	cmd[12] = 0x1C;
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0xd; 
	cmd_info.data_type = 0x29;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd[0] = 0xB1;
	cmd[1] = 0x32;
	cmd[2] = 0x84;
	cmd[3] = 0x02;
	cmd[4] = 0x83;
	cmd[5] = 0x12;
	cmd[6] = 0x00;
	cmd[7] = 0x70;
	cmd[8] = 0x1C;
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x9; 
	cmd_info.data_type = 0x29;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd[0] = 0xB2;
	cmd[1] = 0x73;
	cmd[2] = 0x09;
	cmd[3] = 0x08;
	cmd[4] = 0x89;
	cmd[5] = 0x48;
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x6; 
	cmd_info.data_type = 0x29;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd[0] = 0xB6;
	cmd[1] = 0x70;
	cmd[2] = 0x70;
	cmd[3] = 0x05;
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x4; 
	cmd_info.data_type = 0x29;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x41B7; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd[0] = 0xC1;
	cmd[1] = 0x10;
	cmd[2] = 0x0E;
	cmd[3] = 0x02;
	cmd[4] = 0x14;
	cmd[5] = 0x14;
	cmd[6] = 0x08;
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x7; 
	cmd_info.data_type = 0x29;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x82C2; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd[0] = 0xC3;
	cmd[1] = 0x22;
	cmd[2] = 0x11;
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x3; 
	cmd_info.data_type = 0x29;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd[0] = 0xD0;
	cmd[1] = 0x07;
	cmd[2] = 0xFF;
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x3; 
	cmd_info.data_type = 0x29;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd[0] = 0xD2;
	cmd[1] = 0x63;
	cmd[2] = 0x0B;
	cmd[3] = 0x08;
	cmd[4] = 0x88;
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x5; 
	cmd_info.data_type = 0x29;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd[0] = 0xC6;
	cmd[1] = 0x08;
	cmd[2] = 0x15;
	cmd[3] = 0xFF;
	cmd[4] = 0x10;
	cmd[5] = 0x16;
	cmd[6] = 0x80;
	cmd[7] = 0x60;
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x8; 
	cmd_info.data_type = 0x29;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x04C7; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd[0] = 0xC9;
	cmd[1] = 0x37;
	cmd[2] = 0x93;
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x3; 
	cmd_info.data_type = 0x29;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd[0] = 0xC8;
	cmd[1] = 0x7D;
	cmd[2] = 0x69;
	cmd[3] = 0x5A;
	cmd[4] = 0x4D;
	cmd[5] = 0x49;
	cmd[6] = 0x3A;
	cmd[7] = 0x3E;
	cmd[8] = 0x2A;
	cmd[9] = 0x45;
	cmd[10] = 0x47;
	cmd[11] = 0x48;
	cmd[12] = 0x69;
	cmd[13] = 0x57;
	cmd[14] = 0x5F;
	cmd[15] = 0x52;
	cmd[16] = 0x4D;
	cmd[17] = 0x40;
	cmd[18] = 0x2C;
	cmd[19] = 0x07;
	cmd[20] = 0x7D;
	cmd[21] = 0x69;
	cmd[22] = 0x5A;
	cmd[23] = 0x4D;
	cmd[24] = 0x49;
	cmd[25] = 0x3A;
	cmd[26] = 0x3E;
	cmd[27] = 0x2A;
	cmd[28] = 0x45;
	cmd[29] = 0x47;
	cmd[30] = 0x48;
	cmd[31] = 0x69;
	cmd[32] = 0x57;
	cmd[33] = 0x5F;
	cmd[34] = 0x52;
	cmd[35] = 0x4D;
	cmd[36] = 0x40;
	cmd[37] = 0x2C;
	cmd[38] = 0x07;
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x27; 
	cmd_info.data_type = 0x29;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0011; 
	cmd_info.data_type = 0x05;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(200000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0029; 
	cmd_info.data_type = 0x05;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
}

#endif /* End of #ifndef __RP_LCD_MIPI_7INCH_1024X600_H__ */
