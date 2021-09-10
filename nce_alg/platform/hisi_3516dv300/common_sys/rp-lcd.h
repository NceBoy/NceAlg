HI_S32     fd     = s32fd;
    	HI_S32     s32Ret;
    	HI_U8      cmd[30];
    	cmd_info_t cmd_info = {0};
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x01FE; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0xC024; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x532F; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x5A34; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0A12; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x4F46; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0xA052; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0xA054; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	cmd_info.cmd_size  = 0x0833; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	cmd_info.cmd_size  = 0x0539; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	cmd_info.cmd_size  = 0x004D; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	cmd_info.cmd_size  = 0x005B; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	cmd_info.cmd_size  = 0x0061; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	cmd_info.cmd_size  = 0x0067; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	cmd_info.cmd_size  = 0x006D; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
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
	cmd_info.cmd_size  = 0x2072; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	cmd_info.cmd_size  = 0x007D; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x027F; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0680; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x1481; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x1082; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x1683; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x1284; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0885; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x3F86; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x3F88; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x3F89; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x3F8A; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0C8B; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0A8C; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0E8D; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x3F8E; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x3F8F; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x3F98; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x3F99; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0F9A; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0B9B; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0D9C; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x3F9D; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x3F9E; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x3F9F; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x3FA2; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x09A3; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x13A4; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x17A5; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x11A6; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x15A7; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x07A9; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x03AA; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x05AD; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x01AE; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x17AF; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x13B0; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x15B1; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x11B2; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0FB3; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x3FB4; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x3FB6; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x3FB7; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x3FB8; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0BB9; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0DBA; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x09BB; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x3FBC; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x3FBD; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x3FC6; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x3FC7; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0ACA; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x3FCB; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x3FCC; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x3FCD; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x3FCF; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0ED0; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x10D1; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x14D2; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x12D3; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x16D4; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x00D5; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x04D6; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0154; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
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
	cmd_info.cmd_size  = 0x0C61; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x1262; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0E63; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0664; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x1265; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0B67; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x1568; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0B69; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0F6C; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x126D; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
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
	cmd_info.cmd_size  = 0x0C71; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x1272; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0E73; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0674; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x1275; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0B77; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x1578; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0B79; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0F7C; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x127D; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
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
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT("MIPI_TX SET CMD failed\n");
	    close(fd);
	    return;
	}
	usleep(1000);
		
	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0xAD58; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
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

