	AREA ADDITION, CODE, READONLY
ENTRY		; MARK FIRST INSTRUCTION TO EXECUTE
START
	MOV R5, #6		; INTIALISE COUNTER TO 6(i.e. N=6)
	MOV R0, #0		; INTIALISE SUM TO ZERO
	LDRR1, =VALUE1 		; LOADS THE ADDRESS OF FIRSTVALUE
LOOP
	LDRH R3, [R1], #02	; READ 16 BIT DATA
	ADD R0, R0, R3		; ADD R2=R2+R3
	SUBS R5, R5, #1		; DECREMENT COUNTER
	CMP R5, #0
	BNE LOOP; LOOK BACK TILL ARRAY 
ENDS
	LDR R4, =RESULT		; LOADS THE ADDRESS OF RESULT
	STR R0, [R4]		; STORES THE RESULT IN R1
JMP B JMP
	VALUE1
	DCW 0X1111, 0X2222, 0X3333, 0XAAAA, 0XBBBB, 0XCCCC
	AREA DATA2, DATA, READWRITE; TO STORE RESULT IN GIVEN ADDRESS
	RESULT DCD 0X0
	END			; MARK END OF FILE