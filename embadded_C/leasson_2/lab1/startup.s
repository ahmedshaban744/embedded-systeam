.globl reset
reset: ldr sp,=0x00011000
bl main
stop: bl stop
