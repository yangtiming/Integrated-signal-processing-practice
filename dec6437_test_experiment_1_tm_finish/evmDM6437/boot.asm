;	filename:	boot.asm
;  	date:		2008/09/10

            .title  "Bootup utility"
            .option D,T
            .length 102
            .width  140
COPY_TABLE    .equ    0x42000400
            .sect ".bootld"
            .global _boot

_boot:      
;************************************************************************
;* Debug Loop -  Comment out B for Normal Operation
;************************************************************************
			nop
            zero B1
_myloop:  
            nop  5

_myloopend: nop  

;************************************************************************
;* Configure EMIF
;************************************************************************
		mvkl  0x01E00010, a6       ; load EMIF register address
		mvkh  0x01E00010, a6
		mvkl  0x0050043C, b6       ; set EMIF register value
		mvkh  0x0050043C, b6
		stw   b6,*a6
		nop   5

;************************************************************************
;* Setup_DDR_135_MHz
;************************************************************************
		mvkl  0x01C41A34, a6 ;DDR2 MDCTL
		mvkh  0x01C41A34, a6
		mvkl  0x00000103, b6
		mvkh  0x00000103, b6
		stw   b6,*a6
		nop   5


		mvkl  0x01c41120, a6 ;PTCMD
		mvkh  0x01c41120, a6
		mvkl  0x00000001, b6
		mvkh  0x00000001, b6
		stw   b6,*a6
		nop   5


		mvkl  0x200000e4, a6 ;DDRPHYCR
		mvkh  0x200000e4, a6
		mvkl  0x50006405, b6
		mvkh  0x50006405, b6
		stw   b6,*a6
		nop   5


		mvkl  0x20000008, a6 ;SDBCR
		mvkh  0x20000008, a6
		mvkl  0x01178822, b6
		mvkh  0x01178822, b6
		stw   b6,*a6
		nop   5


		mvkl  0x20000010, a6 ;SDTIMR
		mvkh  0x20000010, a6
		mvkl  0x22923a49, b6
		mvkh  0x22923a49, b6
		stw   b6,*a6
		nop   5


		mvkl  0x20000014, a6;SDTIMR2
		mvkh  0x20000014, a6
		mvkl  0x0012C722, b6
		mvkh  0x0012C722, b6
		stw   b6,*a6
		nop   5


		mvkl  0x2000000c, a6;SDRCR
		mvkh  0x2000000c, a6
		mvkl  0x000004ef, b6
		mvkh  0x000004ef, b6
		stw   b6,*a6
		nop   5


		mvkl  0x01C41A34, a6 ;DDR2 MDCTL
		mvkh  0x01C41A34, a6
		mvkl  0x00001A01, b6
		mvkh  0x00001A01, b6
		stw   b6,*a6
		nop   5


		mvkl  0x01c41120, a6 ;DITCSRB0
		mvkh  0x01c41120, a6
		mvkl  0x00000000, b6
		mvkh  0x00000000, b6
		stw   b6,*a6
		nop   5


		mvkl  0x01C41A34, a6 ;DDR2 MDCTL
		mvkh  0x01C41A34, a6
		mvkl  0x00000703, b6
		mvkh  0x00000703, b6
		stw   b6,*a6
		nop   5


		mvkl  0x01c41120, a6 ;DITCSRB0
		mvkh  0x01c41120, a6
		mvkl  0x00000000, b6
		mvkh  0x00000000, b6
		stw   b6,*a6
		nop   5


		mvkl  0x200000f0, a6 ;VTPIOCR
		mvkh  0x200000f0, a6
		mvkl  0x0000201F, b6
		mvkh  0x0000201F, b6
		stw   b6,*a6
		nop   5


		mvkl  0x200000f0, a6 ;VTPIOCR
		mvkh  0x200000f0, a6
		mvkl  0x0000A01F, b6
		mvkh  0x0000A01F, b6
		stw   b6,*a6
		nop   5


		mvkl  0x01C4004c, a6 ;DDRVTPER
		mvkh  0x01C4004c, a6
		mvkl  0x00000001, b6
		mvkh  0x00000001, b6
		stw   b6,*a6
		nop   5


		mvkl  0x200000f0, a6 ;VTPIOCR
		mvkh  0x200000f0, a6
		mvkl  0x0000A384, b6
		mvkh  0x0000A384, b6
		stw   b6,*a6
		nop   5


		mvkl  0x200000f0, a6 ;VTPIOCR
		mvkh  0x200000f0, a6
		mvkl  0x00008384, b6
		mvkh  0x00008384, b6
		stw   b6,*a6
		nop   5

		mvkl  0x01C4004c, a6 ;DDRVTPER
		mvkh  0x01C4004c, a6
		mvkl  0x00000000, b6
		mvkh  0x00000000, b6
		stw   b6, *a6
		nop   5
        nop   9
        nop   9
        nop   9
        nop   9
        nop   9
        nop   9
        nop   9
        nop   9
;************************************************************************
;* _setupPinMux
;************************************************************************
		mvkl  0x01C40000, a6       ; load PINMUX0 register address
		mvkh  0x01C40000, a6
		mvkl  0x00148681, b6       ; set PINMUX0 register value
		mvkh  0x00148681, b6
		stw   b6,*a6
		nop   5

		mvkl  0x01C40004, a6       ; load PINMUX1 register address
		mvkh  0x01C40004, a6
		mvkl  0x01615940, b6       ; set PINMUX1 register value
		mvkh  0x01615940, b6
		stw   b6,*a6
		nop   5

		mvkl  0x01C40048, a6       ; load CFG_VDD3P3V_PWDN register address
		mvkh  0x01C40048, a6
		mvkl  0x00000000, b6       ; set CFG_VDD3P3V_PWDN register value
		mvkh  0x00000000, b6
		stw   b6,*a6
		nop   5

;************************************************************************
;* Setup_PLL1_594_MHz_OscIn
;************************************************************************
		mvkl  0x01C40900, a6       ; load pll_ctl register address
		mvkh  0x01C40900, a6
		mvkl  0x00000049, b6       ; set pll_ctl register value
		mvkh  0x00000049, b6
		stw   b6,*a6
		nop   5

		mvkl  0x01C40910, a6       ; load pll_pllm register address
		mvkh  0x01C40910, a6
		mvkl  0x00000015, b6       ; set pll_pllm register value
		mvkh  0x00000015, b6
		stw   b6,*a6
		nop   5

		mvkl  0x01C40938, a6       ; load pll_cmd register address
		mvkh  0x01C40938, a6
		mvkl  0x00000001, b6       ; set pll_cmd register value
		mvkh  0x00000001, b6
		stw   b6,*a6
		nop   5

		mvkl  0x01C4093c, a6       ; load pll_stat register address
		mvkh  0x01C4093c, a6
		mvkl  0x00000006, b6       ; set pll_stat register value
		mvkh  0x00000006, b6
		stw   b6,*a6
		nop   5

		mvkl  0x01C40918, a6       ; load pll_div1 register address
		mvkh  0x01C40918, a6
		mvkl  0x00008000, b6       ; set pll_div1 register value
		mvkh  0x00008000, b6
		stw   b6,*a6
		nop   5

		mvkl  0x01C4091c, a6       ; load pll_div2 register address
		mvkh  0x01C4091c, a6
		mvkl  0x00008002, b6       ; set pll_div2 register value
		mvkh  0x00008002, b6
		stw   b6,*a6
		nop   5

		mvkl  0x01C40920, a6       ; load pll_div3 register address
		mvkh  0x01C40920, a6
		mvkl  0x00008005, b6       ; set pll_div3 register value
		mvkh  0x00008005, b6
		stw   b6,*a6
		nop   5

;************************************************************************
;* Setup_PLL2_DDR_162_MHz_OscIn
;************************************************************************
		mvkl  0x01C40d00, a6       ; load pll_ctl register address
		mvkh  0x01C40d00, a6
		mvkl  0x00000049, b6       ; set pll_ctl register value
		mvkh  0x00000049, b6
		stw   b6,*a6
		nop   5

		mvkl  0x01C40d10, a6       ; load pll_pllm register address
		mvkh  0x01C40d10, a6
		mvkl  0x00000017, b6       ; set pll_pllm register value
		mvkh  0x00000017, b6
		stw   b6,*a6
		nop   5

		mvkl  0x01C40d38, a6       ; load pll_cmd register address
		mvkh  0x01C40d38, a6
		mvkl  0x00000001, b6       ; set pll_cmd register value
		mvkh  0x00000001, b6
		stw   b6,*a6
		nop   5

		mvkl  0x01C40d3c, a6       ; load pll_stat register address
		mvkh  0x01C40d3c, a6
		mvkl  0x00000006, b6       ; set pll_stat register value
		mvkh  0x00000006, b6
		stw   b6,*a6
		nop   5

		mvkl  0x01C40d18, a6       ; load pll_div1 register address
		mvkh  0x01C40d18, a6
		mvkl  0x00008001, b6       ; set pll_div1 register value
		mvkh  0x00008001, b6
		stw   b6,*a6
		nop   5

		mvkl  0x01C40d1c, a6       ; load pll_div2 register address
		mvkh  0x01C40d1c, a6
		mvkl  0x0000800b, b6       ; set pll_div2 register value
		mvkh  0x0000800b, b6
		stw   b6,*a6
		nop   5

		mvkl  0x01C40d20, a6       ; load pll_div3 register address
		mvkh  0x01C40d20, a6
		mvkl  0x00008000, b6       ; set pll_div3 register value
		mvkh  0x00008000, b6
		stw   b6,*a6
		nop   5
		
;****************************************************************************
;* Copy code sections
;****************************************************************************
        mvkl  COPY_TABLE, a3   ; load table pointer
        mvkh  COPY_TABLE, a3

        ldw   *a3++, b1        ; Load entry point
;		nop   5
;		mvkl  0x80001680, b1   ; load table pointer
;       mvkh  0x80001680, b1

copy_section_top:
        ldw   *a3++, b0        ; byte count 
        ldw   *a3++, a4        ; ram start address
        nop   3

 [!b0]  b copy_done            ; have we copied all sections?
        nop   5

copy_loop:
        ldb   *a3++,b5
        sub   b0,1,b0          ; decrement counter
 [ b0]  b     copy_loop        ; setup branch if not done
 [!b0]  b     copy_section_top
        zero  a1
 [!b0]  and   3,a3,a1
        stb   b5,*a4++
 [!b0]  and   -4,a3,a5         ; round address up to next multiple of 4
 [ a1]  add   4,a5,a3          ; round address up to next multiple of 4 
       
;****************************************************************************
;* Jump to entry point
;****************************************************************************
copy_done:
		mvkl  0x0000010, b0       ; set pll_div1 register value
		nop 5
copy_done1:
        sub   b0,1,b0 
	   [ b0]  b copy_done1            ; have we copied all sections?  
        nop  9          
       
        b    .S2 b1
        nop  9

;delay_boot:
;		mvkl  0x00000100, b0       ; set pll_div1 register value
;		nop   5
;        sub   b0,1,b0          ; decrement counter
;	   [ b0]  b delay_boot            ; have we copied all sections?  
;        nop  9 