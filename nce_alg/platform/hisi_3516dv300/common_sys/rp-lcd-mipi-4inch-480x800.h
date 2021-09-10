#ifndef __RP_LCD_MIPI_4INCH_480X800_H__
#define __RP_LCD_MIPI_4INCH_480X800_H__
#include "sample_comm.h"
#include "hi_mipi_tx.h"
/*============================= mipi 4 inch 480x800 lcd config ====================================*/
combo_dev_cfg_t MIPI_TX_4INCH_480X800_60_CONFIG = {
	.devno = 0,
	.lane_id = {0, 1, -1, -1},
	.output_mode = OUTPUT_MODE_DSI_VIDEO,

	.output_format = OUT_FORMAT_RGB_24_BIT,
	.video_mode =  BURST_MODE,

	.sync_info = {
		.vid_pkt_size=480,
		.vid_hsa_pixels=50,  //10
		.vid_hbp_pixels=40,  //30
		.vid_hline_pixels=580,
		.vid_vsa_lines=10,  //5
		.vid_vbp_lines=14,  //12
		.vid_vfp_lines=10,  //16
		.vid_active_lines=834,
		.edpi_cmd_size=0,
	},
	.phy_data_rate=370,
	 .pixel_clk=28000,

  };

VO_SYNC_INFO_S MIPI_TX_4INCH_480X800_60_SYNC_INFO = {
	.u16Hact=480,
	.u16Hbb=40,
	.u16Hfb=40,
	.u16Hpw=10,
	.u16Vact=800,
	.u16Vbb=24,
	.u16Vfb=16,
	.u16Vpw=5,

};

VO_USER_INTFSYNC_INFO_S MIPI_TX_4INCH_480X800_60_USER_INTFSYNC_INFO = {
	.stUserIntfSyncAttr =
	{
		.stUserSyncPll	=
		{
			.u32Fbdiv=225,
			.u32Frac=0x4F51AC,
			.u32Refdiv=4,
			.u32Postdiv1=7,
			.u32Postdiv2=7,

		},
	},

	.u32DevDiv			= 1,
	                    .u32PreDiv			= 1,
                                        };

lcd_resoluton_t MIPI_TX_4INCH_480X800_60_LCD_RESOLUTION = {
	.pu32W	= 480,
	.pu32H	= 800,
	.pu32Frm= 60,

};


HI_VOID InitScreen_mipi_4inch_480x800(HI_S32 s32fd)
{
	SAMPLE_PRT("%s,%d.\n",__FUNCTION__,__LINE__);
	HI_S32     fd     = s32fd;
	HI_S32     s32Ret;
	HI_U8      cmd[30];
	cmd_info_t cmd_info = {0};
	HI_U32 i = 0;
	cmd[0] = 0xFF;
	cmd[1] = 0xFF;
	cmd[2] = 0x98;
	cmd[3] = 0x06;
	cmd[4] = 0x04;
	cmd[5] = 0x00;
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 6;
	cmd_info.data_type = 0x29;
	cmd_info.cmd       = cmd;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x1008;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0121;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0230;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0031;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x1040;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x5541;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0242;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0943;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0744;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x7850;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x7851;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0052;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x7753;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0760;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0061;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0862;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0063;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x00A0;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x03A1;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x08A2;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0FA3;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x07A4;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0BA5;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x07A6;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x06A7;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x07A8;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0CA9;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0EAA;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x05AB;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0CAC;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x21AD;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x1CAE;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x00C0;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x04C1;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x09C2;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0EC3;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x06C4;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0BC5;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x07C6;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x05C7;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x08C8;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0CC9;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0FCA;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x06CB;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0CCC;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x20CD;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x1CCE;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x00CF;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd[0] = 0xFF;
	cmd[1] = 0xFF;
	cmd[2] = 0x98;
	cmd[3] = 0x06;
	cmd[4] = 0x04;
	cmd[5] = 0x06;
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 6;
	cmd_info.data_type = 0x29;
	cmd_info.cmd       = cmd;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x2100;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0901;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0002;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
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
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0104;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0105;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x8006;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0507;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0208;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x8009;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x000A;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x000B;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0A0C;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0A0D;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x000E;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x000F;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0xE010;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0xE411;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0412;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0013;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0014;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0xC015;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0816;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
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
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0018;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
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
	if (HI_SUCCESS != s32Ret) {
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
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x001B;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
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
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x001D;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0120;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x2321;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x4522;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x6723;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0124;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x2325;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x4526;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x6727;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0130;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x1131;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0032;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0xEE33;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0xFF34;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0xCB35;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0xDA36;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0xAD37;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0xBC38;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x7639;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x673A;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x223B;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x223C;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x223D;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x223E;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x223F;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x2240;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x1052;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x1053;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x1354;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd[0] = 0xFF;
	cmd[1] = 0xFF;
	cmd[2] = 0x98;
	cmd[3] = 0x06;
	cmd[4] = 0x04;
	cmd[5] = 0x07;
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 6;
	cmd_info.data_type = 0x29;
	cmd_info.cmd       = cmd;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x10B3;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x2217;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x7702;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0xB226;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x79E1;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd[0] = 0xFF;
	cmd[1] = 0xFF;
	cmd[2] = 0x98;
	cmd[3] = 0x06;
	cmd[4] = 0x04;
	cmd[5] = 0x00;
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 6;
	cmd_info.data_type = 0x29;
	cmd_info.cmd       = cmd;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0035;
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
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
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(300000);

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0029;
	cmd_info.data_type = 0x05;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(100000);

	cmd[0] = 0xFF;
	cmd[1] = 0xFF;
	cmd[2] = 0x98;
	cmd[3] = 0x06;
	cmd[4] = 0x04;
	cmd[5] = 0x00;
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 6;
	cmd_info.data_type = 0x29;
	cmd_info.cmd       = cmd;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret) {
		SAMPLE_PRT("MIPI_TX SET CMD failed\n");
		close(fd);
		return;
	}
	usleep(1000);

}

#endif /* End of #ifndef __RP_LCD_MIPI_4INCH_480X800_H__ */
