section .data
sdot dd 0.0

section .text
bits 64
default rel
global sdot_asm

sdot_asm:
    xorps xmm0, xmm0    ; ensures that xmm0 = 0
    L1:
        movss xmm1, [rdx]
        movss xmm2, [r8]
        mulss xmm1, xmm2
        addss xmm0, xmm1

        add rdx, 4
        add r8, 4
        loop L1
    
    movss [sdot], xmm0
    xor rax, rax
    ret