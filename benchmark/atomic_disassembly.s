
./a.out:     file format elf64-littleaarch64


Disassembly of section .init:

0000000000000768 <_init>:
 768:	a9bf7bfd 	stp	x29, x30, [sp,#-16]!
 76c:	910003fd 	mov	x29, sp
 770:	94000020 	bl	7f0 <call_weak_fn>
 774:	a8c17bfd 	ldp	x29, x30, [sp],#16
 778:	d65f03c0 	ret

Disassembly of section .plt:

0000000000000780 <__gmon_start__@plt-0x20>:
 780:	a9bf7bf0 	stp	x16, x30, [sp,#-16]!
 784:	90000090 	adrp	x16, 10000 <__FRAME_END__+0xf570>
 788:	f947fe11 	ldr	x17, [x16,#4088]
 78c:	913fe210 	add	x16, x16, #0xff8
 790:	d61f0220 	br	x17
 794:	d503201f 	nop
 798:	d503201f 	nop
 79c:	d503201f 	nop

00000000000007a0 <__gmon_start__@plt>:
 7a0:	b0000090 	adrp	x16, 11000 <_GLOBAL_OFFSET_TABLE_+0x50>
 7a4:	f9400211 	ldr	x17, [x16]
 7a8:	91000210 	add	x16, x16, #0x0
 7ac:	d61f0220 	br	x17

00000000000007b0 <_ZNSt8ios_base4InitC1Ev@plt>:
 7b0:	b0000090 	adrp	x16, 11000 <_GLOBAL_OFFSET_TABLE_+0x50>
 7b4:	f9400611 	ldr	x17, [x16,#8]
 7b8:	91002210 	add	x16, x16, #0x8
 7bc:	d61f0220 	br	x17

00000000000007c0 <__cxa_atexit@plt>:
 7c0:	b0000090 	adrp	x16, 11000 <_GLOBAL_OFFSET_TABLE_+0x50>
 7c4:	f9400a11 	ldr	x17, [x16,#16]
 7c8:	91004210 	add	x16, x16, #0x10
 7cc:	d61f0220 	br	x17

00000000000007d0 <__cxa_finalize@plt>:
 7d0:	b0000090 	adrp	x16, 11000 <_GLOBAL_OFFSET_TABLE_+0x50>
 7d4:	f9400e11 	ldr	x17, [x16,#24]
 7d8:	91006210 	add	x16, x16, #0x18
 7dc:	d61f0220 	br	x17

00000000000007e0 <_ZNSt6thread2idC1Ev@plt>:
 7e0:	b0000090 	adrp	x16, 11000 <_GLOBAL_OFFSET_TABLE_+0x50>
 7e4:	f9401211 	ldr	x17, [x16,#32]
 7e8:	91008210 	add	x16, x16, #0x20
 7ec:	d61f0220 	br	x17

Disassembly of section .text:

00000000000007f0 <call_weak_fn>:
 7f0:	90000080 	adrp	x0, 10000 <__FRAME_END__+0xf570>
 7f4:	f947dc00 	ldr	x0, [x0,#4024]
 7f8:	b4000040 	cbz	x0, 800 <call_weak_fn+0x10>
 7fc:	17ffffe9 	b	7a0 <__gmon_start__@plt>
 800:	d65f03c0 	ret
 804:	00000000 	.inst	0x00000000 ; undefined

0000000000000808 <deregister_tm_clones>:
 808:	b0000081 	adrp	x1, 11000 <_GLOBAL_OFFSET_TABLE_+0x50>
 80c:	b0000080 	adrp	x0, 11000 <_GLOBAL_OFFSET_TABLE_+0x50>
 810:	9100c021 	add	x1, x1, #0x30
 814:	9100c000 	add	x0, x0, #0x30
 818:	91001c21 	add	x1, x1, #0x7
 81c:	cb000021 	sub	x1, x1, x0
 820:	f100383f 	cmp	x1, #0xe
 824:	540000a9 	b.ls	838 <deregister_tm_clones+0x30>
 828:	90000081 	adrp	x1, 10000 <__FRAME_END__+0xf570>
 82c:	f947ec21 	ldr	x1, [x1,#4056]
 830:	b4000041 	cbz	x1, 838 <deregister_tm_clones+0x30>
 834:	d61f0020 	br	x1
 838:	d65f03c0 	ret
 83c:	d503201f 	nop

0000000000000840 <register_tm_clones>:
 840:	b0000081 	adrp	x1, 11000 <_GLOBAL_OFFSET_TABLE_+0x50>
 844:	b0000080 	adrp	x0, 11000 <_GLOBAL_OFFSET_TABLE_+0x50>
 848:	9100c021 	add	x1, x1, #0x30
 84c:	9100c000 	add	x0, x0, #0x30
 850:	cb000021 	sub	x1, x1, x0
 854:	9343fc21 	asr	x1, x1, #3
 858:	8b41fc21 	add	x1, x1, x1, lsr #63
 85c:	9341fc21 	asr	x1, x1, #1
 860:	b40000c1 	cbz	x1, 878 <register_tm_clones+0x38>
 864:	90000082 	adrp	x2, 10000 <__FRAME_END__+0xf570>
 868:	f947f042 	ldr	x2, [x2,#4064]
 86c:	b4000062 	cbz	x2, 878 <register_tm_clones+0x38>
 870:	d61f0040 	br	x2
 874:	d503201f 	nop
 878:	d65f03c0 	ret
 87c:	d503201f 	nop

0000000000000880 <__do_global_dtors_aux>:
 880:	a9be7bfd 	stp	x29, x30, [sp,#-32]!
 884:	910003fd 	mov	x29, sp
 888:	f9000bf3 	str	x19, [sp,#16]
 88c:	b0000093 	adrp	x19, 11000 <_GLOBAL_OFFSET_TABLE_+0x50>
 890:	3940c260 	ldrb	w0, [x19,#48]
 894:	35000140 	cbnz	w0, 8bc <__do_global_dtors_aux+0x3c>
 898:	90000080 	adrp	x0, 10000 <__FRAME_END__+0xf570>
 89c:	f947e400 	ldr	x0, [x0,#4040]
 8a0:	b4000080 	cbz	x0, 8b0 <__do_global_dtors_aux+0x30>
 8a4:	b0000080 	adrp	x0, 11000 <_GLOBAL_OFFSET_TABLE_+0x50>
 8a8:	f9401400 	ldr	x0, [x0,#40]
 8ac:	97ffffc9 	bl	7d0 <__cxa_finalize@plt>
 8b0:	97ffffd6 	bl	808 <deregister_tm_clones>
 8b4:	52800020 	mov	w0, #0x1                   	// #1
 8b8:	3900c260 	strb	w0, [x19,#48]
 8bc:	f9400bf3 	ldr	x19, [sp,#16]
 8c0:	a8c27bfd 	ldp	x29, x30, [sp],#32
 8c4:	d65f03c0 	ret

00000000000008c8 <frame_dummy>:
 8c8:	90000080 	adrp	x0, 10000 <__FRAME_END__+0xf570>
 8cc:	91376000 	add	x0, x0, #0xdd8
 8d0:	f9400001 	ldr	x1, [x0]
 8d4:	b5000061 	cbnz	x1, 8e0 <frame_dummy+0x18>
 8d8:	17ffffda 	b	840 <register_tm_clones>
 8dc:	d503201f 	nop
 8e0:	90000081 	adrp	x1, 10000 <__FRAME_END__+0xf570>
 8e4:	f947e021 	ldr	x1, [x1,#4032]
 8e8:	b4ffff81 	cbz	x1, 8d8 <frame_dummy+0x10>
 8ec:	a9bf7bfd 	stp	x29, x30, [sp,#-16]!
 8f0:	910003fd 	mov	x29, sp
 8f4:	d63f0020 	blr	x1
 8f8:	a8c17bfd 	ldp	x29, x30, [sp],#16
 8fc:	17ffffd1 	b	840 <register_tm_clones>

0000000000000900 <_Z41__static_initialization_and_destruction_0ii>:
 900:	a9be7bfd 	stp	x29, x30, [sp,#-32]!
 904:	910003fd 	mov	x29, sp
 908:	b9001fa0 	str	w0, [x29,#28]
 90c:	b9001ba1 	str	w1, [x29,#24]
 910:	b9401fa0 	ldr	w0, [x29,#28]
 914:	7100041f 	cmp	w0, #0x1
 918:	54000241 	b.ne	960 <_Z41__static_initialization_and_destruction_0ii+0x60>
 91c:	b9401ba1 	ldr	w1, [x29,#24]
 920:	529fffe0 	mov	w0, #0xffff                	// #65535
 924:	6b00003f 	cmp	w1, w0
 928:	540001c1 	b.ne	960 <_Z41__static_initialization_and_destruction_0ii+0x60>
 92c:	b0000080 	adrp	x0, 11000 <_GLOBAL_OFFSET_TABLE_+0x50>
 930:	9100e000 	add	x0, x0, #0x38
 934:	97ffff9f 	bl	7b0 <_ZNSt8ios_base4InitC1Ev@plt>
 938:	b0000080 	adrp	x0, 11000 <_GLOBAL_OFFSET_TABLE_+0x50>
 93c:	9100a002 	add	x2, x0, #0x28
 940:	b0000080 	adrp	x0, 11000 <_GLOBAL_OFFSET_TABLE_+0x50>
 944:	9100e001 	add	x1, x0, #0x38
 948:	90000080 	adrp	x0, 10000 <__FRAME_END__+0xf570>
 94c:	f947e800 	ldr	x0, [x0,#4048]
 950:	97ffff9c 	bl	7c0 <__cxa_atexit@plt>
 954:	b0000080 	adrp	x0, 11000 <_GLOBAL_OFFSET_TABLE_+0x50>
 958:	91010000 	add	x0, x0, #0x40
 95c:	97ffffa1 	bl	7e0 <_ZNSt6thread2idC1Ev@plt>
 960:	d503201f 	nop
 964:	a8c27bfd 	ldp	x29, x30, [sp],#32
 968:	d65f03c0 	ret

000000000000096c <_GLOBAL__sub_I_atomiclock.cpp>:
 96c:	a9bf7bfd 	stp	x29, x30, [sp,#-16]!
 970:	910003fd 	mov	x29, sp
 974:	529fffe1 	mov	w1, #0xffff                	// #65535
 978:	52800020 	mov	w0, #0x1                   	// #1
 97c:	97ffffe1 	bl	900 <_Z41__static_initialization_and_destruction_0ii>
 980:	a8c17bfd 	ldp	x29, x30, [sp],#16
 984:	d65f03c0 	ret

0000000000000988 <_ZNSt6thread2idC1Ev>:
 988:	d10043ff 	sub	sp, sp, #0x10
 98c:	f90007e0 	str	x0, [sp,#8]
 990:	f94007e0 	ldr	x0, [sp,#8]
 994:	f900001f 	str	xzr, [x0]
 998:	d503201f 	nop
 99c:	910043ff 	add	sp, sp, #0x10
 9a0:	d65f03c0 	ret

Disassembly of section .fini:

00000000000009a4 <_fini>:
 9a4:	a9bf7bfd 	stp	x29, x30, [sp,#-16]!
 9a8:	910003fd 	mov	x29, sp
 9ac:	a8c17bfd 	ldp	x29, x30, [sp],#16
 9b0:	d65f03c0 	ret
