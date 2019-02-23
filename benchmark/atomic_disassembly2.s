
./a.out:     file format elf64-littleaarch64


Disassembly of section .init:

00000000004004b8 <_init>:
  4004b8:	a9bf7bfd 	stp	x29, x30, [sp,#-16]!
  4004bc:	910003fd 	mov	x29, sp
  4004c0:	9400002e 	bl	400578 <call_weak_fn>
  4004c4:	a8c17bfd 	ldp	x29, x30, [sp],#16
  4004c8:	d65f03c0 	ret

Disassembly of section .plt:

00000000004004d0 <__libc_start_main@plt-0x20>:
  4004d0:	a9bf7bf0 	stp	x16, x30, [sp,#-16]!
  4004d4:	90000090 	adrp	x16, 410000 <__FRAME_END__+0xf320>
  4004d8:	f947fe11 	ldr	x17, [x16,#4088]
  4004dc:	913fe210 	add	x16, x16, #0xff8
  4004e0:	d61f0220 	br	x17
  4004e4:	d503201f 	nop
  4004e8:	d503201f 	nop
  4004ec:	d503201f 	nop

00000000004004f0 <__libc_start_main@plt>:
  4004f0:	b0000090 	adrp	x16, 411000 <_GLOBAL_OFFSET_TABLE_+0x28>
  4004f4:	f9400211 	ldr	x17, [x16]
  4004f8:	91000210 	add	x16, x16, #0x0
  4004fc:	d61f0220 	br	x17

0000000000400500 <__stack_chk_fail@plt>:
  400500:	b0000090 	adrp	x16, 411000 <_GLOBAL_OFFSET_TABLE_+0x28>
  400504:	f9400611 	ldr	x17, [x16,#8]
  400508:	91002210 	add	x16, x16, #0x8
  40050c:	d61f0220 	br	x17

0000000000400510 <__gmon_start__@plt>:
  400510:	b0000090 	adrp	x16, 411000 <_GLOBAL_OFFSET_TABLE_+0x28>
  400514:	f9400a11 	ldr	x17, [x16,#16]
  400518:	91004210 	add	x16, x16, #0x10
  40051c:	d61f0220 	br	x17

0000000000400520 <abort@plt>:
  400520:	b0000090 	adrp	x16, 411000 <_GLOBAL_OFFSET_TABLE_+0x28>
  400524:	f9400e11 	ldr	x17, [x16,#24]
  400528:	91006210 	add	x16, x16, #0x18
  40052c:	d61f0220 	br	x17

Disassembly of section .text:

0000000000400530 <_start>:
  400530:	d280001d 	mov	x29, #0x0                   	// #0
  400534:	d280001e 	mov	x30, #0x0                   	// #0
  400538:	aa0003e5 	mov	x5, x0
  40053c:	f94003e1 	ldr	x1, [sp]
  400540:	910023e2 	add	x2, sp, #0x8
  400544:	910003e6 	mov	x6, sp
  400548:	580000c0 	ldr	x0, 400560 <_start+0x30>
  40054c:	580000e3 	ldr	x3, 400568 <_start+0x38>
  400550:	58000104 	ldr	x4, 400570 <_start+0x40>
  400554:	97ffffe7 	bl	4004f0 <__libc_start_main@plt>
  400558:	97fffff2 	bl	400520 <abort@plt>
  40055c:	00000000 	.word	0x00000000
  400560:	00400680 	.word	0x00400680
  400564:	00000000 	.word	0x00000000
  400568:	00400a58 	.word	0x00400a58
  40056c:	00000000 	.word	0x00000000
  400570:	00400ad0 	.word	0x00400ad0
  400574:	00000000 	.word	0x00000000

0000000000400578 <call_weak_fn>:
  400578:	90000080 	adrp	x0, 410000 <__FRAME_END__+0xf320>
  40057c:	f947f000 	ldr	x0, [x0,#4064]
  400580:	b4000040 	cbz	x0, 400588 <call_weak_fn+0x10>
  400584:	17ffffe3 	b	400510 <__gmon_start__@plt>
  400588:	d65f03c0 	ret
  40058c:	00000000 	.inst	0x00000000 ; undefined

0000000000400590 <deregister_tm_clones>:
  400590:	b0000081 	adrp	x1, 411000 <_GLOBAL_OFFSET_TABLE_+0x28>
  400594:	b0000080 	adrp	x0, 411000 <_GLOBAL_OFFSET_TABLE_+0x28>
  400598:	9100c021 	add	x1, x1, #0x30
  40059c:	9100c000 	add	x0, x0, #0x30
  4005a0:	91001c21 	add	x1, x1, #0x7
  4005a4:	cb000021 	sub	x1, x1, x0
  4005a8:	f100383f 	cmp	x1, #0xe
  4005ac:	540000a9 	b.ls	4005c0 <deregister_tm_clones+0x30>
  4005b0:	580000c1 	ldr	x1, 4005c8 <deregister_tm_clones+0x38>
  4005b4:	b4000061 	cbz	x1, 4005c0 <deregister_tm_clones+0x30>
  4005b8:	d61f0020 	br	x1
  4005bc:	d503201f 	nop
  4005c0:	d65f03c0 	ret
  4005c4:	d503201f 	nop
	...

00000000004005d0 <register_tm_clones>:
  4005d0:	b0000081 	adrp	x1, 411000 <_GLOBAL_OFFSET_TABLE_+0x28>
  4005d4:	b0000080 	adrp	x0, 411000 <_GLOBAL_OFFSET_TABLE_+0x28>
  4005d8:	9100c021 	add	x1, x1, #0x30
  4005dc:	9100c000 	add	x0, x0, #0x30
  4005e0:	cb000021 	sub	x1, x1, x0
  4005e4:	9343fc21 	asr	x1, x1, #3
  4005e8:	8b41fc21 	add	x1, x1, x1, lsr #63
  4005ec:	9341fc21 	asr	x1, x1, #1
  4005f0:	b4000081 	cbz	x1, 400600 <register_tm_clones+0x30>
  4005f4:	580000a2 	ldr	x2, 400608 <register_tm_clones+0x38>
  4005f8:	b4000042 	cbz	x2, 400600 <register_tm_clones+0x30>
  4005fc:	d61f0040 	br	x2
  400600:	d65f03c0 	ret
  400604:	d503201f 	nop
	...

0000000000400610 <__do_global_dtors_aux>:
  400610:	a9be7bfd 	stp	x29, x30, [sp,#-32]!
  400614:	910003fd 	mov	x29, sp
  400618:	f9000bf3 	str	x19, [sp,#16]
  40061c:	b0000093 	adrp	x19, 411000 <_GLOBAL_OFFSET_TABLE_+0x28>
  400620:	3940e260 	ldrb	w0, [x19,#56]
  400624:	35000080 	cbnz	w0, 400634 <__do_global_dtors_aux+0x24>
  400628:	97ffffda 	bl	400590 <deregister_tm_clones>
  40062c:	52800020 	mov	w0, #0x1                   	// #1
  400630:	3900e260 	strb	w0, [x19,#56]
  400634:	f9400bf3 	ldr	x19, [sp,#16]
  400638:	a8c27bfd 	ldp	x29, x30, [sp],#32
  40063c:	d65f03c0 	ret

0000000000400640 <frame_dummy>:
  400640:	90000080 	adrp	x0, 410000 <__FRAME_END__+0xf320>
  400644:	9137c000 	add	x0, x0, #0xdf0
  400648:	f9400001 	ldr	x1, [x0]
  40064c:	b5000061 	cbnz	x1, 400658 <frame_dummy+0x18>
  400650:	17ffffe0 	b	4005d0 <register_tm_clones>
  400654:	d503201f 	nop
  400658:	58000101 	ldr	x1, 400678 <frame_dummy+0x38>
  40065c:	b4ffffa1 	cbz	x1, 400650 <frame_dummy+0x10>
  400660:	a9bf7bfd 	stp	x29, x30, [sp,#-16]!
  400664:	910003fd 	mov	x29, sp
  400668:	d63f0020 	blr	x1
  40066c:	a8c17bfd 	ldp	x29, x30, [sp],#16
  400670:	17ffffd8 	b	4005d0 <register_tm_clones>
  400674:	d503201f 	nop
	...

0000000000400680 <main>:
  400680:	a9bc7bfd 	stp	x29, x30, [sp,#-64]!
  400684:	910003fd 	mov	x29, sp
  400688:	b0000080 	adrp	x0, 411000 <_GLOBAL_OFFSET_TABLE_+0x28>
  40068c:	9100c000 	add	x0, x0, #0x30
  400690:	f9400001 	ldr	x1, [x0]
  400694:	f9001fa1 	str	x1, [x29,#56]
  400698:	d2800001 	mov	x1, #0x0                   	// #0
  40069c:	9100a3a0 	add	x0, x29, #0x28
  4006a0:	52800001 	mov	w1, #0x0                   	// #0
  4006a4:	94000049 	bl	4007c8 <_ZN4hiva4base12AtomicRWLockC1Eb>
  4006a8:	b9001fbf 	str	wzr, [x29,#28]
  4006ac:	b9401fa1 	ldr	w1, [x29,#28]
  4006b0:	528847e0 	mov	w0, #0x423f                	// #16959
  4006b4:	72a001e0 	movk	w0, #0xf, lsl #16
  4006b8:	6b00003f 	cmp	w1, w0
  4006bc:	5400014c 	b.gt	4006e4 <main+0x64>
  4006c0:	9100a3a1 	add	x1, x29, #0x28
  4006c4:	910083a0 	add	x0, x29, #0x20
  4006c8:	94000051 	bl	40080c <_ZN4hiva4base14WriteLockGuardC1ERNS0_12AtomicRWLockE>
  4006cc:	910083a0 	add	x0, x29, #0x20
  4006d0:	9400005c 	bl	400840 <_ZN4hiva4base14WriteLockGuardD1Ev>
  4006d4:	b9401fa0 	ldr	w0, [x29,#28]
  4006d8:	11000400 	add	w0, w0, #0x1
  4006dc:	b9001fa0 	str	w0, [x29,#28]
  4006e0:	17fffff3 	b	4006ac <main+0x2c>
  4006e4:	52800000 	mov	w0, #0x0                   	// #0
  4006e8:	b0000081 	adrp	x1, 411000 <_GLOBAL_OFFSET_TABLE_+0x28>
  4006ec:	9100c021 	add	x1, x1, #0x30
  4006f0:	f9401fa2 	ldr	x2, [x29,#56]
  4006f4:	f9400021 	ldr	x1, [x1]
  4006f8:	ca010041 	eor	x1, x2, x1
  4006fc:	f100003f 	cmp	x1, #0x0
  400700:	54000040 	b.eq	400708 <main+0x88>
  400704:	97ffff7f 	bl	400500 <__stack_chk_fail@plt>
  400708:	a8c47bfd 	ldp	x29, x30, [sp],#64
  40070c:	d65f03c0 	ret

0000000000400710 <_ZStanSt12memory_orderSt23__memory_order_modifier>:
  400710:	d10043ff 	sub	sp, sp, #0x10
  400714:	b9000fe0 	str	w0, [sp,#12]
  400718:	b9000be1 	str	w1, [sp,#8]
  40071c:	b9400fe1 	ldr	w1, [sp,#12]
  400720:	b9400be0 	ldr	w0, [sp,#8]
  400724:	0a000020 	and	w0, w1, w0
  400728:	910043ff 	add	sp, sp, #0x10
  40072c:	d65f03c0 	ret

0000000000400730 <_ZNSt13__atomic_baseIiEC2Ei>:
  400730:	d10043ff 	sub	sp, sp, #0x10
  400734:	f90007e0 	str	x0, [sp,#8]
  400738:	b90007e1 	str	w1, [sp,#4]
  40073c:	f94007e0 	ldr	x0, [sp,#8]
  400740:	b94007e1 	ldr	w1, [sp,#4]
  400744:	b9000001 	str	w1, [x0]
  400748:	d503201f 	nop
  40074c:	910043ff 	add	sp, sp, #0x10
  400750:	d65f03c0 	ret

0000000000400754 <_ZNSt6atomicIiEC1Ei>:
  400754:	a9be7bfd 	stp	x29, x30, [sp,#-32]!
  400758:	910003fd 	mov	x29, sp
  40075c:	f9000fa0 	str	x0, [x29,#24]
  400760:	b90017a1 	str	w1, [x29,#20]
  400764:	f9400fa0 	ldr	x0, [x29,#24]
  400768:	b94017a1 	ldr	w1, [x29,#20]
  40076c:	97fffff1 	bl	400730 <_ZNSt13__atomic_baseIiEC2Ei>
  400770:	d503201f 	nop
  400774:	a8c27bfd 	ldp	x29, x30, [sp],#32
  400778:	d65f03c0 	ret

000000000040077c <_ZNSt13__atomic_baseIjEC2Ej>:
  40077c:	d10043ff 	sub	sp, sp, #0x10
  400780:	f90007e0 	str	x0, [sp,#8]
  400784:	b90007e1 	str	w1, [sp,#4]
  400788:	f94007e0 	ldr	x0, [sp,#8]
  40078c:	b94007e1 	ldr	w1, [sp,#4]
  400790:	b9000001 	str	w1, [x0]
  400794:	d503201f 	nop
  400798:	910043ff 	add	sp, sp, #0x10
  40079c:	d65f03c0 	ret

00000000004007a0 <_ZNSt6atomicIjEC1Ej>:
  4007a0:	a9be7bfd 	stp	x29, x30, [sp,#-32]!
  4007a4:	910003fd 	mov	x29, sp
  4007a8:	f9000fa0 	str	x0, [x29,#24]
  4007ac:	b90017a1 	str	w1, [x29,#20]
  4007b0:	f9400fa0 	ldr	x0, [x29,#24]
  4007b4:	b94017a1 	ldr	w1, [x29,#20]
  4007b8:	97fffff1 	bl	40077c <_ZNSt13__atomic_baseIjEC2Ej>
  4007bc:	d503201f 	nop
  4007c0:	a8c27bfd 	ldp	x29, x30, [sp],#32
  4007c4:	d65f03c0 	ret

00000000004007c8 <_ZN4hiva4base12AtomicRWLockC1Eb>:
  4007c8:	a9be7bfd 	stp	x29, x30, [sp,#-32]!
  4007cc:	910003fd 	mov	x29, sp
  4007d0:	f9000fa0 	str	x0, [x29,#24]
  4007d4:	39005fa1 	strb	w1, [x29,#23]
  4007d8:	f9400fa0 	ldr	x0, [x29,#24]
  4007dc:	52800001 	mov	w1, #0x0                   	// #0
  4007e0:	97fffff0 	bl	4007a0 <_ZNSt6atomicIjEC1Ej>
  4007e4:	f9400fa0 	ldr	x0, [x29,#24]
  4007e8:	91001000 	add	x0, x0, #0x4
  4007ec:	52800001 	mov	w1, #0x0                   	// #0
  4007f0:	97ffffd9 	bl	400754 <_ZNSt6atomicIiEC1Ei>
  4007f4:	f9400fa0 	ldr	x0, [x29,#24]
  4007f8:	39405fa1 	ldrb	w1, [x29,#23]
  4007fc:	39002001 	strb	w1, [x0,#8]
  400800:	d503201f 	nop
  400804:	a8c27bfd 	ldp	x29, x30, [sp],#32
  400808:	d65f03c0 	ret

000000000040080c <_ZN4hiva4base14WriteLockGuardC1ERNS0_12AtomicRWLockE>:
  40080c:	a9be7bfd 	stp	x29, x30, [sp,#-32]!
  400810:	910003fd 	mov	x29, sp
  400814:	f9000fa0 	str	x0, [x29,#24]
  400818:	f9000ba1 	str	x1, [x29,#16]
  40081c:	f9400fa0 	ldr	x0, [x29,#24]
  400820:	f9400ba1 	ldr	x1, [x29,#16]
  400824:	f9000001 	str	x1, [x0]
  400828:	f9400fa0 	ldr	x0, [x29,#24]
  40082c:	f9400000 	ldr	x0, [x0]
  400830:	9400000d 	bl	400864 <_ZN4hiva4base12AtomicRWLock9WriteLockEv>
  400834:	d503201f 	nop
  400838:	a8c27bfd 	ldp	x29, x30, [sp],#32
  40083c:	d65f03c0 	ret

0000000000400840 <_ZN4hiva4base14WriteLockGuardD1Ev>:
  400840:	a9be7bfd 	stp	x29, x30, [sp,#-32]!
  400844:	910003fd 	mov	x29, sp
  400848:	f9000fa0 	str	x0, [x29,#24]
  40084c:	f9400fa0 	ldr	x0, [x29,#24]
  400850:	f9400000 	ldr	x0, [x0]
  400854:	9400006c 	bl	400a04 <_ZN4hiva4base12AtomicRWLock11WriteUnlockEv>
  400858:	d503201f 	nop
  40085c:	a8c27bfd 	ldp	x29, x30, [sp],#32
  400860:	d65f03c0 	ret

0000000000400864 <_ZN4hiva4base12AtomicRWLock9WriteLockEv>:
  400864:	a9b87bfd 	stp	x29, x30, [sp,#-128]!
  400868:	910003fd 	mov	x29, sp
  40086c:	f9000fa0 	str	x0, [x29,#24]
  400870:	b0000080 	adrp	x0, 411000 <_GLOBAL_OFFSET_TABLE_+0x28>
  400874:	9100c000 	add	x0, x0, #0x30
  400878:	f9400001 	ldr	x1, [x0]
  40087c:	f9003fa1 	str	x1, [x29,#120]
  400880:	d2800001 	mov	x1, #0x0                   	// #0
  400884:	f9400fa0 	ldr	x0, [x29,#24]
  400888:	91001000 	add	x0, x0, #0x4
  40088c:	f90033a0 	str	x0, [x29,#96]
  400890:	52800020 	mov	w0, #0x1                   	// #1
  400894:	b90037a0 	str	w0, [x29,#52]
  400898:	528000a0 	mov	w0, #0x5                   	// #5
  40089c:	b9003ba0 	str	w0, [x29,#56]
  4008a0:	f94033a0 	ldr	x0, [x29,#96]
  4008a4:	b94037a1 	ldr	w1, [x29,#52]
  4008a8:	885ffc02 	ldaxr	w2, [x0]
  4008ac:	4b010043 	sub	w3, w2, w1
  4008b0:	8804fc03 	stlxr	w4, w3, [x0]
  4008b4:	35ffffa4 	cbnz	w4, 4008a8 <_ZN4hiva4base12AtomicRWLock9WriteLockEv+0x44>
  4008b8:	b90027bf 	str	wzr, [x29,#36]
  4008bc:	b9002bbf 	str	wzr, [x29,#40]
  4008c0:	f9400fa0 	ldr	x0, [x29,#24]
  4008c4:	f9003ba0 	str	x0, [x29,#112]
  4008c8:	52800020 	mov	w0, #0x1                   	// #1
  4008cc:	b9002fa0 	str	w0, [x29,#44]
  4008d0:	528000a0 	mov	w0, #0x5                   	// #5
  4008d4:	b90033a0 	str	w0, [x29,#48]
  4008d8:	f9403ba0 	ldr	x0, [x29,#112]
  4008dc:	b9402fa1 	ldr	w1, [x29,#44]
  4008e0:	885ffc02 	ldaxr	w2, [x0]
  4008e4:	0b010043 	add	w3, w2, w1
  4008e8:	8804fc03 	stlxr	w4, w3, [x0]
  4008ec:	35ffffa4 	cbnz	w4, 4008e0 <_ZN4hiva4base12AtomicRWLock9WriteLockEv+0x7c>
  4008f0:	f9400fa0 	ldr	x0, [x29,#24]
  4008f4:	91001000 	add	x0, x0, #0x4
  4008f8:	f9002fa0 	str	x0, [x29,#88]
  4008fc:	12800000 	mov	w0, #0xffffffff            	// #-1
  400900:	b9003fa0 	str	w0, [x29,#60]
  400904:	52800040 	mov	w0, #0x2                   	// #2
  400908:	b90043a0 	str	w0, [x29,#64]
  40090c:	b90047bf 	str	wzr, [x29,#68]
  400910:	529fffe1 	mov	w1, #0xffff                	// #65535
  400914:	b94047a0 	ldr	w0, [x29,#68]
  400918:	97ffff7e 	bl	400710 <_ZStanSt12memory_orderSt23__memory_order_modifier>
  40091c:	b9004ba0 	str	w0, [x29,#72]
  400920:	529fffe1 	mov	w1, #0xffff                	// #65535
  400924:	b94043a0 	ldr	w0, [x29,#64]
  400928:	97ffff7a 	bl	400710 <_ZStanSt12memory_orderSt23__memory_order_modifier>
  40092c:	b9004fa0 	str	w0, [x29,#76]
  400930:	f9402fa1 	ldr	x1, [x29,#88]
  400934:	b9403fa4 	ldr	w4, [x29,#60]
  400938:	910093a0 	add	x0, x29, #0x24
  40093c:	b9400003 	ldr	w3, [x0]
  400940:	885ffc22 	ldaxr	w2, [x1]
  400944:	6b03005f 	cmp	w2, w3
  400948:	54000061 	b.ne	400954 <_ZN4hiva4base12AtomicRWLock9WriteLockEv+0xf0>
  40094c:	8805fc24 	stlxr	w5, w4, [x1]
  400950:	710000bf 	cmp	w5, #0x0
  400954:	1a9f17e1 	cset	w1, eq
  400958:	7100003f 	cmp	w1, #0x0
  40095c:	54000041 	b.ne	400964 <_ZN4hiva4base12AtomicRWLock9WriteLockEv+0x100>
  400960:	b9000002 	str	w2, [x0]
  400964:	2a0103e0 	mov	w0, w1
  400968:	52000000 	eor	w0, w0, #0x1
  40096c:	53001c00 	uxtb	w0, w0
  400970:	7100001f 	cmp	w0, #0x0
  400974:	540001a0 	b.eq	4009a8 <_ZN4hiva4base12AtomicRWLock9WriteLockEv+0x144>
  400978:	b90027bf 	str	wzr, [x29,#36]
  40097c:	b9402ba0 	ldr	w0, [x29,#40]
  400980:	11000400 	add	w0, w0, #0x1
  400984:	b9002ba0 	str	w0, [x29,#40]
  400988:	b9402ba0 	ldr	w0, [x29,#40]
  40098c:	7100141f 	cmp	w0, #0x5
  400990:	1a9f17e0 	cset	w0, eq
  400994:	53001c00 	uxtb	w0, w0
  400998:	7100001f 	cmp	w0, #0x0
  40099c:	54fffaa0 	b.eq	4008f0 <_ZN4hiva4base12AtomicRWLock9WriteLockEv+0x8c>
  4009a0:	b9002bbf 	str	wzr, [x29,#40]
  4009a4:	17ffffd3 	b	4008f0 <_ZN4hiva4base12AtomicRWLock9WriteLockEv+0x8c>
  4009a8:	f9400fa0 	ldr	x0, [x29,#24]
  4009ac:	f90037a0 	str	x0, [x29,#104]
  4009b0:	52800020 	mov	w0, #0x1                   	// #1
  4009b4:	b90053a0 	str	w0, [x29,#80]
  4009b8:	528000a0 	mov	w0, #0x5                   	// #5
  4009bc:	b90057a0 	str	w0, [x29,#84]
  4009c0:	f94037a0 	ldr	x0, [x29,#104]
  4009c4:	b94053a1 	ldr	w1, [x29,#80]
  4009c8:	885ffc02 	ldaxr	w2, [x0]
  4009cc:	4b010043 	sub	w3, w2, w1
  4009d0:	8804fc03 	stlxr	w4, w3, [x0]
  4009d4:	35ffffa4 	cbnz	w4, 4009c8 <_ZN4hiva4base12AtomicRWLock9WriteLockEv+0x164>
  4009d8:	d503201f 	nop
  4009dc:	b0000080 	adrp	x0, 411000 <_GLOBAL_OFFSET_TABLE_+0x28>
  4009e0:	9100c000 	add	x0, x0, #0x30
  4009e4:	f9403fa1 	ldr	x1, [x29,#120]
  4009e8:	f9400000 	ldr	x0, [x0]
  4009ec:	ca000020 	eor	x0, x1, x0
  4009f0:	f100001f 	cmp	x0, #0x0
  4009f4:	54000040 	b.eq	4009fc <_ZN4hiva4base12AtomicRWLock9WriteLockEv+0x198>
  4009f8:	97fffec2 	bl	400500 <__stack_chk_fail@plt>
  4009fc:	a8c87bfd 	ldp	x29, x30, [sp],#128
  400a00:	d65f03c0 	ret

0000000000400a04 <_ZN4hiva4base12AtomicRWLock11WriteUnlockEv>:
  400a04:	d10083ff 	sub	sp, sp, #0x20
  400a08:	f90007e0 	str	x0, [sp,#8]
  400a0c:	f94007e0 	ldr	x0, [sp,#8]
  400a10:	91001000 	add	x0, x0, #0x4
  400a14:	f9000fe0 	str	x0, [sp,#24]
  400a18:	52800020 	mov	w0, #0x1                   	// #1
  400a1c:	b90013e0 	str	w0, [sp,#16]
  400a20:	528000a0 	mov	w0, #0x5                   	// #5
  400a24:	b90017e0 	str	w0, [sp,#20]
  400a28:	f9400fe0 	ldr	x0, [sp,#24]
  400a2c:	b94013e1 	ldr	w1, [sp,#16]
  400a30:	885ffc02 	ldaxr	w2, [x0]
  400a34:	0b010043 	add	w3, w2, w1
  400a38:	8804fc03 	stlxr	w4, w3, [x0]
  400a3c:	35ffffa4 	cbnz	w4, 400a30 <_ZN4hiva4base12AtomicRWLock11WriteUnlockEv+0x2c>
  400a40:	2a0203e0 	mov	w0, w2
  400a44:	3100041f 	cmn	w0, #0x1
  400a48:	d503201f 	nop
  400a4c:	910083ff 	add	sp, sp, #0x20
  400a50:	d65f03c0 	ret
  400a54:	00000000 	.inst	0x00000000 ; undefined

0000000000400a58 <__libc_csu_init>:
  400a58:	a9bc7bfd 	stp	x29, x30, [sp,#-64]!
  400a5c:	910003fd 	mov	x29, sp
  400a60:	a9025bf5 	stp	x21, x22, [sp,#32]
  400a64:	90000095 	adrp	x21, 410000 <__FRAME_END__+0xf320>
  400a68:	a90153f3 	stp	x19, x20, [sp,#16]
  400a6c:	90000094 	adrp	x20, 410000 <__FRAME_END__+0xf320>
  400a70:	913782b5 	add	x21, x21, #0xde0
  400a74:	9137a294 	add	x20, x20, #0xde8
  400a78:	cb150294 	sub	x20, x20, x21
  400a7c:	a90363f7 	stp	x23, x24, [sp,#48]
  400a80:	aa0203f6 	mov	x22, x2
  400a84:	2a0003f8 	mov	w24, w0
  400a88:	aa0103f7 	mov	x23, x1
  400a8c:	97fffe8b 	bl	4004b8 <_init>
  400a90:	9343fe94 	asr	x20, x20, #3
  400a94:	b4000154 	cbz	x20, 400abc <__libc_csu_init+0x64>
  400a98:	d2800013 	mov	x19, #0x0                   	// #0
  400a9c:	f8737aa3 	ldr	x3, [x21,x19,lsl #3]
  400aa0:	aa1603e2 	mov	x2, x22
  400aa4:	aa1703e1 	mov	x1, x23
  400aa8:	2a1803e0 	mov	w0, w24
  400aac:	91000673 	add	x19, x19, #0x1
  400ab0:	d63f0060 	blr	x3
  400ab4:	eb14027f 	cmp	x19, x20
  400ab8:	54ffff21 	b.ne	400a9c <__libc_csu_init+0x44>
  400abc:	a94153f3 	ldp	x19, x20, [sp,#16]
  400ac0:	a9425bf5 	ldp	x21, x22, [sp,#32]
  400ac4:	a94363f7 	ldp	x23, x24, [sp,#48]
  400ac8:	a8c47bfd 	ldp	x29, x30, [sp],#64
  400acc:	d65f03c0 	ret

0000000000400ad0 <__libc_csu_fini>:
  400ad0:	d65f03c0 	ret

Disassembly of section .fini:

0000000000400ad4 <_fini>:
  400ad4:	a9bf7bfd 	stp	x29, x30, [sp,#-16]!
  400ad8:	910003fd 	mov	x29, sp
  400adc:	a8c17bfd 	ldp	x29, x30, [sp],#16
  400ae0:	d65f03c0 	ret
