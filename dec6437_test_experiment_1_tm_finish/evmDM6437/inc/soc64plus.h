/*  ============================================================================
 *   Copyright (c) Texas Instruments Inc 2002, 2003, 2004, 2005
 *
 *   Use of this software is controlled by the terms and conditions found in the
 *   license agreement under which this software has been supplied.
 *   ===========================================================================
 */

#ifndef _SOCC64PLUS_H_
#define _SOCC64PLUS_H_

/* =============================================================================
 *  Revision History
 *  ===============
 *  14-Mar-2005 brn Moved the Event Ids from csl_intc.h to soc64plus.h
 * =============================================================================
 */

#include <cslr.h>
/**************************************************************************\
* 64 soc file
\**************************************************************************/

/*****************************************************************************\
* Static inline definition
\*****************************************************************************/

#define CSL_IDEF_INLINE static inline

#define CSL_EDMA_1                         0
/*  Memory Protection specific details */
/** @brief Base address of UMC Memory protection registers */
#define CSL_MEMPROT_L2_REGS               (0x184A000u)

/** @brief Base address of PMC memory Protection registers */
#define CSL_MEMPROT_L1P_REGS              (0x184A400u)

/** @brief Base address of DMC memory protection registers */
#define CSL_MEMPROT_L1D_REGS              (0x184AC00u)

/** @brief Base address of CONFIG memory protection registers */
#define CSL_MEMPROT_CONFIG_REGS           (0x1820300u)

/** @brief Base address of INTC memory mapped registers */
#define CSL_INTC_REGS                     (0x01800000u)

/** @brief Base address of Channel controller  memory mapped registers */
#define CSL_EDMACC_1_REGS                 (0x01C00000u)
/** @brief Base address of Transfer controller  memory mapped registers */
#define CSL_EDMATC_0_REGS                ( 0x1C10000u) /* Needs to change as per soc */
#define CSL_EDMATC_1_REGS                ( 0x1C10400u) /* Needs to change as per soc */

/** Added : Mistral Srinivas */

#define CSL_MCBSP                        1
#define CSL_MCBSP_1_REGS                 (0x01E02000)

#define CSL_PWRDWN_0                          0
/** @brief Base address of PDC registers */
#define CSL_PWRDWN_PDC_REGS                 (0x01810000)

/** @brief Base address of L2 power Down registers */
#define CSL_PWRDWN_L2                       (0x0184c000)


/*  Memory Protection specific details */
/** @brief Base address of UMC Memory protection registers */
#define CSL_MEMPROT_L2_REGS               (0x184A000u)

/** @brief Base address of PMC memory Protection registers */
#define CSL_MEMPROT_L1P_REGS              (0x184A400u)

/** @brief Base address of DMC memory protection registers */
#define CSL_MEMPROT_L1D_REGS              (0x184AC00u)

/** @brief Base address of CONFIG memory protection registers */
#define CSL_MEMPROT_CONFIG_REGS           (0x1820300u)

#define CSL_MEMPROT_L2     (0)
#define CSL_MEMPROT_L1P    (1)
#define CSL_MEMPROT_L1D    (2)
#define CSL_MEMPROT_CONFIG (3)
/** #brief Bandwidth Management instance number */
#define CSL_BWMNGMT_0      (0)
/** #brief Bandwidth Management module address */
#define CSL_BWMNGMT_REGS                    (0x01820200u)

#define CSL_EDC_REGS                        (0x01846000u)

/*****************************************************************************\
* Interrupt Event IDs
\*****************************************************************************/

/**
 * @brief   Interrupt Event IDs
 */
#define    CSL_INTC_EVENTID_0       (0)
#define    CSL_INTC_EVENTID_1       (1)
#define    CSL_INTC_EVENTID_2       (2)
#define    CSL_INTC_EVENTID_3       (3)
#define    CSL_INTC_EVENTID_4       (4)
#define    CSL_INTC_EVENTID_5       (5)
#define    CSL_INTC_EVENTID_6       (6)
#define    CSL_INTC_EVENTID_7       (7)
#define    CSL_INTC_EVENTID_8       (8)
#define    CSL_INTC_EVENTID_9       (9)
#define    CSL_INTC_EVENTID_10      (10)
#define    CSL_INTC_EVENTID_11      (11)
#define    CSL_INTC_EVENTID_12      (12)
#define    CSL_INTC_EVENTID_13      (13)
#define    CSL_INTC_EVENTID_14      (14)
#define    CSL_INTC_EVENTID_15      (15)
#define    CSL_INTC_EVENTID_16      (16)
#define    CSL_INTC_EVENTID_17      (17)
#define    CSL_INTC_EVENTID_18      (18)
#define    CSL_INTC_EVENTID_19      (19)
#define    CSL_INTC_EVENTID_20      (20)
#define    CSL_INTC_EVENTID_21      (21)
#define    CSL_INTC_EVENTID_22      (22)
#define    CSL_INTC_EVENTID_23      (23)
#define    CSL_INTC_EVENTID_24      (24)
#define    CSL_INTC_EVENTID_25      (25)
#define    CSL_INTC_EVENTID_26      (26)
#define    CSL_INTC_EVENTID_27      (27)
#define    CSL_INTC_EVENTID_28      (28)
#define    CSL_INTC_EVENTID_29      (29)
#define    CSL_INTC_EVENTID_30      (30)
#define    CSL_INTC_EVENTID_31      (31)
#define    CSL_INTC_EVENTID_32      (32)
#define    CSL_INTC_EVENTID_33      (33)
#define    CSL_INTC_EVENTID_34      (34)
#define    CSL_INTC_EVENTID_35      (35)
#define    CSL_INTC_EVENTID_36      (36)
#define    CSL_INTC_EVENTID_37      (37)
#define    CSL_INTC_EVENTID_38      (38)
#define    CSL_INTC_EVENTID_39      (39)
#define    CSL_INTC_EVENTID_40      (40)
#define    CSL_INTC_EVENTID_41      (41)
#define    CSL_INTC_EVENTID_42      (42)
#define    CSL_INTC_EVENTID_43      (43)
#define    CSL_INTC_EVENTID_44      (44)
#define    CSL_INTC_EVENTID_45      (45)
#define    CSL_INTC_EVENTID_46      (46)
#define    CSL_INTC_EVENTID_47      (47)
#define    CSL_INTC_EVENTID_48      (48)
#define    CSL_INTC_EVENTID_49      (49)
#define    CSL_INTC_EVENTID_50      (50)
#define    CSL_INTC_EVENTID_51      (51)
#define    CSL_INTC_EVENTID_52      (52)
#define    CSL_INTC_EVENTID_53      (53)
#define    CSL_INTC_EVENTID_54      (54)
#define    CSL_INTC_EVENTID_55      (55)
#define    CSL_INTC_EVENTID_56      (56)
#define    CSL_INTC_EVENTID_57      (57)
#define    CSL_INTC_EVENTID_58      (58)
#define    CSL_INTC_EVENTID_59      (59)
#define    CSL_INTC_EVENTID_60      (60)
#define    CSL_INTC_EVENTID_61      (61)
#define    CSL_INTC_EVENTID_62      (62)
#define    CSL_INTC_EVENTID_63      (63)
#define    CSL_INTC_EVENTID_64      (64)
#define    CSL_INTC_EVENTID_65      (65)
#define    CSL_INTC_EVENTID_66      (66)
#define    CSL_INTC_EVENTID_67      (67)
#define    CSL_INTC_EVENTID_68      (68)
#define    CSL_INTC_EVENTID_69      (69)
#define    CSL_INTC_EVENTID_70      (70)
#define    CSL_INTC_EVENTID_71      (71)
#define    CSL_INTC_EVENTID_72      (72)
#define    CSL_INTC_EVENTID_73      (73)
#define    CSL_INTC_EVENTID_74      (74)
#define    CSL_INTC_EVENTID_75      (75)
#define    CSL_INTC_EVENTID_76      (76)
#define    CSL_INTC_EVENTID_77      (77)
#define    CSL_INTC_EVENTID_78      (78)
#define    CSL_INTC_EVENTID_79      (79)
#define    CSL_INTC_EVENTID_80      (80)
#define    CSL_INTC_EVENTID_81      (81)
#define    CSL_INTC_EVENTID_82      (82)
#define    CSL_INTC_EVENTID_83      (83)
#define    CSL_INTC_EVENTID_84      (84)
#define    CSL_INTC_EVENTID_85      (85)
#define    CSL_INTC_EVENTID_86      (86)
#define    CSL_INTC_EVENTID_87      (87)
#define    CSL_INTC_EVENTID_88      (88)
#define    CSL_INTC_EVENTID_89      (89)
#define    CSL_INTC_EVENTID_90      (90)
#define    CSL_INTC_EVENTID_91      (91)
#define    CSL_INTC_EVENTID_92      (92)
#define    CSL_INTC_EVENTID_93      (93)
#define    CSL_INTC_EVENTID_94      (94)
#define    CSL_INTC_EVENTID_95      (95)
#define    CSL_INTC_EVENTID_96      (96)
#define    CSL_INTC_EVENTID_97      (97)
#define    CSL_INTC_EVENTID_98      (98)
#define    CSL_INTC_EVENTID_99      (99)
#define    CSL_INTC_EVENTID_100     (100)
#define    CSL_INTC_EVENTID_101     (101)
#define    CSL_INTC_EVENTID_102     (102)
#define    CSL_INTC_EVENTID_103     (103)
#define    CSL_INTC_EVENTID_104     (104)
#define    CSL_INTC_EVENTID_105     (105)
#define    CSL_INTC_EVENTID_106     (106)
#define    CSL_INTC_EVENTID_107     (107)
#define    CSL_INTC_EVENTID_108     (108)
#define    CSL_INTC_EVENTID_109     (109)
#define    CSL_INTC_EVENTID_110     (110)
#define    CSL_INTC_EVENTID_111     (111)
#define    CSL_INTC_EVENTID_112     (112)
#define    CSL_INTC_EVENTID_113     (113)
#define    CSL_INTC_EVENTID_114     (114)
#define    CSL_INTC_EVENTID_115     (115)
#define    CSL_INTC_EVENTID_116     (116)
#define    CSL_INTC_EVENTID_117     (117)
#define    CSL_INTC_EVENTID_118     (118)
#define    CSL_INTC_EVENTID_119     (119)
#define    CSL_INTC_EVENTID_120     (120)
#define    CSL_INTC_EVENTID_121     (121)
#define    CSL_INTC_EVENTID_122     (122)
#define    CSL_INTC_EVENTID_123     (123)
#define    CSL_INTC_EVENTID_124     (124)
#define    CSL_INTC_EVENTID_125     (125)
#define    CSL_INTC_EVENTID_126     (126)
#define    CSL_INTC_EVENTID_127     (127)

#endif  /* _SOC64PLUS_H_ */

