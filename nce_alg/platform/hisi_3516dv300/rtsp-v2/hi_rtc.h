/*
 * include/hi_rtc.h for Linux .
 *
 * This file defines hi_rtc micro-definitions for driver developer.
 *
 * History:
 *      10-April-2006 create this file
 */

#ifndef __HI_RTC__
#define __HI_RTC__

typedef struct {
        unsigned int  year;
        unsigned int  month;
        unsigned int  date;
        unsigned int  hour;
        unsigned int  minute;
        unsigned int  second;
        unsigned int  weekday;
} rtc_time_t;

typedef	struct {
	unsigned char reg_index;
	unsigned char val;
} reg_data_t;

typedef struct {
	unsigned int freq_l;
} rtc_freq_t;

#define HI_RTC_AIE_ON		_IO('p', 0x01)
#define HI_RTC_AIE_OFF		_IO('p', 0x02)

#define HI_RTC_GET_FREQ		_IOR('P', 0x05, rtc_freq_t)
#define HI_RTC_SET_FREQ		_IOW('p', 0x06, rtc_freq_t)

#define HI_RTC_ALM_SET		_IOW('p', 0x07,  rtc_time_t)
#define HI_RTC_ALM_READ		_IOR('p', 0x08,  rtc_time_t)
#define HI_RTC_RD_TIME		_IOR('p', 0x09,  rtc_time_t)
#define HI_RTC_SET_TIME		_IOW('p', 0x0a,  rtc_time_t)
#define HI_RTC_RESET		_IO('p', 0x0b)
#define HI_RTC_REG_SET		_IOW('p', 0x0c,  reg_data_t)
#define HI_RTC_REG_READ		_IOWR('p', 0x0d,  reg_data_t)

#endif

