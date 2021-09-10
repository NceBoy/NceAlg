#ifndef __RP_LCD_MIPI_8INCH_800X1280_H__
#define __RP_LCD_MIPI_8INCH_800X1280_H__
#include "sample_comm.h"
#include "hi_mipi_tx.h"
/*============================= mipi 8 inch 800x1280 lcd config ====================================*/
combo_dev_cfg_t MIPI_TX_8INCH_800X1280_60_CONFIG =
{
    .devno = 0,
    .lane_id = {0, 1, 2, 3},
    .output_mode = OUTPUT_MODE_DSI_VIDEO,
    .output_format = OUT_FORMAT_RGB_24_BIT,
    .video_mode =  BURST_MODE,

    .sync_info = {
        .vid_pkt_size     = 800, // hact
        .vid_hsa_pixels   = 6,  // hsa   //20
        .vid_hbp_pixels   = 60,  // hbp  //20
        .vid_hline_pixels = 926, // hact + hsa + hbp + hfp  //hfb=32 //972
        .vid_vsa_lines    = 4,   // vsa
        .vid_vbp_lines    = 8,  // vbp
        .vid_vfp_lines    = 8,   // vfp
        .vid_active_lines = 1280,// vact
        .edpi_cmd_size    = 0,
    },

//    .phy_data_rate = 445,		// 445 stable
    .phy_data_rate = 459,		// 459 stable
    .pixel_clk = 72228,
};

VO_SYNC_INFO_S MIPI_TX_8INCH_800X1280_60_SYNC_INFO = 
{
	.u16Hact	= 800,
	.u16Hbb		= 60,
	.u16Hfb		= 60,
	.u16Hpw		= 6,
	.u16Vact	= 1280,
	.u16Vbb		= 8,
	.u16Vfb		= 8,
	.u16Vpw		= 4,
};

VO_USER_INTFSYNC_INFO_S MIPI_TX_8INCH_800X1280_60_USER_INTFSYNC_INFO = 
{
	.stUserIntfSyncAttr = 
	{
		.stUserSyncPll	= 
		{
			.u32Fbdiv	= 72,
			.u32Frac	= 0x3A5E35,
			.u32Refdiv	= 2,
			.u32Postdiv1= 4,
			.u32Postdiv2= 3,
		},
	},

	.u32DevDiv			= 1,
	.u32PreDiv			= 1,
};

lcd_resoluton_t MIPI_TX_8INCH_800X1280_60_LCD_RESOLUTION = 
{
	.pu32W	= 800,
	.pu32H	= 1280,
	.pu32Frm= 60,

};

HI_VOID InitScreen_mipi_8inch_800x1280(HI_S32 s32fd)
{
    HI_S32     fd     = s32fd;
    HI_S32     s32Ret;
    HI_U8      cmd[30];
    cmd_info_t cmd_info = {0};
    
	SAMPLE_PRT("%s,%d.\n",__FUNCTION__,__LINE__);
#if 1    
cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x00E0;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x93E1;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x65E2;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0xF8E3;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x00E0;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1070;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1371;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0672;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0380;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x04E0;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x032D;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x01E0;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0000;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0xA001;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0003;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0xA004;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0017;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0xB118;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0119;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x001A;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0xB11B;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x011C;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x3E1F;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x2D20;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x2D21;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0E22;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1937;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0538;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0839;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x123A;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x783C;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x803E;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x803F;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0640;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0xA041;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0155;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0156;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x6957;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0A58;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0A59;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x285A;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x195B;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x7C5D;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x655E;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x535F;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x4860;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x4361;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x3562;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x3963;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x2364;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x3D65;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x3C66;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x3D67;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x5A68;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x4669;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x576A;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x4B6B;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x496C;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x2F6D;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x036E;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x006F;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x7C70;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x6571;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x5372;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x4873;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x4374;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x3575;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x3976;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x2377;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x3D78;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x3C79;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x3D7A;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x5A7B;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x467C;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x577D;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x4B7E;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x497F;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x2F80;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0381;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0082;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x02E0;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x4700;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x4701;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x4502;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x4503;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x4B04;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x4B05;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x4906;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x4907;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x4108;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F09;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F0A;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F0B;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F0C;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F0D;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F0E;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x430F;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F10;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F11;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F12;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F13;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F14;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F15;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x4616;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x4617;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x4418;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x4419;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x4A1A;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x4A1B;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x481C;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x481D;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x401E;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F1F;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F20;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F21;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F22;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F23;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F24;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x4225;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F26;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F27;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F28;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F29;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F2A;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F2B;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x112C;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0F2D;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0D2E;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0B2F;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0930;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0731;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0532;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1833;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1734;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F35;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0136;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F37;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F38;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F39;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F3A;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F3B;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F3C;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F3D;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F3E;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x133F;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F40;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F41;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1042;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0E43;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0C44;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0A45;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0846;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0647;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0448;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1849;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x174A;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F4B;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x004C;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F4D;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F4E;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F4F;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F50;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F51;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F52;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F53;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F54;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1255;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F56;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F57;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x4058;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0059;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x005A;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x305B;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x035C;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x305D;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x015E;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x025F;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0060;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0161;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0262;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0363;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x6B64;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0065;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0066;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x7367;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0568;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0669;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x6B6A;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x086B;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x006C;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x046D;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x046E;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x886F;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0070;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0071;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0672;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x7B73;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0074;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0775;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x0076;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x5D77;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1778;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1F79;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x007A;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x007B;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x007C;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x037D;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x7B7E;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x01E0;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x010E;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x03E0;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x2F98;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x04E0;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x1009;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x2B2B;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x442E;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x00E0;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x02E6;
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

cmd_info.devno     = 0;
cmd_info.cmd_size  = 0x02E7;
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
#endif
	cmd_info.devno = 0;
	cmd_info.cmd_size = 0x11;
	cmd_info.data_type    = 0x05;
	cmd_info.cmd          = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
		SAMPLE_PRT("MIPI_TX_SET CMD failed\n");
		close(fd);
		return;
	}           
	usleep(120000);

	cmd_info.devno = 0;
	cmd_info.cmd_size = 0x29;
	cmd_info.data_type    = 0x05;
	cmd_info.cmd          = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
		SAMPLE_PRT("MIPI_TX_SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(120000);
}

#endif /* End of #ifndef __RP_LCD_MIPI_8INCH_800X1280_H__*/
