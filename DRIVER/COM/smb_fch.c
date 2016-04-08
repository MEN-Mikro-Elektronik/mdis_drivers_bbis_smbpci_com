/*********************  P r o g r a m  -  M o d u l e ***********************/
/*!
 *        \file  smb_fch.c
 *
 *      \author  dieter.pfeuffer@men.de
 *        $Date: $
 *    $Revision: $
 *
 *      \brief   SMBPCI BBIS - SMBPCI_FCH variant specific functions
 *
 *     Required: ---
 *
 *     \switches DBG 
 * */
 /*-------------------------------[ History ]--------------------------------
 *
 * $Log: smb_fch.c,v $
 *---------------------------------------------------------------------------
 * (c) Copyright by MEN Mikro Elektronik GmbH, Nuernberg, Germany
 ****************************************************************************/

#include "smbpci_int.h"		/* internal header file */

/****************************** SmbInitLib **********************************/
/** Initialize the SMB library
 *
 *  \param brdHdl     \IN  Bbis handle
 *
 *  \return           \c 0 On success or error code
 */
extern int32 __SMBPCI_InitLib(
	BBIS_HANDLE *brdH
)
{
    int32           error;
	SMB_DESC_FCH    descSmb;

	DBGWRT_1((DBH, "%s baseAddr %08p\n", __FUNCTION__, brdH->virtCtrlBase ));

	OSS_MemFill( brdH->osH, sizeof(descSmb), (char*)&descSmb, 0x00 );

	descSmb.baseAddr = brdH->virtCtrlBase;
	descSmb.dbgLevel = brdH->dbgLev;
	descSmb.alertPollFreq = (int32)brdH->alertPollFreq;
	descSmb.busyWait = (int32)brdH->busyWait;

#ifdef _SMBPCI_FCH_ASF
	if( brdH->smbAddrSpaceType == OSS_ADDRSPACE_MEM )
	    error = SMB_FCH_Init( &descSmb, brdH->osH, &brdH->smbH );
	else
#endif
		error = SMB_FCH_IO_Init( &descSmb, brdH->osH, &brdH->smbH );

    if( error )
    {
	    DBGWRT_ERR((DBH,"*** %s\n", __FUNCTION__));
    }

	return ( error );
}




