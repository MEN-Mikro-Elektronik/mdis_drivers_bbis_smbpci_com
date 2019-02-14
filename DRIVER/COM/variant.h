/***********************  I n c l u d e  -  F i l e  ***********************/
/*!
 *        \file  variant.h
 *
 *      \author  dieter.pfeuffer@men.de
 *        $Date: 2012/03/23 09:12:55 $
 *    $Revision: 1.13 $
 *
 *       \brief  Header file for SMBPCI BBIS with variant specific stuff
 *
 *    \switches  SMBPCI_VARIANT
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


#ifndef _VARIANT_H
#define _VARIANT_H

#ifdef __cplusplus
    extern "C" {
#endif


/*-----------------------------------------+
|  ICH SMBus controller                    |
+-----------------------------------------*/
#if defined( _SMBPCI_ICH )
#	define VAR_NAME					SMBPCI_ICH		/**< hw-name and func-prefix	*/
#	define VAR_NAME_STR				"SMBPCI_ICH"	/**< hw-name and func-prefix	*/
#	define VAR_PCI_VEN_ID			0x8086			/* pci vendor-id                */
#	define VAR_PCI_DEV_ID			0x266A			/* pci device-id - ICH6 (F14)   */
#	define VAR_PCI_DEV_ID_2			0x27DA			/* pci device-id - ICH7 (F15)   */
#	define VAR_PCI_DEV_ID_3			0x2410			/* pci device-id - ICH0 (EM07)  */
#	define VAR_PCI_DEV_ID_4			0x2443			/* pci device-id - ICH2 (EM07n) */
#   define VAR_PCI_DEV_ID_5         0x283E			/* pci device-id - ICH8 (F18)   */
#   define VAR_PCI_DEV_ID_6         0x2930			/* pci device-id - ICH9 (F19P)  */
#   define VAR_PCI_DEV_ID_7         0x3B30			/* pci device-id - PCH  (G20)   */
#   define VAR_PCI_DEV_ID_8         0x1C22			/* pci device-id - PCH  (F21P)  */
#	define VAR_PCI_DEV_ID_9			0x1E22			/* pci device-id - PantherPoint (G22/F22) */
#	define VAR_CTRLR_BAR			4				/* BAR to ctrl registers	    */
#	define VAR_CTRLR_OFFSET			0x00			/* offset to ctrl registers     */
#	define VAR_CTRLR_SIZE			0x18			/* size of ctrl registers       */
/*-----------------------------------------+
|  SCH SMBus controller                    |
+-----------------------------------------*/
#elif defined( _SMBPCI_SCH )
#	define VAR_NAME					SMBPCI_SCH		/**< hw-name and func-prefix  */
#	define VAR_NAME_STR				"SMBPCI_SCH"	/**< hw-name and func-prefix  */
#	define VAR_PCI_VEN_ID			0x8086			/* pci vendor-id              */
#	define VAR_PCI_DEV_ID			0x8119			/* pci device-id - SCH (XM01) */
#	define VAR_PCI_DEV_ID_2			0x8186			/* pci device-id - TopCliff (MM2) */
#	define VAR_CTRLR_BAR			0x40			/* Offset to BAR register     */
#	define VAR_CTRLR_OFFSET			0x00			/* offset to ctrl registers   */
#	define VAR_CTRLR_SIZE			0x40			/* size of ctrl registers     */
/*-----------------------------------------+
|  FCH SMBus controllers (standard/asf)    |
+-----------------------------------------*/
#elif defined( _SMBPCI_FCH ) || defined( _SMBPCI_FCH_ASF )
#	define VAR_PCI_VEN_ID			0x1002			/* pci vendor-id                */
#	define VAR_PCI_DEV_ID			0x4385			/* pci device-id - A55E (SC24)  */
#	define VAR_PMIO_IDXDATA			0xCD6			/* PM I/O register space */
#	define VAR_PMIO_SIZE			2				/* PM I/0 register size  */
#	define VAR_PMIO_IDX_OFF			0x000			/* offset to index register (r/w, 8bits) */
#	define VAR_PMIO_DATA_OFF		0x001			/* offset to data register (r/w, 8bits)  */
	/* FCH standard SMBus controller */
#	if defined( _SMBPCI_FCH )
#		define VAR_NAME					SMBPCI_FCH		/**< hw-name and func-prefix	*/
#		define VAR_NAME_STR				"SMBPCI_FCH"	/**< hw-name and func-prefix	*/
#		define VAR_PM_SMBADDR			0x2C			/* PM Smbus0En (r/w, 16bits)   */
#		define VAR_PM_SMBADDR_BYTES		2				/* PM Smbus0En byte size       */
#		define VAR_PM_SMBUS0EN_BADDR	0xFFE0			/* PM SmBus0_baddr mask (15:5) */
#		define VAR_CTRLR_SIZE			0x14			/* size of ctrl registers      */
	/* FCH_ASF SMBus controller */
#	else
#		define VAR_NAME					SMBPCI_FCH_ASF	/**< hw-name and func-prefix	*/
#		define VAR_NAME_STR				"SMBPCI_FCH_ASF"/**< hw-name and func-prefix	*/
#		define VAR_PM_SMBADDR			0x24			/* PM AcpiMmioEn (r/w, 32bits)          */
#		define VAR_PM_SMBADDR_BYTES		4				/* PM AcpiMmioEn byte size              */
#		define VAR_PM_ACPIMMIOEN_ENBL	0x00000001		/* PM AcpiMMioDecodeEn mask (1:enabled) */
#		define VAR_PM_ACPIMMIOEN_IO		0x00000002		/* PM AcpiMMIoSel mask (1:i/o mapped)   */
#		define VAR_PM_ACPIMMIOEN_ASF	0xFFFFF000		/* PM AcpiMMioAddr 31:12 mask           */
#		define VAR_PM_ACPIMMIOEN_ASFOFF	0x900			/* offset to ASF registers              */
#		define VAR_CTRLR_SIZE			0x17			/* size of ctrl registers               */
#	endif
/*-----------------------------------------+
|  16Z001 SMBus controller on F208         |
+-----------------------------------------*/
#elif defined( _SMBPCI_16Z001_F208 )
#	define VAR_NAME					SMBPCI_16Z001_F208		/**< hw-name and func-prefix	*/
#	define VAR_NAME_STR				"SMBPCI_16Z001_F208"	/**< hw-name and func-prefix	*/
#	define VAR_PCI_VEN_ID			0x1172			/* pci vendor-id (Altera) */
#	define VAR_PCI_VEN_ID_2			0x1A88			/* pci vendor-id (MEN) */
#	define VAR_PCI_DEV_ID			0x4D45			/* pci device-id */
#	define VAR_CTRLR_BAR			3				/* BAR to ctrl registers	*/
#	define VAR_CTRLR_OFFSET			0x00			/* offset to ctrl registers */
#	define VAR_CTRLR_SIZE			0x0D			/* size of ctrl registers */
/*-----------------------------------------+
|  16Z001 SMBus controller                 |
+-----------------------------------------*/
#elif (defined( _SMBPCI_16Z001 ) || defined( _SMBPCI_16Z001_IO ))
#	ifdef _SMBPCI_16Z001
#		define VAR_NAME				SMBPCI_16Z001	/**< hw-name and func-prefix	*/
#		define VAR_NAME_STR			"SMBPCI_16Z001"	/**< hw-name and func-prefix	*/
#	else
#		define VAR_NAME				SMBPCI_16Z001_IO	/**< hw-name and func-prefix	*/
#		define VAR_NAME_STR			"SMBPCI_16Z001_IO"	/**< hw-name and func-prefix	*/
#	endif
#	define VAR_PCI_VEN_ID			0x1172			/* pci vendor-id (Altera) */
#	define VAR_PCI_VEN_ID_2			0x1A88			/* pci vendor-id (MEN) */
#	define VAR_PCI_DEV_ID			0x4D45			/* pci device-id */
#	define VAR_CTRLR_OFFSET			0x00			/* offset to ctrl registers */
#	define VAR_CTRLR_SIZE			0x0D			/* size of ctrl registers */
/*-----------------------------------------+
|  16Z001 SMBus controller @ ISA bus       |
+-----------------------------------------*/
#elif (defined( _SMBPCI_ISA_16Z001 ) || defined( _SMBPCI_ISA_16Z001_IO ))
#	ifdef _SMBPCI_ISA_16Z001
#		define VAR_NAME				SMBISA_16Z001	/**< hw-name and func-prefix	*/
#		define VAR_NAME_STR			"SMBISA_16Z001"	/**< hw-name and func-prefix	*/
#	else
#		define VAR_NAME				SMBISA_16Z001_IO	/**< hw-name and func-prefix	*/
#		define VAR_NAME_STR			"SMBISA_16Z001_IO"	/**< hw-name and func-prefix	*/
#	endif
#	define VAR_CTRLR_SIZE			0x0D			/* size of ctrl registers */
#	define VAR_ISA					1				/* SMB ctrl at ISA bus */
/*-----------------------------------------+
|  Native SMB Controller (OnChip)          |
+-----------------------------------------*/
#elif defined( _SMBPCI_NAT )
#   define VAR_NAME					SMB_NATIVE		/**< hw-name and func-prefix	*/
#	define VAR_NAME_STR				"SMB_NATIVE"	/**< hw-name and func-prefix	*/
#endif

#ifndef VAR_NAME
#	error "*** VAR_NAME must be set"
#endif

#ifndef VAR_NAME_STR
#	error "*** VAR_NAME_STR must be set"
#endif

#ifdef __cplusplus
    }
#endif

#endif /* _VARIANT_H */





