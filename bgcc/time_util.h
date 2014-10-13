/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_TIME_UTIL_H_
#define _BGCC2_TIME_UTIL_H_

#include <string>
#include "bgcc_common.h"

namespace bgcc {

    /**
     * @brief ʱ��ʵ�ù�����
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012��05��30�� 21ʱ11��15��
     */

#ifdef _WIN32
    struct timezone 
    {
        int  tz_minuteswest; /* minutes W of Greenwich */
        int  tz_dsttime;     /* type of dst correction */
    };

	//int gettimeofday(struct ::timeval *tv, struct timezone *tz);
#endif

    class TimeUtil {
    public:
        /**
         * @brief get_timestamp_s ��ȡʱ������룩
         *
         * @return ���ش�Epoch������������
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��05��30�� 21ʱ11��25��
         */
        static uint64_t get_timestamp_s();

        /**
         * @brief get_timestamp_ms ��ȡʱ��������룩
         *
         * @return ���ش�Epoch��������΢����
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��05��30�� 21ʱ12��14��
         */
        static uint64_t get_timestamp_ms();
        
        /**
         * @brief ��ȡ΢�뼶ʱ���
         *
         * @return  uint64_t 
         * @retval   
         * @see 
         * @note 
         * @author zhangyue
         * @date 2012/12/24 16:38:45
        **/
        static uint64_t get_timestamp_us();

        /**
         * @brief safe_sleep_s ֧���жϵ�sleep���룩
         *
         * @param second ˯�ߵ�����
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��05��30�� 21ʱ12��42��
         */
        static void safe_sleep_s(uint32_t second);

        /**
         * @brief safe_sleep_ms ֧���жϵ�sleep�����룩
         *
         * @param millisecond ˯�ߵĺ�����
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��05��30�� 21ʱ13��05��
         */
        static void safe_sleep_ms(uint32_t millisecond);

        /**
         * @brief format_datetime_str ��ʱ�����ʽ��
         *
         * @param millisecond ��Epoch�������ĺ�����
         *
         * @return ʱ����ַ���
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��05��30�� 21ʱ13��53��
         */
        static std::string format_datetime_str(uint64_t millisecond);

#ifndef _WIN32
//        struct ::timespec;
        /**
         * @brief get_abs_timespec ��ȡ�ӵ�ǰʱ��� milliSeconds �����ľ���ʱ��
         *
         * @param ts ��ž���ʱ��
         * @param millisecond ��ǰ��ĺ�����
         *
         * @return �ɹ�����0
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��05��30�� 21ʱ14��47��
         */
        static int32_t get_abs_timespec(struct timespec* ts, int32_t millisecond);
#endif

        /**
         * @brief strftimeval ��struct timevalת��Ϊ�ַ�����ʽ����ʽΪ"YYYY-MM-DD HH:mm::SS.xxx"
         *
         * @param buffer [out] ���ջ��������Ƽ���������СΪ24���ֽڡ�
         * @param buflen ��������С
         * @param tv ��ת����struct timevalָ��
         *
         * @return ����д�뻺�������ַ�����������\0�������򷵻�-1
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��05��22�� 16ʱ50��14��
         */
        static int32_t strftimeval(char* buffer, int32_t buflen, const struct timeval* tv);

        /**
         * @brief get_date ��ȡ���ڴ� "YYYYMMDD"
         *
         * @return ���ڴ�
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��12�� 17ʱ23��19��
         */
        static std::string get_date();

        /**
         * @brief get_time ��ȡʱ�䴮 "HHmmSS.xxx"
         *
         * @return 
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012��06��12�� 17ʱ23��56��
         */
        static std::string get_time();

        /**
         * @brief ��ȡ��ǰ���ڼ�
         *
         * @return  int32_t 
         * @retval   
         * @see 
         * @note 
         * @author zhangyue
         * @date 2012/12/24 16:20:08
        **/
        static int32_t get_day();

        /**
         * @brief ��ȡָ�����ڵ����ڼ�
         *
         * @param [in/out] time   : time_t
         * @return  int32_t 
         * @retval   
         * @see 
         * @note 
         * @author zhangyue
         * @date 2012/12/24 16:20:11
        **/
        static int32_t get_day( time_t time );

        /**
         * @brief ��ʽ����ǰʱ�䣬Ĭ�ϸ�ʽΪ��%Y%m%d-%H:%M:%S��
         *
         * @param [in/out] fmt   : const char*
         * @return  std::string 
         * @retval   
         * @see 
         * @note 
         * @author zhangyue
         * @date 2012/12/24 16:20:18
        **/
        static std::string format_time(const char * fmt = NULL);

        /**
         * @brief ��ʽ��ָ��ʱ�䣬Ĭ�ϸ�ʽΪ��%Y%m%d-%H:%M:%S��
         *
         * @param [in/out] time   : time_t
         * @param [in/out] fmt   : const char*
         * @return  std::string 
         * @retval   
         * @see 
         * @note 
         * @author zhangyue
         * @date 2012/12/24 16:20:28
        **/
        static std::string format_time(time_t time, const char * fmt = NULL);

        /**
         * @brief ��ʽ��ָ��ʱ�䣬Ĭ�ϸ�ʽΪ��%Y%m%d-%H:%M:%S��
         *
         * @param [in/out] time   : const struct timeval*
         * @param [in/out] fmt   : const char*
         * @return  std::string 
         * @retval   
         * @see 
         * @note 
         * @author zhangyue
         * @date 2012/12/24 16:20:31
        **/
        static std::string format_time(const struct timeval* tv, const char * fmt = NULL);
		 
		/**
         * @brief ��ʽ��ָ��ʱ�䣬Ĭ�ϸ�ʽΪ��%Y%m%d-%H:%M:%S��
         *
         * @param [in/out] time   : const struct timeval*
         * @param [in/out] fmt   : const char*
         * @return  std::string 
         * @retval   
         * @see 
         * @note 
         * @author zhangyue
         * @date 2012/12/24 16:20:31
        **/
		static int32_t gettimeofday(struct ::timeval *tv, struct timezone *tz);

#ifdef _WIN32
    private:
		/*__declspec(thread)*/ static FILETIME _ft;             /**< ��׼ʱ��    */
        /*__declspec(thread)*/ static LARGE_INTEGER _pform;     /**< ��׼ʱ���  */
#endif
    }; // end of class TimeUtil
}

#endif // _BGCC2_TIME_UTIL_H_
