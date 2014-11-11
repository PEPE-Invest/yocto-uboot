/*
 *  include/configs/digi_common.h
 *
 *  Copyright (C) 2006 by Digi International Inc.
 *  All rights reserved.
 *
 *  This program is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License version2  as published by
 *  the Free Software Foundation.
*/
/*
 *  !Revision:   $Revision: 1.4 $:
 *  !Author:     Markus Pietrek
 *  !Descr:      Defines all definitions that are common to all DIGI platforms
*/

#ifndef __DIGI_COMMON_H
#define __DIGI_COMMON_H

/* global helper stuff */

#define XMK_STR(x)	#x
#define MK_STR(x)	XMK_STR(x)

/* may undefine settings */
#include <digi_version.h>

/* stuff that may be undefined in userconfig.h */
/* ********** user key configuration ********** */
#ifndef CONFIG_UBOOT_DISABLE_USER_KEYS
# define CONFIG_USER_KEY
#endif
/* ********** console configuration ********** */
#ifdef CONFIG_SILENT_CONSOLE
# define CFG_SET_SILENT		"yes"
#else
# define CFG_SET_SILENT		"no"
#endif
#define CONFIG_GET_CONS_FROM_CONS_VAR
#define CONFIG_GET_BAUDRATE_FROM_VAR

/* ********** System Initialization ********** */
#ifdef CONFIG_DOWNLOAD_BY_DEBUGGER
# define CONFIG_SKIP_RELOCATE_UBOOT
#endif /* CONFIG_DOWNLOAD_BY_DEBUGGER */

/*
 * If we are developing, we might want to start armboot from ram
 * so we MUST NOT initialize critical regs like mem-timing ...
 */
/* define for developing */
#undef	CONFIG_SKIP_LOWLEVEL_INIT

#define PLATFORMNAME_MAXLEN	30	/* Max length of module and
					 * platform name */
#define MAX_DYNVARS		100	/* Max number of dynamic variables */

/* ********** Prompt *********** */
#define CONFIG_PROMPT_SEPARATOR		"#"

/* ********** Rootfs *********** */
/* Delay before trying to mount the rootfs from a media */
#define ROOTFS_DELAY		10

#ifndef CONFIG_ZERO_BOOTDELAY_CHECK
# define CONFIG_ZERO_BOOTDELAY_CHECK	/* check for keypress on bootdelay==0 */
#endif  /* CONFIG_ZERO_BOOTDELAY_CHECK */

/* ********** network ********** */
#ifndef CONFIG_TFTP_RETRIES_ON_ERROR
# define CONFIG_TFTP_RETRIES_ON_ERROR	5
#endif

#define CONFIG_SILENT_CONSOLE
#define CONFIG_SOURCE
#define CONFIG_AUTO_BOOTSCRIPT
#define CONFIG_BOOTSCRIPT		CONFIG_SYS_BOARD "-boot.scr"
#define CONFIG_CMD_TIME

#define CONFIG_OVERWRITE_ETHADDR_ONCE
#define CONFIG_DEFAULT_NETWORK_SETTINGS	\
	"ethaddr=00:04:f3:ff:ff:fa\0" \
	"wlanaddr=00:04:f3:ff:ff:fb\0" \
	"btaddr=00:04:f3:ff:ff:fc\0" \
	"ipaddr=192.168.42.30\0" \
	"serverip=192.168.42.1\0" \
	"netmask=255.255.0.0\0"

#define CONFIG_ROOTPATH		"/exports/nfsroot-" CONFIG_SYS_BOARD
#define CONFIG_ENV_VARS_UBOOT_CONFIG

#define CARRIERBOARD_VERSION_UNDEFINED	0

/* ********** usb/mmc ********** */
#define DEFAULT_KERNEL_FS		"fat"
#define DEFAULT_KERNEL_DEVPART		"0:1"
#define DEFAULT_ROOTFS_SATA_PART	"/dev/sda2"
#define DEFAULT_ROOTFS_MMC_PART		"/dev/mmcblk0p2"
#define DEFAULT_ROOTFS_USB_PART		"/dev/sda2"

/* ********** memory sizes ********** */
#define SPI_LOADER_SIZE		8192

/* NVRAM */
#define CONFIG_ENV_SIZE		(16 * 1024)

/*-----------------------------------------------------------------------
 * Stack sizes
 *
 * The stack sizes are set up in start.S using the settings below
 */
#define CONFIG_STACKSIZE	(128*1024)	/* regular stack */
#define CONFIG_SYS_GBL_DATA_SIZE	256     /* size in bytes reserved for initial data */

/* ********** misc stuff ********** */
#define CONFIG_CMD_ENV_FLAGS
#define CONFIG_SYS_PBSIZE	 (CONFIG_SYS_CBSIZE + CONFIG_PROMPT_MAXLEN + 16)
#define CONFIG_SYS_MAXARGS	32			/* max number of command args */
#define CONFIG_SYS_BARGSIZE	CONFIG_SYS_CBSIZE	/* Boot Argument Buffer Size */

/* valid baudrates */
#define CONFIG_SYS_BAUDRATE_TABLE	{9600, 19200, 38400, 57600, 115200}

/* In: serial, Out: serial etc. */
#define CFG_CONSOLE_INFO_QUIET

/* stuff for DVTs and special information */
#define CONFIG_DVT_PROVIDED

/* compilation */
#define CONFIG_SYS_64BIT_VSPRINTF      /* we need if for NVRAM */
#define CONFIG_SYS_64BIT_STRTOUL       /* we need if for NVRAM */

/* device tree */
#define CONFIG_FDT_MAXSIZE    (128 * 1024)

/* Digi commands arguments help */
#define DIGICMD_ARG_BLKDEV_HELP	\
	"       - device:part: number of device and partition\n"
#define DIGICMD_ARG_FILESYS_HELP	\
	"       - filesystem: fat (default)|ext4\n"
#define DIGICMD_ARG_FILENAME_HELP	\
	"       - filename: file to transfer (if not provided, filename will\n" \
	"                   will be taken from variable '<partition>_file')\n"
#define DIGICMD_ARG_IMGADDR_HELP	\
	"       - image_address: address of image in RAM\n"
#define DIGICMD_ARG_IMGSIZE_HELP	\
	"       - image_size: size of image in RAM\n"
#define DIGICMD_ARG_SOURCEFILE_HELP	\
	"       - source_file: file to transfer\n"
#define DIGICMD_ARG_TARGETFILE_HELP	\
	"       - target_file: target filename\n"
#define DIGICMD_ARG_TARGETFILESYS_HELP	\
	"       - target_fs: fat (default)\n"

/* Help arguments for update command */
#define DIGICMD_UPDATE_NET_ARGS_HELP	\
	"      source=" CONFIG_SUPPORTED_SOURCES_NET " -> " \
	"[filename]\n" \
		DIGICMD_ARG_FILENAME_HELP
#define DIGICMD_UPDATE_BLOCK_ARGS_HELP	\
	"      source=" CONFIG_SUPPORTED_SOURCES_BLOCK " -> " \
	"[device:part] [filesystem] [filename]\n" \
		DIGICMD_ARG_BLKDEV_HELP \
		DIGICMD_ARG_FILESYS_HELP \
		DIGICMD_ARG_FILENAME_HELP
#define DIGICMD_UPDATE_RAM_ARGS_HELP	\
	"      source=ram -> <image_address> <image_size>\n" \
		DIGICMD_ARG_IMGADDR_HELP \
		DIGICMD_ARG_IMGSIZE_HELP

/* Help arguments for dboot command */
#define DIGICMD_DBOOT_NET_ARGS_HELP	DIGICMD_UPDATE_NET_ARGS_HELP
#define DIGICMD_DBOOT_BLOCK_ARGS_HELP	DIGICMD_UPDATE_BLOCK_ARGS_HELP

/* Help arguments for updatefile command */
#define DIGICMD_UPDATEFILE_NET_ARGS_HELP	\
	"      source=" CONFIG_SUPPORTED_SOURCES_NET " -> " \
	"[source_file] [targetfile] [target_fs]\n" \
		DIGICMD_ARG_SOURCEFILE_HELP \
		DIGICMD_ARG_TARGETFILE_HELP \
		DIGICMD_ARG_TARGETFILESYS_HELP
#define DIGICMD_UPDATEFILE_BLOCK_ARGS_HELP	\
	"      source=" CONFIG_SUPPORTED_SOURCES_BLOCK " -> " \
	"[device:part] [filesystem] [source_file] [target_file] [target_fs]\n" \
		DIGICMD_ARG_BLKDEV_HELP \
		DIGICMD_ARG_FILESYS_HELP \
		DIGICMD_ARG_SOURCEFILE_HELP \
		DIGICMD_ARG_TARGETFILE_HELP \
		DIGICMD_ARG_TARGETFILESYS_HELP
#define DIGICMD_UPDATEFILE_RAM_ARGS_HELP	\
	"      source=ram -> "\
	"<image_address> <image_size> [targetfile] [target_fs]\n" \
		DIGICMD_ARG_IMGADDR_HELP \
		DIGICMD_ARG_IMGSIZE_HELP \
		DIGICMD_ARG_TARGETFILE_HELP \
		DIGICMD_ARG_TARGETFILESYS_HELP

#ifndef __ASSEMBLY__		/* put C only stuff in this section */
/* macros */
#define VIDEO_MENU_OPTION(text, hook, param)	\
	{MENU_OPTION, text, hook, param}
/* global functions */
int bsp_init(void);
#endif /* __ASSEMBLY__ */

#endif /* __DIGI_COMMON_H */
