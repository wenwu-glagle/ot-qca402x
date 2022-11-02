/*
 *  Copyright (c) 2022, The OpenThread Authors.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  3. Neither the name of the copyright holder nor the
 *     names of its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file
 *   This file includes all compile-time configuration constants used by
 *   QCA4024 applications for OpenThread.
 */

#ifndef OPENTHREAD_CORE_QCA4024_CONFIG_H_
#define OPENTHREAD_CORE_QCA4024_CONFIG_H_


/**
 * @def OPENTHREAD_CONFIG_CLI_MAX_LINE_LENGTH
 *
 * The maximum size of the CLI line in bytes including the null terminator.
 *
 */
#ifndef OPENTHREAD_CONFIG_CLI_MAX_LINE_LENGTH
#if OPENTHREAD_CONFIG_REFERENCE_DEVICE_ENABLE
#define OPENTHREAD_CONFIG_CLI_MAX_LINE_LENGTH 640 // Default for Test Harness certification
#else
#define OPENTHREAD_CONFIG_CLI_MAX_LINE_LENGTH 384 // Stack default
#endif
#endif

/*
 * @def OPENTHREAD_CONFIG_RADIO_915MHZ_OQPSK_SUPPORT
 *
 * Define to 1 if you want to enable physical layer to support OQPSK modulation in 915MHz band.
 * (currently not supported).
 *
 */
#define OPENTHREAD_CONFIG_RADIO_915MHZ_OQPSK_SUPPORT 0


/*
 * @def OPENTHREAD_CONFIG_RADIO_2P4GHZ_OQPSK_SUPPORT
 *
 * Define to 1 if you want to enable physical layer to support OQPSK modulation in 2.4GHz band.
 *
 */
#define OPENTHREAD_CONFIG_RADIO_2P4GHZ_OQPSK_SUPPORT 1


/*
 * @def OPENTHREAD_CONFIG_PLATFORM_RADIO_PROPRIETARY_SUPPORT
 *
 * Define to 1 if you want to enable physical layer to support proprietary radio configurations.
 *
 * This configuration option is used by the Sub-GHz feature to specify proprietary radio parameters,
 * currently not defined by the Thread spec.
 */
#define OPENTHREAD_CONFIG_PLATFORM_RADIO_PROPRIETARY_SUPPORT 0


/**
 * @def OPENTHREAD_CONFIG_PLATFORM_INFO
 *
 * The platform-specific string to insert into the OpenThread version string.
 *
 */
#ifndef OPENTHREAD_CONFIG_PLATFORM_INFO
#define OPENTHREAD_CONFIG_PLATFORM_INFO "QCA4024"
#endif

/**
 * @def OPENTHREAD_CONFIG_MAC_CSL_AUTO_SYNC_ENABLE
 *
 * This setting configures CSL auto synchronization based on data poll mechanism in Thread 1.2.
 *
 */
#ifndef OPENTHREAD_CONFIG_MAC_CSL_AUTO_SYNC_ENABLE
#if OPENTHREAD_CONFIG_REFERENCE_DEVICE_ENABLE
#define OPENTHREAD_CONFIG_MAC_CSL_AUTO_SYNC_ENABLE 0
#else
#define OPENTHREAD_CONFIG_MAC_CSL_AUTO_SYNC_ENABLE 1
#endif
#endif

/**
 * @def OPENTHREAD_CONFIG_MAC_CSL_REQUEST_AHEAD_US
 *
 * Define how many microseconds ahead should MAC deliver CSL frame to SubMac.
 *
 */
#ifndef OPENTHREAD_CONFIG_MAC_CSL_REQUEST_AHEAD_US
#define OPENTHREAD_CONFIG_MAC_CSL_REQUEST_AHEAD_US 2000
#endif

/**
 * @def OPENTHREAD_CONFIG_CSL_RECEIVE_TIME_AHEAD
 *
 * Reception scheduling and ramp up time needed for the CSL receiver to be ready, in units of microseconds.
 *
 */
#ifndef OPENTHREAD_CONFIG_CSL_RECEIVE_TIME_AHEAD
#define OPENTHREAD_CONFIG_CSL_RECEIVE_TIME_AHEAD 600
#endif

/**
 * @def OPENTHREAD_CONFIG_CSL_MIN_RECEIVE_ON
 *
 * The minimum CSL receive window (in microseconds) required to receive an IEEE 802.15.4 frame.
 * - Maximum frame size with preamble: 6*2+127*2 symbols
 * - AIFS: 12 symbols
 * - Maximum ACK size with preamble: 6*2+33*2 symbols
 * - Additional frame window: 6*2+127*2 symbols
 */
#ifndef OPENTHREAD_CONFIG_CSL_MIN_RECEIVE_ON
#define OPENTHREAD_CONFIG_CSL_MIN_RECEIVE_ON 622 * 16
#endif

/*
 * @def OPENTHREAD_CONFIG_MAC_SOFTWARE_RETRANSMIT_ENABLE
 *
 * Define to 1 if you want to enable software retransmission logic.
 *
 */
#ifndef OPENTHREAD_CONFIG_MAC_SOFTWARE_RETRANSMIT_ENABLE
#define OPENTHREAD_CONFIG_MAC_SOFTWARE_RETRANSMIT_ENABLE 0
#endif

/**
 * @def OPENTHREAD_CONFIG_MAC_SOFTWARE_CSMA_BACKOFF_ENABLE
 *
 * Define to 1 if you want to enable software CSMA-CA backoff logic.
 * RCPs only.
 *
 */
#ifndef OPENTHREAD_CONFIG_MAC_SOFTWARE_CSMA_BACKOFF_ENABLE
#define OPENTHREAD_CONFIG_MAC_SOFTWARE_CSMA_BACKOFF_ENABLE 0
#endif

/**
 * @def OPENTHREAD_CONFIG_MAC_SOFTWARE_TX_SECURITY_ENABLE
 *
 * Define to 1 if you want to enable software transmission security logic.
 * RCPs only.
 *
 */
#ifndef OPENTHREAD_CONFIG_MAC_SOFTWARE_TX_SECURITY_ENABLE
#define OPENTHREAD_CONFIG_MAC_SOFTWARE_TX_SECURITY_ENABLE 1
#endif

/**
 * @def OPENTHREAD_CONFIG_MAC_SOFTWARE_TX_TIMING_ENABLE
 *
 * Define to 1 to enable software transmission target time logic.
 * RCPs only.
 *
 */
#ifndef OPENTHREAD_CONFIG_MAC_SOFTWARE_TX_TIMING_ENABLE
#define OPENTHREAD_CONFIG_MAC_SOFTWARE_TX_TIMING_ENABLE 1
#endif

/**
 * @def OPENTHREAD_CONFIG_MAC_SOFTWARE_RX_TIMING_ENABLE
 *
 * Define to 1 to enable software reception target time logic.
 * RCPs only.
 *
 */
#ifndef OPENTHREAD_CONFIG_MAC_SOFTWARE_RX_TIMING_ENABLE
#define OPENTHREAD_CONFIG_MAC_SOFTWARE_RX_TIMING_ENABLE 0
#endif

/**
 * @def OPENTHREAD_CONFIG_MAC_SOFTWARE_ENERGY_SCAN_ENABLE
 *
 * Define to 1 if you want to enable software energy scanning logic.
 * RCPs only.
 *
 */
#ifndef OPENTHREAD_CONFIG_MAC_SOFTWARE_ENERGY_SCAN_ENABLE
#define OPENTHREAD_CONFIG_MAC_SOFTWARE_ENERGY_SCAN_ENABLE 0
#endif

/**
 * @def OPENTHREAD_CONFIG_PLATFORM_USEC_TIMER_ENABLE
 *
 * Define to 1 if you want to support microsecond timer in platform.
 *
 */
#ifndef OPENTHREAD_CONFIG_PLATFORM_USEC_TIMER_ENABLE
#define OPENTHREAD_CONFIG_PLATFORM_USEC_TIMER_ENABLE 0
#endif

/**
 * @def OPENTHREAD_CONFIG_PLATFORM_FLASH_API_ENABLE
 *
 * Define to 1 to enable otPlatFlash* APIs to support non-volatile storage.
 *
 * When defined to 1, the platform MUST implement the otPlatFlash* APIs instead of the otPlatSettings* APIs.
 *
 */
#ifndef OPENTHREAD_CONFIG_PLATFORM_FLASH_API_ENABLE
#define OPENTHREAD_CONFIG_PLATFORM_FLASH_API_ENABLE 0
#endif

/**
 * @def OPENTHREAD_CONFIG_TCP_ENABLE
 *
 * Define as 1 to enable TCPlp (low power TCP defined in Thread spec).
 *
 */
#ifndef OPENTHREAD_CONFIG_TCP_ENABLE
#define OPENTHREAD_CONFIG_TCP_ENABLE 0
#endif

/**
 * @def OPENTHREAD_CONFIG_NCP_HDLC_ENABLE
 *
 * Define to 1 to enable the NCP HDLC interface.
 *
 */
#ifndef OPENTHREAD_CONFIG_NCP_HDLC_ENABLE
#define OPENTHREAD_CONFIG_NCP_HDLC_ENABLE 1
#endif

/**
 * @def OPENTHREAD_CONFIG_NCP_CPC_ENABLE
 *
 * Define to 1 to enable NCP CPC support.
 *
 */
#ifndef OPENTHREAD_CONFIG_NCP_CPC_ENABLE
#define OPENTHREAD_CONFIG_NCP_CPC_ENABLE 0
#endif

/**
 * @def OPENTHREAD_CONFIG_NCP_SPI_ENABLE
 *
 * Define to 1 to enable NCP SPI support.
 *
 */
#ifndef OPENTHREAD_CONFIG_NCP_SPI_ENABLE
#define OPENTHREAD_CONFIG_NCP_SPI_ENABLE 0
#endif


/**
 * @def OPENTHREAD_CONFIG_HEAP_EXTERNAL_ENABLE
 *
 * Enable the external heap.
 *
 */
#define OPENTHREAD_CONFIG_HEAP_EXTERNAL_ENABLE 1



/**
 * @def OPENTHREAD_CONFIG_COMMISSIONER_ENABLE
 *
 * Define to 1 to enable Commissioner support.
 *
 */
#ifndef OPENTHREAD_CONFIG_COMMISSIONER_ENABLE
#define OPENTHREAD_CONFIG_COMMISSIONER_ENABLE 1
#endif


/**
 * @def OPENTHREAD_CONFIG_JOINER_ENABLE
 *
 * Define to 1 to enable Joiner support.
 *
 */
#ifndef OPENTHREAD_CONFIG_JOINER_ENABLE
#define OPENTHREAD_CONFIG_JOINER_ENABLE 1
#endif


/**
 * @def OPENTHREAD_CONFIG_DHCP6_CLIENT_ENABLE
 *
 * Define to 1 to enable DHCPv6 Client support.
 *
 */
#ifndef OPENTHREAD_CONFIG_DHCP6_CLIENT_ENABLE
#define OPENTHREAD_CONFIG_DHCP6_CLIENT_ENABLE 1
#endif

/**
 * @def OPENTHREAD_CONFIG_DHCP6_SERVER_ENABLE
 *
 * Define to 1 to enable DHCPv6 Server support.
 *
 */
#ifndef OPENTHREAD_CONFIG_DHCP6_SERVER_ENABLE
#define OPENTHREAD_CONFIG_DHCP6_SERVER_ENABLE 1
#endif


/**
 * @def OPENTHREAD_CONFIG_DNSSD_SERVER_ENABLE
 *
 * Define to 1 to enable DNS-SD Server support.
 *
 */
#ifndef OPENTHREAD_CONFIG_DNSSD_SERVER_ENABLE
#define OPENTHREAD_CONFIG_DNSSD_SERVER_ENABLE 1
#endif


/**
 * @def OPENTHREAD_CONFIG_ECDSA_ENABLE
 *
 * Define to 1 to enable ECDSA support.
 *
 */
#define OPENTHREAD_CONFIG_ECDSA_ENABLE 1


/**
 * @def OPENTHREAD_CONFIG_BORDER_ROUTER_ENABLE
 *
 * Define to 1 to enable Border Router support.
 *
 */
#ifndef OPENTHREAD_CONFIG_BORDER_ROUTER_ENABLE
#define OPENTHREAD_CONFIG_BORDER_ROUTER_ENABLE 1
#endif


/**
 * @def OPENTHREAD_CONFIG_SRP_SERVER_ENABLE
 *
 * Define to 1 to enable SRP Server support.
 *
 */
#ifndef OPENTHREAD_CONFIG_SRP_SERVER_ENABLE
#define OPENTHREAD_CONFIG_SRP_SERVER_ENABLE 1
#endif

/**
 * @def OPENTHREAD_CONFIG_SRP_CLIENT_ENABLE
 *
 * Define to 1 to enable SRP Client support.
 *
 */
#ifndef OPENTHREAD_CONFIG_SRP_CLIENT_ENABLE
#define OPENTHREAD_CONFIG_SRP_CLIENT_ENABLE 1
#endif

/**
 * @def OPENTHREAD_CONFIG_TMF_NETDATA_SERVICE_ENABLE
 *
 * Define to 1 to support injecting Service entries into the Thread Network Data.
 *
 */
#ifndef OPENTHREAD_CONFIG_TMF_NETDATA_SERVICE_ENABLE
#define OPENTHREAD_CONFIG_TMF_NETDATA_SERVICE_ENABLE 1
#endif


#endif // OPENTHREAD_CORE_QCA4024_CONFIG_H_
