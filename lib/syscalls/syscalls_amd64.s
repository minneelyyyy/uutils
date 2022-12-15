.extern errno

.global sys_exit
sys_exit:
	mov $1, %rax
	syscall

.macro define_syscall name,num
.global \name
\name:
	mov $\num, %rax
	syscall
	jc 1f
	ret

	1:
	mov %eax, errno
	mov $0xFFFFFFFFFFFFFFFF, %eax
	ret
.endm

.include "lib/syscalls/tbl.s"
