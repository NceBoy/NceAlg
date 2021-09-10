#ifndef __RP_LCD_MIPI_5INCH_720x1280_H__
#define __RP_LCD_MIPI_5INCH_720x1280_H__
#include "sample_comm.h"
#include "hi_mipi_tx.h"
/*============================= mipi 5 inch 720x1280 lcd config ====================================*/
combo_dev_cfg_t MIPI_TX_5INCH_720x1280_60_CONFIG = {
	.devno = 0,
	.lane_id = {0, 1, -1,-1},
	.output_mode = OUTPUT_MODE_DSI_VIDEO,

	.output_format = OUT_FORMAT_RGB_24_BIT,
	.video_mode =  BURST_MODE,

	.sync_info = {
		.vid_pkt_size=720,
		.vid_hsa_pixels=4,
		.vid_hbp_pixels=30,
		.vid_hline_pixels=818,
		.vid_vsa_lines=2,
		.vid_vbp_lines=16,
		.vid_vfp_lines=16,
		.vid_active_lines=1314,
		.edpi_cmd_size=0,

	},
	.phy_data_rate=774,
	 .pixel_clk=64492,
  };

VO_SYNC_INFO_S MIPI_TX_5INCH_720x1280_60_SYNC_INFO = {
	.u16Hact=720,
	.u16Hbb=34,
	.u16Hfb=64,
	.u16Hpw=4,
	.u16Vact=1280,
	.u16Vbb=18,
	.u16Vfb=16,
	.u16Vpw=2,
};

VO_USER_INTFSYNC_INFO_S MIPI_TX_5INCH_720x1280_60_USER_INTFSYNC_INFO = {
	.stUserIntfSyncAttr =
	{
		.stUserSyncPll	=
		{
			.u32Fbdiv=526,
			.u32Frac=0xAD6F54,
			.u32Refdiv=4,
			.u32Postdiv1=7,
			.u32Postdiv2=7,
		},
	},

	.u32DevDiv			= 1,
	.u32PreDiv			= 1,
    };

lcd_resoluton_t MIPI_TX_5INCH_720x1280_60_LCD_RESOLUTION = {
	.pu32W	= 720,
	.pu32H	= 1280,
	.pu32Frm= 60,

};


HI_VOID InitScreen_mipi_5inch_720x1280(HI_S32 s32fd)
{
	HI_S32     fd     = s32fd;
	HI_S32     s32Ret;
	cmd_info_t cmd_info = {0};

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x01FE;
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
	cmd_info.cmd_size  = 0x0024;
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
	cmd_info.cmd_size  = 0x5325;
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
	cmd_info.cmd_size  = 0x0026;
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
	cmd_info.cmd_size  = 0x0A27;
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
	cmd_info.cmd_size  = 0x0A29;
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
	cmd_info.cmd_size  = 0xE52B;
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
	cmd_info.cmd_size  = 0x5216;
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
	cmd_info.cmd_size  = 0x542F;
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
	cmd_info.cmd_size  = 0x5934;
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
	cmd_info.cmd_size  = 0x061A;
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
	cmd_info.cmd_size  = 0x5F46;
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
	cmd_info.cmd_size  = 0x7052;
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
	cmd_info.cmd_size  = 0x0053;
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
	cmd_info.cmd_size  = 0x7054;
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
	cmd_info.cmd_size  = 0x0055;
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
	cmd_info.cmd_size  = 0x115F;
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
	cmd_info.cmd_size  = 0x03FE;
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
	cmd_info.cmd_size  = 0x0500;
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
	cmd_info.cmd_size  = 0x1601;
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
	cmd_info.cmd_size  = 0x0B02;
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
	cmd_info.cmd_size  = 0x0F03;
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
	cmd_info.cmd_size  = 0x7D04;
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
	cmd_info.cmd_size  = 0x0005;
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
	cmd_info.cmd_size  = 0x5006;
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
	cmd_info.cmd_size  = 0x1608;
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
	cmd_info.cmd_size  = 0x0D09;
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
	cmd_info.cmd_size  = 0x110A;
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
	cmd_info.cmd_size  = 0x7D0B;
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
	cmd_info.cmd_size  = 0x000C;
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
	cmd_info.cmd_size  = 0x500D;
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
	cmd_info.cmd_size  = 0x070E;
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
	cmd_info.cmd_size  = 0x080F;
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
	cmd_info.cmd_size  = 0x0110;
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
	cmd_info.cmd_size  = 0x0211;
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
	cmd_info.cmd_size  = 0x0012;
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
	cmd_info.cmd_size  = 0x7D13;
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
	cmd_info.cmd_size  = 0x8515;
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
	cmd_info.cmd_size  = 0x0317;
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
	cmd_info.cmd_size  = 0x0418;
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
	cmd_info.cmd_size  = 0x0519;
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
	cmd_info.cmd_size  = 0x061A;
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
	cmd_info.cmd_size  = 0x7D1C;
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
	cmd_info.cmd_size  = 0x851E;
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
	cmd_info.cmd_size  = 0x081F;
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
	cmd_info.cmd_size  = 0x0020;
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
	cmd_info.cmd_size  = 0x0021;
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
	cmd_info.cmd_size  = 0x0022;
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
	cmd_info.cmd_size  = 0x0023;
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
	cmd_info.cmd_size  = 0x0024;
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
	cmd_info.cmd_size  = 0x0025;
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
	cmd_info.cmd_size  = 0x0026;
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
	cmd_info.cmd_size  = 0x0027;
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
	cmd_info.cmd_size  = 0x0028;
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
	cmd_info.cmd_size  = 0x0029;
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
	cmd_info.cmd_size  = 0x072A;
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
	cmd_info.cmd_size  = 0x082B;
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
	cmd_info.cmd_size  = 0x012D;
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
	cmd_info.cmd_size  = 0x022F;
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
	cmd_info.cmd_size  = 0x0030;
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
	cmd_info.cmd_size  = 0x4031;
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
	cmd_info.cmd_size  = 0x0532;
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
	cmd_info.cmd_size  = 0x0833;
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
	cmd_info.cmd_size  = 0x5434;
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
	cmd_info.cmd_size  = 0x7D35;
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
	cmd_info.cmd_size  = 0x0036;
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
	cmd_info.cmd_size  = 0x0337;
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
	cmd_info.cmd_size  = 0x0438;
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
	cmd_info.cmd_size  = 0x0539;
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
	cmd_info.cmd_size  = 0x063A;
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
	cmd_info.cmd_size  = 0x003B;
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
	cmd_info.cmd_size  = 0x403D;
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
	cmd_info.cmd_size  = 0x053F;
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
	cmd_info.cmd_size  = 0x0840;
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
	cmd_info.cmd_size  = 0x5441;
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
	cmd_info.cmd_size  = 0x7D42;
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
	cmd_info.cmd_size  = 0x0043;
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
	cmd_info.cmd_size  = 0x0044;
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
	cmd_info.cmd_size  = 0x0045;
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
	cmd_info.cmd_size  = 0x0046;
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
	cmd_info.cmd_size  = 0x0047;
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
	cmd_info.cmd_size  = 0x0048;
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
	cmd_info.cmd_size  = 0x0049;
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
	cmd_info.cmd_size  = 0x004A;
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
	cmd_info.cmd_size  = 0x004B;
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
	cmd_info.cmd_size  = 0x004C;
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
	cmd_info.cmd_size  = 0x004D;
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
	cmd_info.cmd_size  = 0x004E;
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
	cmd_info.cmd_size  = 0x004F;
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
	cmd_info.cmd_size  = 0x0050;
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
	cmd_info.cmd_size  = 0x0051;
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
	cmd_info.cmd_size  = 0x0053;
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
	cmd_info.cmd_size  = 0x0054;
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
	cmd_info.cmd_size  = 0x0055;
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
	cmd_info.cmd_size  = 0x0056;
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
	cmd_info.cmd_size  = 0x0058;
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
	cmd_info.cmd_size  = 0x0059;
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
	cmd_info.cmd_size  = 0x005A;
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
	cmd_info.cmd_size  = 0x005B;
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
	cmd_info.cmd_size  = 0x005C;
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
	cmd_info.cmd_size  = 0x005D;
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
	cmd_info.cmd_size  = 0x005E;
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
	cmd_info.cmd_size  = 0x005F;
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
	cmd_info.cmd_size  = 0x0060;
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
	cmd_info.cmd_size  = 0x0062;
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
	cmd_info.cmd_size  = 0x0064;
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
	cmd_info.cmd_size  = 0x0065;
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
	cmd_info.cmd_size  = 0x0066;
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
	cmd_info.cmd_size  = 0x0067;
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
	cmd_info.cmd_size  = 0x0068;
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
	cmd_info.cmd_size  = 0x0069;
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
	cmd_info.cmd_size  = 0x006A;
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
	cmd_info.cmd_size  = 0x006B;
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
	cmd_info.cmd_size  = 0x006C;
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
	cmd_info.cmd_size  = 0x006D;
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
	cmd_info.cmd_size  = 0x006E;
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
	cmd_info.cmd_size  = 0x006F;
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
	cmd_info.cmd_size  = 0x0070;
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
	cmd_info.cmd_size  = 0x0071;
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
	cmd_info.cmd_size  = 0x2072;
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
	cmd_info.cmd_size  = 0x0073;
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
	cmd_info.cmd_size  = 0x0874;
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
	cmd_info.cmd_size  = 0x0875;
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
	cmd_info.cmd_size  = 0x0876;
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
	cmd_info.cmd_size  = 0x0877;
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
	cmd_info.cmd_size  = 0x0878;
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
	cmd_info.cmd_size  = 0x0879;
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
	cmd_info.cmd_size  = 0x007A;
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
	cmd_info.cmd_size  = 0x007B;
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
	cmd_info.cmd_size  = 0x007C;
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
	cmd_info.cmd_size  = 0x007D;
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
	cmd_info.cmd_size  = 0xBF7E;
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
	cmd_info.cmd_size  = 0x3F7F;
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
	cmd_info.cmd_size  = 0x3F80;
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
	cmd_info.cmd_size  = 0x3F81;
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
	cmd_info.cmd_size  = 0x3F82;
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
	cmd_info.cmd_size  = 0x3F83;
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
	cmd_info.cmd_size  = 0x3F84;
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
	cmd_info.cmd_size  = 0x0285;
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
	cmd_info.cmd_size  = 0x0686;
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
	cmd_info.cmd_size  = 0x3F87;
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
	cmd_info.cmd_size  = 0x1488;
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
	cmd_info.cmd_size  = 0x1089;
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
	cmd_info.cmd_size  = 0x168A;
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
	cmd_info.cmd_size  = 0x128B;
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
	cmd_info.cmd_size  = 0x088C;
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
	cmd_info.cmd_size  = 0x0C8D;
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
	cmd_info.cmd_size  = 0x0A8E;
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
	cmd_info.cmd_size  = 0x0E8F;
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
	cmd_info.cmd_size  = 0x0090;
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
	cmd_info.cmd_size  = 0x0491;
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
	cmd_info.cmd_size  = 0x3F92;
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
	cmd_info.cmd_size  = 0x3F93;
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
	cmd_info.cmd_size  = 0x3F94;
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
	cmd_info.cmd_size  = 0x3F95;
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
	cmd_info.cmd_size  = 0x0596;
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
	cmd_info.cmd_size  = 0x0197;
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
	cmd_info.cmd_size  = 0x0F98;
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
	cmd_info.cmd_size  = 0x0B99;
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
	cmd_info.cmd_size  = 0x0D9A;
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
	cmd_info.cmd_size  = 0x099B;
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
	cmd_info.cmd_size  = 0x139C;
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
	cmd_info.cmd_size  = 0x179D;
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
	cmd_info.cmd_size  = 0x119E;
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
	cmd_info.cmd_size  = 0x159F;
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
	cmd_info.cmd_size  = 0x3FA0;
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
	cmd_info.cmd_size  = 0x07A2;
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
	cmd_info.cmd_size  = 0x03A3;
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
	cmd_info.cmd_size  = 0x3FA4;
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
	cmd_info.cmd_size  = 0x3FA5;
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
	cmd_info.cmd_size  = 0x3FA6;
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
	cmd_info.cmd_size  = 0x3FA7;
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
	cmd_info.cmd_size  = 0x3FA9;
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
	cmd_info.cmd_size  = 0x3FAA;
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
	cmd_info.cmd_size  = 0x3FAB;
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
	cmd_info.cmd_size  = 0x3FAC;
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
	cmd_info.cmd_size  = 0x3FAD;
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
	cmd_info.cmd_size  = 0x3FAE;
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
	cmd_info.cmd_size  = 0x3FAF;
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
	cmd_info.cmd_size  = 0x3FB0;
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
	cmd_info.cmd_size  = 0x3FB1;
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
	cmd_info.cmd_size  = 0x3FB2;
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
	cmd_info.cmd_size  = 0x05B3;
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
	cmd_info.cmd_size  = 0x01B4;
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
	cmd_info.cmd_size  = 0x3FB5;
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
	cmd_info.cmd_size  = 0x17B6;
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
	cmd_info.cmd_size  = 0x13B7;
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
	cmd_info.cmd_size  = 0x15B8;
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
	cmd_info.cmd_size  = 0x11B9;
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
	cmd_info.cmd_size  = 0x0FBA;
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
	cmd_info.cmd_size  = 0x0BBB;
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
	cmd_info.cmd_size  = 0x0DBC;
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
	cmd_info.cmd_size  = 0x09BD;
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
	cmd_info.cmd_size  = 0x07BE;
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
	cmd_info.cmd_size  = 0x03BF;
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
	cmd_info.cmd_size  = 0x3FC0;
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
	cmd_info.cmd_size  = 0x3FC1;
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
	cmd_info.cmd_size  = 0x3FC2;
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
	cmd_info.cmd_size  = 0x3FC3;
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
	cmd_info.cmd_size  = 0x02C4;
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
	cmd_info.cmd_size  = 0x06C5;
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
	cmd_info.cmd_size  = 0x08C6;
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
	cmd_info.cmd_size  = 0x0CC7;
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
	cmd_info.cmd_size  = 0x0AC8;
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
	cmd_info.cmd_size  = 0x0EC9;
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
	cmd_info.cmd_size  = 0x10CA;
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
	cmd_info.cmd_size  = 0x14CB;
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
	cmd_info.cmd_size  = 0x12CC;
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
	cmd_info.cmd_size  = 0x16CD;
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
	cmd_info.cmd_size  = 0x3FCE;
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

	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x04D0;
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
	cmd_info.cmd_size  = 0x3FD1;
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
	cmd_info.cmd_size  = 0x3FD2;
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
	cmd_info.cmd_size  = 0x3FD3;
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
	cmd_info.cmd_size  = 0x3FD4;
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
	cmd_info.cmd_size  = 0x3FD5;
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
	cmd_info.cmd_size  = 0x3FD6;
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
	cmd_info.cmd_size  = 0x3FD7;
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
	cmd_info.cmd_size  = 0x02DC;
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
	cmd_info.cmd_size  = 0x12DE;
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
	cmd_info.cmd_size  = 0x0EFE;
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
	cmd_info.cmd_size  = 0x7501;
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
	cmd_info.cmd_size  = 0x04FE;
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
	cmd_info.cmd_size  = 0x0060;
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
	cmd_info.cmd_size  = 0x0861;
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
	cmd_info.cmd_size  = 0x0E62;
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
	cmd_info.cmd_size  = 0x0D63;
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
	cmd_info.cmd_size  = 0x0564;
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
	cmd_info.cmd_size  = 0x1065;
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
	cmd_info.cmd_size  = 0x0E66;
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
	cmd_info.cmd_size  = 0x0A67;
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
	cmd_info.cmd_size  = 0x1668;
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
	cmd_info.cmd_size  = 0x0C69;
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
	cmd_info.cmd_size  = 0x106A;
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
	cmd_info.cmd_size  = 0x076B;
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
	cmd_info.cmd_size  = 0x0E6C;
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
	cmd_info.cmd_size  = 0x136D;
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
	cmd_info.cmd_size  = 0x0C6E;
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
	cmd_info.cmd_size  = 0x006F;
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
	cmd_info.cmd_size  = 0x0070;
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
	cmd_info.cmd_size  = 0x0871;
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
	cmd_info.cmd_size  = 0x0E72;
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
	cmd_info.cmd_size  = 0x0D73;
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
	cmd_info.cmd_size  = 0x0574;
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
	cmd_info.cmd_size  = 0x1075;
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
	cmd_info.cmd_size  = 0x0E76;
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
	cmd_info.cmd_size  = 0x0A77;
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
	cmd_info.cmd_size  = 0x1678;
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
	cmd_info.cmd_size  = 0x0C79;
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
	cmd_info.cmd_size  = 0x107A;
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
	cmd_info.cmd_size  = 0x077B;
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
	cmd_info.cmd_size  = 0x0E7C;
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
	cmd_info.cmd_size  = 0x137D;
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
	cmd_info.cmd_size  = 0x0C7E;
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
	cmd_info.cmd_size  = 0x007F;
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
	cmd_info.cmd_size  = 0x00FE;
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
	usleep(200000);

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
	usleep(1000);

}

#endif /* End of #ifndef __RP_LCD_MIPI_5INCH_720x1280_H__ */
