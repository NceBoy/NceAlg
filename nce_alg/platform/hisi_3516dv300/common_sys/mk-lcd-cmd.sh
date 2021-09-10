#!/bin/bash
# init format
# "addr value1 value2 ..."
init=(
"FE 01"
"24 C0"
"25 53"
"26 00"
"2B E5"
"27 0A"
"29 0A"
"16 52"
"2F 53"
"34 5A"
"1B 00"
"12 0A"
"1A 06"
"46 4F"
"52 A0"
"53 00"
"54 A0"
"55 00"
"FE 03"
"00 05"
"01 16"
"02 0B"
"03 0F"
"04 7D"
"05 00"
"06 50"
"07 05"
"08 16"
"09 0D"
"0A 11"
"0B 7D"
"0C 00"
"0D 50"
"0E 07"
"0F 08"
"10 01"
"11 02"
"12 00"
"13 7D"
"14 00"
"15 85"
"16 08"
"17 03"
"18 04"
"19 05"
"1A 06"
"1B 00"
"1C 7D"
"1D 00"
"1E 85"
"1F 08"
"20 00"
"21 00"
"22 00"
"23 00"
"24 00"
"25 00"
"26 00"
"27 00"
"28 00"
"29 00"
"2A 07"
"2B 08"
"2D 01"
"2F 02"
"30 00"
"31 40"
"32 05"
"33 08"
"34 54"
"35 7D"
"36 00"
"37 03"
"38 04"
"39 05"
"3A 06"
"3B 00"
"3D 40"
"3F 05"
"40 08"
"41 54"
"42 7D"
"43 00"
"44 00"
"45 00"
"46 00"
"47 00"
"48 00"
"49 00"
"4A 00"
"4B 00"
"4C 00"
"4D 00"
"4E 00"
"4F 00"
"50 00"
"51 00"
"52 00"
"53 00"
"54 00"
"55 00"
"56 00"
"58 00"
"59 00"
"5A 00"
"5B 00"
"5C 00"
"5D 00"
"5E 00"
"5F 00"
"60 00"
"61 00"
"62 00"
"63 00"
"64 00"
"65 00"
"66 00"
"67 00"
"68 00"
"69 00"
"6A 00"
"6B 00"
"6C 00"
"6D 00"
"6E 00"
"6F 00"
"70 00"
"71 00"
"72 20"
"73 00"
"74 08"
"75 08"
"76 08"
"77 08"
"78 08"
"79 08"
"7A 00"
"7B 00"
"7C 00"
"7D 00"
"7E BF"
"7F 02"
"80 06"
"81 14"
"82 10"
"83 16"
"84 12"
"85 08"
"86 3F"
"87 3F"
"88 3F"
"89 3F"
"8A 3F"
"8B 0C"
"8C 0A"
"8D 0E"
"8E 3F"
"8F 3F"
"90 00"
"91 04"
"92 3F"
"93 3F"
"94 3F"
"95 3F"
"96 05"
"97 01"
"98 3F"
"99 3F"
"9A 0F"
"9B 0B"
"9C 0D"
"9D 3F"
"9E 3F"
"9F 3F"
"A0 3F"
"A2 3F"
"A3 09"
"A4 13"
"A5 17"
"A6 11"
"A7 15"
"A9 07"
"AA 03"
"AB 3F"
"AC 3F"
"AD 05"
"AE 01"
"AF 17"
"B0 13"
"B1 15"
"B2 11"
"B3 0F"
"B4 3F"
"B5 3F"
"B6 3F"
"B7 3F"
"B8 3F"
"B9 0B"
"BA 0D"
"BB 09"
"BC 3F"
"BD 3F"
"BE 07"
"BF 03"
"C0 3F"
"C1 3F"
"C2 3F"
"C3 3F"
"C4 02"
"C5 06"
"C6 3F"
"C7 3F"
"C8 08"
"C9 0C"
"CA 0A"
"CB 3F"
"CC 3F"
"CD 3F"
"CE 3F"
"CF 3F"
"D0 0E"
"D1 10"
"D2 14"
"D3 12"
"D4 16"
"D5 00"
"D6 04"
"D7 3F"
"DC 02"
"DE 12"
"FE 0E"
"01 75"
"54 01"
"FE 04"
"60 00"
"61 0C"
"62 12"
"63 0E"
"64 06"
"65 12"
"66 0E"
"67 0B"
"68 15"
"69 0B"
"6A 10"
"6B 07"
"6C 0F"
"6D 12"
"6E 0C"
"6F 00"
"70 00"
"71 0C"
"72 12"
"73 0E"
"74 06"
"75 12"
"76 0E"
"77 0B"
"78 15"
"79 0B"
"7A 10"
"7B 07"
"7C 0F"
"7D 12"
"7E 0C"
"7F 00"
"FE 00"
"58 AD"
)

echo   "HI_S32     fd     = s32fd;
    	HI_S32     s32Ret;
    	HI_U8      cmd[30];
    	cmd_info_t cmd_info = {0};" > rp-lcd.h

n_init=${#init[*]}							#获取一维init的数组长度
for ((i=0;i<$n_init;i++));
do
	inner_init=(${init[$i]})				#将一维init字符串赋值到数组
	n_inner_init=${#inner_init[*]}			#获取二维init的数组长度

	if [ $n_inner_init -gt 2 ]; then
		#echo "inner size : $n_inner_init"

		for ((j=0;j<$n_inner_init;j++));
  		do
			#echo ${inner_init[$j]}					# 显示测试
			echo "	cmd[$j] = 0x${inner_init[$j]};" >> rp-lcd.h
  		done
		#n_inner_init_10to16=$(echo "obase=16;${n_inner_init}"|bc)
		#n_inner_init_10to16=$(printf "%x" $n_inner_init)
		#n_inner_init_10to16=$(echo "obase=16;15"|bc)
		#echo "inner size : $n_inner_init"
		#echo "$n_inner_init_10to16"
		n_inner_init_10to16=$(printf "%x" $n_inner_init)
		echo "	cmd_info.devno     = 0;
	cmd_info.cmd_size  = ${n_inner_init_10to16}; 
	cmd_info.data_type = 0x29;
	cmd_info.cmd       = cmd;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT(\"MIPI_TX SET CMD failed\\n\");
	    close(fd);
	    return;
	}
	usleep(1000);
		" >> rp-lcd.h
	elif [ $n_inner_init -eq 2 ]; then
		#echo "inner size : $n_inner_init"
		echo "	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x${inner_init[1]}${inner_init[0]}; 
	cmd_info.data_type = 0x23;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT(\"MIPI_TX SET CMD failed\\n\");
	    close(fd);
	    return;
	}
	usleep(1000);
		" >> rp-lcd.h
	else
		echo "error size : $n_inner_init"
	fi
done

echo "	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0011; 
	cmd_info.data_type = 0x05;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT(\"MIPI_TX SET CMD failed\\n\");
	    close(fd);
	    return;
	}
	usleep(200000);
" >> rp-lcd.h
		
echo "	cmd_info.devno     = 0;
	cmd_info.cmd_size  = 0x0029; 
	cmd_info.data_type = 0x05;
	cmd_info.cmd       = NULL;
	s32Ret = ioctl(fd, HI_MIPI_TX_SET_CMD, &cmd_info);
	if (HI_SUCCESS != s32Ret)
	{
	    SAMPLE_PRT(\"MIPI_TX SET CMD failed\\n\");
	    close(fd);
	    return;
	}
	usleep(1000);
" >> rp-lcd.h
