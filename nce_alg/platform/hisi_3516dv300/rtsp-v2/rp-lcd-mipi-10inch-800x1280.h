#ifndef __RP_LCD_MIPI_10INCH_800X1280_H__
#define __RP_LCD_MIPI_10INCH_800X1280_H__
#include "sample_comm.h"
#include "hi_mipi_tx.h"

/*============================= mipi 10 inch 800x1280 lcd config ====================================*/
combo_dev_cfg_t MIPI_TX_10INCH_800X1280_60_CONFIG =
{
    .devno = 0,
    .lane_id = {0, 1, 2, 3},
    .output_mode = OUTPUT_MODE_DSI_VIDEO,
    .output_format = OUT_FORMAT_RGB_24_BIT,
    .video_mode =  BURST_MODE,

    .sync_info = {
        .vid_pkt_size     = 800, // hact
        .vid_hsa_pixels   = 18,  // hsa   //20
        .vid_hbp_pixels   = 18,  // hbp  //20
        .vid_hline_pixels = 854, // hact + hsa + hbp + hfp  //hfb=32 //972
        .vid_vsa_lines    = 4,   // vsa
        .vid_vbp_lines    = 8,  // vbp
        .vid_vfp_lines    = 24,   // vfp
        .vid_active_lines = 1316,// vact
        .edpi_cmd_size    = 0,
    },

    .phy_data_rate = 495,
    .pixel_clk = 67432,
};

VO_SYNC_INFO_S MIPI_TX_10INCH_800X1280_60_SYNC_INFO = 
{
	.u16Hact	= 800,
	.u16Hbb		= 36,
	.u16Hfb		= 18,
	.u16Hpw		= 18,
	.u16Vact	= 1280,
	.u16Vbb		= 12,
	.u16Vfb		= 24,
	.u16Vpw		= 4,
};

VO_USER_INTFSYNC_INFO_S MIPI_TX_10INCH_800X1280_60_USER_INTFSYNC_INFO = 
{
	.stUserIntfSyncAttr = 
	{
		.stUserSyncPll	= 
		{
			.u32Fbdiv	= 67,
			.u32Frac	= 0x6e8d10,
			.u32Refdiv	= 2,
			.u32Postdiv1= 4,
			.u32Postdiv2= 3,
		},
	},

	.u32DevDiv			= 1,
	.u32PreDiv			= 1,
};

lcd_resoluton_t MIPI_TX_10INCH_800X1280_60_LCD_RESOLUTION = 
{
	.pu32W	= 800,
	.pu32H	= 1280,
	.pu32Frm= 60,

};

HI_VOID InitScreen_mipi_10inch_800x1280(HI_S32 s32fd)
{
    HI_S32     fd     = s32fd;
    HI_S32     s32Ret;
    HI_U8      cmd[30];
    cmd_info_t cmd_info = {0};
	HI_U32 i = 0;

    SAMPLE_PRT("%s,%d.\n",__FUNCTION__,__LINE__);
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
cmd_info.cmd_size  = 0x0270; 
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
cmd_info.cmd_size  = 0x2371; 
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
cmd_info.cmd_size  = 0x6601; 
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
cmd_info.cmd_size  = 0x6D04; 
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
cmd_info.cmd_size  = 0xBF18; 
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
cmd_info.cmd_size  = 0x0019; 
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
cmd_info.cmd_size  = 0xBF1B; 
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
cmd_info.cmd_size  = 0x001C; 
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
cmd_info.cmd_size  = 0x2820; 
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
cmd_info.cmd_size  = 0x2821; 
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
cmd_info.cmd_size  = 0x0937; 
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
cmd_info.cmd_size  = 0x0438; 
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
cmd_info.cmd_size  = 0xFF3D; 
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
cmd_info.cmd_size  = 0xFF3E; 
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
cmd_info.cmd_size  = 0x7F3F; 
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
cmd_info.cmd_size  = 0x0F55; 
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
cmd_info.cmd_size  = 0x295A; 
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
cmd_info.cmd_size  = 0x155B; 
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
cmd_info.cmd_size  = 0x555F; 
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
cmd_info.cmd_size  = 0x4960; 
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
cmd_info.cmd_size  = 0x4461; 
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
cmd_info.cmd_size  = 0x3A63; 
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
cmd_info.cmd_size  = 0x5D68; 
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
cmd_info.cmd_size  = 0x4D69; 
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
cmd_info.cmd_size  = 0x566A; 
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
cmd_info.cmd_size  = 0x486B; 
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
cmd_info.cmd_size  = 0x456C; 
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
cmd_info.cmd_size  = 0x386D; 
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
cmd_info.cmd_size  = 0x256E; 
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
cmd_info.cmd_size  = 0x5572; 
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
cmd_info.cmd_size  = 0x4973; 
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
cmd_info.cmd_size  = 0x4474; 
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
cmd_info.cmd_size  = 0x3A76; 
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
cmd_info.cmd_size  = 0x5D7B; 
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
cmd_info.cmd_size  = 0x4D7C; 
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
cmd_info.cmd_size  = 0x567D; 
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
cmd_info.cmd_size  = 0x487E; 
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
cmd_info.cmd_size  = 0x457F; 
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
cmd_info.cmd_size  = 0x3880; 
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
cmd_info.cmd_size  = 0x2581; 
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
cmd_info.cmd_size  = 0x1E00; 
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
cmd_info.cmd_size  = 0x1E01; 
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
cmd_info.cmd_size  = 0x4102; 
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
cmd_info.cmd_size  = 0x4103; 
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
cmd_info.cmd_size  = 0x4304; 
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
cmd_info.cmd_size  = 0x4305; 
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
cmd_info.cmd_size  = 0x1F06; 
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
cmd_info.cmd_size  = 0x1F07; 
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
cmd_info.cmd_size  = 0x1F08; 
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
cmd_info.cmd_size  = 0x1E0A; 
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
cmd_info.cmd_size  = 0x1E0B; 
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
cmd_info.cmd_size  = 0x470D; 
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
cmd_info.cmd_size  = 0x470E; 
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
cmd_info.cmd_size  = 0x450F; 
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
cmd_info.cmd_size  = 0x4510; 
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
cmd_info.cmd_size  = 0x4B11; 
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
cmd_info.cmd_size  = 0x4B12; 
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
cmd_info.cmd_size  = 0x4913; 
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
cmd_info.cmd_size  = 0x4914; 
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
cmd_info.cmd_size  = 0x1E16; 
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
cmd_info.cmd_size  = 0x1E17; 
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
cmd_info.cmd_size  = 0x4018; 
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
cmd_info.cmd_size  = 0x4019; 
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
cmd_info.cmd_size  = 0x421A; 
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
cmd_info.cmd_size  = 0x421B; 
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
cmd_info.cmd_size  = 0x1F1C; 
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
cmd_info.cmd_size  = 0x1F1D; 
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
cmd_info.cmd_size  = 0x1F1E; 
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
cmd_info.cmd_size  = 0x1f1F; 
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
cmd_info.cmd_size  = 0x1E20; 
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
cmd_info.cmd_size  = 0x1E21; 
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
cmd_info.cmd_size  = 0x1f22; 
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
cmd_info.cmd_size  = 0x4623; 
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
cmd_info.cmd_size  = 0x4624; 
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
cmd_info.cmd_size  = 0x4425; 
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
cmd_info.cmd_size  = 0x4426; 
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
cmd_info.cmd_size  = 0x4A27; 
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
cmd_info.cmd_size  = 0x4A28; 
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
cmd_info.cmd_size  = 0x4829; 
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
cmd_info.cmd_size  = 0x482A; 
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
cmd_info.cmd_size  = 0x1f2B; 
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
cmd_info.cmd_size  = 0x1F2C; 
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
cmd_info.cmd_size  = 0x1F2D; 
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
cmd_info.cmd_size  = 0x422E; 
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
cmd_info.cmd_size  = 0x422F; 
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
cmd_info.cmd_size  = 0x4030; 
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
cmd_info.cmd_size  = 0x4031; 
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
cmd_info.cmd_size  = 0x1E32; 
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
cmd_info.cmd_size  = 0x1E33; 
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
cmd_info.cmd_size  = 0x1F34; 
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
cmd_info.cmd_size  = 0x1E36; 
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
cmd_info.cmd_size  = 0x1E37; 
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
cmd_info.cmd_size  = 0x4839; 
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
cmd_info.cmd_size  = 0x483A; 
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
cmd_info.cmd_size  = 0x4A3B; 
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
cmd_info.cmd_size  = 0x4A3C; 
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
cmd_info.cmd_size  = 0x443D; 
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
cmd_info.cmd_size  = 0x443E; 
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
cmd_info.cmd_size  = 0x463F; 
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
cmd_info.cmd_size  = 0x4640; 
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
cmd_info.cmd_size  = 0x1F42; 
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
cmd_info.cmd_size  = 0x1F43; 
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
cmd_info.cmd_size  = 0x4344; 
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
cmd_info.cmd_size  = 0x4345; 
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
cmd_info.cmd_size  = 0x4146; 
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
cmd_info.cmd_size  = 0x4147; 
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
cmd_info.cmd_size  = 0x1E48; 
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
cmd_info.cmd_size  = 0x1E49; 
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
cmd_info.cmd_size  = 0x1E4A; 
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
cmd_info.cmd_size  = 0x1E4C; 
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
cmd_info.cmd_size  = 0x1E4D; 
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
cmd_info.cmd_size  = 0x494F; 
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
cmd_info.cmd_size  = 0x4950; 
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
cmd_info.cmd_size  = 0x4B51; 
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
cmd_info.cmd_size  = 0x4B52; 
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
cmd_info.cmd_size  = 0x4553; 
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
cmd_info.cmd_size  = 0x4554; 
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
cmd_info.cmd_size  = 0x4755; 
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
cmd_info.cmd_size  = 0x4756; 
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
cmd_info.cmd_size  = 0x1058; 
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
cmd_info.cmd_size  = 0x025C; 
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
cmd_info.cmd_size  = 0x405D; 
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
cmd_info.cmd_size  = 0x3060; 
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
cmd_info.cmd_size  = 0x6A63; 
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
cmd_info.cmd_size  = 0x6A64; 
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
cmd_info.cmd_size  = 0x0565; 
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
cmd_info.cmd_size  = 0x1266; 
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
cmd_info.cmd_size  = 0x7467; 
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
cmd_info.cmd_size  = 0x0468; 
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
cmd_info.cmd_size  = 0x6A69; 
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
cmd_info.cmd_size  = 0x6A6A; 
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
cmd_info.cmd_size  = 0x066D; 
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
cmd_info.cmd_size  = 0x006E; 
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

#if 1 
	// 0x1117006c 0x00003515;
    cmd_info.devno     = 0;
    cmd_info.cmd_size  = 0x0035;
    cmd_info.data_type = 0x23;
    cmd_info.cmd       = NULL;
    s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
    if (HI_SUCCESS != s32Ret)
    {
        SAMPLE_PRT("MIPI_TX SET CMD failed\n");
        close(fd);
        return;
    }
    usleep(10000);
#endif
}

#endif /* End of #ifndef __RP_LCD_MIPI_10INCH_800X1280_H__*/
