/***********************  I n c l u d e  -  F i l e  ***********************/
/*!
 *        \file  smbpci_int.h
 *
 *      \author  dieter.pfeuffer@men.de
 *        $Date: 2012/01/30 15:11:31 $
 *    $Revision: 1.10 $
 *
 *       \brief  SMBPCI BBIS internal header file
 *
 *    \switches  VAR_NAME
 */
 /*
 *---------------------------------------------------------------------------
 * (c) Copyright by MEN Mikro Elektronik GmbH, Nuremberg, Germany
 ******************************************************************************/
/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _SMBPCI_INT_H
#define _SMBPCI_INT_H

#ifdef __cplusplus
    extern "C" {
#endif


#define _NO_BBIS_HANDLE		/* bb_defs.h: don't define BBIS_HANDLE struct */

#include <MEN/mdis_com.h>
#include <MEN/men_typs.h>   /* system dependend definitions   */
#include <MEN/maccess.h>    /* hw access macros and types     */
#include <MEN/dbg.h>        /* debug functions                */
#include <MEN/oss.h>        /* oss functions                  */
#include <MEN/desc.h>       /* descriptor functions           */
#include <MEN/bb_defs.h>    /* bbis definitions				  */
#include <MEN/mdis_err.h>   /* MDIS error codes               */
#include <MEN/mdis_api.h>   /* MDIS global defs               */

#include <MEN/smb2.h>		/* SMB2 definitions */
#include "variant.h"		/* variant specific stuff */


/*-----------------------------------------+
|  DEFINES                                 |
+-----------------------------------------*/
/* debug settings */
#define DBG_MYLEVEL		brdH->dbgLev	/**< Debug level */
#define DBH				brdH->dbgH		/**< Debug handle */

#define MAX_PCI_PATH				16		/**< max number of bridges to devices */
#define PCI_SECONDARY_BUS_NUMBER	0x19	/* PCI bridge config */

#define RESOURCE_NBR	1				/**< number of resources (#0..#n) to assign */
#define RES_CTRL_ADDR	0				/**< resource #0: controller address space */
#define MAX_DEVS		16				/**< max number of devices supported */
#define DEVNAME_SIZE	30

#define INVALID_SMBID	0xffffffff		/**< invalid smbId[x] */

#ifdef MAC_MEM_MAPPED
#	define ADDRSPACE		OSS_ADDRSPACE_MEM
#	define RES_SPACETYPE	OSS_RES_MEM
#else
#	define ADDRSPACE		OSS_ADDRSPACE_IO
#	define RES_SPACETYPE	OSS_RES_IO
#endif

/* SMB ctrl at PCIbus */
#ifndef VAR_ISA
#	define BUSTYPE		OSS_BUSTYPE_PCI
/* SMB ctrl at ISAbus */
#else
#	define BUSTYPE		OSS_BUSTYPE_ISA
#endif


/*-----------------------------------------+
|  TYPEDEFS                                |
+-----------------------------------------*/
typedef struct {
	char		name[DEVNAME_SIZE];	/** copy of SMBDEV_n/NAME */
} SMBDEV;
		
		
/** bbis handle */
typedef struct {
	/* common */
	MDIS_IDENT_FUNCT_TBL idFuncTbl;	/**< id function table */
    u_int32     ownMemSize;			/**< own memory size */
    OSS_HANDLE	*osH;				/**< os specific handle */
    DESC_HANDLE *descH;				/**< descriptor handle pointer */
    u_int32     dbgLev;				/**< debug level for BBIS */
	DBG_HANDLE  *dbgH;				/**< debug handle */
	u_int32		busNbr;				/** PCI bus number or 0 for ISA */
	u_int32     domainNbr;          /** PCI domain number or 0 for ISA */
/* SMB ctrl at PCIbus */
#ifndef VAR_ISA
	u_int32		idCheck;			/**< 1: check id */
	u_int32		pciDevNbr;			/** PCI device number */
	u_int32		pciFuncNbr;			/** PCI function number */
	u_int8		pciPath[MAX_PCI_PATH]; /** PCI path	*/
	u_int32		pciPathLen;			/** number of bytes in pciPath */
#endif
	SMBDEV		smb[MAX_DEVS];		/** SMBDEV_n parameters */
	void		*smbH;				/** SMB handle */
	int         alreadyInitialized;  /** SMB handle was already initialized , do not close at exit */
	u_int32		smbBusNbr;			/** SMB bus number */
	u_int32		alertPollFreq;		/** alert poll frequency (see smb2.h) */
	u_int32		busyWait;			/** wait time for blocking semaphore (see smb2.h) */
	
	/* used resources */
#ifdef OSS_HAS_UNASSIGN_RESOURCES
	u_int32		resourcesAssigned;  /**< flag resources assigned */
#endif
	OSS_RESOURCES	res[RESOURCE_NBR];	/**< resources to un-/assign */
	void			*virtCtrlBase;		/**< virtual addr spaces */
	int32			smbResourceType;	/** OSS_RES_MEM, OSS_RES_IO */
	int32			smbAddrSpaceType;	/** OSS_ADDRSPACE_MEM, OSS_ADDRSPACE_IO */

} BBIS_HANDLE;


/* include files which need BBIS_HANDLE */
#include <MEN/bb_entry.h>	/* bbis jumptable			*/
#include <MEN/bb_smbpci.h>	/* SMBPCI bbis header file	*/


/*-----------------------------------------+
|  PROTOTYPES                              |
+-----------------------------------------*/
#define  __SMBPCI_InitLib	  SMBPCI_GLOBNAME(VAR_NAME,InitLib)
extern int32 __SMBPCI_InitLib( BBIS_HANDLE *brdHdl );


#ifdef __cplusplus
    }
#endif

#endif /* _SMBPCI_INT_H */





